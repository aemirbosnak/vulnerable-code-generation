//FormAI DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct Email
{
    char sender[MAX_BUFFER_SIZE];
    char receiver[MAX_BUFFER_SIZE];
    char subject[MAX_BUFFER_SIZE];
    char body[MAX_BUFFER_SIZE];
} Email;

typedef struct Node
{
    Email data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(Email newEmail)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = newEmail;
    newNode->next = NULL;
    return newNode;
}

void addEmail(Email newEmail)
{
    Node* newNode = createNode(newEmail);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void displayEmails()
{
    Node* temp = head;

    if(temp == NULL)
    {
        printf("No emails found.\n");
        return;
    }

    while(temp != NULL)
    {
        printf("Sender: %s\n", temp->data.sender);
        printf("Receiver: %s\n", temp->data.receiver);
        printf("Subject: %s\n", temp->data.subject);
        printf("Body: %s\n", temp->data.body);
        printf("\n");

        temp = temp->next;
    }
}

void deleteEmail(char subject[])
{
    Node* temp = head;
    Node* prev = NULL;

    if(temp == NULL)
    {
        printf("No emails found.\n");
        return;
    }

    while(temp != NULL && (strcmp(temp->data.subject, subject) != 0))
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Email with subject '%s' not found.\n", subject);
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    printf("Email with subject '%s' deleted successfully.\n", subject);
}

void menu()
{
    int choice;
    Email newEmail;

    do
    {
        printf("1. Add new email.\n");
        printf("2. Display all emails.\n");
        printf("3. Delete an email.\n");
        printf("4. Exit.\n");

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Sender: ");
                scanf("%s", newEmail.sender);

                printf("Receiver: ");
                scanf("%s", newEmail.receiver);

                printf("Subject: ");
                scanf("%s", newEmail.subject);

                printf("Body: ");
                scanf("%s", newEmail.body);

                addEmail(newEmail);
                break;
            case 2:
                displayEmails();
                break;
            case 3:
                printf("Enter the subject of the email to delete: ");
                char subjectToDelete[MAX_BUFFER_SIZE];
                scanf("%s", subjectToDelete);

                deleteEmail(subjectToDelete);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");

    } while(choice != 4);
}

int main()
{
    menu();
    return 0;
}