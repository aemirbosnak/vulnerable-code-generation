//FormAI DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

int main() {
    int choice, numContacts=0, i;
    struct contact *book = NULL;
    do {
        printf("Select an option:\n");
        printf("1. Add a contact\n");
        printf("2. Print all contacts\n");
        printf("3. Delete a contact\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Add a contact
                numContacts++;
                book = realloc(book, numContacts * sizeof(struct contact));
                printf("Enter name: ");
                scanf("%s", book[numContacts-1].name);
                printf("Enter phone number: ");
                scanf("%s", book[numContacts-1].phone);
                break;
            case 2:
                // Print all contacts
                printf("Name\t Phone\n");
                for (i = 0; i < numContacts; i++) {
                    printf("%s\t %s\n", book[i].name, book[i].phone);
                }
                break;
            case 3:
                // Delete a contact
                printf("Enter name of contact to delete: ");
                char deleteName[50];
                scanf("%s", deleteName);
                for (i = 0; i < numContacts; i++) {
                    if (strcmp(deleteName, book[i].name) == 0) {
                        // shift array to remove deleted contact
                        for (int j = i; j < numContacts - 1; j++) {
                            strcpy(book[j].name, book[j+1].name);
                            strcpy(book[j].phone, book[j+1].phone);
                        }
                        numContacts--;
                        book = realloc(book, numContacts * sizeof(struct contact));
                        printf("Contact deleted\n");
                        break;
                    }
                }
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                free(book);
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);
    return 0;
}