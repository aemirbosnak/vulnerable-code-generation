//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char password[MAX_PASSWORD_LENGTH]) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i, j;

    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
}

void add_password() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    generate_password(password);

    printf("Password generated: %s\n", password);

    strcpy(passwords[num_passwords].username, username);
    strcpy(passwords[num_passwords].password, password);

    num_passwords++;
}

void print_passwords() {
    int i;

    printf("Username\tPassword\n");

    for (i = 0; i < num_passwords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    printf("Welcome to Password Manager!\n");

    while (1) {
        printf("\n");
        printf("1. Add password\n");
        printf("2. Print passwords\n");
        printf("3. Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_password();
            break;
        case 2:
            print_passwords();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}