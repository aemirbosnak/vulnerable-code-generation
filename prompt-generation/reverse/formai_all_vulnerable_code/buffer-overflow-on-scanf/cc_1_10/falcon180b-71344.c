//Falcon-180B DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    int length = strlen(password);
    if (length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;
    numPasswords++;
}

int main() {
    char input[100];

    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Add Password\n2. View Passwords\n3. Exit\n");
        scanf("%s", input);

        switch (input[0]) {
        case '1':
            printf("Enter password: ");
            scanf("%s", input);
            addPassword(input);
            break;
        case '2':
            printf("\nPasswords:\n");
            for (int i = 0; i < numPasswords; i++) {
                printf("%s (%d characters)\n", passwords[i].password, passwords[i].length);
            }
            break;
        case '3':
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}