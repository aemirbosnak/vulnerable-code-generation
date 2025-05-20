//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct node* insertAtBeginning(struct node* head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a new node at the end of the list
struct node* insertAtEnd(struct node* head, int data) {
    struct node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    struct node* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    return head;
}

// Function to insert a new node at a specified position
struct node* insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = createNode(data);
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    struct node* curr = head;
    int count = 1;
    while(count < position-1 && curr != NULL) {
        curr = curr->next;
        count++;
    }
    if(curr == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Function to delete the first node
struct node* deleteAtBeginning(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node
struct node* deleteAtEnd(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    }
    struct node* curr = head;
    while(curr->next->next != NULL) {
        curr = curr->next;
    }
    struct node* temp = curr->next;
    curr->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node from a specified position
struct node* deleteAtPosition(struct node* head, int position) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if(position == 1) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node* curr = head;
    int count = 1;
    while(count < position-1 && curr != NULL) {
        curr = curr->next;
        count++;
    }
    if(curr == NULL || curr->next == NULL) {
        printf("Invalid position\n");
        return head;
    }
    struct node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

// Function to display the linked list
void displayList(struct node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* curr = head;
    printf("List: ");
    while(curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, data, position;
    struct node* head = NULL;
    while(1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: // Insert at beginning
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2: // Insert at end
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3: // Insert at position
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4: // Delete at beginning
                head = deleteAtBeginning(head);
                break;
            case 5: // Delete at end
                head = deleteAtEnd(head);
                break;
            case 6: // Delete at position
                printf("Enter the position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7: // Display list
                displayList(head);
                break;
            case 8: // Exit
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}