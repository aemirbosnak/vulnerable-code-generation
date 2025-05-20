//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    char choice;
    do {
        printf("\n");
        printf("1. Add a new password\n");
        printf("2. Modify an existing password\n");
        printf("3. View all passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            if (numPasswords >= MAX_PASSWORDS) {
                printf("Maximum number of passwords reached.\n");
            } else {
                printf("Enter the name of the password: ");
                scanf("%s", passwords[numPasswords].name);
                printf("Enter the password: ");
                scanf("%s", passwords[numPasswords].password);
                numPasswords++;
            }
            break;

        case '2':
            printf("Enter the name of the password to modify: ");
            scanf("%s", passwords[numPasswords - 1].name);
            printf("Enter the new password: ");
            scanf("%s", passwords[numPasswords - 1].password);
            break;

        case '3':
            printf("\nName\tPassword\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%s\t%s\n", passwords[i].name, passwords[i].password);
            }
            break;

        case '4':
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}