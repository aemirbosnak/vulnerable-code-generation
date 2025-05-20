//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(int length, char *password) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>/?";
    int i;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
}

// Function to check if the password is strong enough
int check_password_strength(char *password) {
    int length = strlen(password);
    int uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;
    int has_uppercase = 0, has_lowercase = 0, has_numbers = 0, has_symbols = 0;
    int i;
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            numbers = 1;
        } else if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?", password[i])!= NULL) {
            symbols = 1;
        }
    }
    if (uppercase && lowercase && numbers && symbols) {
        return 4;
    } else if (uppercase && lowercase && numbers) {
        return 3;
    } else if (uppercase && lowercase) {
        return 2;
    } else if (uppercase || lowercase || numbers) {
        return 1;
    } else {
        return 0;
    }
}

// Function to display the password strength
void display_password_strength(int strength) {
    switch (strength) {
        case 4:
            printf("Password is very strong.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        default:
            printf("Password is very weak.\n");
            break;
    }
}

int main() {
    int length, strength;
    char password[100];

    // Get the password length from the user
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a secure password
    generate_password(length, password);

    // Check the password strength
    strength = check_password_strength(password);

    // Display the password and its strength
    printf("Generated password: %s\n", password);
    display_password_strength(strength);

    return 0;
}