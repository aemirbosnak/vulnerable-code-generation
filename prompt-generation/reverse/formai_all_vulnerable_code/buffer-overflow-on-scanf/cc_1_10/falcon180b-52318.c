//Falcon-180B DATASET v1.0 Category: Password management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define HASH_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
} Password;

void hashPassword(char* password, char* hash) {
    int i = 0;
    int j = 0;
    int k = 0;
    char hexChars[] = "0123456789ABCDEF";
    while (i < strlen(password)) {
        if (isalpha(password[i])) {
            hash[j++] = toupper(password[i]);
        } else if (isdigit(password[i])) {
            hash[j++] = password[i];
        }
        i++;
    }
    while (j < 16) {
        hash[j++] = hexChars[k++ % 16];
    }
    hash[j] = '\0';
}

void generateHash(char* password, char* hash) {
    hashPassword(password, hash);
}

int compareHashes(char* hash1, char* hash2) {
    int i = 0;
    while (i < strlen(hash1) && i < strlen(hash2)) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char hash[HASH_LENGTH];
    int choice = 0;

    system("clear");
    printf("Welcome to the Password Manager!\n\n");

    while (choice!= 4) {
        printf("1. Add a new password\n");
        printf("2. View/edit passwords\n");
        printf("3. Delete a password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a username: ");
                scanf("%s", username);
                printf("Enter a password: ");
                scanf("%s", password);
                generateHash(password, hash);
                strcpy(passwords[numPasswords].username, username);
                strcpy(passwords[numPasswords].password, password);
                strcpy(passwords[numPasswords].hash, hash);
                numPasswords++;
                printf("\nPassword added successfully!\n\n");
                break;

            case 2:
                if (numPasswords == 0) {
                    printf("No passwords found.\n\n");
                } else {
                    printf("Username\t\tPassword\n");
                    for (int i = 0; i < numPasswords; i++) {
                        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
                    }
                }
                break;

            case 3:
                if (numPasswords == 0) {
                    printf("No passwords found.\n\n");
                } else {
                    printf("Enter the username of the password you want to delete: ");
                    scanf("%s", username);
                    for (int i = 0; i < numPasswords; i++) {
                        if (strcmp(passwords[i].username, username) == 0) {
                            printf("Password deleted successfully!\n\n");
                            numPasswords--;
                            break;
                        }
                    }
                }
                break;

            case 4:
                printf("Thank you for using the Password Manager!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}