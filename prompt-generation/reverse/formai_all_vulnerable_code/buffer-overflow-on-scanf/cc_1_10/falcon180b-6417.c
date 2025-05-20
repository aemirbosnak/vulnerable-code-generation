//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 32

// Function to generate a random password
void generate_password(char *password, int length) {
    const char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-=+[{]}\\|;:'\",<.>/?`~";
    int i = 0;
    while (i < length) {
        password[i] = characters[rand() % strlen(characters)];
        i++;
    }
    password[i] = '\0';
}

// Function to check if a password meets the complexity requirements
bool is_password_complex_enough(char *password) {
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else {
            special_count++;
        }
    }

    return (uppercase_count > 0 && lowercase_count > 0 && digit_count > 0 && special_count > 0);
}

// Function to prompt the user for a password length and generate a password
void generate_password_interactive() {
    int length;
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("Enter the desired password length (between 8 and 32): ");
        scanf("%d", &length);
    } while (length < 8 || length > MAX_PASSWORD_LENGTH);

    srand(time(NULL));
    generate_password(password, length);

    while (!is_password_complex_enough(password)) {
        srand(time(NULL));
        generate_password(password, length);
    }

    printf("Your new password is: %s\n", password);
}

// Function to generate a password and print it to the console
void generate_password_console() {
    char password[MAX_PASSWORD_LENGTH];
    int length = rand() % MAX_PASSWORD_LENGTH + 8;

    srand(time(NULL));
    generate_password(password, length);

    while (!is_password_complex_enough(password)) {
        srand(time(NULL));
        generate_password(password, length);
    }

    printf("Your new password is: %s\n", password);
}

int main() {
    int choice;

    do {
        printf("Welcome to the Secure Password Generator!\n\n");
        printf("1. Generate a password interactively\n");
        printf("2. Generate a password and print it to the console\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generate_password_interactive();
            break;
        case 2:
            generate_password_console();
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (true);

    return 0;
}