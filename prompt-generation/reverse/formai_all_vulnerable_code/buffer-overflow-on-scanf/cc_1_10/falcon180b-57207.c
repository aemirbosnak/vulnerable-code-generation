//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void addNode(struct node** head, int data) {
    struct node* newNode = createNode(data);
    struct node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

// Function to delete a node from the list
void deleteNode(struct node** head, int data) {
    struct node* temp = *head;
    struct node* prev = NULL;
    if (temp!= NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    return;
}

// Function to search for a node in the list
struct node* searchNode(struct node* head, int data) {
    struct node* temp = head;
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return NULL;
    }
    return temp;
}

// Function to print the list
void printList(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

// Driver code
int main() {
    struct node* head = NULL;
    int choice, data;
    while (1) {
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Search node\n");
        printf("4. Print list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                struct node* result = searchNode(head, data);
                if (result!= NULL) {
                    printf("Node found\n");
                } else {
                    printf("Node not found\n");
                }
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}