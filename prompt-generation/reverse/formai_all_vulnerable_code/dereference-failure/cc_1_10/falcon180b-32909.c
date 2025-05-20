//Falcon-180B DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

struct password {
    char *username;
    char *password;
    int length;
};

void generate_password(char *password, int length) {
    const char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords, i;
    struct password *passwords;

    printf("Enter number of passwords to generate: ");
    scanf("%d", &num_passwords);

    passwords = malloc(num_passwords * sizeof(struct password));

    for (i = 0; i < num_passwords; i++) {
        char username[20];
        char password[MAX_PASSWORD_LENGTH];

        printf("Enter username for password %d: ", i + 1);
        scanf("%s", username);

        printf("Enter desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &passwords[i].length);

        generate_password(password, passwords[i].length);
        strcpy(passwords[i].password, password);
        passwords[i].username = strdup(username);
    }

    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }

    free(passwords);

    return 0;
}