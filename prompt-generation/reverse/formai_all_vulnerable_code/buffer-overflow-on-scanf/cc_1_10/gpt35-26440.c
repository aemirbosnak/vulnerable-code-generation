//FormAI DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password struct that stores username and password
typedef struct {
    char username[50];
    char password[50];
    int hashcode; // Hashcode for password
} Password;

// Function to hash a password using a simple hash function
int hashPassword(char* password) {
    int hash = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        hash += password[i];
    }
    return hash;
}

// Function to add a new password to the password list
void addPassword(Password* passwords, int* numPasswords) {
    char username[50];
    char password[50];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    int hashcode = hashPassword(password);
    printf("Password added.\n");
    Password newPassword = {strcpy(newPassword.username, username),
                            strcpy(newPassword.password, password),
                            hashcode};
    passwords[*numPasswords] = newPassword;
    *numPasswords += 1;
}

// Function to check if a given password matches the hashcode of the stored password
int checkPassword(char* password, Password storedPassword) {
    int hashcode = hashPassword(password);
    if (hashcode == storedPassword.hashcode) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the index of a password in the password list
int getPasswordIndex(char* username, Password* passwords, int numPasswords) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a password from the password list
void deletePassword(Password* passwords, int* numPasswords) {
    char username[50];
    printf("Enter username to delete: ");
    scanf("%s", username);
    int passwordIndex = getPasswordIndex(username, passwords, *numPasswords);
    if (passwordIndex == -1) {
        printf("Password not found.\n");
    } else {
        for (int i = passwordIndex; i < *numPasswords - 1; i++) {
            passwords[i] = passwords[i+1];
        }
        *numPasswords -= 1;
        printf("Password deleted.\n");
    }
}

// Main function
int main() {
    Password passwords[100];
    int numPasswords = 0;
    while (1) {
        printf("\nEnter a command (add, check, delete, exit):\n");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            addPassword(passwords, &numPasswords);
        } else if (strcmp(command, "check") == 0) {
            char username[50];
            char password[50];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            int passwordIndex = getPasswordIndex(username, passwords, numPasswords);
            if (passwordIndex == -1) {
                printf("Password not found.\n");
            } else {
                if (checkPassword(password, passwords[passwordIndex])) {
                    printf("Password is correct.\n");
                } else {
                    printf("Incorrect password.\n");
                }
            }
        } else if (strcmp(command, "delete") == 0) {
            deletePassword(passwords, &numPasswords);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}