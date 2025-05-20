//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char symbol;
    struct node *next;
}node;

node *front = NULL;
node *rear = NULL;

void push(char c)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->symbol = c;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void pop()
{
    if(front == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    node *temp = front;
    front = front->next;
    free(temp);
}

void display()
{
    if(front == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    node *temp = front;
    while(temp!= NULL)
    {
        printf("%c", temp->symbol);
        temp = temp->next;
        if(temp!= NULL)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int c;
    while(1)
    {
        printf("Enter a character: ");
        scanf("%c", &c);
        push(c);
        if(c == '*')
            break;
    }
    display();
    pop();
    return 0;
}