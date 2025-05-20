//Falcon-180B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int strength;
} Password;

void generate_password(Password *password, int length) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+~`|}{[]\:;?><,./-=";
    int charset_size = strlen(charset);

    for (i = 0; i < length; i++) {
        password->password[i] = charset[rand() % charset_size];
    }

    password->length = length;
    password->strength = 0;
}

int calculate_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else {
            symbols = 1;
        }
    }

    int strength = 0;
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (numbers) {
        strength++;
    }
    if (symbols) {
        strength++;
    }

    return strength;
}

void print_password(Password *password) {
    int i;

    for (i = 0; i < password->length; i++) {
        printf("%c", password->password[i]);
    }
}

int main() {
    int length;
    char choice;
    Password password;

    do {
        printf("\nPassword Manager\n");
        printf("1. Generate Password\n");
        printf("2. Check Password Strength\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter password length (between 1 and 50): ");
                scanf("%d", &length);
                generate_password(&password, length);
                printf("\nGenerated Password: ");
                print_password(&password);
                printf("\nPassword Strength: %d\n", calculate_strength(password.password));
                break;
            case '2':
                printf("Enter password: ");
                scanf("%s", password.password);
                printf("\nPassword Strength: %d\n", calculate_strength(password.password));
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '3');

    return 0;
}