//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char number[20];
} contact;

int main() {
    contact phonebook[100];
    int num_contacts = 0;
    char name[20];
    char number[20];

    printf("Welcome to the Phone Book of Verona!\n");
    printf("------------------------------------\n");

    while (1) {
        printf("What wouldst thou like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Find a contact\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the contact:\n");
                scanf(" %s", name);
                printf("Enter the number of the contact:\n");
                scanf(" %s", number);

                strcpy(phonebook[num_contacts].name, name);
                strcpy(phonebook[num_contacts].number, number);
                num_contacts++;

                printf("Contact added!\n");
                break;
            case 2:
                printf("Enter the name of the contact you seek:\n");
                scanf(" %s", name);

                int found = 0;
                for (int i = 0; i < num_contacts; i++) {
                    if (strcmp(phonebook[i].name, name) == 0) {
                        printf("Name: %s\n", phonebook[i].name);
                        printf("Number: %s\n", phonebook[i].number);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Contact not found!\n");
                }
                break;
            case 3:
                printf("Farewell!\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}