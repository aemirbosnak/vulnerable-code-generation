//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 1024

// Function to compress the input string
void compress(char* input_string, char* output_string) {
    int i, j, count = 0;
    char temp[MAX_STRING_LENGTH];

    // Initialize the output string with the first character of input string
    strcpy(output_string, input_string[0]);
    count++;

    // Compare the adjacent characters of input string
    for(i = 1; i < strlen(input_string); i++) {
        // If the current character is same as the previous character, increment the count
        if(input_string[i] == input_string[i-1]) {
            count++;
        }
        // Otherwise, update the output string with the current character and reset the count
        else {
            strcat(output_string, input_string[i]);
            count = 1;
        }
    }

    // Add the count of repeated characters to the output string
    sprintf(temp, "%d", count);
    strcat(output_string, temp);
}

// Function to decompress the compressed string
void decompress(char* compressed_string, char* decompressed_string) {
    int i, j, count = 0;
    char temp[MAX_STRING_LENGTH];

    // Initialize the decompressed string with the first character of compressed string
    strcpy(decompressed_string, compressed_string[0]);
    count++;

    // Compare the adjacent characters of compressed string
    for(i = 1; i < strlen(compressed_string); i++) {
        // If the current character is a digit, increment the count
        if(compressed_string[i] >= '0' && compressed_string[i] <= '9') {
            count = count * (compressed_string[i] - '0');
        }
        // Otherwise, update the decompressed string with the current character
        else {
            strcat(decompressed_string, compressed_string[i]);
        }
    }

    // Add the repeated characters to the decompressed string
    for(i = 0; i < count; i++) {
        strcat(decompressed_string, decompressed_string[strlen(decompressed_string)-1]);
    }
}

int main() {
    char input_string[MAX_STRING_LENGTH], compressed_string[MAX_STRING_LENGTH], decompressed_string[MAX_STRING_LENGTH];

    // Get the input string from user
    printf("Enter the input string: ");
    scanf("%s", input_string);

    // Compress the input string
    compress(input_string, compressed_string);
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string
    decompress(compressed_string, decompressed_string);
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}