//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 50
#define MAX_NUM_USERS 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

void generatePassword(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-=+;:,.<>?/\\";
    int charsetLength = strlen(charset);
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }
    password[length] = '\0';
}

int main() {
    User users[MAX_NUM_USERS];
    int numUsers = 0;

    while (1) {
        printf("Enter username: ");
        scanf("%s", users[numUsers].username);

        if (numUsers == MAX_NUM_USERS) {
            printf("Maximum number of users reached.\n");
            break;
        }

        printf("Enter password length (between 1 and 50): ");
        int length;
        scanf("%d", &length);
        if (length < 1 || length > MAX_PASSWORD_LENGTH) {
            printf("Invalid password length.\n");
            continue;
        }

        generatePassword(users[numUsers].password, length);

        numUsers++;
    }

    printf("\nUser list:\n");
    for (int i = 0; i < numUsers; i++) {
        printf("%s: %s\n", users[i].username, users[i].password);
    }

    return 0;
}