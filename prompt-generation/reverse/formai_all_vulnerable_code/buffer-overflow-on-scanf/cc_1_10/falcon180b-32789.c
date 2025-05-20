//Falcon-180B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to validate input string
int isValidInput(char *input)
{
    int i = 0;
    while(input[i]!= '\0')
    {
        if(input[i] < 48 || input[i] > 57)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

//Function to calculate factorial
int factorial(int n)
{
    int fact = 1;
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    char input[10];
    int num;

    //Prompt user to enter a number
    printf("Enter a non-negative integer: ");
    scanf("%s", input);

    //Validate user input
    if(!isValidInput(input))
    {
        printf("Error: Input must be a non-negative integer.\n");
        exit(1);
    }

    //Convert input string to integer
    num = atoi(input);

    //Calculate factorial
    if(num < 0)
    {
        printf("Error: Input must be a non-negative integer.\n");
        exit(1);
    }
    else
    {
        int result = factorial(num);
        printf("The factorial of %d is %d.\n", num, result);
    }

    return 0;
}