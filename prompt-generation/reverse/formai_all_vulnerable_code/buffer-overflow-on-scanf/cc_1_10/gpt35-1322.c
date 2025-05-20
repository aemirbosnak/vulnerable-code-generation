//FormAI DATASET v1.0 Category: Password management ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PASSWORD_LENGTH 15
#define ENCRYPT_VALUE 15

// Function to encrypt password
void encrypt(char *password) {
    for(int i=0; i<strlen(password); i++) {
        password[i] += ENCRYPT_VALUE;
    }
}

// Function to decrypt password
void decrypt(char *password) {
    for(int i=0; i<strlen(password); i++) {
        password[i] -= ENCRYPT_VALUE;
    }
}

// Function to check if password is valid
int isValid(char *password) {
    int length = strlen(password);
    if(length != PASSWORD_LENGTH) {
        return 0;
    }
    for(int i=0; i<length; i++) {
        if(!isalnum(password[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {

    printf("==== PASSWORD MANAGER ====\n");

    // Array to store passwords
    char passwords[10][PASSWORD_LENGTH];
    int numPasswords = 0;

    // Menu options
    int choice;
    do {
        printf("1. Add Password\n2. View Passwords\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                // Get new password from user
                char password[PASSWORD_LENGTH];
                printf("Enter password (15 alphanumeric characters only): ");
                scanf("%s", password);
                if(!isValid(password)) {
                    printf("Invalid password.\n");
                    break;
                }
                // Encrypt password and add to array
                encrypt(password);
                strcpy(passwords[numPasswords], password);
                numPasswords++;
                printf("Password added.\n");
                break;
            }
            case 2: {
                // View all passwords
                if(numPasswords == 0) {
                    printf("No passwords stored.\n");
                    break;
                }
                printf("==== PASSWORDS ====\n");
                for(int i=0; i<numPasswords; i++) {
                    char password[PASSWORD_LENGTH];
                    strcpy(password, passwords[i]);
                    decrypt(password);
                    printf("%d. %s\n", i+1, password);
                }
                break;
            }
            case 3: {
                // Exit
                printf("Goodbye.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(1);

    return 0;
}