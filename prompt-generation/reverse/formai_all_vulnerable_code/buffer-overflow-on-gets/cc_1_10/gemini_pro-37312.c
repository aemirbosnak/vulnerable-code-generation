//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to compress the string using LZW algorithm
char *compress(char *str) {
    // Create a dictionary to store the codes for each substring
    int dict_size = 256;
    char **dict = malloc(sizeof(char *) * dict_size);
    for (int i = 0; i < 256; i++) {
        dict[i] = malloc(sizeof(char) * 2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Create a string to store the compressed data
    char *compressed = malloc(sizeof(char) * MAX_SIZE);
    int compressed_len = 0;

    // Iterate over the input string
    int curr_code = 256;
    int curr_len = 0;
    char *curr_str = malloc(sizeof(char) * MAX_SIZE);
    for (int i = 0; i < strlen(str); i++) {
        // Check if the current character is already in the dictionary
        int found = 0;
        for (int j = 0; j < dict_size; j++) {
            if (strcmp(dict[j], curr_str) == 0) {
                found = 1;
                break;
            }
        }

        // If the current character is not in the dictionary, add it to the dictionary
        if (!found) {
            dict[curr_code] = malloc(sizeof(char) * (curr_len + 2));
            strcpy(dict[curr_code], curr_str);
            dict[curr_code][curr_len] = str[i];
            dict[curr_code][curr_len + 1] = '\0';
            curr_code++;
        }

        // Add the code for the current character to the compressed data
        compressed[compressed_len++] = curr_code;

        // Update the current substring and its length
        curr_str[curr_len++] = str[i];
        curr_str[curr_len] = '\0';
    }

    // Free the memory allocated for the dictionary and the current substring
    for (int i = 0; i < dict_size; i++) {
        free(dict[i]);
    }
    free(dict);
    free(curr_str);

    // Return the compressed data
    return compressed;
}

// Function to decompress the string using LZW algorithm
char *decompress(char *compressed) {
    // Create a dictionary to store the codes for each substring
    int dict_size = 256;
    char **dict = malloc(sizeof(char *) * dict_size);
    for (int i = 0; i < 256; i++) {
        dict[i] = malloc(sizeof(char) * 2);
        dict[i][0] = i;
        dict[i][1] = '\0';
    }

    // Create a string to store the decompressed data
    char *decompressed = malloc(sizeof(char) * MAX_SIZE);
    int decompressed_len = 0;

    // Iterate over the compressed data
    int curr_code = 256;
    int curr_len = 0;
    char *curr_str = malloc(sizeof(char) * MAX_SIZE);
    for (int i = 0; i < strlen(compressed); i++) {
        // Get the code for the current character from the compressed data
        int code = compressed[i];

        // Check if the code is already in the dictionary
        int found = 0;
        for (int j = 0; j < dict_size; j++) {
            if (dict[j][0] == code) {
                found = 1;
                break;
            }
        }

        // If the code is not in the dictionary, add it to the dictionary
        if (!found) {
            dict[curr_code] = malloc(sizeof(char) * (curr_len + 2));
            strcpy(dict[curr_code], curr_str);
            dict[curr_code][curr_len] = curr_str[0];
            dict[curr_code][curr_len + 1] = '\0';
            curr_code++;
        }

        // Append the substring corresponding to the code to the decompressed data
        strcat(decompressed, dict[code]);
        decompressed_len += strlen(dict[code]);

        // Update the current substring and its length
        curr_str[curr_len++] = dict[code][0];
        curr_str[curr_len] = '\0';
    }

    // Free the memory allocated for the dictionary and the current substring
    for (int i = 0; i < dict_size; i++) {
        free(dict[i]);
    }
    free(dict);
    free(curr_str);

    // Return the decompressed data
    return decompressed;
}

// Main function
int main() {
    // Get the input string from the user
    char str[MAX_SIZE];
    printf("Enter the string to compress: ");
    gets(str);

    // Compress the string using LZW algorithm
    char *compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string using LZW algorithm
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}