//Falcon-180B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 32

struct password {
    char name[MAX_PASSWORD_LENGTH];
    char value[MAX_PASSWORD_LENGTH];
};

void generate_password(char *password) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?";
    for (i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

int main(void) {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int i, j;
    struct password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Enter a name for the password manager: ");
    scanf("%s", name);

    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        generate_password(password);
        printf("Enter a name for password %d: ", i + 1);
        scanf("%s", passwords[i].name);
        strcpy(passwords[i].value, password);
        printf("Password %s has been generated.\n", passwords[i].name);
    }

    printf("Password manager for %s:\n", name);
    for (i = 0; i < num_passwords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].value);
    }

    return 0;
}