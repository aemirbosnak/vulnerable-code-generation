//Falcon-180B DATASET v1.0 Category: Password management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} password_t;

void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);
    int i;
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }
    password[i] = '\0';
}

int main() {
    int num_passwords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);

    password_t passwords[MAX_PASSWORDS];
    int num_generated_passwords = 0;

    while (num_generated_passwords < num_passwords) {
        int length;
        printf("Enter the desired password length (between 1 and 32): ");
        scanf("%d", &length);
        if (length < 1 || length > MAX_PASSWORD_LENGTH) {
            printf("Invalid password length.\n");
            continue;
        }

        char password[MAX_PASSWORD_LENGTH];
        generate_password(password, length);

        int i;
        for (i = 0; i < num_generated_passwords; i++) {
            if (strcmp(passwords[i].password, password) == 0) {
                printf("Duplicate password generated.\n");
                break;
            }
        }
        if (i == num_generated_passwords) {
            strcpy(passwords[num_generated_passwords].password, password);
            passwords[num_generated_passwords].length = length;
            num_generated_passwords++;
        }
    }

    printf("Generated passwords:\n");
    for (int i = 0; i < num_generated_passwords; i++) {
        printf("%d-character password: %s\n", passwords[i].length, passwords[i].password);
    }

    return 0;
}