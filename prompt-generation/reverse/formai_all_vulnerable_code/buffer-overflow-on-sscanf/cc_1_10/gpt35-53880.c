//FormAI DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_FILE "passwords.txt"
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void exit_failure(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void encrypt(char *password) {
    int n = strlen(password);
    for (int i = 0; i < n; i++) {
        password[i] = password[i] + ((i % 2 == 0) ? -1 : 1);
    }
}

void decrypt(char *password) {
    int n = strlen(password);
    for (int i = 0; i < n; i++) {
        password[i] = password[i] + ((i % 2 == 0) ? 1 : -1);
    }
}

void write_password(struct Password password) {
    FILE *fp = fopen(PASSWORD_FILE, "a");
    if (fp == NULL) {
        exit_failure("Unable to create file for passwords");
    }

    encrypt(password.password);
    fprintf(fp, "%s %s\n", password.username, password.password);

    fclose(fp);
}

void read_passwords() {
    FILE *fp = fopen(PASSWORD_FILE, "r");
    if (fp == NULL) {
        exit_failure("Unable to open file for passwords");
    }

    char line[MAX_PASSWORD_LENGTH * 2];
    while (fgets(line, sizeof(line), fp)) {
        char username[MAX_PASSWORD_LENGTH];
        char password[MAX_PASSWORD_LENGTH];
        sscanf(line, "%s %s", username, password);

        decrypt(password);
        printf("%s's password is %s\n", username, password);
    }

    fclose(fp);
}

int main() {
    char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the password manager! Please enter a username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    encrypt(password);
    struct Password new_password = { .username = username, .password = password };
    write_password(new_password);

    printf("New password saved!\n\n");

    printf("All saved passwords:\n");
    read_passwords();

    return EXIT_SUCCESS;
}