//Falcon-180B DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}:;\"'[]\\|/?<>,. ";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords;
    int i;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    password_t passwords[MAX_PASSWORDS];
    FILE *passwords_file;

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    printf("Enter your username: ");
    scanf("%s", username);

    for (i = 0; i < num_passwords; i++) {
        printf("Password %d for %s:\n", i + 1, username);
        generate_password(password, MAX_PASSWORD_LENGTH);
        strncpy(passwords[i].password, password, MAX_PASSWORD_LENGTH);
        strncpy(passwords[i].username, username, MAX_USERNAME_LENGTH);
        printf("Password: %s\n", passwords[i].password);
    }

    passwords_file = fopen("passwords.txt", "w");

    if (passwords_file == NULL) {
        printf("Error: could not open passwords file.\n");
        exit(1);
    }

    for (i = 0; i < num_passwords; i++) {
        fprintf(passwords_file, "Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    fclose(passwords_file);

    printf("Passwords saved to passwords.txt\n");

    return 0;
}