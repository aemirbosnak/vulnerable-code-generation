//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void to_hex(int num);         // function prototype

int main()
{
    int num;                // initialize variable to hold decimal integer
    char hex[100];          // initialize character array to hold hexadecimal equivalent
    char input[100];        // initialize character array to hold user input

    printf("Enter a decimal integer: ");
    fgets(input, 100, stdin);   // get user input as a string and store in input array

    // remove newline character from input array
    if (input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';

    // check if input is a valid decimal integer
    int valid = 1;
    for (int i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid input! Please enter a decimal integer.\n");
            valid = 0;
            break;
        }
    }

    // if input is valid, convert to integer and call to_hex function
    if (valid)
    {
        num = atoi(input);      // convert input to integer
        printf("Decimal: %d\n", num);
        printf("Hexadecimal: ");
        to_hex(num);            // call to_hex function
        printf("\n");
    }

    return 0;
}

// function to convert decimal integer to hexadecimal equivalent
void to_hex(int num) {
    char hex[100];          // initialize character array to hold hexadecimal equivalent

    // loop through each hexadecimal digit and append to hex array
    int i = 0;
    while (num != 0)
    {
        int rem = num % 16;
        if (rem < 10)
            hex[i++] = rem + 48;
        else
            hex[i++] = rem + 55;
        num /= 16;
    }

    // print hexadecimal equivalent in reverse order
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}