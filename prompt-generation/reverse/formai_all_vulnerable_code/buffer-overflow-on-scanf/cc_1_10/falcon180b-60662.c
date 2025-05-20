//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct password {
    char service[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct password passwords[MAX_PASSWORDS];

    char choice;
    do {
        printf("\nPassword Manager\n");
        printf("1. Add a new password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1': {
                if(numPasswords >= MAX_PASSWORDS) {
                    printf("Error: Maximum number of passwords reached.\n");
                } else {
                    printf("Enter the service name: ");
                    scanf("%s", passwords[numPasswords].service);
                    printf("Enter the username: ");
                    scanf("%s", passwords[numPasswords].username);
                    printf("Enter the password: ");
                    scanf("%s", passwords[numPasswords].password);
                    numPasswords++;
                    printf("Password added successfully.\n");
                }
                break;
            }
            case '2': {
                if(numPasswords == 0) {
                    printf("No passwords added yet.\n");
                } else {
                    printf("\nPasswords:\n");
                    for(int i=0; i<numPasswords; i++) {
                        printf("%s\t%s\t%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                    }
                }
                break;
            }
            case '3': {
                printf("Exiting...\n");
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    } while(choice!= '3');

    return 0;
}