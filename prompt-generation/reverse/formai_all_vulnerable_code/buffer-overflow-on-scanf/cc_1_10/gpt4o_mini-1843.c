//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

// Function to generate a random secure password
void generate_password(char *password, int length) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{};:,.<>?";
    
    // Combine all character sets in a single string
    const char *all_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{};:,.<>?";
    
    // Ensure each password has at least one character from each category
    password[0] = upper[rand() % strlen(upper)];
    password[1] = lower[rand() % strlen(lower)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill the remaining characters
    for (int i = 4; i < length; i++) {
        password[i] = all_characters[rand() % strlen(all_characters)];
    }

    // Shuffle the password to make it more secure
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the string
    password[length] = '\0';
}

int main() {
    int length;
    char password[MAX_LENGTH + 1];
    
    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter desired password length (minimum 8, maximum %d): ", MAX_LENGTH);
    
    // Get the password length from the user
    while (1) {
        scanf("%d", &length);
        if (length >= 8 && length <= MAX_LENGTH) {
            break;
        }
        printf("Please enter a valid length: ");
    }

    generate_password(password, length);

    // Display the generated password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}