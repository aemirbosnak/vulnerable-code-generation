//Falcon-180B DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[32];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_entry;

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-=+;:,.?/";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    int num_passwords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    password_entry passwords[MAX_PASSWORDS];
    int num_generated_passwords = 0;

    while (num_generated_passwords < num_passwords) {
        int i;
        for (i = 0; i < MAX_PASSWORDS; i++) {
            if (passwords[i].length == 0) {
                int length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH;
                generate_password(passwords[i].password, length);
                passwords[i].length = length;
                num_generated_passwords++;
                break;
            }
        }
    }

    printf("\nGenerated passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s (%d characters)\n", passwords[i].password, passwords[i].length);
    }

    return 0;
}