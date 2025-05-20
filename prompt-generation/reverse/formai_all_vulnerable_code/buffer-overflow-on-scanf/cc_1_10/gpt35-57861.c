//FormAI DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 50  //maximum password length

typedef struct {
    char website[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwordList[10];   //create password list, with capacity for 10 passwords
    int menuChoice;
    do {
        printf("=== Password Manager ===\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1: //add password
                if (numPasswords == 10) {
                    printf("Password manager is full!\n");
                    break;
                }
                Password newPassword;
                printf("Website: ");
                scanf("%s", newPassword.website);
                printf("Username: ");
                scanf("%s", newPassword.username);
                printf("Password: ");
                scanf("%s", newPassword.password);
                passwordList[numPasswords] = newPassword;   //add new password to list
                numPasswords++;
                break;
            case 2: //view passwords
                if (numPasswords == 0) {
                    printf("No passwords stored yet.\n");
                    break;
                }
                printf("=== Passwords ===\n");
                for (int i = 0; i < numPasswords; i++) {
                    printf("Website: %s\n", passwordList[i].website);
                    printf("Username: %s\n", passwordList[i].username);
                    printf("Password: %s\n", passwordList[i].password);
                }
                break;
            case 3: //exit
                printf("Exiting...\n");
                break;
            default: //invalid option
                printf("Invalid Choice. Try Again.\n");
                break;
        }
    } while (menuChoice != 3);

    return 0;
}