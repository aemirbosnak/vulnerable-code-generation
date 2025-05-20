//FormAI DATASET v1.0 Category: Binary Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

void to_binary(char *bin, int num); // Function prototype to convert decimal to binary
void reverse(char *s); // Function prototype to reverse a string
void clear_buffer(); // Function prototype to clear input buffer

int main()
{
    char input[BUF_SIZE]; // Input buffer to store user input
    int num; // Decimal to be converted to binary
    char binary[BUF_SIZE]; // String to store binary representation of num

    printf("Enter a decimal number to convert to binary: ");
    fgets(input, BUF_SIZE, stdin); // Read user input from stdin

    // Remove trailing newline character
    if (input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    // Convert string input to integer
    num = atoi(input);

    // Convert decimal to binary and store in binary string
    to_binary(binary, num);

    // Print binary representation of num
    printf("Binary representation of %d is: %s\n", num, binary);

    return 0;
}

void to_binary(char *bin, int num)
{
    int i, j;
    char temp[BUF_SIZE];

    // Convert decimal to binary by repeated division by 2
    for (i = 0; num > 0; i++)
    {
        temp[i] = num % 2 + '0'; // '0' or '1'
        num = num / 2;
    }

    // Null terminate binary string
    temp[i] = '\0';

    // Reverse binary string and store in bin
    reverse(temp);
    strcpy(bin, temp);
}

void reverse(char *s)
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void clear_buffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}