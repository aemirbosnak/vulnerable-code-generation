//Falcon-180B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

int searchPassword(char *username, char *password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0 && strcmp(passwords[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void listPasswords() {
    int i;
    printf("Username\tPassword\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    do {
        printf("Enter a username (max 50 characters): ");
        scanf("%s", username);
        printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
        scanf("%s", password);

        addPassword(username, password);

        printf("1. Add another password\n2. List all passwords\n3. Exit\n");
        scanf("%d", &choice);
    } while (choice!= 3);

    return 0;
}