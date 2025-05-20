//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
// Password Strength Checker
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the password strength levels
#define WEAK 1
#define MEDIUM 2
#define STRONG 3

// Define the password length range
#define MIN_LENGTH 8
#define MAX_LENGTH 16

// Define the character sets
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL "!@#$%^&*()"

// Define the password structure
struct password {
    char password[MAX_LENGTH];
    int length;
    int strength;
};

// Function to check the password strength
int check_password(struct password *pass) {
    // Check the password length
    if (pass->length < MIN_LENGTH || pass->length > MAX_LENGTH) {
        return WEAK;
    }

    // Check the password character sets
    int lowercase = strchr(LOWERCASE, pass->password[0]) != NULL;
    int uppercase = strchr(UPPERCASE, pass->password[0]) != NULL;
    int numbers = strchr(NUMBERS, pass->password[0]) != NULL;
    int special = strchr(SPECIAL, pass->password[0]) != NULL;

    if (!lowercase && !uppercase && !numbers && !special) {
        return WEAK;
    }

    // Check the password complexity
    if (strchr(LOWERCASE, pass->password[0]) != NULL &&
        strchr(UPPERCASE, pass->password[0]) != NULL &&
        strchr(NUMBERS, pass->password[0]) != NULL &&
        strchr(SPECIAL, pass->password[0]) != NULL) {
        return STRONG;
    } else {
        return MEDIUM;
    }
}

// Function to display the password strength
void display_password_strength(int strength) {
    switch (strength) {
        case WEAK:
            printf("Weak Password\n");
            break;
        case MEDIUM:
            printf("Medium Password\n");
            break;
        case STRONG:
            printf("Strong Password\n");
            break;
        default:
            printf("Invalid Password\n");
            break;
    }
}

// Main function
int main() {
    // Initialize the password structure
    struct password pass;
    pass.length = 0;
    pass.strength = 0;

    // Get the password from the user
    printf("Enter the password: ");
    scanf("%s", pass.password);

    // Check the password strength
    pass.strength = check_password(&pass);

    // Display the password strength
    display_password_strength(pass.strength);

    return 0;
}