//Code Llama-13B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Password {
    char *username;
    char *password;
};

void addPassword(struct Password *passwords, char *username, char *password) {
    for (int i = 0; i < 10; i++) {
        if (passwords[i].username == NULL) {
            passwords[i].username = username;
            passwords[i].password = password;
            break;
        }
    }
}

void printPasswords(struct Password *passwords) {
    for (int i = 0; i < 10; i++) {
        if (passwords[i].username != NULL) {
            printf("%s %s\n", passwords[i].username, passwords[i].password);
        }
    }
}

void updatePassword(struct Password *passwords, char *username, char *newPassword) {
    for (int i = 0; i < 10; i++) {
        if (passwords[i].username == username) {
            passwords[i].password = newPassword;
            break;
        }
    }
}

void deletePassword(struct Password *passwords, char *username) {
    for (int i = 0; i < 10; i++) {
        if (passwords[i].username == username) {
            passwords[i].username = NULL;
            passwords[i].password = NULL;
            break;
        }
    }
}

int main() {
    struct Password passwords[10];
    char username[20], password[20], newPassword[20];

    for (int i = 0; i < 10; i++) {
        passwords[i].username = NULL;
        passwords[i].password = NULL;
    }

    printf("Enter a username: ");
    scanf("%s", username);
    printf("Enter a password: ");
    scanf("%s", password);

    addPassword(passwords, username, password);
    printPasswords(passwords);

    printf("Enter a new password: ");
    scanf("%s", newPassword);

    updatePassword(passwords, username, newPassword);
    printPasswords(passwords);

    printf("Enter a username to delete: ");
    scanf("%s", username);
    deletePassword(passwords, username);
    printPasswords(passwords);

    return 0;
}