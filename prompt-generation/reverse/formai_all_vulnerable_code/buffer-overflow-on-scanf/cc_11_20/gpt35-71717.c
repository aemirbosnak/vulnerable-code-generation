//FormAI DATASET v1.0 Category: Password management ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Password {
    char website[20];
    char username[20];
    char password[20];
};

int main() {
    int i, n, choice;
    struct Password passwords[10];

    printf("Welcome to your Password Manager!\n");
    printf("How many passwords would you like to store? (Maximum 10)\n");
    scanf("%d", &n);

    while (n > 10) {
        printf("Sorry, the maximum number of passwords you can store is 10. Please enter a valid number.\n");
        scanf("%d", &n);
    }

    printf("Great! Let's get started.\n");

    for (i = 0; i < n; i++) {
        printf("\nEnter the website: ");
        scanf("%s", passwords[i].website);

        printf("Enter the username: ");
        scanf("%s", passwords[i].username);

        printf("Enter the password: ");
        scanf("%s", passwords[i].password);

        printf("Account created successfully!\n");
    }

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. View password\n");
        printf("2. Edit password\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter website: ");
                char website[20];
                scanf("%s", website);

                for (i = 0; i < n; i++) {
                    if (strcmp(passwords[i].website, website) == 0) {
                        printf("\nWebsite: %s\n", passwords[i].website);
                        printf("Username: %s\n", passwords[i].username);
                        printf("Password: %s\n", passwords[i].password);
                        break;
                    }
                }

                if (i == n) {
                    printf("\n%s not found. Please try again.\n", website);
                }
                break;

            case 2:
                printf("\nEnter website: ");
                char webs[20];
                scanf("%s", webs);

                for (i = 0; i < n; i++) {
                    if (strcmp(passwords[i].website, webs) == 0) {
                        printf("\n%s\n", passwords[i].website);
                        printf("Enter new username: ");
                        scanf("%s", passwords[i].username);

                        printf("Enter new password: ");
                        scanf("%s", passwords[i].password);

                        printf("\n%s updated successfully!\n", passwords[i].website);
                        break;
                    }
                }

                if (i == n) {
                    printf("\n%s not found. Please try again.\n", webs);
                }
                break;

            case 3:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}