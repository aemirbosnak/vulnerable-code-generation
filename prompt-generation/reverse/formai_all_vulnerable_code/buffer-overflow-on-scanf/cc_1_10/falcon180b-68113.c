//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 50

struct {
    char username[50];
    char password[50];
} passwords[MAX_PASSWORDS];

int num_passwords = 0;

void add_password(char* username, char* password) {
    if (num_passwords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords!\n");
        return;
    }

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void print_passwords() {
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

void main() {
    printf("Welcome to the Happy Password Manager!\n");

    char choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("A - Add password\n");
        printf("P - Print passwords\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                printf("Enter username: ");
                char username[50];
                scanf("%s", username);

                printf("Enter password: ");
                char password[50];
                scanf("%s", password);

                add_password(username, password);
                break;

            case 'P':
                print_passwords();
                break;

            case 'Q':
                printf("Goodbye!\n");
                return;

            default:
                printf("Invalid choice.\n");
        }
    }
}