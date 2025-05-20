//FormAI DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The compression function
void compress(char *input_string) {
    int length = strlen(input_string);
    int i, j, count;
    char current_char;

    // Loop through the input string
    for(i = 0; i < length; i++) {
        current_char = input_string[i];
        count = 1;

        // Check if the current character is repeated
        for(j = i + 1; j < length; j++) {
            if(input_string[j] != current_char)
                break;
            count++;
        }

        // If the character is repeated, compress it
        if(count > 1) {
            // Remove the repeated characters
            memmove(&input_string[i], &input_string[i + count - 1], length - i - count + 1);

            // Add the count of the repeated characters
            char count_str[10];
            sprintf(count_str, "%d", count);
            input_string[i] = current_char;
            strcat(input_string, count_str);

            // Update the length of the input string
            length = strlen(input_string);
        }
    }

    printf("Compressed string: %s\n", input_string);
}

// The main function to test the compression algorithm
int main() {
    char input_string[100];

    // Get the input string from the user
    printf("Enter the string to compress: ");
    scanf("%s", input_string);

    // Compress the string
    compress(input_string);

    return 0;
}