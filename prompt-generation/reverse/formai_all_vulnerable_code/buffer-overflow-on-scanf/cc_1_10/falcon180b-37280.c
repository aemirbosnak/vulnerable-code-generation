//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    do {
        system("clear");
        printf("Password Manager\n");
        printf("================\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("\n");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                }
                else {
                    printf("Enter username: ");
                    scanf(" %[^\n]", passwords[numPasswords].username);
                    printf("Enter password: ");
                    scanf(" %[^\n]", passwords[numPasswords].password);
                    numPasswords++;
                    printf("\nPassword added successfully.\n");
                }
                break;

            case '2':
                if(numPasswords == 0) {
                    printf("No passwords added yet.\n");
                }
                else {
                    printf("Passwords:\n");
                    for(int i=0; i<numPasswords; i++) {
                        printf("%s: %s\n", passwords[i].username, passwords[i].password);
                    }
                }
                break;

            case '3':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice!= '3');

    return 0;
}