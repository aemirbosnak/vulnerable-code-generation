//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
};

int MENU() {
    int choice;
    printf("Welcome to the Phone Book Application!\n");
    printf("1. Add a Contact\n");
    printf("2. Search for a Contact\n");
    printf("3. Display all Contacts\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int size = 5;  // initial array size
    int count = 0; // contact count
    struct Contact* book = malloc(size * sizeof(struct Contact)); // allocate memory for contact book
    int choice;
    char search_name[MAX_NAME_LENGTH];
    int i;

    do {
        choice = MENU();

        switch (choice) {
            case 1: // Add a Contact
                if (count >= size) {
                    size *= 2;
                    book = realloc(book, size * sizeof(struct Contact)); // double the array size
                }
                printf("Enter contact name: ");
                scanf("%s", book[count].name);
                printf("Enter phone number: ");
                scanf("%s", book[count].phone);
                printf("Contact added successfully!\n\n");
                count++;
                break;
            case 2: // Search for a Contact
                printf("Enter contact name: ");
                scanf("%s", search_name);
                for (i = 0; i < count; i++) {
                    if (strcmp(search_name, book[i].name) == 0) {
                        printf("Name: %s\n", book[i].name);
                        printf("Phone: %s\n\n", book[i].phone);
                        break;
                    }
                }
                if (i == count) {
                    printf("Contact not found.\n\n");
                }
                break;
            case 3: // Display all Contacts
                if (count == 0) {
                    printf("Contact book is empty.\n\n");
                } else {
                    printf("Contacts:\n");
                    for (i = 0; i < count; i++) {
                        printf("%d. Name: %s, Phone: %s\n", i+1, book[i].name, book[i].phone);
                    }
                    printf("\n");
                }
                break;
            case 4: // Exit
                printf("Thank you for using the Phone Book Application!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }

    } while (choice != 4);

    free(book); // free memory allocated for contact book
    return 0;
}