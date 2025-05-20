//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    strncpy(passwords[numPasswords].username, username, MAX_USERNAME_LENGTH);
    strncpy(passwords[numPasswords].password, password, MAX_PASSWORD_LENGTH);
    numPasswords++;
}

int findPassword(char* username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

char* getPassword(char* username) {
    int index = findPassword(username);
    if (index == -1) {
        return NULL;
    } else {
        return passwords[index].password;
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Retrieve password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(username, password);
                printf("Password added successfully.\n");
                break;
            case 2:
                printf("Enter username: ");
                scanf("%s", username);
                char* passwordFound = getPassword(username);
                if (passwordFound!= NULL) {
                    printf("Password for %s: %s\n", username, passwordFound);
                } else {
                    printf("Password not found.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}