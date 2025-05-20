//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 128

// Function to generate a random character
char generate_random_char() {
    // Array of all possible characters
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-`";
    // Get the length of the array
    int length = strlen(characters);
    // Generate a random index
    int index = rand() % length;
    // Return the character at the random index
    return characters[index];
}

// Function to generate a random password
char* generate_random_password(int length) {
    // Allocate memory for the password
    char* password = malloc(length + 1);
    // Generate a random character for each position in the password
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_char();
    }
    // Terminate the password with a null character
    password[length] = '\0';
    // Return the password
    return password;
}

// Function to print the password generation configuration
void print_configuration(int length, int num_passwords) {
    printf("Password Generator Configuration:\n");
    printf("------------------------------\n");
    printf("Password Length: %d\n", length);
    printf("Number of Passwords: %d\n", num_passwords);
}

// Function to main program
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Prompt the user to enter the desired password length
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);
    
    // Prompt the user to enter the number of passwords to generate
    int num_passwords;
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);
    
    // Print the password generation configuration
    print_configuration(length, num_passwords);
    
    // Generate the passwords and print them to the console
    for (int i = 0; i < num_passwords; i++) {
        char* password = generate_random_password(length);
        printf("Password %d: %s\n", i + 1, password);
        free(password);
    }
    
    return 0;
}