//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32
#define PASSWORD_LENGTH 12
#define CHAR_SET_SIZE 62

char char_set[CHAR_SET_SIZE] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/~`"};

void generate_password(char *password, int length) {
    int i;
    srand(time(NULL));

    for (i = 0; i < length; i++) {
        int random_index = rand() % CHAR_SET_SIZE;
        password[i] = char_set[random_index];
    }

    password[length] = '\0';
}

int is_weak_password(char *password, int length) {
    int i;
    int weak = 0;

    // Check for common weak passwords
    if (strcmp(password, "password") == 0) {
        weak = 1;
    }
    if (strcmp(password, "123456") == 0) {
        weak = 1;
    }
    if (strcmp(password, "qwerty") == 0) {
        weak = 1;
    }
    if (strcmp(password, "admin") == 0) {
        weak = 1;
    }
    if (strcmp(password, "letmein") == 0) {
        weak = 1;
    }

    // Check for password length
    if (length < MIN_LENGTH) {
        weak = 1;
    }

    // Check for repeated characters
    for (i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            weak = 1;
            break;
        }
    }

    return weak;
}

int main() {
    char password[MAX_LENGTH];
    int length;
    int weak_password;

    printf("Enter the desired password length (min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Generating a password of length %d...\n", PASSWORD_LENGTH);
        length = PASSWORD_LENGTH;
    }

    generate_password(password, length);

    do {
        printf("Generated password: %s\n", password);
        printf("Is this password weak? (y/n): ");
        scanf(" %c", &weak_password);

        if (weak_password == 'y') {
            generate_password(password, length);
        }
    } while (is_weak_password(password, length));

    printf("Strong password generated: %s\n", password);

    return 0;
}