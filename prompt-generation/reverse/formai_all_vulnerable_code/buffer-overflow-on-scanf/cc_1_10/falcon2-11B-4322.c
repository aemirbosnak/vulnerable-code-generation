//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    char email[100];
};

int main() {
    struct User users[10];
    int numUsers = 0;

    printf("Mailing list manager\n");
    printf("-------------------\n");

    while (1) {
        printf("\n1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Send email to all users\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter user name: ");
                scanf("%s", users[numUsers].name);
                printf("Enter user email: ");
                scanf("%s", users[numUsers].email);
                numUsers++;
                break;
            case 2:
                printf("\nEnter user name: ");
                scanf("%s", users[numUsers].name);
                numUsers--;
                break;
            case 3:
                printf("\nSending email to all users...\n");
                for (int i = 0; i < numUsers; i++) {
                    printf("To: %s\n", users[i].name);
                    printf("From: %s\n", "Mailing List Manager");
                    printf("Subject: Mailing list update\n");
                    printf("Message: %s is now part of the mailing list.\n", users[i].name);
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}