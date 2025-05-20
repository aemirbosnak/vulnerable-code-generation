//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a decimal number to binary
char *decimalToBinary(int n)
{
    // Check if the number is negative
    if (n < 0)
    {
        printf("Error: The number must be non-negative.\n");
        return NULL;
    }

    // Create a buffer to store the binary representation
    int bufferSize = 33; // 32 bits for the binary representation + 1 for the null terminator
    char *buffer = (char *)malloc(bufferSize * sizeof(char));

    // Initialize the buffer to all zeros
    memset(buffer, '0', bufferSize);

    // Convert the number to binary by repeatedly dividing by 2 and storing the remainders
    int index = bufferSize - 2;
    while (n > 0)
    {
        buffer[index--] = (n % 2) + '0';
        n /= 2;
    }

    // Add the null terminator to the end of the buffer
    buffer[bufferSize - 1] = '\0';

    // Return the binary representation
    return buffer;
}

// Function to convert a binary number to decimal
int binaryToDecimal(char *binary)
{
    // Check if the string is a valid binary number
    for (int i = 0; binary[i] != '\0'; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Error: The string is not a valid binary number.\n");
            return -1;
        }
    }

    // Convert the binary number to decimal by multiplying each bit by the appropriate power of 2 and adding the results
    int decimal = 0;
    int power = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--)
    {
        decimal += (binary[i] - '0') * power;
        power *= 2;
    }

    // Return the decimal representation
    return decimal;
}

// Function to print the usage of the program
void printUsage()
{
    printf("Usage:\n");
    printf("binary_converter [option] [number]\n");
    printf("Options:\n");
    printf("  -b: Convert decimal to binary\n");
    printf("  -d: Convert binary to decimal\n");
    printf("Examples:\n");
    printf("  binary_converter -b 10 -> 1010\n");
    printf("  binary_converter -d 1010 -> 10\n");
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the user provided enough arguments
    if (argc < 3)
    {
        printUsage();
        return 1;
    }

    // Get the option and the number from the arguments
    char *option = argv[1];
    int number;
    sscanf(argv[2], "%d", &number);

    // Convert the number based on the option
    char *result;
    if (strcmp(option, "-b") == 0)
    {
        result = decimalToBinary(number);
    }
    else if (strcmp(option, "-d") == 0)
    {
        result = binaryToDecimal(argv[2]);
    }
    else
    {
        printf("Error: Invalid option.\n");
        printUsage();
        return 1;
    }

    // Print the result
    if (result != NULL)
    {
        printf("Result: %s\n", result);
    }

    // Free the allocated memory
    free(result);

    return 0;
}