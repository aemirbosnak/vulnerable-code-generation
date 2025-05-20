//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function Declarations
void generate_password(char *password, int length);
void display_password(char *password);
void choose_character_set(char *charset, int *set_size);
void shuffle_password(char *password, int length);

// Constants for password criteria
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32
#define CHARSET_LENGTH 128

int main() {
    int length;
    
    // Seed the random number generator
    srand(time(NULL));

    // Ask user for password length
    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter desired password length (%d to %d): ", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
    
    while (1) {
        scanf("%d", &length);
        if (length >= PASSWORD_MIN_LENGTH && length <= PASSWORD_MAX_LENGTH) {
            break;
        } else {
            printf("Invalid length! Please enter a number between %d and %d: ", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
        }
    }

    // Generate the password
    char password[PASSWORD_MAX_LENGTH + 1];
    generate_password(password, length);
    
    // Display the generated password
    display_password(password);

    return 0;
}

void generate_password(char *password, int length) {
    char charset[CHARSET_LENGTH];
    int set_size;
    
    // Choose character set based on desired criteria
    choose_character_set(charset, &set_size);
    
    // Generate password using random characters from the chosen set
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % set_size];
    }
    password[length] = '\0';  // Null terminate the string

    // Shuffle for added security
    shuffle_password(password, length);
}

void choose_character_set(char *charset, int *set_size) {
    int index = 0;
    
    // Lowercase letters
    for (char c = 'a'; c <= 'z'; c++) {
        charset[index++] = c;
    }
    // Uppercase letters
    for (char c = 'A'; c <= 'Z'; c++) {
        charset[index++] = c;
    }
    // Digits
    for (char c = '0'; c <= '9'; c++) {
        charset[index++] = c;
    }
    // Special characters
    char special_chars[] = "!@#$%^&*()-_=+[]{};:,.<>?/~";
    for (int i = 0; i < strlen(special_chars); i++) {
        charset[index++] = special_chars[i];
    }

    *set_size = index;  // Set the size of the character set
}

void shuffle_password(char *password, int length) {
    // Fisher-Yates shuffle algorithm
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

void display_password(char *password) {
    printf("Your secure password is: %s\n", password);
}