//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program calculates the checksum value for a given string using the Cyclic Redundancy Check (CRC) algorithm.

// Define the generator polynomial value (CRC-16/CCITT-FALSE standard)
#define POLY 0x1021

// Function that performs the CRC calculation
unsigned short crc_calc(const unsigned char *data, int len)
{
    unsigned short crc = 0;

    for (int i = 0; i < len; i++) 
    {
        crc ^= (data[i] << 8);
        for (int b = 0; b < 8; b++) 
        {
            if ((crc & 0x8000) != 0)
                crc ^= POLY;

            crc <<= 1;
        }
    }

    return crc;
}

int main()
{
    char input[100];

    // Prompt the user for input and read it
    printf("Enter a string to calculate its checksum:\n");
    fgets(input, 100, stdin);

    // Remove the newline character from the input (if present)
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // Calculate the checksum value for the input string
    unsigned short checksum = crc_calc((const unsigned char *)input, strlen(input));

    // Print the input string and its checksum value
    printf("\nInput string: %s\n", input);
    printf("Checksum value: %04X\n", checksum);

    return 0;
}