//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 25

typedef struct Node
{
    char character;
    struct Node* next;
} Node;

void insert(struct Node** head, char character)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->character = character;
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
    struct Node* head = NULL;

    char command[MAX_CHAR];
    printf("Enter a command: ");
    scanf("%s", command);

    for (int i = 0; command[i] != '\0'; i++)
    {
        insert(&head, command[i]);
    }

    printf("Your command is: ");
    for (struct Node* node = head; node; node = node->next)
    {
        printf("%c ", node->character);
    }

    printf("\n");

    return 0;
}