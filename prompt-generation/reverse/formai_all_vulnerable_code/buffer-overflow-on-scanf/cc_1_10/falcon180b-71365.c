//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding
void compress(char input[], int *output_size) {
    int i = 0, j = 0, count = 1;
    char *output = (char *) malloc(strlen(input) * sizeof(char));

    // Iterate through the input string
    while (input[i]!= '\0') {
        // If the current character is same as the previous one, increment the count
        if (i > 0 && input[i] == input[i - 1]) {
            count++;
        }
        // If the count is greater than 1 or the current character is different from the previous one, add the character and count to the output string
        else {
            output[j] = input[i];
            j++;
            output[j] = count;
            j++;
            count = 1;
        }
        i++;
    }

    // Add the last character and count to the output string
    output[j] = input[i - 1];
    j++;
    output[j] = count;
    j++;

    // Set the output size and terminate the output string
    *output_size = j;
    output[j] = '\0';
}

// Function to decompress the input string using Run Length Encoding
void decompress(char input[], int input_size, char output[]) {
    int i = 0, j = 0;

    // Iterate through the input string
    while (i < input_size) {
        // If the current character is a number, add the previous character count number of times to the output string
        if (isdigit(input[i])) {
            int count = input[i] - '0';
            while (count > 0 && i < input_size) {
                output[j] = input[i + 1];
                j++;
                count--;
                i++;
            }
        }
        // If the current character is a letter, add it to the output string
        else {
            output[j] = input[i];
            j++;
            i++;
        }
    }

    // Terminate the output string
    output[j] = '\0';
}

int main() {
    char input[1000], output[1000];
    int input_size, output_size;

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, &output_size);
    printf("Compressed string: ");
    for (int i = 0; i < output_size; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    // Decompress the compressed string
    decompress(output, output_size, input);
    printf("Decompressed string: %s\n", input);

    return 0;
}