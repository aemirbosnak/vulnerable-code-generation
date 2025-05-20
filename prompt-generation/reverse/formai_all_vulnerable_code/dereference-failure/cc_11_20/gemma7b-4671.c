//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char keylog[1024];

void recordKeystroke(char key)
{
    strcat(keylog, key);
    system("/bin/flush");
    sleep(1);
}

int main()
{
    char buffer[256];
    int i, j, flag = 0, result = 0;
    char operator;

    system("/bin/clear");

    printf("Enter your calculator expression: ");
    fgets(buffer, 256, stdin);

    for (i = 0; buffer[i] != '\0'; i++)
    {
        switch (buffer[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                recordKeystroke(buffer[i]);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                operator = buffer[i];
                flag = 1;
                break;
            case '=':
                recordKeystroke('='), result = calculate(buffer);
                printf("Result: %d\n", result);
                flag = 1;
                break;
        }
    }

    if (flag == 0)
    {
        printf("Invalid expression.\n");
    }

    return 0;
}

int calculate(char *expr)
{
    int i, num1, num2, result = 0;
    char operator;

    for (i = 0; expr[i] != '\0'; i++)
    {
        switch (expr[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                num1 = num1 * 10 + expr[i] - '0';
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                operator = expr[i];
                break;
            case '=':
                num2 = num2 * 10 + expr[i - 1] - '0';
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
                return result;
        }
    }

    return result;
}