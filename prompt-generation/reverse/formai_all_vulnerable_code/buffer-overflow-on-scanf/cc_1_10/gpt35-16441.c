//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the C String Manipulation Program!\n\n");
    
    // Prompt user for input string
    char input[100];
    printf("Please enter a string: ");
    fgets(input, 100, stdin);
    strtok(input, "\n"); // Remove newline character from input
    
    printf("\nThank you! You entered '%s'.\n\n", input);
    
    // Determine length of input string
    int length = strlen(input);
    printf("The length of your string is %d.\n\n", length);
    
    // Reverse input string
    char reverse[100];
    for (int i = 0; i < length; i++) {
        reverse[length - i - 1] = input[i];
    }
    reverse[length] = '\0'; // Terminate string
    
    printf("Here is your string reversed: '%s'.\n\n", reverse);
    
    // Convert input string to uppercase
    char uppercase[100];
    for (int i = 0; i < length; i++) {
        uppercase[i] = toupper(input[i]);
    }
    uppercase[length] = '\0'; // Terminate string
    
    printf("Here is your string in uppercase: '%s'.\n\n", uppercase);
    
    // Convert input string to lowercase
    char lowercase[100];
    for (int i = 0; i < length; i++) {
        lowercase[i] = tolower(input[i]);
    }
    lowercase[length] = '\0'; // Terminate string
    
    printf("Here is your string in lowercase: '%s'.\n\n", lowercase);
    
    // Replace all occurrences of a character in input string
    char replace;
    printf("Please enter a character to replace in your string: ");
    scanf("%c", &replace);
    getchar(); // Remove extra newline character from buffer
    
    char replaced[100];
    int num_replaced = 0;
    for (int i = 0; i < length; i++) {
        if (input[i] == replace) {
            replaced[i] = '*';
            num_replaced++;
        }
        else {
            replaced[i] = input[i];
        }
    }
    replaced[length] = '\0'; // Terminate string
    
    printf("Here is your string with all occurrences of '%c' replaced with '*': '%s'.\n", replace, replaced);
    printf("Number of characters replaced: %d.\n\n", num_replaced);
    
    // Determine if input string is a palindrome
    int is_palindrome = 1; // Assume input string is a palindrome
    for (int i = 0; i < length / 2; i++) {
        if (input[i] != input[length - i - 1]) {
            is_palindrome = 0; // Input string is not a palindrome
            break;
        }
    }
    
    if (is_palindrome) {
        printf("Congratulations, your string is a palindrome!\n\n");
    }
    else {
        printf("Sorry, your string is not a palindrome.\n\n");
    }
    
    printf("Thank you for using the C String Manipulation Program! I hope you have a great day!\n\n");
    
    return 0;
}