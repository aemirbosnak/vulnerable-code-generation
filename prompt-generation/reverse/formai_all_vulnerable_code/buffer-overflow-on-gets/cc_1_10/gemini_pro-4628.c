//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

// Function to compress a string using LZW algorithm
char* compress(char* str) {
    // Create a dictionary to store the compressed codes
    int dict_size = 256;
    char* dict[dict_size];
    for (int i = 0; i < dict_size; i++) {
        dict[i] = (char*) malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Create a string to store the compressed code
    char* compressed_str = (char*) malloc(MAX_STR_LEN);
    int compressed_len = 0;

    // Iterate over the input string
    int curr_code = 0;
    int prev_code = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if the current character is already in the dictionary
        int code = -1;
        for (int j = 0; j < dict_size; j++) {
            if (strcmp(dict[j], str + i) == 0) {
                code = j;
                break;
            }
        }

        // If the current character is not in the dictionary, add it to the dictionary
        if (code == -1) {
            code = dict_size++;
            dict[code] = (char*) malloc(strlen(str + i) + 1);
            strcpy(dict[code], str + i);
        }

        // If the current code is different from the previous code, add the previous code to the compressed string
        if (code != prev_code) {
            compressed_str[compressed_len++] = prev_code;
            prev_code = code;
        }
    }

    // Add the last code to the compressed string
    compressed_str[compressed_len++] = prev_code;

    // Return the compressed string
    return compressed_str;
}

// Function to decompress a string using LZW algorithm
char* decompress(char* compressed_str) {
    // Create a dictionary to store the decompressed codes
    int dict_size = 256;
    char* dict[dict_size];
    for (int i = 0; i < dict_size; i++) {
        dict[i] = (char*) malloc(2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Create a string to store the decompressed string
    char* decompressed_str = (char*) malloc(MAX_STR_LEN);
    int decompressed_len = 0;

    // Iterate over the compressed string
    int curr_code = 0;
    int prev_code = -1;
    for (int i = 0; compressed_str[i] != '\0'; i++) {
        // Get the current code
        curr_code = compressed_str[i];

        // If the current code is not in the dictionary, add it to the dictionary
        if (curr_code >= dict_size) {
            dict[dict_size] = (char*) malloc(strlen(dict[prev_code]) + strlen(dict[curr_code - prev_code]));
            strcpy(dict[dict_size], dict[prev_code]);
            strcat(dict[dict_size], dict[curr_code - prev_code]);
            dict_size++;
        }

        // Add the decompressed code to the decompressed string
        strcat(decompressed_str, dict[curr_code]);

        // Update the previous code
        prev_code = curr_code;
    }

    // Return the decompressed string
    return decompressed_str;
}

int main() {
    // Get the input string from the user
    char str[MAX_STR_LEN];
    printf("Enter the string to be compressed: ");
    gets(str);

    // Compress the string
    char* compressed_str = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_str);

    // Decompress the string
    char* decompressed_str = decompress(compressed_str);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_str);

    // Free the allocated memory
    free(compressed_str);
    free(decompressed_str);

    return 0;
}