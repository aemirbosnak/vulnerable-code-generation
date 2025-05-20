//Falcon-180B DATASET v1.0 Category: Password management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    while (1) {
        printf("\nPassword Management System\n");
        printf("---------------------------------\n");
        printf("1. Add a new password\n");
        printf("2. Delete a password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numPasswords == MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the website name: ");
                    scanf("%s", passwords[numPasswords].website);

                    printf("Enter the username: ");
                    scanf("%s", passwords[numPasswords].username);

                    printf("Enter the password: ");
                    scanf("%s", passwords[numPasswords].password);

                    numPasswords++;
                }
                break;

            case 2:
                printf("Enter the website name to delete the password: ");
                scanf("%s", passwords[numPasswords - 1].website);

                for (int i = 0; i < numPasswords; i++) {
                    if (strcmp(passwords[i].website, passwords[numPasswords - 1].website) == 0) {
                        numPasswords--;
                    }
                }

                printf("Password deleted.\n");
                break;

            case 3:
                printf("Website\tUsername\tPassword\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%s\t%s\t%s\n", passwords[i].website, passwords[i].username, passwords[i].password);
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}