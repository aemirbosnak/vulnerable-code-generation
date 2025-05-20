//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char operator;
    double number1, number2, result;
    int i, flag = 0;

    printf("Enter an expression: ");
    scanf("%s", buffer);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            operator = buffer[i];
            number1 = atof(buffer[i - 1] - '0');
            number2 = atof(buffer[i - 2] - '0');

            switch (operator)
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
                        printf("Cannot divide by zero\n");
                        flag = 1;
                    }
                    else
                    {
                        result = number1 / number2;
                    }
                    break;
            }

            if (flag == 0)
            {
                printf("The result is: %.2lf\n", result);
            }
        }
    }

    return 0;
}