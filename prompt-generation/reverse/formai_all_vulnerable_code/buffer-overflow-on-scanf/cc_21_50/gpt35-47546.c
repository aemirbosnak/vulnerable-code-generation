//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input file
#define MAX_SIZE 1000

// Define the maximum size of the compressed file
#define COMP_SIZE 500

// Define the maximum number of occurrences for each character
#define MAX_COUNT 255

// Define the structure for holding character counts and compressed bits
typedef struct
{
    unsigned char count;
    char bits[MAX_COUNT];
} CharacterInfo;

// Define the structure for holding compressed data
typedef struct
{
    unsigned char data[COMP_SIZE];
    unsigned char size;
} CompressedData;

// Define the main function
int main()
{
    // Declare variables
    char fileName[1000];
    FILE *inputFile;
    int i, j, count;
    unsigned char character;
    unsigned char buffer[MAX_SIZE];
    CharacterInfo charInfo[MAX_COUNT];
    CompressedData compData;

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", fileName);

    // Open the input file
    inputFile = fopen(fileName, "rb");
    if (inputFile == NULL)
    {
        printf("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    // Read the input file into a buffer
    fread(buffer, sizeof(char), MAX_SIZE, inputFile);

    // Close the input file
    fclose(inputFile);

    // Initialize the character counts to zero
    for (i = 0; i < MAX_COUNT; i++)
    {
        charInfo[i].count = 0;

        // Initialize the compressed bits to an empty string
        for (j = 0; j < MAX_COUNT; j++)
            charInfo[i].bits[j] = '\0';
    }

    // Count the occurrences of each character in the buffer
    count = strlen(buffer);
    for (i = 0; i < count; i++)
        charInfo[buffer[i]].count++;

    // Create a binary tree for the characters based on their count
    while (1)
    {
        // Find the two characters with the lowest count
        int min1 = MAX_COUNT, min2 = MAX_COUNT;
        for (i = 0; i < MAX_COUNT; i++)
        {
            if (charInfo[i].count > 0 && charInfo[i].count < charInfo[min1].count)
                min1 = i;

            if (charInfo[i].count > 0 && charInfo[i].count < charInfo[min2].count && i != min1)
                min2 = i;
        }

        // If there are no characters left, exit the loop
        if (min2 == MAX_COUNT)
            break;

        // Combine the two characters into a single entry with a new count
        charInfo[min1].count += charInfo[min2].count;

        // Assign 0 to the first character and 1 to the second character in the compressed bits
        for (i = 0; i < MAX_COUNT; i++)
        {
            if (charInfo[min1].bits[i] == '\0' && charInfo[min2].bits[i] != '\0')
                charInfo[min1].bits[i] = '0' + charInfo[min2].bits[i];
            else if (charInfo[min1].bits[i] == '\0' && charInfo[min2].bits[i] == '\0')
                break;
        }

        // Set the count of the second character to 0 and clear its compressed bits
        charInfo[min2].count = 0;
        for (i = 0; i < MAX_COUNT; i++)
            charInfo[min2].bits[i] = '\0';
    }

    // Compress the input file using the binary tree
    compData.size = 0;
    compData.data[0] = 0;
    for (i = 0; i < count; i++)
    {
        // Get the compressed bits for the current input character
        strcpy(compData.data + compData.size, charInfo[buffer[i]].bits);
        compData.size += strlen(charInfo[buffer[i]].bits);

        // Output the compressed data to the console if the buffer is full or at the end of the file
        if (compData.size >= COMP_SIZE || i == count - 1)
        {
            for (j = 0; j < compData.size; j += 8)
                printf("%c", strtol(compData.data + j, NULL, 2));
            compData.data[0] = 0;
            compData.size = 0;
        }
    }

    return 0;
}