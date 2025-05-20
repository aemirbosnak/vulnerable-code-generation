//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: medieval
/*
 * A medieval-style file encrypter in C
 *
 * This program encrypts a file using a simple substitution cipher.
 * The cipher is based on the letter values of the letters in the alphabet.
 * The program takes a file as input and outputs the encrypted file.
 * The key is a string of letters that is used to encrypt the file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

void encrypt_file(FILE *in_file, FILE *out_file, const char *key) {
    char ch;
    int i = 0;

    while ((ch = fgetc(in_file)) != EOF) {
        // If the character is a letter, encrypt it
        if (ch >= 'A' && ch <= 'Z') {
            // Calculate the new character value
            int new_val = (ch + key[i]) % 26;
            // Write the new character to the output file
            fputc(new_val + 'A', out_file);
            // Increment the key index
            i = (i + 1) % strlen(key);
        } else {
            // If the character is not a letter, write it to the output file unchanged
            fputc(ch, out_file);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        printf("Error opening input file %s\n", argv[1]);
        return 1;
    }

    // Open the output file
    FILE *out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        printf("Error opening output file %s\n", argv[2]);
        return 1;
    }

    // Encrypt the file
    encrypt_file(in_file, out_file, argv[3]);

    // Close the input and output files
    fclose(in_file);
    fclose(out_file);

    return 0;
}