//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 16 // maximum length of password
#define MIN_PASSWORD_LENGTH 8 // minimum length of password

// function to generate a random password
void generate_password(char *password, int length) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?"; // all possible characters
    char *p = password;

    // generate a random password
    for (i = 0; i < length; i++) {
        *p++ = charset[rand() % (sizeof(charset) - 1)];
    }

    *p = '\0'; // null terminate the password
}

// function to validate a password
int validate_password(char *password) {
    int i, count = 0;

    // check if password contains at least one uppercase letter
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            count++;
            break;
        }
    }

    // check if password contains at least one lowercase letter
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            count++;
            break;
        }
    }

    // check if password contains at least one digit
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            count++;
            break;
        }
    }

    // check if password contains at least one special character
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            count++;
            break;
        }
    }

    // check if password is at least 8 characters long
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    return count >= 4; // password is valid if it contains at least 4 different types of characters
}

int main() {
    int length, i;
    char password[MAX_PASSWORD_LENGTH];

    // get user input for password length
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // generate a random password
    generate_password(password, length);

    // print the generated password
    printf("Generated password: %s\n", password);

    // validate the generated password
    if (validate_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}