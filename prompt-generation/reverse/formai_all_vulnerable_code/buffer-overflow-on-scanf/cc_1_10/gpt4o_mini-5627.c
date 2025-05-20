//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 10
#define MAX_LENGTH 16
#define NUM_PASSWORDS 5

// Function prototypes
void generate_password(char *password, int length);
int is_valid_password(const char *password);
void display_help();

int main() {
    char passwords[NUM_PASSWORDS][MAX_LENGTH + 1]; // Store generated passwords
    int i;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n");
    printf("This program generates strong random passwords.\n");
    printf("Please enter the desired length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    
    int length;
    scanf("%d", &length);

    // Validate input length
    if(length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    for(i = 0; i < NUM_PASSWORDS; i++) {
        generate_password(passwords[i], length);
        // Ensure validity of the generated password
        while(!is_valid_password(passwords[i])) {
            generate_password(passwords[i], length);
        }
    }

    printf("\nGenerated Passwords:\n");
    for(i = 0; i < NUM_PASSWORDS; i++) {
        printf("%d: %s\n", i + 1, passwords[i]);
    }

    return 0;
}

void generate_password(char *password, int length) {
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()_-+=<>?";
    
    // Ensure the password contains at least one character from each category
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = symbols[rand() % strlen(symbols)];

    // Fill the rest of the password
    for(int i = 4; i < length; i++) {
        int category = rand() % 4;

        switch(category) {
            case 0:
                password[i] = lowercase[rand() % strlen(lowercase)];
                break;
            case 1:
                password[i] = uppercase[rand() % strlen(uppercase)];
                break;
            case 2:
                password[i] = digits[rand() % strlen(digits)];
                break;
            case 3:
                password[i] = symbols[rand() % strlen(symbols)];
                break;
        }
    }

    // Shuffle the password
    for(int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    password[length] = '\0'; // Null-terminate the string
}

int is_valid_password(const char *password) {
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_symbol = 0;
    
    // Check password characteristics
    for(const char *ptr = password; *ptr; ptr++) {
        if(islower(*ptr)) has_lower = 1;
        else if(isupper(*ptr)) has_upper = 1;
        else if(isdigit(*ptr)) has_digit = 1;
        else if(strchr("!@#$%^&*()_-+=<>?", *ptr)) has_symbol = 1;
    }
    
    return has_lower && has_upper && has_digit && has_symbol; // Ensure all conditions are met
}

void display_help() {
    printf("This program generates secure passwords according to certain rules:\n");
    printf("- Passwords must contain at least one lowercase letter.\n");
    printf("- Passwords must contain at least one uppercase letter.\n");
    printf("- Passwords must contain at least one digit.\n");
    printf("- Passwords must contain at least one special character (e.g., !@#$%^&*()).\n");
    printf("- Password lengths can be specified between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
}