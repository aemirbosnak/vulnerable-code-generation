//FormAI DATASET v1.0 Category: Phone Book ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

int main() {
    struct contact phonebook[1000];
    int numContacts = 0;
    char input[10], search[50];
    int i, j, found;

    do {
        printf("Phone Book\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%s", input);

        switch (atoi(input)) {
            case 1:
                printf("Name: ");
                scanf("%s", phonebook[numContacts].name);
                printf("Phone number: ");
                scanf("%s", phonebook[numContacts].phone);
                printf("Contact added successfully!\n");
                numContacts++;
                break;

            case 2:
                printf("Search: ");
                scanf("%s", search);
                found = 0;
                for (i = 0; i < numContacts; i++) {
                    if (strcmp(phonebook[i].name, search) == 0) {
                        printf("Name: %s\nPhone: %s\n", phonebook[i].name, phonebook[i].phone);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (atoi(input) != 3);

    return 0;
}