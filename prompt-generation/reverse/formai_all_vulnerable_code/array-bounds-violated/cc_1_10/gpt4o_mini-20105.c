//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for password generation
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char special[] = "!@#$%^&*()-_=+<>?";

// Function to generate a secure password
void generatePassword(int length) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Length validation
    if (length < 4) {
        printf("Password length should be at least 4.\n");
        return;
    }
    
    // Create an array to store the password
    char password[length + 1];
    
    // Ensure at least one character from each category is included
    password[0] = lowercase[rand() % (sizeof(lowercase) - 1)];
    password[1] = uppercase[rand() % (sizeof(uppercase) - 1)];
    password[2] = digits[rand() % (sizeof(digits) - 1)];
    password[3] = special[rand() % (sizeof(special) - 1)];
    
    // Fill the rest of the password with random characters from all categories
    for (int i = 4; i < length; i++) {
        int type = rand() % 4; // Randomly choose a character type
        switch(type) {
            case 0: password[i] = lowercase[rand() % (sizeof(lowercase) - 1)]; break;
            case 1: password[i] = uppercase[rand() % (sizeof(uppercase) - 1)]; break;
            case 2: password[i] = digits[rand() % (sizeof(digits) - 1)]; break;
            case 3: password[i] = special[rand() % (sizeof(special) - 1)]; break;
        }
    }
    
    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        // Swap the characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Null terminate the password string
    password[length] = '\0';

    // Print the generated password
    printf("Generated Password: %s\n", password);
}

int main() {
    int length;
    
    // Get the desired password length from the user
    printf("Enter the desired password length (minimum 4): ");
    scanf("%d", &length);
    
    // Generate and display the password
    generatePassword(length);
    
    return 0;
}