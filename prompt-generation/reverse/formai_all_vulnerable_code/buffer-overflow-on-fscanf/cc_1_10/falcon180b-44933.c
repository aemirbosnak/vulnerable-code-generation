//Falcon-180B DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

void generatePassword(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i = 0;
    while (i < strlen(charset)) {
        password->password[i] = charset[rand() % strlen(charset)];
        i++;
    }
    password->password[i] = '\0';
}

int main() {
    FILE *passwordsFile;
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    passwordsFile = fopen("passwords.txt", "r");
    if (passwordsFile == NULL) {
        printf("Error: passwords.txt not found.\n");
        return 1;
    }

    while (fscanf(passwordsFile, "%s %s", passwords[numPasswords].username, passwords[numPasswords].password)!= EOF) {
        numPasswords++;
        if (numPasswords == MAX_PASSWORDS) {
            printf("Error: Maximum number of passwords reached.\n");
            fclose(passwordsFile);
            return 1;
        }
    }

    fclose(passwordsFile);

    int choice;
    do {
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Generate password\n");
        printf("4. Save passwords to file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the username: ");
                scanf("%s", passwords[numPasswords].username);
                generatePassword(&passwords[numPasswords]);
                numPasswords++;
                if (numPasswords == MAX_PASSWORDS) {
                    printf("Error: Maximum number of passwords reached.\n");
                }
                break;

            case 2:
                printf("Enter the username of the password you want to remove: ");
                scanf("%s", passwords[numPasswords].username);
                for (int i = 0; i < numPasswords - 1; i++) {
                    if (strcmp(passwords[i].username, passwords[numPasswords].username) == 0) {
                        memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (numPasswords - i - 1));
                        numPasswords--;
                        break;
                    }
                }
                break;

            case 3:
                printf("Enter the username: ");
                scanf("%s", passwords[numPasswords].username);
                generatePassword(&passwords[numPasswords]);
                numPasswords++;
                if (numPasswords == MAX_PASSWORDS) {
                    printf("Error: Maximum number of passwords reached.\n");
                }
                break;

            case 4:
                passwordsFile = fopen("passwords.txt", "w");
                if (passwordsFile == NULL) {
                    printf("Error: Unable to open passwords.txt for writing.\n");
                    return 1;
                }
                for (int i = 0; i < numPasswords; i++) {
                    fprintf(passwordsFile, "%s %s\n", passwords[i].username, passwords[i].password);
                }
                fclose(passwordsFile);
                printf("Passwords saved to file.\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}