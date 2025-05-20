//FormAI DATASET v1.0 Category: Linked list operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertAtBeginning(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Element %d inserted at the beginning\n", data);
}

void insertAtEnd(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* current = head;
    if (head == NULL) {
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        printf("Element %d inserted at the end\n", data);
    }
    else {
        while (current->next != NULL)
            current = current->next;
        newNode->data = data;
        newNode->next = NULL;
        current->next = newNode;
        printf("Element %d inserted at the end\n", data);
    }
}

void insertAtPosition(int data, int position) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* current = head;
    int i;
    for (i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Error: Not enough elements in the list\n");
            return;
        }
        current = current->next;
    }
    newNode->data = data;
    newNode->next = current->next;
    current->next = newNode;
    printf("Element %d inserted at position %d\n", data, position);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    printf("Element %d deleted from the beginning\n", temp->data);
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    struct node* current = head;
    struct node* prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
        head = NULL;
    else
        prev->next = NULL;
    printf("Element %d deleted from the end\n", current->data);
    free(current);
}

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("Error: List is empty\n");
        return;
    }
    struct node* current = head;
    struct node* prev = NULL;
    int i;
    for (i = 1; i < position; i++) {
        if (current == NULL) {
            printf("Error: Not enough elements in the list\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    if (prev == NULL)
        head = current->next;
    else
        prev->next = current->next;
    printf("Element %d deleted from position %d\n", current->data, position);
    free(current);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* current = head;
    printf("Elements in the list are: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &position);
            insertAtPosition(data, position);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &position);
            deleteFromPosition(position);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}