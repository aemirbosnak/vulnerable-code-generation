//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scientific_calculator()
{
    char input[100];
    char operator[2];
    float number1, number2, result;
    int i, j, flag = 0;

    printf("Enter an expression: ");
    scanf("%s", input);

    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            operator[0] = input[i];
            flag = 1;
        }
    }

    if (flag)
    {
        printf("Invalid operator.\n");
        return;
    }

    number1 = atof(input);
    number2 = atof(input + i + 1);

    switch (operator[0])
    {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 == 0)
            {
                printf("Cannot divide by zero.\n");
                return;
            }
            result = number1 / number2;
            break;
        default:
            printf("Invalid operator.\n");
            return;
    }

    result = round(result);
    printf("The result is: %f\n", result);
}

int main()
{
    scientific_calculator();

    return 0;
}