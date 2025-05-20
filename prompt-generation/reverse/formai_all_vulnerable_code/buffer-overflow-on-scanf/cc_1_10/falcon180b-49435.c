//Falcon-180B DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

struct password {
    char *username;
    char *password;
};

void generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char *passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    printf("Enter number of passwords to generate: ");
    scanf("%d", &num_passwords);

    for (int i = 0; i < num_passwords; i++) {
        char username[MAX_PASSWORD_LENGTH];
        char password[MAX_PASSWORD_LENGTH];

        printf("Enter username for password %d: ", i + 1);
        scanf("%s", username);

        generate_password(password, MAX_PASSWORD_LENGTH);

        passwords[i] = malloc(MAX_PASSWORD_LENGTH * 2 + 1);
        strcpy(passwords[i], username);
        strcat(passwords[i], ":");
        strcat(passwords[i], password);
    }

    qsort(passwords, num_passwords, sizeof(char *), compare_passwords);

    for (int i = 0; i < num_passwords; i++) {
        printf("%s\n", passwords[i]);
    }

    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i]);
    }

    return 0;
}