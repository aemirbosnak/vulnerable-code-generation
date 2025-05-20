//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

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
    char binary[MAX];
    int i, decimal = 0, power = 0, carry = 0;
    Node* head = NULL;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    for (i = strlen(binary) - 1; i >= 0; i--)
    {
        int digit = binary[i] - '0';

        insertAtTail(&head, digit);

        if (digit > carry)
        {
            carry = digit - carry;
            insertAtTail(&head, carry);
        }

        decimal += digit * pow(2, power);
        power++;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}