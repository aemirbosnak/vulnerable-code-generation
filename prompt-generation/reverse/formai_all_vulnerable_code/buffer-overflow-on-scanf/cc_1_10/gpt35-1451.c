//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char email[50];
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;
} LinkedList;

// function to create a new linked list
LinkedList *createLinkedList()
{
    LinkedList *l = (LinkedList*)malloc(sizeof(LinkedList));
    l->head = NULL;
    l->size = 0;
    return l;
}

// function to check if a given email is already in the list
int search(LinkedList *l, char email[])
{
    Node *ptr = l->head;
    while (ptr != NULL)
    {
        if (strcmp(ptr->email, email) == 0)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

// function to insert a new email into the list
void insert(LinkedList *l, char email[])
{
    if (search(l, email))
    {
        printf("Email already exists in list.\n");
        return;
    }
    else
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        strcpy(newNode->email, email);
        newNode->next = NULL;
        if (l->head == NULL)
        {
            l->head = newNode;
        }
        else
        {
            Node *ptr = l->head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        l->size++;
        printf("Email added successfully.\n");
    }
}

// function to delete an email from the list
void delete(LinkedList *l, char email[])
{
    if (l->head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (strcmp(l->head->email, email) == 0)
    {
        Node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        l->size--;
        printf("Email deleted successfully.\n");
        return;
    }
    Node *ptr = l->head;
    Node *prev = NULL;
    while (ptr != NULL)
    {
        if (strcmp(ptr->email, email) == 0)
        {
            prev->next = ptr->next;
            free(ptr);
            l->size--;
            printf("Email deleted successfully.\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Email not found in list.\n");
}

// function to print all emails in the list
void printList(LinkedList *l)
{
    if (l->head == NULL)
        printf("List is empty.\n");
    else
    {
        Node *ptr = l->head;
        while (ptr != NULL)
        {
            printf("%s\n", ptr->email);
            ptr = ptr->next;
        }
    }
}

int main()
{
    // create a new linked list
    LinkedList *l = createLinkedList();

    // loop to display menu and get user input
    int choice;
    char email[50];
    do
    {
        printf("Mailing List Manager:\n");
        printf("1. Add an email\n");
        printf("2. Delete an email\n");
        printf("3. View all emails\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                insert(l, email);
                break;
            case 2:
                printf("Enter email to delete: ");
                scanf("%s", email);
                delete(l, email);
                break;
            case 3:
                printf("All emails in list:\n");
                printList(l);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}