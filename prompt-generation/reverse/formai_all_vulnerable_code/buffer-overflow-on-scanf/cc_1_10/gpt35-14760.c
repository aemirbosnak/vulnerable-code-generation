//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the phone book
struct contact {
    char name[30];
    char phone[15];
    struct contact *next;
} *head;

// Function declarations
void add_contact();
void delete_contact();
void search_contact();
void display_contacts();
void save_contacts();
void load_contacts();
void free_contacts(struct contact* node);

int main() {
    int choice = 0;

    // Load contacts from file
    load_contacts();

    while (choice != 5) {
        printf("\nC Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                delete_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    // Save contacts to file
    save_contacts();

    // Free memory
    free_contacts(head);

    return 0;
}

// Function to add a new contact
void add_contact() {
    struct contact *temp, *right;

    temp = (struct contact*)malloc(sizeof(struct contact));
    printf("Enter name: ");
    scanf("%s", temp->name);
    printf("Enter phone number: ");
    scanf("%s", temp->phone);
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        right = head;
        while (right->next != NULL)
            right = right->next;
        right->next = temp;
    }

    printf("Contact added successfully!\n");
}

// Function to delete a contact
void delete_contact() {
    struct contact *temp, *prev;
    char search_name[30];

    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf("%s", search_name);

    temp = head;
    prev = head;

    while (temp != NULL) {
        if (strcmp(temp->name, search_name) == 0) {
            if (temp == head) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Contact deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found!\n");
}

// Function to search for a contact
void search_contact() {
    struct contact *temp;
    char search_name[30];

    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Enter name to search: ");
    scanf("%s", search_name);

    temp = head;

    while (temp != NULL) {
        if (strcmp(temp->name, search_name) == 0) {
            printf("Name: %s\n", temp->name);
            printf("Phone: %s\n", temp->phone);
            return;
        }

        temp = temp->next;
    }

    printf("Contact not found!\n");
}

// Function to display all contacts
void display_contacts() {
    struct contact *temp;

    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Contacts:\n");

    temp = head;

    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        temp = temp->next;
    }
}

// Function to save contacts to file
void save_contacts() {
    struct contact *temp;
    FILE *fptr;

    fptr = fopen("phonebook.dat", "wb");

    temp = head;

    while (temp != NULL) {
        fwrite(temp, sizeof(struct contact), 1, fptr);
        temp = temp->next;
    }

    fclose(fptr);

    printf("Contacts saved to file!\n");
}

// Function to load contacts from file
void load_contacts() {
    struct contact *temp;
    FILE *fptr;

    fptr = fopen("phonebook.dat", "rb");

    if (fptr == NULL) {
        return;
    }

    while (!feof(fptr)) {
        temp = (struct contact*)malloc(sizeof(struct contact));
        fread(temp, sizeof(struct contact), 1, fptr);
        if (feof(fptr)) {
            free(temp);
        } else {
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
            } else {
                struct contact *right = head;
                while (right->next != NULL) {
                    right = right->next;
                }
                right->next = temp;
            }
        }
    }

    fclose(fptr);
}

// Function to free all contacts
void free_contacts(struct contact* node) {
    if (node == NULL) {
        return;
    }

    free_contacts(node->next);

    free(node);
}