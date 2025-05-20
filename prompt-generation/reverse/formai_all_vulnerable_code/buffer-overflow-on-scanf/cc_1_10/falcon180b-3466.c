//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50], password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

int findPassword(char *username) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    int choice, i;

    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Find password\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;

        case 2:
            printf("Enter username: ");
            scanf("%s", passwords[0].username);

            i = findPassword(passwords[0].username);

            if (i!= -1) {
                printf("Password: %s\n", passwords[i].password);
            } else {
                printf("Password not found.\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}