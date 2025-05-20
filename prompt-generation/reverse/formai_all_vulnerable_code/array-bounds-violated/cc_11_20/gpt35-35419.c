//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char original_text[500] = ""; // Declare an empty string to hold user input
    printf("Please enter some text:\n");
    fgets(original_text, sizeof(original_text), stdin); // Get user input
    
    // Remove newline character from input string
    int length = strlen(original_text);
    if (original_text[length-1] == '\n') {
        original_text[length-1] = '\0';
    }
    
    // Convert input string to uppercase and print to console
    printf("Your input in uppercase: ");
    for (int i = 0; original_text[i] != '\0'; i++) {
        printf("%c", toupper(original_text[i]));
    }
    
    printf("\n"); // Print newline separator
    
    // Convert input string to lowercase and print to console
    printf("Your input in lowercase: ");
    for (int i = 0; original_text[i] != '\0'; i++) {
        printf("%c", tolower(original_text[i]));
    }
    
    printf("\n"); // Print newline separator
    
    // Count number of vowels in input string and print to console
    int num_vowels = 0;
    for (int i = 0; original_text[i] != '\0'; i++) {
        char current_char = tolower(original_text[i]); // Convert characters to lowercase for simplicity in checking vowels
        if (current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u') {
            num_vowels++;
        }
    }
    printf("The number of vowels in your input is: %d\n", num_vowels);
    
    // Reverse input string and print to console
    char reversed_text[500] = "";
    for (int i = length-1; i >= 0; i--) {
        strncat(reversed_text, &original_text[i], 1);
    }
    printf("Your input, reversed: %s\n", reversed_text);
    
    return 0;
}