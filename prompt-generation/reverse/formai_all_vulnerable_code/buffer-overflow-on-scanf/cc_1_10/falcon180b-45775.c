//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numPasswords == MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter name of website or service: ");
                scanf("%s", passwords[numPasswords].name);

                printf("Enter password: ");
                scanf("%s", passwords[numPasswords].password);

                numPasswords++;
            }
            break;

        case 2:
            printf("Enter name of website or service to remove: ");
            scanf("%s", passwords[numPasswords - 1].name);

            for (int i = 0; i < numPasswords - 1; i++) {
                strcpy(passwords[i].name, passwords[i + 1].name);
                strcpy(passwords[i].password, passwords[i + 1].password);
            }

            numPasswords--;
            break;

        case 3:
            printf("Passwords:\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%s: %s\n", passwords[i].name, passwords[i].password);
            }
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}