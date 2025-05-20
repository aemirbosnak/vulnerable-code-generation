//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 80

typedef struct {
    char* username;
    char* password;
    int length;
} password_t;

void generate_password(char* password, int length) {
    const char* chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    char* username = (char*)malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    char* password = (char*)malloc(MAX_PASSWORD_LENGTH * sizeof(char));

    while (1) {
        printf("Enter username: ");
        scanf("%s", username);

        if (num_passwords >= MAX_PASSWORDS) {
            printf("You have reached the maximum number of passwords.\n");
            break;
        }

        int password_length = rand() % 16 + 8;
        generate_password(password, password_length);
        strcpy(passwords[num_passwords].password, password);
        passwords[num_passwords].length = password_length;
        passwords[num_passwords].username = strdup(username);

        num_passwords++;

        printf("Password generated for %s:\n", username);
        printf("%s\n", passwords[num_passwords - 1].password);
    }

    return 0;
}