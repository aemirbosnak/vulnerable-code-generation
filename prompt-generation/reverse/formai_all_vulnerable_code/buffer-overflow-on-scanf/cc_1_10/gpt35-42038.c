//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structure for the stack nodes
typedef struct Node 
{
    double data;
    struct Node* next;
} Node;

// function prototypes
Node* createNode(double data);
int isEmpty(Node* top);
void push(Node** top, double data);
double pop(Node** top);

// main calculator function
double calculator(char* expression)
{
    Node* stack = NULL;        // initialize the stack
    int i, len;
    double num1, num2, result;
    char ch;

    len = strlen(expression);  // get the length of expression

    for(i=0; i<len; i++)
    {
        ch = expression[i];

        // if character is a digit or decimal point, push onto stack
        if(isdigit(ch) || ch=='.')
        {
            char buffer[16] = "";
            int j = 0;
            while(isdigit(ch) || ch=='.')
            {
                buffer[j++] = ch;
                ch = expression[++i];
            }
            double number = atof(buffer);
            push(&stack, number);
        }

        // if character is an operator, pop two numbers from stack and perform operation
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
        {
            num1 = pop(&stack);
            num2 = pop(&stack);
            switch(ch)
            {
                case '+': result = num2 + num1; break;
                case '-': result = num2 - num1; break;
                case '*': result = num2 * num1; break;
                case '/': result = num2 / num1; break;
                case '^': result = pow(num2, num1); break;
            }
            push(&stack, result);
        }
    }
    return pop(&stack);     // return the final result
}

// function to create new node
Node* createNode(double data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to check if stack is empty
int isEmpty(Node* top)
{
    if(top == NULL)
        return 1;
    else
        return 0;
}

// function to push data onto stack
void push(Node** top, double data)
{
    Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// function to pop data from stack
double pop(Node** top)
{
    double data;
    Node* temp;

    if(isEmpty(*top))
    {
        printf("Error: stack is empty\n");
        return 0;
    }
    else
    {
        temp = *top;
        data = temp->data;
        *top = (*top)->next;
        free(temp);
        return data;
    }
}

// main function
int main()
{
    char expression[100];

    printf("Enter your expression: ");
    scanf("%s", expression);

    double result = calculator(expression);

    printf("Result: %lf\n", result);

    return 0;
}