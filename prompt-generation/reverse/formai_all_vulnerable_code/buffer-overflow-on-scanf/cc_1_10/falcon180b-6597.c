//Falcon-180B DATASET v1.0 Category: Password management ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void generate_password(char *password, int length) {
    const char *chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords, i;
    password_t *passwords = NULL;

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    if (num_passwords <= 0 || num_passwords > MAX_PASSWORDS) {
        printf("Invalid number of passwords.\n");
        return 1;
    }

    passwords = (password_t *)malloc(num_passwords * sizeof(password_t));

    if (passwords == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < num_passwords; i++) {
        printf("Enter username for password %d: ", i + 1);
        scanf("%s", passwords[i].username);

        generate_password(passwords[i].password, MAX_PASSWORD_LENGTH);

        printf("Password for %s: %s\n", passwords[i].username, passwords[i].password);
    }

    free(passwords);

    return 0;
}