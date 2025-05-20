//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    // Initializing variables
    int length, contains_upper, contains_lower, contains_digit, contains_special;
    char password[100];
    srand(time(NULL)); // Initializing random seed using current time
    
    // Getting user inputs
    printf("Enter length of password: ");
    scanf("%d", &length);
    printf("Include uppercase letters: (0 for no, 1 for yes) ");
    scanf("%d", &contains_upper);
    printf("Include lowercase letters: (0 for no, 1 for yes) ");
    scanf("%d", &contains_lower);
    printf("Include digits: (0 for no, 1 for yes) ");
    scanf("%d", &contains_digit);
    printf("Include special characters: (0 for no, 1 for yes) ");
    scanf("%d", &contains_special);
    
    // Creating string of characters for password generation
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()_+-=";
    char options[100] = ""; // Initializing empty string
    if (contains_upper) { // Adding uppercase letters to the options string
        strcat(options, upper);
    }
    if (contains_lower) { // Adding lowercase letters to the options string
        strcat(options, lower);
    }
    if (contains_digit) { // Adding digits to the options string
        strcat(options, digits);
    }
    if (contains_special) { // Adding special characters to the options string
        strcat(options, special);
    }
    
    if (strlen(options) == 0) { // If no options are selected, end the program
        printf("You must select at least one type of character.");
        return 0;
    }
    
    for (int i = 0; i < length; i++) { // Looping through the password length
        int random_index = rand() % strlen(options); // Generating random index for character selection
        password[i] = options[random_index]; // Adding selected character to password array
    }
    password[length] = '\0'; // Null terminating password array
    
    printf("Your generated password is: %s\n", password);
    return 0;
}