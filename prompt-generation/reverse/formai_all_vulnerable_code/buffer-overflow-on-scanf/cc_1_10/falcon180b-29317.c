//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int used;
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    int choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the Peaceful Password Manager!\n\n");
    printf("Please choose an option:\n");
    printf("1. Create a new password\n");
    printf("2. View saved passwords\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    while (choice!= 3) {
        switch (choice) {
            case 1:
                printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH - 1);
                scanf("%s", username);
                printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", password);

                for (int i = 0; i < num_passwords; i++) {
                    if (strcmp(passwords[i].username, username) == 0) {
                        printf("Username already in use.\n");
                        break;
                    }
                }

                if (num_passwords >= MAX_PASSWORDS) {
                    printf("Maximum number of passwords reached.\n");
                } else {
                    strcpy(passwords[num_passwords].username, username);
                    strcpy(passwords[num_passwords].password, password);
                    passwords[num_passwords].used = 0;
                    num_passwords++;
                    printf("Password saved successfully.\n");
                }
                break;

            case 2:
                printf("\nSaved Passwords:\n");
                for (int i = 0; i < num_passwords; i++) {
                    printf("%s - %s\n", passwords[i].username, passwords[i].password);
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Create a new password\n");
        printf("2. View saved passwords\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
    }

    return 0;
}