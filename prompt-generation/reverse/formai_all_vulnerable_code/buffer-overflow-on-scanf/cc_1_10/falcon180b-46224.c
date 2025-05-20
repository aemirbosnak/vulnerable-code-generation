//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct contact {
    char name[50];
    char phone[15];
};

int main() {
    int choice, i;
    char search[50];
    struct contact phonebook[100];
    int count = 0;

    printf("Welcome to the Phone Book!\n");
    printf("-------------------------\n");

    for (i = 0; i < 100; i++) {
        printf("Enter contact %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", phonebook[i].name);
        printf("Phone number: ");
        scanf("%s", phonebook[i].phone);
    }

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count == 100) {
                printf("Phone book is full!\n");
            } else {
                printf("Enter contact information:\n");
                printf("Name: ");
                scanf("%s", phonebook[count].name);
                printf("Phone number: ");
                scanf("%s", phonebook[count].phone);
                count++;
            }
            break;

        case 2:
            printf("Enter name to search: ");
            scanf("%s", search);

            for (i = 0; i < count; i++) {
                if (strcmp(phonebook[i].name, search) == 0) {
                    printf("Name: %s\n", phonebook[i].name);
                    printf("Phone number: %s\n", phonebook[i].phone);
                }
            }

            if (i == count) {
                printf("Contact not found!\n");
            }
            break;

        case 3:
            printf("Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}