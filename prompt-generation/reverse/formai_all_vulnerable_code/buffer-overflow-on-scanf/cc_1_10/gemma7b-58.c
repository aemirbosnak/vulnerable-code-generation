//Gemma-7B DATASET v1.0 Category: Password management ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

char passwords[MAX_PASSWORDS][256];

void add_password() {
    int i = 0;
    for (; passwords[i][0] != '\0'; i++) {}
    strcpy(passwords[i], "");
    printf("Enter a password: ");
    fgets(passwords[i], 256, stdin);
    passwords[i][strlen(passwords[i]) - 1] = '\0';
}

void list_passwords() {
    int i = 0;
    for (; passwords[i][0] != '\0'; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }
}

int main() {
    int choice;

    while (1) {
        system("clear");
        printf("Welcome to the Password Manager!\n");
        printf("1. Add a password\n");
        printf("2. List passwords\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                list_passwords();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}