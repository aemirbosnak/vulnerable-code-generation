//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Our secret key, shhh!
const char KEY = 'k';

int main() {
    // Cheerfully greet the user
    printf("Howdy, let's encrypt some files like a jolly band of pirates!\n");

    // Prompt the user for the file to encrypt
    char filename[100];
    printf("Avast, matey! What be the name of the file ye be wantin' to encrypt?\n");
    scanf("%s", filename);

    // Open the file for reading
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Shiver me timbers! I can't find that file, matey.\n");
        return 1;
    }

    // Prompt the user for the output file
    char output[100];
    printf("Now, tell me the name of the treasure chest ye be wantin' to store the encrypted file in.\n");
    scanf("%s", output);

    // Open the output file for writing
    FILE *output_file = fopen(output, "wb");
    if (output_file == NULL) {
        printf("Avast! I can't write to that file, matey.\n");
        return 1;
    }

    // Read the input file byte by byte and encrypt it
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        // Perform the encryption with our secret key
        ch = (ch + KEY) % 256;

        // Write the encrypted byte to the output file
        fputc(ch, output_file);
    }

    // Close the files and bid the user farewell
    fclose(input);
    fclose(output_file);
    printf("Well shiver me timbers! Ye be now the proud owner of an encrypted file. May it bring ye great riches!\n");

    return 0;
}