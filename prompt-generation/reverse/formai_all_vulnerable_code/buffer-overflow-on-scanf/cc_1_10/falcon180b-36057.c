//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 80

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter the username: ");
        scanf("%s", passwords[numPasswords].username);

        printf("Enter the password: ");
        scanf("%s", passwords[numPasswords].password);

        numPasswords++;
    }

    while (1) {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("\nAdd password:\n");
                    printf("Enter the username: ");
                    scanf("%s", passwords[numPasswords].username);

                    printf("Enter the password: ");
                    scanf("%s", passwords[numPasswords].password);

                    numPasswords++;
                }
                break;

            case 2:
                printf("\nView passwords:\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}