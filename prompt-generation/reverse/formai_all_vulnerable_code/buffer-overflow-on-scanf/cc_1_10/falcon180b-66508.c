//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20
#define MAX_PASSWORD_ATTEMPTS 5

int generate_password(char *password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);
    int i;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int attempts = 0;

    printf("Secure Password Generator\n");
    printf("-------------------------\n");

    while (1) {
        printf("Enter desired password length (between %d and %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);

        if (password_length >= MIN_PASSWORD_LENGTH && password_length <= MAX_PASSWORD_LENGTH) {
            break;
        } else {
            printf("Invalid password length. Please try again.\n");
        }
    }

    while (1) {
        if (generate_password(password, password_length) == 0) {
            printf("Password generated successfully:\n%s\n", password);
            break;
        } else {
            printf("Failed to generate password. Retrying...\n");
            attempts++;

            if (attempts >= MAX_PASSWORD_ATTEMPTS) {
                printf("Maximum number of attempts reached. Exiting...\n");
                return 1;
            }
        }
    }

    return 0;
}