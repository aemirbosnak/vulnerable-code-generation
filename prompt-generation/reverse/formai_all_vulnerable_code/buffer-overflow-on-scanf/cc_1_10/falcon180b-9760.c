//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generate_password(char *password, int length) {
    const char *chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+=[]{}|;:,.<>?";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int compare_passwords(const void *a, const void *b) {
    const Password *p1 = a;
    const Password *p2 = b;
    return strcmp(p1->username, p2->username);
}

int main() {
    int num_passwords;
    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &num_passwords);

    Password passwords[MAX_PASSWORDS];
    int num_generated_passwords = 0;

    while (num_generated_passwords < num_passwords) {
        printf("Enter a username: ");
        scanf("%s", passwords[num_generated_passwords].username);

        generate_password(passwords[num_generated_passwords].password, MAX_PASSWORD_LENGTH);

        num_generated_passwords++;
    }

    qsort(passwords, num_generated_passwords, sizeof(Password), compare_passwords);

    for (int i = 0; i < num_generated_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    return 0;
}