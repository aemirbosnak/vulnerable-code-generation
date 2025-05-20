//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_strong_password(const char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    if(length < 8) {
        printf("Password too short! (Minimum 8 characters)\n");
        return 0; // Not strong
    }

    for(int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else if (ispunct(password[i])) has_special = 1;
    }

    if (!has_upper) {
        printf("Missing uppercase letter!\n");
    }
    if (!has_lower) {
        printf("Missing lowercase letter!\n");
    }
    if (!has_digit) {
        printf("Missing digit!\n");
    }
    if (!has_special) {
        printf("Missing special character!\n");
    }

    return has_upper && has_lower && has_digit && has_special; // Return if all requirements met
}

void get_password() {
    char password[128];
    printf("Please enter your password: ");
    fgets(password, sizeof(password), stdin);
    
    // Remove newline character if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    if (is_strong_password(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak. Please try again.\n");
    }
}

int main() {
    while (1) {
        printf("\n--- Password Strength Checker ---\n");
        get_password();
        char choice;
        printf("Do you want to check another password? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n'); // To clear input buffer
        if (choice != 'y' && choice != 'Y') {
            printf("Thank you for using the Password Strength Checker! Goodbye!\n");
            break;
        }
    }
    
    return 0;
}