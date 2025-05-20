//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to add a node at the end of the list
void add_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    struct node *temp = *head;
    if (*head == NULL) {
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to delete a node with given data from the list
void delete_node(struct node **head, int data) {
    struct node *temp = *head, *prev;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with given data in the list
struct node *search_node(struct node *head, int data) {
    struct node *temp = head;
    while (temp!= NULL && temp->data!= data)
        temp = temp->next;
    return temp;
}

// Function to print the list
void print_list(struct node *head) {
    struct node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Add node\n2. Delete node\n3. Search node\n4. Print list\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                add_node(&head, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_node(&head, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                struct node *result = search_node(head, data);
                if (result!= NULL)
                    printf("Node found\n");
                else
                    printf("Node not found\n");
                break;
            case 4:
                printf("List: ");
                print_list(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}