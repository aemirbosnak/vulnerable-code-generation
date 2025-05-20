//Falcon-180B DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

int main() {
    int numPasswords = 0;
    char choice;
    Password passwords[MAX_PASSWORDS];

    do {
        printf("Welcome to the Password Manager\n");
        printf("A - Add a password\n");
        printf("D - Delete a password\n");
        printf("S - Search for a password\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case 'A':
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the password to add: ");
                    scanf("%s", passwords[numPasswords].password);
                    passwords[numPasswords].length = strlen(passwords[numPasswords].password);
                    numPasswords++;
                }
                break;
            case 'D':
                if(numPasswords == 0) {
                    printf("No passwords to delete.\n");
                } else {
                    printf("Enter the password to delete: ");
                    char passwordToDelete[MAX_PASSWORD_LENGTH];
                    scanf("%s", passwordToDelete);
                    int i;
                    for(i = 0; i < numPasswords; i++) {
                        if(strcmp(passwords[i].password, passwordToDelete) == 0) {
                            memset(passwords[i].password, 0, MAX_PASSWORD_LENGTH);
                            numPasswords--;
                            printf("Password deleted.\n");
                            break;
                        }
                    }
                    if(i == numPasswords) {
                        printf("Password not found.\n");
                    }
                }
                break;
            case 'S':
                if(numPasswords == 0) {
                    printf("No passwords to search.\n");
                } else {
                    printf("Enter the password to search for: ");
                    char passwordToSearch[MAX_PASSWORD_LENGTH];
                    scanf("%s", passwordToSearch);
                    int i;
                    for(i = 0; i < numPasswords; i++) {
                        if(strcmp(passwords[i].password, passwordToSearch) == 0) {
                            printf("Password found.\n");
                            break;
                        }
                    }
                    if(i == numPasswords) {
                        printf("Password not found.\n");
                    }
                }
                break;
            case 'Q':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 'Q');

    return 0;
}