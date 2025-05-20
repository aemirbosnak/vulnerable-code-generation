//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 100

int top = -1;
char stack[MAX];

void push(char c)
{
    if(top >= MAX - 1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}

char pop()
{
    if(top < 0)
    {
        printf("Stack Underflow\n");
        return 'M';
    }
    else
    {
        char x = stack[top];
        top--;
        return x;
    }
}

int priority(char c)
{
    if(c == '(')
    {
        return 0;
    }
    else if(c == '+' || c == '-')
    {
        return 1;
    }
    else if(c == '*' || c == '/')
    {
        return 2;
    }
    else if(c == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

float evaluatePostfix(char *postfix)
{
    float stack[MAX];
    int top = -1;
    int i = 0;

    while(postfix[i] != '\0')
    {
        if(postfix[i] <= '9' && postfix[i] >= '0')
        {
            float num = 0;
            while(postfix[i] <= '9' && postfix[i] >= '0')
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            if(postfix[i] == '.')
            {
                i++; 
            }
            float decimal = 1;
            while(postfix[i] <= '9' && postfix[i] >= '0')
            {
                decimal = decimal / 10;
                num = num + (postfix[i] - '0') * decimal;
                i++;
            }
            stack[++top] = num;
        }
        else
        {
            float val1 = stack[top--];
            float val2 = stack[top--];

            switch(postfix[i])
            {
                case '+':
                    stack[++top] = val2 + val1;
                    break;
                case '-':
                    stack[++top] = val2 - val1;
                    break;
                case '*':
                    stack[++top] = val2 * val1;
                    break;
                case '/':
                    stack[++top] = val2 / val1;
                    break;
                case '^':
                    stack[++top] = pow(val2, val1);
                    break;
            }
            i++;
        }
    }
    return stack[top--];
}

float calculate(char* expression)
{
    char postfix[MAX];
    int i = 0, j = 0;

    while(expression[i] != '\0')
    {
        if(expression[i] == ' ')
        {
            i++;
            continue;
        }
        else if(expression[i] == '(')
        {
            push(expression[i]);
        }
        else if(expression[i] == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            stack[top] = pop();
        }
        else if(expression[i] <= '9' && expression[i] >= '0' || expression[i] == '.')
        {
            while(expression[i] <= '9' && expression[i] >= '0' || expression[i] == '.')
            {
                postfix[j++] = expression[i++];
            }
            postfix[j++] = ' ';
            i--;
        }
        else
        {
            while(priority(stack[top]) >= priority(expression[i]))
            {
                postfix[j++] = pop();
            }
            push(expression[i]);
        }
        i++;
    }

    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return evaluatePostfix(postfix);
}

int main()
{
    char input[MAX];
    float result;

    printf("Enter an arithmetic expression: ");
    fgets(input, MAX, stdin);
    result = calculate(input);

    printf("The result is: %.2f",result);

    return 0;
}