//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

int main() {
    char choice;
    int i;

    while(1) {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. Delete Password\n");
        printf("3. View Passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter username: ");
                    scanf("%s", passwords[numPasswords].username);
                    printf("Enter password: ");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                }
                break;
            case '2':
                if(numPasswords == 0) {
                    printf("No passwords to delete.\n");
                } else {
                    printf("Enter password to delete: ");
                    scanf("%s", passwords[0].username);
                    for(i=0; i<numPasswords; i++) {
                        if(strcmp(passwords[i].username, passwords[0].username) == 0) {
                            strcpy(passwords[i].username, "");
                            strcpy(passwords[i].password, "");
                            numPasswords--;
                            break;
                        }
                    }
                }
                break;
            case '3':
                if(numPasswords == 0) {
                    printf("No passwords to view.\n");
                } else {
                    printf("\nUsername\tPassword\n");
                    for(i=0; i<numPasswords; i++) {
                        if(strlen(passwords[i].username) > 0 && strlen(passwords[i].password) > 0) {
                            printf("%s\t%s\n", passwords[i].username, passwords[i].password);
                        }
                    }
                }
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}