//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
const char* check_password_strength(const char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    // Define special characters
    const char *special_chars = "!@#$%^&*()-_+=<>?{}[]|\\:;\"',." ;

    // Analyze the password
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else if (strchr(special_chars, password[i])) has_special = 1;
    }

    // Evaluate password strength
    if (length >= 12 && has_upper && has_lower && has_digit && has_special)
        return "Strong Password";
    else if (length >= 8 && ((has_upper && has_lower && has_digit) || 
             (has_upper && has_digit && has_special) || 
             (has_lower && has_digit && has_special)))
        return "Moderate Password";
    else
        return "Weak Password";
}

// Main function
int main() {
    char password[100];
    char choice;

    printf("Welcome to the Password Strength Checker!\n");
    do {
        printf("Please enter a password to check: ");
        scanf("%s", password); // Read user input

        // Check password strength
        const char* strength = check_password_strength(password);
        printf("Password Strength: %s\n", strength);

        // Ask user if they want to continue
        printf("Do you want to check another password? (y/n): ");
        scanf(" %c", &choice); // Read user choice
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Password Strength Checker. Goodbye!\n");
    return 0;
}