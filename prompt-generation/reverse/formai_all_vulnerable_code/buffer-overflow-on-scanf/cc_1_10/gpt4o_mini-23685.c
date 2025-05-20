//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 12
#define MAX_PASSWORD_LENGTH 16
#define LOWERCASE 26
#define UPPERCASE 26
#define DIGITS 10
#define SPECIAL_CHARS 10

// Function prototypes
void generate_password(char *password, int length);
void shuffle(char *password, int length);
void print_password(char *password, int length);
int validate_password(char *password, int length);

// Define character sets
const char lowercase_set[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits_set[] = "0123456789";
const char special_chars_set[] = "!@#$%^&*()";

int main() {
    int password_length;
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 for null terminator

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (%d to %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    
    // Read user input for password length
    while (1) {
        scanf("%d", &password_length);
        if (password_length >= MIN_PASSWORD_LENGTH && password_length <= MAX_PASSWORD_LENGTH) {
            break;
        }
        printf("Invalid length. Please enter a length between %d and %d: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    }

    // Generate a password
    generate_password(password, password_length);

    // Shuffle the password for added security
    shuffle(password, password_length);

    // Print the generated password
    print_password(password, password_length);

    // Validate the generated password
    if (validate_password(password, password_length)) {
        printf("Your generated password is valid and secure!\n");
    } else {
        printf("The generated password is not secure. Please try again.\n");
    }

    return 0;
}

// Function to generate the password
void generate_password(char *password, int length) {
    int i = 0;

    // Ensure at least one character from each category
    password[i++] = lowercase_set[rand() % LOWERCASE];
    password[i++] = uppercase_set[rand() % UPPERCASE];
    password[i++] = digits_set[rand() % DIGITS];
    password[i++] = special_chars_set[rand() % SPECIAL_CHARS];

    // Fill the remaining characters randomly
    for (; i < length; i++) {
        int random_set = rand() % 4;  // Choose from 4 sets

        switch (random_set) {
            case 0:
                password[i] = lowercase_set[rand() % LOWERCASE];
                break;
            case 1:
                password[i] = uppercase_set[rand() % UPPERCASE];
                break;
            case 2:
                password[i] = digits_set[rand() % DIGITS];
                break;
            case 3:
            default:
                password[i] = special_chars_set[rand() % SPECIAL_CHARS];
                break;
        }
    }
    password[length] = '\0'; // Null-terminate the password
}

// Function to shuffle the password
void shuffle(char *password, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

// Function to print the password
void print_password(char *password, int length) {
    printf("Generated Password: ");
    for (int i = 0; i < length; i++) {
        putchar(password[i]);
    }
    printf("\n");
}

// Function to validate the password
int validate_password(char *password, int length) {
    int has_lower = 0, has_upper = 0, has_digit = 0, has_special = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') has_lower = 1;
        else if (password[i] >= 'A' && password[i] <= 'Z') has_upper = 1;
        else if (password[i] >= '0' && password[i] <= '9') has_digit = 1;
        else if (strchr(special_chars_set, password[i])) has_special = 1;
    }

    return has_lower && has_upper && has_digit && has_special;
}