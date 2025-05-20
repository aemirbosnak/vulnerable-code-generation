//FormAI DATASET v1.0 Category: Phone Book ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_EMAIL_LEN 50
#define MAX_AGE 150

// Struct definition for contact
typedef struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char email[MAX_EMAIL_LEN];
    int age;
    struct Contact *next;
} Contact;

// Function prototypes
void addContact(Contact **head);
void printContacts(Contact *head);
void searchContact(Contact *head);
void deleteContact(Contact **head);

int main() {
    Contact *head = NULL;
    int choice;

    do {
        printf("\n\n\t\t\tC Phone Book\n\n");
        printf("\t1. Add Contact\n");
        printf("\t2. Print Contacts\n");
        printf("\t3. Search Contact\n");
        printf("\t4. Delete Contact\n");
        printf("\t5. Exit\n");
        printf("\tEnter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(&head);
                break;
            case 2:
                printContacts(head);
                break;
            case 3:
                searchContact(head);
                break;
            case 4:
                deleteContact(&head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (1);
}

// Function to add a contact
void addContact(Contact **head) {
    Contact *newContact = (Contact *) malloc(sizeof(Contact));

    printf("\nEnter name: ");
    fflush(stdin);
    gets(newContact->name);

    printf("Enter phone number: ");
    fflush(stdin);
    gets(newContact->phone);

    printf("Enter email address: ");
    fflush(stdin);
    gets(newContact->email);

    printf("Enter age: ");
    fflush(stdin);
    scanf("%d", &newContact->age);

    newContact->next = NULL;

    if (*head == NULL) {
        *head = newContact;
    } else {
        Contact *temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newContact;
    }

    printf("\nContact added successfully!\n");
}

// Function to print all contacts
void printContacts(Contact *head) {
    if (head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\nName\t\tPhone Number\t\tEmail Address\t\tAge\n");

    while (head != NULL) {
        printf("%s\t\t%s\t\t%s\t\t%d\n", head->name, head->phone, head->email, head->age);
        head = head->next;
    }
}

// Function to search for a contact
void searchContact(Contact *head) {
    if (head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    char search[MAX_NAME_LEN];
    printf("\nEnter name to search: ");
    fflush(stdin);
    gets(search);

    Contact *temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, search) == 0) {
            printf("\nName\t\tPhone Number\t\tEmail Address\t\tAge\n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", temp->name, temp->phone, temp->email, temp->age);
            found = 1;
            break;
        }

        temp = temp->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}

// Function to delete a contact
void deleteContact(Contact **head) {
    if (*head == NULL) {
        printf("\nNo contacts found.\n");
        return;
    }

    char search[MAX_NAME_LEN];
    printf("\nEnter name to delete: ");
    fflush(stdin);
    gets(search);

    Contact *temp = *head, *prev = NULL;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, search) == 0) {
            if (prev == NULL) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);

            printf("\nContact deleted successfully!\n");
            found = 1;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}