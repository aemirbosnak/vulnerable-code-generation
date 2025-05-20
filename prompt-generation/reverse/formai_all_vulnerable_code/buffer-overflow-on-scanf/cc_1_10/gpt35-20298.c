//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct Node
{
    char email[50];
    struct Node *next;
}*head = NULL, *tail = NULL;


void add_email(char *email)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    printf("\n%s has been added to the mailing list.", email);
}

void display_emails()
{
    struct Node *temp = head;
    printf("\nEmails in the mailing list are: ");
    while(temp != NULL)
    {
        printf("\n%s", temp->email);
        temp = temp->next;
    }
}

void search_email(char *email)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->email, email) == 0)
        {
            printf("\n%s is in the mailing list.", email);
            return;
        }
        temp = temp->next;
    }
    printf("\n%s is not in the mailing list.", email);
}

void delete_email(char *email)
{
    struct Node *temp = head, *prev = NULL;
    while(temp != NULL)
    {
        if(strcmp(temp->email, email) == 0)
        {
            if(temp == head)
            {
                head = head->next;
            }
            else if(temp == tail)
            {
                prev->next = NULL;
                tail = prev;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("\n%s has been deleted from the mailing list.", email);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("\n%s is not in the mailing list.", email);
}

int check_email(char *email)
{
    int i, at = 0, dot = 0, len = strlen(email);
    if(len == 0 || len > 50)
    {
        return 0; //invalid email
    }
    for(i=0;i<len;i++)
    {
        if(!isalnum(email[i]) && email[i] != '-' && email[i] != '_' && email[i] != '.')
        {
            return 0; //invalid email
        }
        else if(email[i] == '@')
        {
            at++;
        }
        else if(email[i] == '.')
        {
            dot++;
        }
    }
    if(at != 1 || dot == 0)
    {
        return 0; //invalid email
    }
    return 1; //valid email
}

int main()
{
    char email[50], choice;
    printf("Welcome to the Mailing List Manager!\n");
    do
    {
        printf("\nPress 1 to Add an email to the list.\nPress 2 to Display all emails.\nPress 3 to Search for an email in the list.\nPress 4 to Delete an email from the list.\nPress 5 to Exit.\n\nEnter your choice: ");
        scanf(" %c", &choice);
        switch(choice)
        {
            case '1':
                printf("\nEnter the email address: ");
                scanf("%s", email);
                if(check_email(email))
                {
                    add_email(email);
                }
                else
                {
                    printf("\nInvalid email address.");
                }
                break;

            case '2':
                if(head == NULL)
                {
                    printf("\nThe mailing list is empty.");
                }
                else
                {
                    display_emails();
                }
                break;

            case '3':
                printf("\nEnter the email address: ");
                scanf("%s", email);
                search_email(email);
                break;

            case '4':
                printf("\nEnter the email address: ");
                scanf("%s", email);
                delete_email(email);
                break;

            case '5':
                printf("\nExiting the program.\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }
    }while(choice != '5');
    return 0;
}