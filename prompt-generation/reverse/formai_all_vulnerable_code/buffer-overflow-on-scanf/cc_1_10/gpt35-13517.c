//FormAI DATASET v1.0 Category: Linked list operations ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure for Linked List
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to insert a new node at the beginning of the Linked List
Node* insertNode(Node *head, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning of the Linked List\n", data);
    return head;
}

// Function to insert a new node at the end of the Linked List
Node* appendNode(Node *head, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at the end of the Linked List\n", data);
    }
    else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("Inserted %d at the end of the Linked List\n", data);
    }
    return head;
}

// Function to delete a node from the Linked List
Node* deleteNode(Node *head, int data) {
    if (head == NULL) {
        printf("The Linked List is empty\n");
        return NULL;
    }
    else if (head->data == data) {
        Node *temp = head;
        head = head->next;
        printf("Deleted %d from the Linked List\n", data);
        free(temp);
        return head;
    }
    else {
        Node *temp = head->next, *prev = head;
        while (temp != NULL && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("%d is not present in the Linked List\n", data);
            return head;
        }
        else {
            prev->next = temp->next;
            printf("Deleted %d from the Linked List\n", data);
            free(temp);
            return head;
        }
    }
}

// Function to print the Linked List
void printList(Node *head) {
    printf("The Linked List is: ");
    if (head == NULL) {
        printf("empty\n");
    }
    else {
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function to perform Linked List operations
int main() {
    Node *head = NULL;
    int option, data;
    do {
        printf("Choose an option:\n");
        printf("1. Insert a new node at the beginning of the Linked List\n");
        printf("2. Insert a new node at the end of the Linked List\n");
        printf("3. Delete a node from the Linked List\n");
        printf("4. Print the Linked List\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = appendNode(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printf("Quitting the program\n");
                break;
            default:
                printf("Invalid choice! Try again\n");
                break;
        }
    } while (option != 5);
    return 0;
}