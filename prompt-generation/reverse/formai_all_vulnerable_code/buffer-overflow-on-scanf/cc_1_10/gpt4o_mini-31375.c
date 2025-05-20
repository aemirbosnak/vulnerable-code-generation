//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128

// Function to check if a character is a special character
int is_special_character(char c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) ||
           (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

// Function to generate a secure password
void generate_password(char *password, int length, int use_upper, int use_lower, int use_digits, int use_special) {
    const char *upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower_case = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special_chars = "!@#$%^&*()-=_+[]{}|;:'\",.<>?/`~";

    int characters_included = 0;
    if (use_upper) characters_included += strlen(upper_case);
    if (use_lower) characters_included += strlen(lower_case);
    if (use_digits) characters_included += strlen(digits);
    if (use_special) characters_included += strlen(special_chars);
    
    if (characters_included == 0) {
        printf("Error: At least one character type must be selected.\n");
        return;
    }

    int index;
    for (int i = 0; i < length; i++) {
        int type = rand() % characters_included;
        if (use_upper && type < strlen(upper_case)) {
            password[i] = upper_case[type];
        } else if (use_lower && type < strlen(upper_case) + strlen(lower_case)) {
            password[i] = lower_case[type - strlen(upper_case)];
        } else if (use_digits && type < strlen(upper_case) + strlen(lower_case) + strlen(digits)) {
            password[i] = digits[type - strlen(upper_case) - strlen(lower_case)];
        } else if (use_special && type < characters_included) {
            password[i] = special_chars[type - (strlen(upper_case) + strlen(lower_case) + strlen(digits))];
        }
    }
    password[length] = '\0'; // Null-terminate the string
}

// Function to display the password 
void display_password(const char *password) {
    printf("Generated Password: %s\n", password);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    char password[MAX_PASSWORD_LENGTH];
    int length, use_upper, use_lower, use_digits, use_special;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter the desired length of the password (8-128): ");
    scanf("%d", &length);
    
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Error: Password length must be between 8 and 128 characters.\n");
        return 1;
    }

    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &use_upper);
    
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &use_lower);
    
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &use_digits);
    
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &use_special);

    // Generate the password
    generate_password(password, length, use_upper, use_lower, use_digits, use_special);
    
    // Display the generated password
    display_password(password);

    return 0;
}