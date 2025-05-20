//FormAI DATASET v1.0 Category: Phone Book ; Style: accurate
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[30];
    char phone[15];
};

int main() {
    int option = 0, count = 0;
    char search[30];
    struct Contact book[100];

    printf("Welcome to your Phone Book!\n");

    while(option != 4) {
        printf("\nPlease select an option:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Show all contacts\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                char name[30], phone[15];
                printf("\nAdding a new contact:\n");
                printf("Name: ");
                scanf("%s", name);
                printf("Phone: ");
                scanf("%s", phone);
                struct Contact new_contact;
                strcpy(new_contact.name, name);
                strcpy(new_contact.phone, phone);
                book[count] = new_contact;
                count++;
                printf("\nContact added successfully.\n");
                break;
            }
            case 2: {
                printf("\nSearching for a contact:\n");
                printf("Name: ");
                scanf("%s", search);
                int found = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(book[i].name, search) == 0) {
                        printf("Name: %s\n", book[i].name);
                        printf("Phone: %s\n", book[i].phone);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 3:
                printf("\nList of all contacts:\n");
                for (int i = 0; i < count; i++) {
                    printf("Name: %s\n", book[i].name);
                    printf("Phone: %s\n", book[i].phone);
                }
                break;
            case 4:
                printf("\nExiting phone book.\n");
                break;
            default:
                printf("\nInvalid option selected. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}