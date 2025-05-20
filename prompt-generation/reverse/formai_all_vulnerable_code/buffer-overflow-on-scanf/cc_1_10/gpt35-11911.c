//FormAI DATASET v1.0 Category: Mailing list manager ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node { // defining a structure 'node' to create a linked list
    char email[50];
    struct node *next; // a pointer that points to the next node
}node;

node *head=NULL; // defining head as NULL, which means initially there's no node

void add_email(char email[50]) // function to add an email to the linked list
{
    node *temp=(node*)malloc(sizeof(node)); //create a new node 
    strcpy(temp->email,email); // copy the email to the new node
    temp->next=head; // make the new node point to the next node
    head=temp; // move the head position to the new node
}

void delete_email(char email[50]) // function to delete an email from the linked list
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->email,email)==0) // if the email matches
        {
            temp->email[0]='\0'; // delete the email from the node
            printf("Email deleted successfully!\n");
            return;
        }
        temp=temp->next; // move to the next node
    }
    printf("Email not found.\n"); // if the email is not present in the linked list
}

void display_emails() // function to display all the emails in the linked list
{
    node *temp=head;
    if(temp==NULL)
    {
        printf("No emails to display.\n"); // if there are no emails in the linked list 
        return;
    }
    printf("Emails:\n");
    while(temp!=NULL)
    {
        printf("%s\n",temp->email); //display the email
        temp=temp->next; // move to the next node
    }
}

int main()
{
    int choice;
    char email[50];
    do
    {
        printf("1. Add an email\n");
        printf("2. Delete an email\n");
        printf("3. Display all emails\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the email: ");
                    scanf("%s",email);
                    add_email(email);
                    break;
            case 2: printf("Enter the email to be deleted: ");
                    scanf("%s",email);
                    delete_email(email);
                    break;
            case 3: display_emails();
                    break;
            case 4: printf("Exiting program...\n");
                    exit(0);
            default: printf("Invalid choice.\n");
        }
    }while(choice!=4);
    return 0;
}