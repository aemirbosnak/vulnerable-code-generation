//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Turing
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

//Function to push an element onto the stack
void push(double *stack, int *top, double value)
{
    if(*top == MAX_SIZE-1)
        printf("\nStack Overflow!");
    else
    {
        (*top)++;
        stack[*top] = value;
    }
}

//Function to pop an element from the stack
double pop(double *stack, int *top)
{
    double value = stack[*top];
    (*top)--;
    return value;
}

//Function to perform arithmetic operations
double operation(double num1, double num2, char operator)
{
    double result = 0;
    switch(operator)
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
            if(num2!= 0)
                result = num1 / num2;
            else
            {
                printf("\nDivision by zero is not allowed!");
                exit(0);
            }
            break;
    }
    return result;
}

//Function to evaluate a postfix expression
double evaluate_postfix(char *expression)
{
    double stack[MAX_SIZE];
    int top = -1;
    int i = 0;
    while(expression[i]!= '\0')
    {
        if(isdigit(expression[i]))
        {
            push(stack, &top, atof(&expression[i]));
            i++;
        }
        else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            double num2 = pop(stack, &top);
            double num1 = pop(stack, &top);
            push(stack, &top, operation(num1, num2, expression[i]));
        }
        i++;
    }
    return pop(stack, &top);
}

int main()
{
    char expression[MAX_SIZE];
    printf("\nEnter a postfix expression: ");
    scanf("%s", expression);
    double result = evaluate_postfix(expression);
    printf("\nThe result is: %lf", result);
    return 0;
}