//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

void generate_password(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}[]=<>?,./;:'\"\\|";
    int i, j;

    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length = MIN_PASSWORD_LENGTH;

    srand(time(NULL));

    while (1) {
        printf("Enter desired password length (minimum %d): ", MIN_PASSWORD_LENGTH);
        scanf("%d", &length);

        if (length < MIN_PASSWORD_LENGTH) {
            printf("Password length must be at least %d characters.\n", MIN_PASSWORD_LENGTH);
            continue;
        }

        generate_password(password, length);

        printf("Generated password: %s\n", password);

        printf("Do you want to generate another password? (y/n) ");
        char choice;
        scanf(" %c", &choice);

        if (choice!= 'y' && choice!= 'Y') {
            break;
        }
    }

    return 0;
}