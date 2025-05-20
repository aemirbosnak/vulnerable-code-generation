//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char *username;
    char *password;
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?~";
    const int charset_length = strlen(charset);
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[length] = '\0';
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length = 0;

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (strlen(username) == 0) {
            printf("Username cannot be empty.\n");
            continue;
        }

        if (num_passwords == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            continue;
        }

        printf("Enter password length (minimum 8): ");
        scanf("%d", &length);

        if (length < 8) {
            printf("Password must be at least 8 characters long.\n");
            continue;
        }

        generate_password(password, length);
        strcpy(passwords[num_passwords].password, password);
        strcpy(passwords[num_passwords].username, username);
        passwords[num_passwords].length = length;
        num_passwords++;

        printf("Password generated for %s:\n%s\n", username, password);
    }

    return 0;
}