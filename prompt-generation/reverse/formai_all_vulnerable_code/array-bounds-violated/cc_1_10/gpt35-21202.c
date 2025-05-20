//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000];
    char secret_message[1000];
    int i,j;
    int binary_secret[8];
    int bit_counter = 0;

    printf("Welcome to the Puzzle Image Steganography program!\n\n");

    printf("Please enter a sentence to hide a secret message in:\n");
    fgets(sentence, 1000, stdin);
    printf("\n");

    printf("Please enter the secret message (8 characters only):\n");
    fgets(secret_message, 1000, stdin);
    printf("\n");

    // Convert each letter in the secret message to binary
    for (i = 0; i < 8; i++)
    {
        int ascii_val = (int)secret_message[i];
        for (j = 7; j >= 0; j--)
        {
            binary_secret[bit_counter] = (ascii_val >> j) & 1;
            bit_counter++;
        }
    }

    // Iterate through the sentence and hide the secret message
    for (i = 0; i < strlen(sentence); i++)
    {
        if (bit_counter >= 64) // Stop if the whole secret message has been hidden
            break;

        int ascii_val = (int)sentence[i];
        int binary_val[8];

        // Convert the ASCII value of the sentence character to binary
        for (j = 7; j >= 0; j--)
        {
            binary_val[j] = (ascii_val >> j) & 1;
        }

        // Replace the least significant bit with the next bit of the secret message
        for (j = 0; j < 8; j++)
        {
            binary_val[j] = binary_val[j] & 254; // Set the LSB to 0

            if (bit_counter < 64) // Only hide the secret message if there are bits left to hide
            {
                binary_val[j] = binary_val[j] | binary_secret[bit_counter];
                bit_counter++;
            }
        }

        // Convert the binary value back to ASCII and print the character
        int new_ascii_val = 0;
        for (j = 0; j < 8; j++)
        {
            new_ascii_val = new_ascii_val | (binary_val[j] << (7 - j));
        }
        printf("%c", new_ascii_val);
    }
    printf("\n\n");

    return 0;
}