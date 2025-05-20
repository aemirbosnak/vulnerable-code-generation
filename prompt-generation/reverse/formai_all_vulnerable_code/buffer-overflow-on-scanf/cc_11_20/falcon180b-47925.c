//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100
#define MAX_USERNAME_LEN 100

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char choice;

    do {
        printf("Password Management System\n");
        printf("-------------------------\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View passwords\n");
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
                    printf("No passwords found.\n");
                } else {
                    printf("Enter username of password to remove: ");
                    scanf("%s", passwords[0].username);
                    for(int i = 0; i < numPasswords; i++) {
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
                    printf("No passwords found.\n");
                } else {
                    printf("Passwords:\n");
                    for(int i = 0; i < numPasswords; i++) {
                        if(strcmp(passwords[i].username, "")!= 0) {
                            printf("%s - %s\n", passwords[i].username, passwords[i].password);
                        }
                    }
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '4');

    return 0;
}