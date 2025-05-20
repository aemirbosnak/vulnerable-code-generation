//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

/*Node structure for the linked list*/
typedef struct node {
    int data;
    struct node *next;
} Node;

/*Function to print the linked list*/
void print(Node *head) {
    if(head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/*Function to insert a node at the beginning of the linked list*/
void insertAtBeginning(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

/*Function to insert a node at the end of the linked list*/
void insertAtEnd(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/*Function to delete the first occurrence of a node with a particular value*/
void delete(Node **head, int value) {
    if(*head == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    if((*head)->data == value) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("%d deleted successfully!\n", value);
        return;
    }
    Node *temp = *head;
    Node *prev = NULL;
    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("%d not found in the linked list!\n", value);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("%d deleted successfully!\n", value);
}

/*Function to reverse the linked list*/
void reverse(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/*Main function*/
int main() {
    Node *head = NULL;
    int choice, value;
    while(1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete\n");
        printf("4. Reverse\n");
        printf("5. Print\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                delete(&head, value);
                break;
            case 4:
                reverse(&head);
                printf("Linked list reversed successfully!\n");
                break;
            case 5:
                print(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}