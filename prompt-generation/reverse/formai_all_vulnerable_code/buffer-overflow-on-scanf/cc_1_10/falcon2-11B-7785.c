//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Linked List Node Structure
struct Node
{
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head)
{
    struct Node* temp = head;
    while (temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = (*head);
    (*head) = newNode;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to delete a node
void deleteNode(struct Node** head, int data)
{
    struct Node* temp = *head;
    struct Node* prev = *head;
    if (*head!= NULL && (*head)->data == data)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to reverse the linked list
void reverseList(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    struct Node* head = NULL;
    int choice, data;
    printf("Linked List Operations\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Delete a Node\n");
    printf("4. Reverse the Linked List\n");
    printf("5. Display Linked List\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;
        case 4:
            reverseList(&head);
            break;
        case 5:
            displayList(head);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid Choice\n");
    }
    return 0;
}