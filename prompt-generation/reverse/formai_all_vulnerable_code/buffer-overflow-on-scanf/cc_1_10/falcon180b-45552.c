//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate a random password
char* generate_password(int length) {
    char *password = malloc(length + 1); // Allocate memory for password and null terminator
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int charset_length = strlen(charset);
    int i;

    for (i = 0; i < length; i++) {
        int random_index = rand() % charset_length;
        password[i] = charset[random_index];
    }

    password[length] = '\0'; // Add null terminator
    return password;
}

// Function to check if password meets requirements
int check_password(char* password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;

    if (length < 8) {
        return 0;
    }

    while (*password) {
        if (isupper(*password)) {
            uppercase = 1;
        } else if (islower(*password)) {
            lowercase = 1;
        } else if (isdigit(*password)) {
            number = 1;
        } else if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?", *password)) {
            special = 1;
        }
        password++;
    }

    if (uppercase && lowercase && number && special) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int length = 12; // Default password length
    char* password;

    // Seed random number generator with current time
    srand(time(NULL));

    while (1) {
        printf("Enter desired password length (minimum 8): ");
        scanf("%d", &length);

        if (length < 8) {
            printf("Password length must be at least 8 characters.\n");
        } else {
            break;
        }
    }

    password = generate_password(length);

    while (!check_password(password)) {
        free(password);
        password = generate_password(length);
    }

    printf("Your secure password is: %s\n", password);
    free(password);

    return 0;
}