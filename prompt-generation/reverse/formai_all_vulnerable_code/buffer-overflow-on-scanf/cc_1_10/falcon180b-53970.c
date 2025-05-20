//Falcon-180B DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password_t;

void generate_password(char *password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}[]|:<>?,./;'\"\\-=";
    int i;

    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }

    password[length] = '\0';
}

int main() {
    int num_passwords;
    char input[MAX_PASSWORD_LENGTH];
    password_t passwords[MAX_PASSWORDS];
    int i, j;

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &num_passwords);

    for (i = 0; i < num_passwords; i++) {
        printf("Password %d:\n", i+1);
        printf("Username: ");
        scanf("%s", passwords[i].username);
        printf("Password: ");
        scanf("%s", input);

        strcpy(passwords[i].password, input);
        generate_password(passwords[i].password, strlen(input));
    }

    printf("\nGenerated passwords:\n");
    for (i = 0; i < num_passwords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n\n", passwords[i].password);
    }

    return 0;
}