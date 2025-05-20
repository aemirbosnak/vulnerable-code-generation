//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void convert(int num)
{
    int i = 0;
    char binary[MAX];

    while (num)
    {
        int digit = num % 2;
        num /= 2;
        binary[i++] = digit + '0';
    }

    binary[i] = '\0';
    printf("%s", binary);
}

int main()
{
    int num1, num2;
    char operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    int result = 0;

    switch (operator)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
    }

    convert(result);
    printf("\nThe result is: ");

    return 0;
}