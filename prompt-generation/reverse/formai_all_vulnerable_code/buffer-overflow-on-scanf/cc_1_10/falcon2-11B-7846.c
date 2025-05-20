//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[50];
    int email[50];
    struct node *next;
} node;

node *head = NULL;

void add_node(char *name, char *email)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(temp->name, name);
    strcpy(temp->email, email);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *current = head;
        while (current->next!= NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

void remove_node(char *name)
{
    node *current = head;
    node *prev = NULL;
    while (current!= NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void display_list()
{
    node *current = head;
    while (current!= NULL)
    {
        printf("%s : %s\n", current->name, current->email);
        current = current->next;
    }
}

int main()
{
    char name[50], email[50];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter email: ");
    scanf("%s", email);
    add_node(name, email);
    display_list();
    return 0;
}