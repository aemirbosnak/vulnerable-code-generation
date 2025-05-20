//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{}|;:,.<>?/"

void generate_password(char *password, int length) {
    const char *char_set = LOWERCASE UPPERCASE DIGITS SPECIAL_CHARS;
    int set_length = strlen(char_set);
    
    // Ensure at least one character from each required category is included
    password[0] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[1] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[2] = DIGITS[rand() % strlen(DIGITS)];
    password[3] = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];
    
    // Fill the rest of the password with random characters from all categories
    for (int i = 4; i < length; i++) {
        password[i] = char_set[rand() % set_length];
    }
    
    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Null terminate the password string
    password[length] = '\0';
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int password_length;
    printf("Welcome to the Secure Password Generator! \n");
    
    // Get user input for password length
    do {
        printf("Enter desired password length [%d-%d]: ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &password_length);
        if (password_length < MIN_LENGTH || password_length > MAX_LENGTH) {
            printf("Invalid length. Please try again.\n");
        }
    } while (password_length < MIN_LENGTH || password_length > MAX_LENGTH);
    
    // Allocate memory for the password
    char *password = (char *) malloc((password_length + 1) * sizeof(char));
    if (password == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    // Generate the password
    generate_password(password, password_length);
    
    // Display the generated password
    printf("Your secure password is: %s\n", password);
    
    // Free the dynamically allocated memory
    free(password);
    
    return 0;
}