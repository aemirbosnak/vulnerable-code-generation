//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32
#define CHAR_SET_LENGTH 62

// Function to generate a random password
char* generate_password(int length) {
    char* password = malloc(length + 1);
    time_t now;
    srand(time(&now));

    for (int i = 0; i < length; i++) {
        password[i] = rand() % CHAR_SET_LENGTH + 'a';
    }

    password[length] = '\0';
    return password;
}

// Function to validate the password
int validate_password(char* password) {
    int length = strlen(password);
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;

    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        } else if (isupper(password[i])) {
            uppercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        }
    }

    if (length >= 8 && lowercase_count > 0 && uppercase_count > 0 && digit_count > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int length;
    char* password;

    printf("Enter desired password length (between 8 and 32 characters): ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length.\n");
        return 1;
    }

    password = generate_password(length);
    printf("Generated password: %s\n", password);
    if (validate_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    free(password);
    return 0;
}