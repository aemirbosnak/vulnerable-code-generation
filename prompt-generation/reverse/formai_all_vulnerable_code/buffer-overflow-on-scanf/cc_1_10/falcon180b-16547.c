//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    char choice;
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];
    
    do {
        printf("\nWelcome to the Password Manager!\n");
        printf("Please choose an option:\n");
        printf("1. Add a password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the username:\n");
                    scanf("%s", passwords[numPasswords].username);
                    printf("Enter the password:\n");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                    printf("Password added successfully!\n");
                }
                break;
            case '2':
                printf("Enter the username to view the password:\n");
                scanf("%s", passwords[numPasswords-1].username);
                printf("Password: %s\n", passwords[numPasswords-1].password);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '3');
    
    return 0;
}