//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASS_LENGTH 30
#define MAX_USER_LENGTH 30
#define PASSWORDS_FILE "passwords.dat"

struct Password {
    char username[MAX_USER_LENGTH];
    char password[MAX_PASS_LENGTH];
};

void add_password() {
    struct Password password;
    FILE* passwords_file = fopen(PASSWORDS_FILE, "ab");

    printf("Enter username: ");
    scanf("%s", &password.username);

    printf("Enter password: ");
    scanf("%s", &password.password);

    fwrite(&password, sizeof(struct Password), 1, passwords_file);

    fclose(passwords_file);
}

void list_passwords() {
    FILE* passwords_file = fopen(PASSWORDS_FILE, "rb");
    struct Password password;

    printf("Username\t\t Password\n");

    while (fread(&password, sizeof(struct Password), 1, passwords_file) == 1) {
        printf("%s\t\t %s\n", password.username, password.password);
    }

    fclose(passwords_file);
}

void search_password() {
    FILE* passwords_file = fopen(PASSWORDS_FILE, "rb");
    struct Password password;
    char search_username[MAX_USER_LENGTH];

    printf("Enter username to search: ");
    scanf("%s", &search_username);

    while (fread(&password, sizeof(struct Password), 1, passwords_file) == 1) {
        if (strcmp(search_username, password.username) == 0) {
            printf("Password for username %s is %s\n", password.username, password.password);
            return;
        }
    }

    printf("Password not found for username %s\n", search_username);

    fclose(passwords_file);
}

int main() {
    while (1) {
        int option;

        printf("\nPassword Management System - Menu Options:\n");
        printf("1. Add Password\n");
        printf("2. List Passwords\n");
        printf("3. Search for Password\n");
        printf("4. Exit\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: add_password(); break;
            case 2: list_passwords(); break;
            case 3: search_password(); break;
            case 4: exit(0); break;
            default: printf("Invalid option\n"); break;
        }
    }

    return 0;
}