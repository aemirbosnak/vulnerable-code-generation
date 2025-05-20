//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// define the node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert a node at the beginning
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

// function to insert a node at the end
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

// function to insert a node at a given position
Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL) {
            printf("Invalid position\n");
            return head;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    return head;
}

// function to delete a node from the beginning
Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    } else {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

// function to delete a node from the end
Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        return head;
    } else {
        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        return head;
    }
}

// function to delete a node from a given position
Node* deleteFromPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    } else if (position == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    } else {
        Node* current = head;
        for (int i = 1; i < position - 1 && current != NULL; i++) {
            current = current->next;
        }
        if (current == NULL || current->next == NULL) {
            printf("Invalid position\n");
            return head;
        } else {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
    }
}

// function to display the linked list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteFromBeginning(head);
                break;
            case 5:
                head = deleteFromEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteFromPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}