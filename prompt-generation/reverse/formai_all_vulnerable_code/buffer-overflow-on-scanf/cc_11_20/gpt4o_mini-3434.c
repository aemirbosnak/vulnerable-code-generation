//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function prototypes
void generate_password(char *password, int length, int index, int hasUpper, int hasLower, int hasDigit, int hasSpecial);
int is_valid_password(const char *password, int length, int hasUpper, int hasLower, int hasDigit, int hasSpecial);
void print_usage();

int main() {
    srand((unsigned int)time(NULL)); // Seed for random number generation

    int length;
    int hasUpper, hasLower, hasDigit, hasSpecial;

    // Ask user for password criteria
    printf("Enter desired password length (8-100): ");
    scanf("%d", &length);
    if (length < 8 || length > MAX_LENGTH) {
        printf("Password length must be between 8 and 100.\n");
        return 1;
    }

    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &hasUpper);

    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &hasLower);

    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &hasDigit);

    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &hasSpecial);

    // Validate user input
    if (!hasUpper && !hasLower && !hasDigit && !hasSpecial) {
        printf("At least one character set must be selected.\n");
        return 1;
    }

    char password[MAX_LENGTH + 1];
    password[length] = '\0'; // Null-terminate the password string

    generate_password(password, length, 0, hasUpper, hasLower, hasDigit, hasSpecial);

    return 0;
}

// Recursive function to generate password
void generate_password(char *password, int length, int index, int hasUpper, int hasLower, int hasDigit, int hasSpecial) {
    if (index == length) { // Base case: password is complete
        if (is_valid_password(password, length, hasUpper, hasLower, hasDigit, hasSpecial)) {
            printf("Generated Password: %s\n", password);
            return;
        }
    } else {
        char choices[4][10] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "abcdefghijklmnopqrstuvwxyz", "0123456789", "!@#$%^&*()-_+=" };
        int selected_set = 0;

        // Select which set to use based on user input
        if (hasUpper) selected_set++;
        if (hasLower) selected_set++;
        if (hasDigit) selected_set++;
        if (hasSpecial) selected_set++;

        if (selected_set > 0) {
            // Randomly choose a character set to get the next character from
            int rand_set = rand() % selected_set;
            int i = 0;

            // Map rand_set to the character sets
            if (rand_set == 0 && hasUpper) i = 0; 
            else if (rand_set == 1 && hasLower) i = 1; 
            else if (rand_set == 2 && hasDigit) i = 2; 
            else if (rand_set == 3 && hasSpecial) i = 3;

            char next_char = choices[i][rand() % strlen(choices[i])];
            password[index] = next_char;

            // Recur to fill the next character
            generate_password(password, length, index + 1, hasUpper, hasLower, hasDigit, hasSpecial);
        }
    }
}

// Validate password based on the criteria
int is_valid_password(const char *password, int length, int hasUpper, int hasLower, int hasDigit, int hasSpecial) {
    int upper = 0, lower = 0, digit = 0, special = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) upper = 1;
        else if (islower(password[i])) lower = 1;
        else if (isdigit(password[i])) digit = 1;
        else if (ispunct(password[i])) special = 1;
    }

    return (!hasUpper || upper) && (!hasLower || lower) && (!hasDigit || digit) && (!hasSpecial || special);
}