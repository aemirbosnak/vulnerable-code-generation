//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to compress the input string
void compress(char input[], char output[], int *output_size) {
    int i, j, count = 1;
    char temp[100];

    // Initialize the output string with the first character of the input string
    strcpy(output, input);

    // Loop through the input string
    for(i = 1; input[i]!= '\0'; i++) {
        // Check if the current character is the same as the previous character
        if(input[i] == input[i-1]) {
            // If yes, increment the count
            count++;
        } else {
            // If no, reset the count and add the character to the output string
            count = 1;
            strcat(output, &input[i]);
        }
    }

    // Add the count to the output string
    sprintf(temp, "%d", count);
    strcat(output, temp);

    // Set the output size
    *output_size = strlen(output);
}

int main() {
    char input[100], output[200];
    int output_size;

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output, &output_size);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    char decompressed[200];
    int i, j;
    for(i = 0, j = 0; i < output_size; i++) {
        if(output[i] >= '0' && output[i] <= '9') {
            int count = output[i] - '0';
            while(count-- > 0) {
                decompressed[j++] = input[i-1];
            }
        } else {
            decompressed[j++] = output[i];
        }
    }
    decompressed[j] = '\0';

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}