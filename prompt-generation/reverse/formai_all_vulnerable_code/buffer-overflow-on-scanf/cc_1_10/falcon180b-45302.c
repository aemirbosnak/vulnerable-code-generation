//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using Run Length Encoding
void compress(char* input, char* output) {
    int i, j, count = 1;
    char temp[100];

    // Copy the first character as it is
    strcpy(output, input);
    output += strlen(output);

    // Encode the remaining string
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '\0') {
            break;
        }
        if (i == 0 || input[i]!= input[i-1]) {
            temp[0] = input[i];
            temp[1] = '\0';
            strcat(output, temp);
        }
        else {
            count++;
        }
    }

    // Add the count for the last character
    if (count > 1) {
        sprintf(temp, "%d%c", count, input[i]);
        strcat(output, temp);
    }
}

// Function to decompress the input string using Run Length Encoding
void decompress(char* input, char* output) {
    int i, j, count = 0;
    char temp[100];

    // Copy the first character as it is
    strcpy(output, input);
    output += strlen(output);

    // Decode the remaining string
    for (i = strlen(input) - 1; i >= 0; i--) {
        if (input[i] == '\0') {
            break;
        }
        if (input[i] == '%') {
            temp[0] = input[++i];
            temp[1] = '\0';
            count = atoi(temp);
            i += sprintf(temp, "%c", input[i]);
            strncat(output, temp, strlen(temp));
        }
        else {
            strncat(output, &input[i], 1);
        }
    }
}

int main() {
    char input[100], output[200];

    // Get the input string from the user
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Display the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Display the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}