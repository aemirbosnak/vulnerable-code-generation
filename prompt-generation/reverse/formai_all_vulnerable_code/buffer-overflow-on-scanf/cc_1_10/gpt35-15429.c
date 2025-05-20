//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20    // Maximum password length
#define MIN_PASSWORD_LENGTH 8     // Minimum password length

int get_random_number() {
    srand((unsigned int)time(NULL));    // Initialize random seed
    int num = rand() % 94 + 33;         // Generate random number from 33 to 126 inclusive
    
    return num;
}

int main() {
    int password_length;
    int num_uppercase = 0;      // Number of uppercase letters
    int num_lowercase = 0;      // Number of lowercase letters
    int num_numbers = 0;        // Number of numbers
    int num_special_chars = 0;  // Number of special characters
    char password[MAX_PASSWORD_LENGTH+1];    // Password string
    
    while (1) {
        printf("Enter the desired length of your password (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);
        
        if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
            printf("Invalid length. Please try again.\n");
        } else {
            break;
        }
    }
    
    for (int i = 0; i < password_length; i++) {
        int num = get_random_number();
        char c = (char)num;
        
        if (isupper(c)) {
            num_uppercase++;
        } else if (islower(c)) {
            num_lowercase++;
        } else if (isdigit(c)) {
            num_numbers++;
        } else {
            num_special_chars++;
        }
        
        password[i] = c;
    }
    
    while (num_uppercase < 1) {
        int index = rand() % password_length;    // Choose random index to replace with an uppercase letter
        char c = (char)(rand() % 26 + 65);       // Generate random uppercase letter
        password[index] = c;
        num_uppercase++;
    }
    
    while (num_lowercase < 1) {
        int index = rand() % password_length;    // Choose random index to replace with a lowercase letter
        char c = (char)(rand() % 26 + 97);       // Generate random lowercase letter
        password[index] = c;
        num_lowercase++;
    }
    
    while (num_numbers < 1) {
        int index = rand() % password_length;    // Choose random index to replace with a number
        char c = (char)(rand() % 10 + 48);       // Generate random number
        password[index] = c;
        num_numbers++;
    }
    
    while (num_special_chars < 1) {
        int index = rand() % password_length;    // Choose random index to replace with a special character
        char c = (char)get_random_number();     // Generate random special character
        password[index] = c;
        num_special_chars++;
    }
    
    password[password_length] = '\0';   // Add null terminator to password string
    
    printf("Your secure password is: %s\n", password);   // Print password
    
    return 0;
}