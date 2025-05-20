//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

int main()
{
    Node* head = NULL;

    char operator;
    float number1, number2;

    printf("Enter an operator (+, -, *, /, %): ");
    scanf("%c", &operator);

    printf("Enter the first number: ");
    scanf("%f", &number1);

    printf("Enter the second number: ");
    scanf("%f", &number2);

    switch (operator)
    {
        case '+':
            insertAtTail(&head, number1 + number2);
            break;
        case '-':
            insertAtTail(&head, number1 - number2);
            break;
        case '*':
            insertAtTail(&head, number1 * number2);
            break;
        case '/':
            if (number2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                insertAtTail(&head, number1 / number2);
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    printf("The result is: ");

    for (Node* current = head; current; current = current->next)
    {
        printf("%f ", current->data);
    }

    printf("\n");

    return 0;
}