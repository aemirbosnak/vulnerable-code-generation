//FormAI DATASET v1.0 Category: Phone Book ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 15

typedef struct PhoneBook {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
    struct PhoneBook *next;
} PhoneBook;

void printInstructions() {
    printf("1. Add a contact\n");
    printf("2. List all contacts\n");
    printf("3. Search for a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Exit\n\n");
}

void addContact(PhoneBook **headPtr) {
    PhoneBook *newContact = (PhoneBook*) malloc(sizeof(PhoneBook));

    printf("Enter contact name: ");
    scanf("%s", newContact->name);

    printf("Enter contact number: ");
    scanf("%s", newContact->number);

    newContact->next = *headPtr;
    *headPtr = newContact;

    printf("Contact successfully added!\n\n");
}

void listContacts(PhoneBook *head) {
    printf("Contact List:\n\n");

    if (head == NULL) {
        printf("No contacts in list.\n\n");
    } else {
        PhoneBook *curr = head;
        int count = 1;

        while (curr != NULL) {
            printf("%d. %s - %s\n", count, curr->name, curr->number);
            curr = curr->next;
            count++;
        }

        printf("\n");
    }
}

void searchContact(PhoneBook *head) {
    if (head == NULL) {
        printf("No contacts in list.\n\n");
    } else {
        char name[MAX_NAME_LEN];
        printf("Enter contact name to search: ");
        scanf("%s", name);

        PhoneBook *curr = head;
        int count = 1;
        int matchFound = 0;

        while (curr != NULL) {
            if (strcmp(curr->name, name) == 0) {
                printf("%d. %s - %s\n", count, curr->name, curr->number);
                matchFound = 1;
            }

            curr = curr->next;
            count++;
        }

        if (!matchFound) {
            printf("No matching contacts found.\n\n");
        } else {
            printf("\n");
        }
    }
}

void deleteContact(PhoneBook **headPtr) {
    if (*headPtr == NULL) {
        printf("No contacts in list.\n\n");
    } else {
        char name[MAX_NAME_LEN];
        printf("Enter contact name to delete: ");
        scanf("%s", name);

        PhoneBook *curr = *headPtr;
        PhoneBook *prev = NULL;
        int matchFound = 0;

        while (curr != NULL) {
            if (strcmp(curr->name, name) == 0) {
                if (prev != NULL) {
                    prev->next = curr->next;
                } else {
                    *headPtr = curr->next;
                }

                free(curr);
                matchFound = 1;
                break;
            }

            prev = curr;
            curr = curr->next;
        }

        if (!matchFound) {
            printf("No matching contacts found.\n\n");
        } else {
            printf("Contact successfully deleted!\n\n");
        }
    }
}

int main() {
    PhoneBook *head = NULL;
    int option;

    do {
        printInstructions();
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addContact(&head);
                break;
            case 2:
                listContacts(head);
                break;
            case 3:
                searchContact(head);
                break;
            case 4:
                deleteContact(&head);
                break;
            case 5:
                printf("Exiting phone book...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
        }
    } while(option != 5);

    return 0;
}