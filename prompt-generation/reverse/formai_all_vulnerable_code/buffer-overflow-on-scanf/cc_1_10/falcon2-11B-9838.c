//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

struct node
{
    char email[50];
    struct node* next;
};

typedef struct node Node;

void push(Node** head_ref, char email[])
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

void delete_email(Node** head_ref, char email[])
{
    Node* temp = *head_ref;
    Node* prev = NULL;

    while(temp!=NULL && strcmp(temp->email, email)!=0)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL)
        printf("Email not found\n");
    else if(prev==NULL)
        *head_ref = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

int main()
{
    Node* head = NULL;
    char email[50];
    int choice = 1;

    while(choice!=0)
    {
        printf("\n1. Push email\n2. Display mailing list\n3. Delete email\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                push(&head, email);
                break;
            case 2:
                display(head);
                break;
            case 3:
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete_email(&head, email);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}