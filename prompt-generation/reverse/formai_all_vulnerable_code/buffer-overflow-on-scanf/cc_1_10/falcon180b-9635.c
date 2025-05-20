//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 128

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Sorry, maximum number of passwords reached.\n");
        return;
    }
    numPasswords++;
    passwords[numPasswords - 1].username = strdup(username);
    passwords[numPasswords - 1].password = strdup(password);
}

int findPasswordIndex(char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

char *getPassword(char *username) {
    int index = findPasswordIndex(username);
    if (index == -1) {
        printf("Password not found.\n");
        return NULL;
    }
    return passwords[index].password;
}

char *generatePassword(int length) {
    char *password = calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }
    return password;
}

int main() {
    srand(time(NULL));
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        addPassword(username, "");
    }

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);
        int index = findPasswordIndex(username);
        if (index == -1) {
            printf("Password not found.\n");
        } else {
            printf("Enter new password length (minimum 8): ");
            scanf("%d", &length);
            if (length < 8) {
                printf("Password length must be at least 8.\n");
            } else {
                char *newPassword = generatePassword(length);
                strcpy(passwords[index].password, newPassword);
                free(newPassword);
                printf("Password updated.\n");
            }
        }
    }

    return 0;
}