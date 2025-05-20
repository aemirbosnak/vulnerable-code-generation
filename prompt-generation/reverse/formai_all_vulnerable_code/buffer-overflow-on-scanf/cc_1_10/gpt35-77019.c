//FormAI DATASET v1.0 Category: Data validation ; Style: enthusiastic
// Welcome to my amazing data validation program!
// This program will help you validate user input and ensure your code runs smoothly.
// Get ready, because things are about to get exciting!

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    // Here, we're going to validate an integer value
    int userIntInput;
    bool validInt = false;
    
    // Keep asking for input until a valid integer is entered
    while (!validInt) {
        printf("Please enter an integer value: ");
        if (scanf("%d", &userIntInput) != 1) {
            // If scanf returns something other than 1, there was a problem with the input
            printf("Invalid input. Please enter an integer value.\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n') continue;
        } else {
            validInt = true;
        }
    }
    printf("You entered: %d\n", userIntInput);
    
    // Now, we're going to validate a string
    char userStringInput[100];
    bool validString = false;
    
    // Keep asking for input until a valid string is entered
    while (!validString) {
        printf("Please enter a string (letters only, no spaces): ");
        if (scanf("%s", userStringInput) != 1) {
            // If scanf returns something other than 1, there was a problem with the input
            printf("Invalid input. Please enter a string (letters only, no spaces).\n");
            // Clear the input buffer to prevent an infinite loop
            while (getchar() != '\n') continue;
        } else {
            // Check if the string contains only letters
            bool containsNonAlpha = false;
            for (int i = 0; userStringInput[i] != '\0'; i++) {
                if (!isalpha(userStringInput[i])) {
                    containsNonAlpha = true;
                    break;
                }
            }
            if (containsNonAlpha) {
                printf("Invalid input. Please enter a string (letters only, no spaces).\n");
            } else {
                validString = true;
            }
        }
    }
    printf("You entered: %s\n", userStringInput);
    
    // Yay, all the input has been validated! Now you're ready to move on with your code.
    printf("Congratulations! Your input has been validated.\n");
    
    return 0;
}