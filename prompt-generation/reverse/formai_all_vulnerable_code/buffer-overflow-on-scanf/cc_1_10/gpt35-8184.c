//FormAI DATASET v1.0 Category: Phone Book ; Style: genious
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 1000

// Structure to hold contact details
struct Contact {
    char name[50];
    char phone_number[15];
};

// Function declaration
void add_contact(struct Contact[], int*);
void search_contact(struct Contact[], int);
void display_all_contacts(struct Contact[], int);
void delete_contact(struct Contact[], int*);

int main() {
    struct Contact phone_book[MAX_ENTRIES];
    int num_entries = 0, choice;

    do {
        printf("Phone Book Menu:\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Display all contacts\n");
        printf("4. Delete a contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(phone_book, &num_entries);
                break;
            case 2:
                search_contact(phone_book, num_entries);
                break;
            case 3:
                display_all_contacts(phone_book, num_entries);
                break;
            case 4:
                delete_contact(phone_book, &num_entries);
                break;
            case 5:
                printf("Thank you for using Phone Book!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void add_contact(struct Contact phone_book[], int* num_entries) {
    char name[50], phone[15];

    if (*num_entries == MAX_ENTRIES) {
        printf("Phone Book is full. Cannot add more contacts.\n");
        return;
    }

    printf("Enter name of the contact: ");
    scanf("%s", name);

    // Check if contact already exists
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact already exists.\n");
            return;
        }
    }

    printf("Enter phone number of the contact: ");
    scanf("%s", phone);

    strcpy(phone_book[*num_entries].name, name);
    strcpy(phone_book[*num_entries].phone_number, phone);
    (*num_entries)++;

    printf("Contact added successfully!\n");
}

void search_contact(struct Contact phone_book[], int num_entries) {
    char name[50];

    printf("Enter name of the contact to search: ");
    scanf("%s", name);

    for (int i = 0; i < num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone Number: %s\n", phone_book[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_all_contacts(struct Contact phone_book[], int num_entries) {
    if (num_entries == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("All contacts:\n");

    for (int i = 0; i < num_entries; i++) {
        printf("%d. Name: %s, Phone Number: %s\n", i+1, phone_book[i].name, phone_book[i].phone_number);
    }
}

void delete_contact(struct Contact phone_book[], int* num_entries) {
    char name[50];

    if (*num_entries == 0) {
        printf("No contacts found. Cannot delete.\n");
        return;
    }

    printf("Enter name of the contact to delete: ");
    scanf("%s", name);

    int index = -1;

    // Find index of contact to delete
    for (int i = 0; i < *num_entries; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }

    // Shift contacts to left to overwrite the deleted contact
    for (int i = index; i < *num_entries-1; i++) {
        strcpy(phone_book[i].name, phone_book[i+1].name);
        strcpy(phone_book[i].phone_number, phone_book[i+1].phone_number);
    }

    (*num_entries)--;
    printf("Contact deleted successfully!\n");
}