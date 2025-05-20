//FormAI DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100

struct Contact {
    char name[50];
    char phone_number[20];
};

int main() {
    struct Contact phone_book[MAX_CONTACTS];
    char input[50];
    int num_contacts = 0;
    int i, j;

    printf("Welcome to your phone book!\n");

    while (1) {
        printf("\nWhat would you like to do?\n1. Add a contact\n2. Search for a contact\n3. Print all contacts\n4. Exit\n");
        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            if (num_contacts == MAX_CONTACTS) {
                printf("Sorry, your phone book is full.\n");
            } else {
                printf("Enter the name: ");
                scanf("%s", phone_book[num_contacts].name);
                printf("Enter the phone number: ");
                scanf("%s", phone_book[num_contacts].phone_number);
                printf("Contact added successfully!\n");
                num_contacts++;
            }
        } else if (strcmp(input, "2") == 0) {
            printf("Enter the name of the contact: ");
            scanf("%s", input);

            int found = 0;
            for (i = 0; i < num_contacts; i++) {
                if (strcmp(phone_book[i].name, input) == 0) {
                    printf("Phone number for %s: %s\n", phone_book[i].name, phone_book[i].phone_number);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Contact not found.\n");
            }

        } else if (strcmp(input, "3") == 0) {
            if (num_contacts == 0) {
                printf("Your phone book is empty.\n");
            } else {
                printf("Your contacts:\n");
                for (i = 0; i < num_contacts; i++) {
                    printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
                }
            }
        } else if (strcmp(input, "4") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}