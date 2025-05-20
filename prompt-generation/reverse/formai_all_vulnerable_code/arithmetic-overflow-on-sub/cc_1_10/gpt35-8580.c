//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNewNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct node **head, int data){
    struct node *newNode = createNewNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at beginning\n", data);
}

// Function to insert a node at the end of the list
void insertAtEnd(struct node **head, int data){
    struct node *newNode = createNewNode(data);
    if (*head == NULL){
        *head = newNode;
        printf("%d inserted at end\n", data);
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    printf("%d inserted at end\n", data);
}

// Function to insert a node at a given position in the list
void insertAtPosition(struct node **head, int data, int position){
    if (position == 0){
        insertAtBeginning(head, data);
        return;
    }
    struct node *newNode = createNewNode(data);
    struct node *temp = *head;
    for (int i=0; i<position-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d inserted at position %d\n", data, position);
}

// Function to delete a node from the beginning of the list
void deleteFromBeginning(struct node **head){
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = temp->next;
    free(temp);
    printf("Deleted from beginning\n");
}

// Function to delete a node from the end of the list
void deleteFromEnd(struct node **head){
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head, *prev;
    if (temp->next == NULL){
        *head = NULL;
        free(temp);
        printf("Deleted from end\n");
        return;
    }
    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Deleted from end\n");
}

// Function to delete a node from a given position in the list
void deleteFromPosition(struct node **head, int position){
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    if (position == 0){
        deleteFromBeginning(head);
        return;
    }
    struct node *temp = *head, *prev;
    for (int i=0; i<position && temp!=NULL; i++){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted from position %d\n", position);
}

// Function to display the list
void displayList(struct node **head){
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node *temp = *head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the list
void reverseList(struct node **head){
    struct node *current = *head, *prev = NULL, *next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List reversed\n");
}

int main(){
    struct node *head = NULL;
    int choice, data, position;
    while (1){
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n");
        printf("5. Delete from end\n6. Delete from position\n7. Display\n8. Reverse\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                displayList(&head);
                break;
            case 8:
                reverseList(&head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}