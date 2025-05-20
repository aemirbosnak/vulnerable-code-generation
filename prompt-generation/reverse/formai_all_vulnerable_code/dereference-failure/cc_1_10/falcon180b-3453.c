//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the size of the key and the alphabet
#define KEY_SIZE 16
#define ALPHABET_SIZE 26

// Define the alphabet
char alphabet[ALPHABET_SIZE] = "abcdefghijklmnopqrstuvwxyz";

// Define the function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    // Initialize the key
    int key_index = 0;
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = tolower(key[i]);
    }

    // Initialize the alphabet
    char* alphabet_copy = malloc(ALPHABET_SIZE);
    strcpy(alphabet_copy, alphabet);

    // Loop through the input file
    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        // Check if the character is a letter
        if (isalpha(ch)) {
            // Find the index of the character in the alphabet
            int index = tolower(ch) - 'a';

            // Find the index of the key character
            int key_char_index = key_index % KEY_SIZE;
            key_index++;

            // Encrypt the character
            char encrypted_ch = alphabet_copy[index + key_char_index];

            // Write the encrypted character to the output file
            fputc(encrypted_ch, output_file);
        } else {
            // Write the non-letter character to the output file
            fputc(ch, output_file);
        }
    }

    // Free the alphabet copy
    free(alphabet_copy);
}

// Define the main function
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt the file
    encrypt_file(input_file, output_file, argv[3]);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}