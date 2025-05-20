//FormAI DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

// Node structure to represent each element in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert a node at a given position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    struct Node* previous = NULL;
    int currentPos = 1;
    while(currentPos < position && temp != NULL) {
        previous = temp;
        temp = temp->next;
        currentPos++;
    }
    if(position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    if(temp == NULL) {
        previous->next = newNode;
        return head;
    }
    previous->next = newNode;
    newNode->next = temp;
    return head;
}

// Function to delete a node at the beginning of the list
struct Node* deleteAtBeginning(struct Node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node at the end of the list
struct Node* deleteAtEnd(struct Node* head) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    struct Node* previous = NULL;
    while(temp->next != NULL) {
        previous = temp;
        temp = temp->next;
    }
    if(previous == NULL) {
        free(temp);
        head = NULL;
        return head;
    }
    previous->next = NULL;
    free(temp);
    return head;
}

// Function to delete a node at a given position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if(head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct Node* temp = head;
    struct Node* previous = NULL;
    int currentPos = 1;
    while(currentPos < position && temp != NULL) {
        previous = temp;
        temp = temp->next;
        currentPos++;
    }
    if(temp == NULL) {
        printf("Position does not exist\n");
        return head;
    }
    if(previous == NULL) {
        head = head->next;
        free(temp);
        return head;
    }
    previous->next = temp->next;
    free(temp);
    return head;    
}

// Function to reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    struct Node* next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
    return head;
}

// Function to find the length of the list
int length(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    do {
        printf("Select an option:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Reverse list\n");
        printf("8. Print list\n");
        printf("9. Length of list\n");
        printf("10. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                head = reverseList(head);
                break;
            case 8:
                printf("Current list: ");
                printList(head);
                break;
            case 9:
                printf("Length of list: %d\n", length(head));
                break;
            case 10:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 10);
    return 0;
}