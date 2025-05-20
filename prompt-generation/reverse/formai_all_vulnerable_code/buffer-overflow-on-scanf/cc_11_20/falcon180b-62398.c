//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int num_passwords = 0;
    Password passwords[MAX_PASSWORDS];

    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new password\n");
        printf("2. View all passwords\n");
        printf("3. Search for a password\n");
        printf("4. Exit\n");

        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the name of the password: ");
                    scanf("%s", passwords[num_passwords].name);

                    printf("Enter the password: ");
                    scanf("%s", passwords[num_passwords].password);

                    num_passwords++;
                }
                break;

            case '2':
                printf("\nPassword List:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s - %s\n", passwords[i].name, passwords[i].password);
                }
                break;

            case '3':
                printf("\nEnter the name of the password to search: ");
                scanf("%s", passwords[num_passwords].name);

                int found = 0;
                for (int i = 0; i < num_passwords; i++) {
                    if (strcmp(passwords[i].name, passwords[num_passwords].name) == 0) {
                        printf("\nPassword found:\n");
                        printf("%s - %s\n", passwords[i].name, passwords[i].password);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("\nPassword not found.\n");
                }
                break;

            case '4':
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}