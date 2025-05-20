//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char temp[100];

    // Copy the input string to temp
    strcpy(temp, input);

    // Initialize count to 1
    int count = 1;

    // Loop through the input string
    for (i = 0; i < strlen(temp); i++) {
        // If the current character matches the previous character
        if (temp[i] == temp[i - 1]) {
            // Increment the count
            count++;
        }
        // If the count is greater than 1
        else if (count > 1) {
            // Append the count to the output string
            sprintf(output + j, "%d%c", count, temp[i - 1]);
            // Reset the count
            count = 1;
        }
        // If the count is 1
        else {
            // Append the current character to the output string
            output[j++] = temp[i];
        }
    }

    // Append the last character to the output string
    output[j++] = temp[i - 1];

    // Append a null character to the output string
    output[j] = '\0';
}

int main() {
    char input[100], output[100];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    return 0;
}