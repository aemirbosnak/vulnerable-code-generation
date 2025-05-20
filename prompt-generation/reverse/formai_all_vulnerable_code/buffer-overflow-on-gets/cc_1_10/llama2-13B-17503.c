//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_OPERands 5
#define MAX_EXPR_LEN 20

// Global variables
int num1, num2, res;
char op[MAX_OPERands][20];

void get_ops(void);
void evaluate(void);

int main(void)
{
    // Initialize variables
    printf("Welcome to the Retro Arithmetic Machine!\n");
    printf("Enter two numbers and an operation (+, -, *, /, or ^): ");
    gets(op[0]); gets(op[1]);

    // Parse the input
    if (strcmp(op[0], "+") == 0)
    {
        num1 = atoi(op[1]);
        num2 = atoi(op[2]);
        evaluate();
    }
    else if (strcmp(op[0], "-") == 0)
    {
        num1 = atoi(op[1]);
        num2 = atoi(op[2]);
        evaluate();
    }
    else if (strcmp(op[0], "*") == 0)
    {
        num1 = atoi(op[1]);
        num2 = atoi(op[2]);
        evaluate();
    }
    else if (strcmp(op[0], "/") == 0)
    {
        num1 = atoi(op[1]);
        num2 = atoi(op[2]);
        evaluate();
    }
    else if (strcmp(op[0], "^") == 0)
    {
        num1 = atoi(op[1]);
        num2 = atoi(op[2]);
        evaluate();
    }
    else
    {
        printf("Invalid operation. Please try again.\n");
        main();
    }

    return 0;
}

void get_ops(void)
{
    printf("Enter two numbers and an operation (+, -, *, /, or ^): ");
    gets(op[0]); gets(op[1]);
}

void evaluate(void)
{
    if (op[0][0] == '+')
    {
        res = num1 + num2;
    }
    else if (op[0][0] == '-')
    {
        res = num1 - num2;
    }
    else if (op[0][0] == '*')
    {
        res = num1 * num2;
    }
    else if (op[0][0] == '/')
    {
        res = num1 / num2;
    }
    else if (op[0][0] == '^')
    {
        res = num1 ^ num2;
    }

    printf("Result: %d\n", res);
}