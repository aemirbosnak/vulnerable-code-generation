//FormAI DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20

// Struct to store user information
typedef struct User {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Function to encrypt the password using caesar cipher
void encrypt_password(char *password, int shift) {
    int i = 0;
    while (password[i] != '\0') {
        if (password[i] >= 'a' && password[i] <= 'z') {
            password[i] = 'a' + (password[i] - 'a' + shift) % 26;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] = 'A' + (password[i] - 'A' + shift) % 26;
        }
        i++;
    }
}

// Function to decrypt the password using caesar cipher
void decrypt_password(char *password, int shift) {
    encrypt_password(password, 26 - shift);
}

// Function to save user information to file
void save_user(User *user) {
    FILE *fp;

    fp = fopen("passwords.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Encrypt the password before saving to file
    encrypt_password(user->password, 3);

    fwrite(user, sizeof(User), 1, fp);

    fclose(fp);
}

// Function to check if username and password match
int check_user(User *user, char *username, char *password) {
    // Decrypt the password before comparing
    decrypt_password(user->password, 3);

    if (strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0) {
        return 1;
    }

    return 0;
}

int main() {
    int choice;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    User user;
    FILE *fp;

    printf("Welcome to the Password Management System!\n");

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Create new account\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a username (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", username);

                printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", password);

                strncpy(user.username, username, MAX_PASSWORD_LENGTH);
                strncpy(user.password, password, MAX_PASSWORD_LENGTH);

                save_user(&user);

                printf("\nAccount created successfully.\n");
                break;
            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                // Open file to read user information
                fp = fopen("passwords.txt", "r");

                if (fp == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                int found = 0;
                while (fread(&user, sizeof(User), 1, fp)) {
                    if (check_user(&user, username, password)) {
                        found = 1;
                        break;
                    }
                }

                fclose(fp);

                if (found) {
                    printf("\nLogin successful!\n");
                } else {
                    printf("\nInvalid username or password.\n");
                }
                break;
            case 3:
                printf("\nExiting program...");
                exit(0);
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    }

    return 0;
}