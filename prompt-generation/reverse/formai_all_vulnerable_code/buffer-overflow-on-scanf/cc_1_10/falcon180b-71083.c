//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 50

typedef struct {
    char name[50];
    char password[PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;

    while (1) {
        printf("\nPassword Management System\n");
        printf("1. Add Password\n");
        printf("2. Edit Password\n");
        printf("3. Delete Password\n");
        printf("4. View Passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter name for password: ");
                    scanf("%s", passwords[numPasswords].name);
                    printf("Enter password: ");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                }
                break;
            case '2':
                printf("Enter name of password to edit: ");
                scanf("%s", passwords[numPasswords - 1].name);
                printf("Enter new password: ");
                scanf("%s", passwords[numPasswords - 1].password);
                break;
            case '3':
                printf("Enter name of password to delete: ");
                scanf("%s", passwords[numPasswords - 1].name);
                numPasswords--;
                break;
            case '4':
                printf("Name\tPassword\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("%s\t%s\n", passwords[i].name, passwords[i].password);
                }
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}