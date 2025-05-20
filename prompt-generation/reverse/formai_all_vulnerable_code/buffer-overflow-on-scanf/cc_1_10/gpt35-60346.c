//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node* createNode(int d) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void insertAtTail(Node **head, int d) {
    Node* newNode = createNode(d);
    if(*head==NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while(curr->next!=NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void printList(Node *head) {
    if(head==NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* curr = head;
    while(curr!=NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void deleteByKey(Node **head, int key) {
    if(*head==NULL) {
        printf("List is empty!\n");
        return;
    }
    Node* temp = *head;
    if(temp->data==key) {
        *head = temp->next;
        free(temp);
        printf("%d deleted from list.\n", key);
        return;
    }
    while(temp->next->data!=key) {
        temp = temp->next;
    }
    Node* toDel = temp->next;
    temp->next = toDel->next;
    free(toDel);
    printf("%d deleted from list.\n", key);
}

int main() {
    Node *head = NULL;
    int choice, key, data;
    printf("Data Structure Example: Linked List Visualization\n");
    while(1) {
        printf("\n\tMENU\n");
        printf("1. Insert at tail\n");
        printf("2. Delete by key\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtTail(&head, data);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteByKey(&head, key);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}