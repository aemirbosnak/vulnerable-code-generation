//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 128
#define MIN_LENGTH 8

// Function to check if the password meets complexity requirements
int is_secure_password(const char *password) {
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    const char *special_chars = "!@#$%^&*()-_=+[]{};:'\"\\|,<.>/?`~";

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) has_upper = 1;
        else if (islower(password[i])) has_lower = 1;
        else if (isdigit(password[i])) has_digit = 1;
        else if (strchr(special_chars, password[i])) has_special = 1;
    }

    return has_upper && has_lower && has_digit && has_special;
}

// Function to generate a secure password
void generate_password(char *password, int length) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special_chars = "!@#$%^&*()-_=+[]{};:'\"\\|,<.>/?`~";

    // Ensure at least one character from each category
    password[0] = upper[rand() % strlen(upper)];
    password[1] = lower[rand() % strlen(lower)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special_chars[rand() % strlen(special_chars)];

    // Fill the rest of the password
    const char *all_chars = upper;
    all_chars = strcat(strdup(all_chars), lower);
    all_chars = strcat(strdup(all_chars), digits);
    all_chars = strcat(strdup(all_chars), special_chars);

    for (int i = 4; i < length; i++) {
        password[i] = all_chars[rand() % strlen(all_chars)];
    }

    // Shuffle the password to avoid predictable patterns
    for (int i = 0; i < length; i++) {
        int r = rand() % length;
        char temp = password[i];
        password[i] = password[r];
        password[r] = temp;
    }
    
    // Null-terminate the string
    password[length] = '\0';
}

int main() {
    srand(time(NULL));  // Seed for random number generation
    int length;
    char password[MAX_LENGTH + 1];

    printf("Welcome to the Secure Password Generator!\n");

    // Ask for password length
    do {
        printf("Enter desired password length (8 - %d): ", MAX_LENGTH);
        scanf("%d", &length);
        if (length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        }
    } while (length < MIN_LENGTH || length > MAX_LENGTH);

    do {
        generate_password(password, length);
        if (!is_secure_password(password)) {
            printf("Generated password did not meet security requirements. Generating again...\n");
        }
    } while (!is_secure_password(password));

    printf("Your secure password is: %s\n", password);

    return 0;
}