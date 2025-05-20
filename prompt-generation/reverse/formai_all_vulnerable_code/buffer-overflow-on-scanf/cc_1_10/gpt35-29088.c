//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *createNode(int);
void insertAtBeginning(Node **, int);
void insertAtEnd(Node **, int);
void insertAtPosition(Node **, int, int);
void deleteAtBeginning(Node **);
void deleteAtEnd(Node **);
void deleteAtPosition(Node **, int);
void traverseList(Node *);

int main()
{
    Node *head = NULL;
    int choice, position, data;

    do
    {
        printf("\n================================\n");
        printf(" Linked List Operations\n");
        printf("================================\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at a position\n");
        printf("7. Traverse the list\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter data to be inserted at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("\nEnter data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("\nEnter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("\nEnter the position of the node to be deleted: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                traverseList(head);
                break;
            case 8:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again...\n");
        }
    } while (choice != 8);

    return 0;
}

Node *createNode(int data)
{
    Node *newNode = (Node *) malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed, exiting program...\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertAtPosition(Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position, please try again...\n");
        return;
    }

    if (position == 1)
    {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);
    Node *temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position, please try again...\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning(Node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty, nothing to delete...\n");
        return;
    }

    Node *temp = *head;

    *head = (*head)->next;
    free(temp);

    printf("\nNode deleted successfully...\n");
}

void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("\nList is empty, nothing to delete...\n");
        return;
    }

    Node *temp = *head;

    if ((*head)->next == NULL)
    {
        *head = NULL;
        free(temp);

        printf("\nNode deleted successfully...\n");
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("\nNode deleted successfully...\n");
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("\nList is empty, nothing to delete...\n");
        return;
    }

    if (position < 1)
    {
        printf("\nInvalid position, please try again...\n");
        return;
    }

    Node *temp = *head;

    if (position == 1)
    {
        *head = (*head)->next;
        free(temp);

        printf("\nNode deleted successfully...\n");
        return;
    }

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
    {
        printf("\nInvalid position, please try again...\n");
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    printf("\nNode deleted successfully...\n");
}

void traverseList(Node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty...\n");
        return;
    }

    printf("\nThe list is: ");
    Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}