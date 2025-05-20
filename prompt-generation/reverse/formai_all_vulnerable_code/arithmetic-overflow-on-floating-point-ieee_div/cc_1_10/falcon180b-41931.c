//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int is_empty(char *s)
{
    return (s[0] == '\0');
}

void clear_buffer(char *s)
{
    strcpy(s, "");
}

void append_char(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}

void print_buffer(char *s)
{
    printf("%s", s);
}

int main()
{
    char buffer[MAX_LEN];
    clear_buffer(buffer);
    double num1, num2, result;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (op)
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
            if (num2 == 0)
            {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    sprintf(buffer, "%.2lf", result);
    print_buffer(buffer);

    return 0;
}