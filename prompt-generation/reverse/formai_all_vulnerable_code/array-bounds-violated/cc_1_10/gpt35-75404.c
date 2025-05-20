//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100];
    int i, j = 0;
    
    printf("Welcome to the Text Processor! \n");
    
    printf("Enter the text you want to process: ");
    fgets(input, sizeof(input), stdin); // Read input from user
    
    // Remove duplicate spaces
    for (i = 0; i < strlen(input); i++) {
        if (!(input[i] == ' ' && input[i+1] == ' ')) { // Ignore if two spaces are found in a row
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // End the processed string with null character
    
    printf("\nProcessed text: %s\n", output);
    
    // Find the most frequent character in the input string
    int counter[256] = {0}; // Initialize each index to 0
    
    for (i = 0; i < strlen(input); i++) {
        counter[(int)input[i]]++; // Increment count of the corresponding ASCII value
    }
    
    int max_count = 0;
    char max_char;
    
    for (i = 0; i < 256; i++) {
        if (counter[i] > max_count) {
            max_count = counter[i];
            max_char = (char)i;
        }
    }
    
    printf("\nMost frequent character: %c\n", max_char);
    
    // Convert the input string to uppercase
    for (i = 0; i < strlen(input); i++) {
        output[i] = toupper(input[i]); // Use toupper function to convert to uppercase
    }
    
    printf("\nUppercased text: %s\n", output);
    
    return 0; // Exit the program
}