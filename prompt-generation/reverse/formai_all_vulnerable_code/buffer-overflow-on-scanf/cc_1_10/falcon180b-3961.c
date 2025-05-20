//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include<stdio.h>

//Function to evaluate the expression
float evaluate(char expression[])
{
    float result = 0;
    int i = 0;
    char op = expression[0];
    while(op!= '\0')
    {
        if(op == '+' || op == '-' || op == '*' || op == '/')
        {
            result += expression[i] - '0';
            i++;
        }
        else
        {
            result += expression[i] - '0';
        }
        op = expression[i];
        i++;
    }
    return result;
}

//Function to evaluate the postfix expression
float evaluatePostfix(char postfix[])
{
    float result = 0;
    int i = 0;
    while(postfix[i]!= '\0')
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            result += postfix[i] - '0';
        }
        else
        {
            float num1 = evaluate(postfix + i + 1);
            float num2 = result;
            result = 0;
            if(postfix[i] == '+')
            {
                result = num1 + num2;
            }
            else if(postfix[i] == '-')
            {
                result = num1 - num2;
            }
            else if(postfix[i] == '*')
            {
                result = num1 * num2;
            }
            else if(postfix[i] == '/')
            {
                result = num1 / num2;
            }
            i += 2;
        }
        i++;
    }
    return result;
}

int main()
{
    char equation[100], postfix[100];
    int i = 0, j = 0;
    printf("Enter the equation: ");
    scanf("%s", equation);
    while(equation[i]!= '\0')
    {
        if(equation[i] >= 'a' && equation[i] <= 'z')
        {
            postfix[j] = equation[i];
            j++;
        }
        else if(equation[i] >= '0' && equation[i] <= '9')
        {
            postfix[j] = equation[i];
            j++;
        }
        else if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/')
        {
            postfix[j] = equation[i];
            j++;
        }
        i++;
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    float result = evaluatePostfix(postfix);
    printf("Result: %f", result);
    return 0;
}