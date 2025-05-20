//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

void generate_password(int length, char *password) {
    // Character sets to use for password generation
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+";
    
    // Combined character set 
    const char *all_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    int all_chars_length = strlen(all_chars);
    
    // Seed the random number generator
    srand(time(NULL));

    // Ensure the first character is of different types for strong password
    password[0] = uppercase[rand() % strlen(uppercase)];
    password[1] = lowercase[rand() % strlen(lowercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Randomly fill the remaining characters
    for (int i = 4; i < length; i++) {
        password[i] = all_chars[rand() % all_chars_length];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int random_index = rand() % length;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    // Null-terminate the password string
    password[length] = '\0';
}

int main() {
    char password[MAX_LENGTH + 1];
    int length;

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (minimum 8, maximum %d): ", MAX_LENGTH);
    
    while (1) {
        scanf("%d", &length);
        if (length >= 8 && length <= MAX_LENGTH) {
            break; // valid length
        }
        printf("Invalid length. Please enter a number between 8 and %d: ", MAX_LENGTH);
    }

    generate_password(length, password);
    
    printf("Your generated secure password is: %s\n", password);
    
    return 0;
}