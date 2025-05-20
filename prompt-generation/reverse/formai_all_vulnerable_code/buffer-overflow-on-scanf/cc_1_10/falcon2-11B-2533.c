//Falcon2-11B DATASET v1.0 Category: Phone Book ; Style: romantic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct node
{
    char name[50];
    char number[20];
    struct node *next;
}node;

node *head=NULL;

void insert(char *name, char *number)
{
    node *temp=malloc(sizeof(node));
    strcpy(temp->name, name);
    strcpy(temp->number, number);
    temp->next=head;
    head=temp;
}

void search(char *name)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->name, name)==0)
        {
            printf("Name: %s\nNumber: %s\n", temp->name, temp->number);
            break;
        }
        temp=temp->next;
    }
}

void delete(char *name)
{
    node *temp=head;
    node *prev=NULL;
    while(temp!=NULL)
    {
        if(strcmp(temp->name, name)==0)
        {
            if(prev==NULL)
            {
                head=temp->next;
                free(temp);
                break;
            }
            else
            {
                prev->next=temp->next;
                free(temp);
                break;
            }
        }
        prev=temp;
        temp=temp->next;
    }
}

void display()
{
    node *temp=head;
    while(temp!=NULL)
    {
        printf("Name: %s\nNumber: %s\n", temp->name, temp->number);
        temp=temp->next;
    }
}

int main()
{
    char name[50], number[20], ch;
    while(1)
    {
        printf("Enter 'i' to insert a name and number,'s' to search a name, 'd' to delete a name, 'l' to list all names, 'q' to quit: ");
        scanf("%c", &ch);
        if(ch=='i')
        {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter number: ");
            scanf("%s", number);
            insert(name, number);
        }
        else if(ch=='s')
        {
            printf("Enter name to search: ");
            scanf("%s", name);
            search(name);
        }
        else if(ch=='d')
        {
            printf("Enter name to delete: ");
            scanf("%s", name);
            delete(name);
        }
        else if(ch=='l')
        {
            display();
        }
        else if(ch=='q')
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}