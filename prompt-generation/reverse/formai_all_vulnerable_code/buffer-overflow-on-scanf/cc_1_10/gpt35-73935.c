//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, num_chars, i, index;
    char password[100];
    srand(time(NULL));
    
    printf("Welcome to the C Secure Password Generator\n");
    
    // Prompt user for desired password length
    printf("Please enter the desired length of your password (between 6 and 20 characters): ");
    scanf("%d", &length);
    
    // Validate password length
    while(length < 6 || length > 20) {
        printf("Invalid length. Please enter a number between 6 and 20: ");
        scanf("%d", &length);
    }
    
    // Prompt user for the number of character types to include in the password
    printf("Please enter the number of character types you would like to include (between 2 and 4): ");
    scanf("%d", &num_chars);
    
    // Validate number of character types
    while(num_chars < 2 || num_chars > 4) {
        printf("Invalid number of character types. Please enter a number between 2 and 4: ");
        scanf("%d", &num_chars);
    }
    
    // Initialize character arrays for each character type
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=";
    
    // Use a for loop to generate the password
    for(i = 0; i < length; i++) {
        // Select a random character type
        index = rand() % num_chars;
        
        // Select a random character from the chosen character type
        switch(index) {
            case 0:
                password[i] = uppercase[rand() % 26];
                break;
            case 1:
                password[i] = lowercase[rand() % 26];
                break;
            case 2:
                password[i] = numbers[rand() % 10];
                break;
            case 3:
                password[i] = symbols[rand() % 14];
                break;
        }
    }
    
    // Add null terminator to password string
    password[length] = '\0';
    
    printf("Your new secure password is: %s\n", password);
    
    return 0;
}