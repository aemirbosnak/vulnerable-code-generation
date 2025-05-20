//FormAI DATASET v1.0 Category: Mailing list manager ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node //structure to store email addresses
{
    char email[100];
    struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;

void addEmailAddress(char email[]) //function to add email to the mailing list
{
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp->email,email);
    temp->next = NULL;

    if(head == NULL) //if the mailing list is empty
    {
        head = temp;
        return;
    }

    Node* p = head;
    while(p->next != NULL) //traversing until the last node
    {
        p = p->next;
    }

    p->next = temp; //adding the node at the end of the list
}

void removeEmailAddress(char email[]) //function to remove email from the mailing list
{
    Node* p = head;
    Node* prev = NULL;

    while(p != NULL)
    {
        if(strcmp(p->email,email) == 0) //if the email matches
        {
            if(prev == NULL) //if the email is the first node
            {
                head = p->next;
                free(p);
                return;
            }
            else //for all other nodes except the first node
            {
                prev->next = p->next;
                free(p);
                return;
            }
        }

        prev = p;
        p = p->next;
    }
}

void displayMailingList() //function to display the mailing list
{
    printf("\nThe Mailing List is:\n");
    Node* p = head;

    while(p != NULL)
    {
        printf("%s\n",p->email);
        p = p->next;
    }
}

int main()
{
    printf("\n*********Welcome to the Mailing List Manager*********\n");

    while(1)
    {
        printf("\n\nChoose an action:\n1. Add Email Address\n2. Remove Email Address\n3. Display Mailing List\n4. Exit\n");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                char email[100];
                printf("\nEnter the Email Address: ");
                scanf("%s",email);
                addEmailAddress(email);
                printf("\nEmail Address added successfully!");
                break;
            }

            case 2:
            {
                char email[100];
                printf("\nEnter the Email Address you want to remove: ");
                scanf("%s",email);
                removeEmailAddress(email);
                printf("\nEmail Address removed successfully!");
                break;
            }

            case 3:
            {
                displayMailingList();
                break;
            }

            case 4:
            {
                printf("\nThank you for using the Mailing List Manager!");
                exit(0);
            }

            default:
            {
                printf("\nInvalid Choice! Please choose again.");
            }
        }
    }

    return 0;
}