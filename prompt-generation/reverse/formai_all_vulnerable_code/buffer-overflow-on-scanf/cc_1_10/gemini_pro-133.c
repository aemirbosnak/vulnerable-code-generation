//GEMINI-pro DATASET v1.0 Category: Binary Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style
#define BITS_PER_BYTE 8
#define MAX_BINARY_LENGTH 1024

// Function to convert a binary string to an integer
int binary_to_int(char *binary)
{
    int i, len, power, num;

    len = strlen(binary);
    num = 0;
    power = 1;

    for (i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
        {
            num += power;
        }
        power *= 2;
    }

    return num;
}

// Function to convert an integer to a binary string
char *int_to_binary(int num)
{
    int i, len, temp;
    char *binary;

    binary = malloc(MAX_BINARY_LENGTH);

    i = 0;
    temp = num;

    while (temp > 0)
    {
        binary[i] = (temp % 2) + '0';
        temp /= 2;
        i++;
    }

    binary[i] = '\0';

    // Reverse the binary string
    len = strlen(binary);

    for (i = 0; i < len / 2; i++)
    {
        char temp = binary[i];
        binary[i] = binary[len - i - 1];
        binary[len - i - 1] = temp;
    }

    return binary;
}

// Main function
int main()
{
    int num;
    char binary[MAX_BINARY_LENGTH];

    // Get the input number
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Convert the integer to binary
    strcpy(binary, int_to_binary(num));

    // Print the binary string
    printf("Binary: %s\n", binary);

    // Convert the binary string to an integer
    num = binary_to_int(binary);

    // Print the integer
    printf("Integer: %d\n", num);

    return 0;
}