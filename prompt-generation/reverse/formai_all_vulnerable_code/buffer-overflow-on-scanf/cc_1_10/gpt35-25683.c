//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
/*
  This program demonstrates the basic implementation of a singly linked list 
  in C language. The operations include creating, inserting, deleting, and 
  printing the linked list.
*/

#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the node of the singly linked list
struct node
{
    int data;
    struct node *next;
};

// Function to create a new node with the given data
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the start of the linked list
struct node *insert_at_beginning(struct node *head, int data)
{
    struct node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    printf("\n%d inserted at the beginning of the linked list.\n", data);
    return head;
}

// Function to insert a node at the end of the linked list
struct node *insert_at_end(struct node *head, int data)
{
    struct node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("\n%d inserted at the end of the linked list.\n", data);
    return head;
}

// Function to insert a node at a specified position in the linked list
struct node *insert_at_position(struct node *head, int data, int position)
{
    struct node *new_node = create_node(data);
    if (head == NULL)
    {
        head = new_node;
        printf("\n%d inserted at the beginning of the empty linked list.\n", data);
    }
    else
    {
        if (position == 1)
        {
            new_node->next = head;
            head = new_node;
            printf("\n%d inserted at position %d of the linked list.\n", data, position);
        }
        else
        {
            struct node *temp = head;
            int count = 1;
            while (temp != NULL && count < position - 1)
            {
                temp = temp->next;
                count++;
            }
            if (temp == NULL)
            {
                printf("\nInvalid position! Maximum allowed position is %d.\n", count);
            }
            else
            {
                new_node->next = temp->next;
                temp->next = new_node;
                printf("\n%d inserted at position %d of the linked list.\n", data, position);
            }
        }
    }
    return head;
}

// Function to delete a node with the given data from the linked list
struct node *delete_node(struct node *head, int data)
{
    if (head == NULL)
    {
        printf("\nThe linked list is empty. Nothing to delete!\n");
    }
    else
    {
        struct node *temp = head, *prev = NULL;
        while (temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("\n%d is not present in the linked list. Nothing to delete!\n", data);
        }
        else
        {
            if (prev == NULL)
            {
                head = head->next;
            }
            else
            {
                prev->next = temp->next;
            }
            printf("\n%d deleted from the linked list.\n", data);
            free(temp);
        }
    }
    return head;
}

// Function to print the linked list
void print_linked_list(struct node *head)
{
    if (head == NULL)
    {
        printf("\nThe linked list is empty. Nothing to print!\n");
    }
    else
    {
        printf("\nThe linked list is: ");
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main()
{
    struct node *head = NULL;   // Initializing an empty linked list
    int choice, data, position; // Variables for storing user input
    printf("Singly Linked List Operations\n");
    printf("----------------------------\n");
    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete a node\n");
        printf("5. Print the linked list\n");
        printf("6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted at the beginning: ");
            scanf("%d", &data);
            head = insert_at_beginning(head, data);
            break;
        case 2:
            printf("\nEnter the data to be inserted at the end: ");
            scanf("%d", &data);
            head = insert_at_end(head, data);
            break;
        case 3:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position where the data should be inserted: ");
            scanf("%d", &position);
            head = insert_at_position(head, data, position);
            break;
        case 4:
            printf("\nEnter the data to be deleted: ");
            scanf("%d", &data);
            head = delete_node(head, data);
            break;
        case 5:
            print_linked_list(head);
            break;
        case 6:
            printf("\nExiting the program!\n");
            exit(0);
        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }
    return 0;
}