//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the input data
#define MAX_INPUT_SIZE 1000

// Define the maximum size of the output data
#define MAX_OUTPUT_SIZE 500

// Define the maximum number of unique characters
#define MAX_UNIQUE_CHARS 256

// Define the character struct for storing character count and code
struct Character {
    int count;
    char code[MAX_UNIQUE_CHARS];
};

// Define the character frequency array
int charFrequency[MAX_UNIQUE_CHARS];

// Define the character array to store unique characters from input
char uniqueChars[MAX_UNIQUE_CHARS];

// Define the character array to store the compressed data
char compressedData[MAX_OUTPUT_SIZE];

// Define the bit position tracker
int bitPosition = 0;

// Define the write bit function
void writeBit(bool bit) {
    // Check if we are at a byte boundary
    if (bitPosition == 8) {
        // Write the byte to the compressed data array
        compressedData[bitPosition / 8 - 1] = (char) (compressedData[bitPosition / 8 - 1] | (1 << (7 - ((bitPosition - 1) % 8))));

        // Reset the bit position
        bitPosition = 1;
    } else {
        // Write the bit to the compressed data array
        compressedData[bitPosition / 8] = (char) (compressedData[bitPosition / 8] | (bit << (7 - ((bitPosition - 1) % 8))));

        // Increment the bit position
        bitPosition++;
    }
}

// Define the compress function
void compress(char *inputData) {
    // Initialize the unique character count to 0
    int uniqueCharCount = 0;

    // Iterate over the input data to get character frequency
    for (int i = 0; i < strlen(inputData); i++) {
        // Increment the character frequency count
        charFrequency[inputData[i]]++;

        // Check if the character is unique
        if (charFrequency[inputData[i]] == 1) {
            // Add the unique character to the unique character array
            uniqueChars[uniqueCharCount++] = inputData[i];
        }
    }

    // Define the character frequency array
    struct Character charCounts[uniqueCharCount];

    // Initialize the character count and code arrays
    for (int i = 0; i < uniqueCharCount; i++) {
        struct Character *charStruct = &charCounts[i];
        charStruct->count = charFrequency[uniqueChars[i]];
        for (int j = 0; j < MAX_UNIQUE_CHARS; j++) {
            charStruct->code[j] = '\0';
        }
    }

    // Sort the character count array in descending order
    for (int i = 0; i < uniqueCharCount; i++) {
        for (int j = i + 1; j < uniqueCharCount; j++) {
            if (charCounts[i].count < charCounts[j].count) {
                struct Character temp = charCounts[i];
                charCounts[i] = charCounts[j];
                charCounts[j] = temp;
            }
        }
    }

    // Generate the Huffman codes for each unique character
    int code = 0;
    for (int i = 0; i < uniqueCharCount; i++) {
        struct Character *charStruct = &charCounts[i];
        int thisCharFrequency = charStruct->count;

        // Calculate the binary code for this character
        for (int j = 0; j < thisCharFrequency; j++) {
            int charIndex = (code >> j) & 1;
            charStruct->code[thisCharFrequency - j - 1] = charIndex + '0';
        }

        // Increment the code for the next character
        code++;
    }

    // Write the Huffman codes for each character to the compressed data array
    for (int i = 0; i < strlen(inputData); i++) {
        char thisChar = inputData[i];
        for (int j = 0; j < uniqueCharCount; j++) {
            if (uniqueChars[j] == thisChar) {
                char *codeString = charCounts[j].code;
                for (int k = 0; k < strlen(codeString); k++) {
                    int bit = codeString[k] - '0';
                    writeBit(bit);
                }
                break;
            }
        }
    }

    // Add the null terminator to the compressed data array
    compressedData[bitPosition / 8] = '\0';
}

// Define the main function
int main() {
    // Get the input data from the user
    char inputData[MAX_INPUT_SIZE];
    printf("Enter the data to compress: ");
    fgets(inputData, MAX_INPUT_SIZE, stdin);

    // Compress the input data
    compress(inputData);

    // Output the compressed data
    printf("Compressed data: %s\n", compressedData);

    return 0;
}