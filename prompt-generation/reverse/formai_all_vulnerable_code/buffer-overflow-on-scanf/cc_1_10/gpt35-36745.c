//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

struct Password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    int passwordCount = 0; // keep track of the number of passwords added
    struct Password passwords[MAX_PASSWORDS];

    while (1) {
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (passwordCount < MAX_PASSWORDS) {
                    struct Password password;

                    printf("Enter website: ");
                    scanf("%s", password.website);

                    printf("Enter username: ");
                    scanf("%s", password.username);

                    printf("Enter password: ");
                    scanf("%s", password.password);

                    passwords[passwordCount++] = password; // add password to the list
                } else {
                    printf("Maximum passwords limit reached!\n");
                }
                break;
            }

            case 2: {
                if (passwordCount > 0) {
                    printf("Website\t\tUsername\t\tPassword\n");

                    for (int i = 0; i < passwordCount; i++) {
                        printf("%s\t\t%s\t\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                    }
                } else {
                    printf("No passwords added yet!\n");
                }
                break;
            }

            case 3: {
                printf("Thank you for using Password Manager!\n");
                exit(0);
            }

            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    }

    return 0;
}