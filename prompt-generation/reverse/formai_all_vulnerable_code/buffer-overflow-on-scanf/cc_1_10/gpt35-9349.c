//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: curious
// Welcome to the Secure Password Generator!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Secure Password Generator!\n");
    
    // Initialize the uppercase, lowercase, numerical, and special character arrays
    char uppercase_letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowercase_letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char numerical_digits[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char special_characters[] = {'!', '@', '#', '$', '%', '&', '*'};
    
    // Set the default password length to 8 characters
    int password_length = 8;
    char password[password_length];
    
    // Prompt the user for the desired password length and store it in the password_length variable
    printf("How many characters do you want your password to be? (8-20): ");
    scanf("%d", &password_length);
    
    // Check if the user input is within the allowed range, otherwise set the default length
    if (password_length < 8 || password_length > 20) {
        printf("Invalid password length, defaulting to 8 characters.\n");
        password_length = 8;
    }
    
    // Store the current time as the random number generator seed
    srand(time(0));
    
    // Loop through the password character array and randomly select a character from the arrays
    for (int i = 0; i < password_length; i++) {
        int random_number = rand() % 4;
        
        switch (random_number) {
            case 0:
                password[i] = uppercase_letters[rand() % 26];
                break;
            case 1:
                password[i] = lowercase_letters[rand() % 26];
                break;
            case 2:
                password[i] = numerical_digits[rand() % 10];
                break;
            case 3:
                password[i] = special_characters[rand() % 7];
                break;
            default:
                printf("Something went wrong, please try again later.");
                return 1;
        }
    }
    
    // Null-terminate the password string
    password[password_length] = '\0';
    
    // Print the secure password to the user
    printf("Your secure password is: %s\n", password);
    
    return 0;
}