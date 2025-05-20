//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct node
{
    char name[50];
    int id;
    struct node *next;
};

struct node *head = NULL;

void create(struct node **start_ref, char name[], int id)
{
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    newnode->id = id;
    newnode->next = (*start_ref);
    (*start_ref) = newnode;
}

void display(struct node *start)
{
    struct node *last;
    printf("\nName\tID\n");
    while (start!= NULL)
    {
        printf("%s\t%d\n", start->name, start->id);
        last = start;
        start = start->next;
    }
}

void search(struct node *start, char name[])
{
    struct node *current = start;
    while (current!= NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            printf("\nID of %s is %d", name, current->id);
            return;
        }
        current = current->next;
    }
    printf("\n%s not found", name);
}

int main()
{
    struct node *start = NULL;
    int choice, id;
    char name[50];

    while (1)
    {
        printf("\n1.Create\n2.Display\n3.Search\n4.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Name: ");
                scanf("%s", name);
                printf("\nEnter ID: ");
                scanf("%d", &id);
                create(&start, name, id);
                break;

            case 2:
                display(start);
                break;

            case 3:
                printf("\nEnter Name to Search: ");
                scanf("%s", name);
                search(start, name);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice");
        }
    }
    return 0;
}