//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1024];
    long int num = 0;
    long int i = 0;
    long int flag = 0;
    long int is_prime = 0;

    printf("Enter a binary number: ");
    scanf("%s", str);

    // Check for valid input
    if (strlen(str) > 10)
    {
        printf("Error: Input too long.\n");
        exit(1);
    }

    // Iterate over the input string
    while (str[i] != '\0')
    {
        // Convert character to integer
        int digit = str[i] - '0';

        // Check if digit is valid
        if (digit < 0 || digit > 1)
        {
            printf("Error: Invalid digit.\n");
            exit(1);
        }

        // Calculate the contribution of the digit
        int contribution = digit * pow(2, i);

        // Add the contribution to the total number
        num += contribution;

        // Increment the index
        i++;
    }

    // Check if the number is prime
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }

    // Print the results
    if (flag == 0)
    {
        printf("The number %ld is prime.\n", num);
    }
    else
    {
        printf("The number %ld is not prime.\n", num);
    }

    return 0;
}