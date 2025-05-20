//FormAI DATASET v1.0 Category: Linked list operations ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node *createLinkedList() {
    Node *head = NULL;
    return head;
}

void insertEnd(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertBegin(Node **head, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertPos(Node **head, int value, int position) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    Node *temp = *head;
    int counter = 1;
    if(position == 1) {
        newNode->next = temp;
        *head = newNode;
    } else {
        while(counter < position-1 && temp != NULL) {
            temp = temp->next;
            counter++;
        }
        if(temp == NULL) {
            printf("Insertion not possible in given position\n");
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteNode(Node **head, int key) {
    Node *temp = *head, *prev;
    if(temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("The given key is not present in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(Node *head) {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = createLinkedList();
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at given position\n");
    printf("4. Delete a node\n");
    printf("5. Display the list\n");
    printf("6. Exit\n");
    int choice, value, position;
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    insertBegin(&head, value);
                    break;
            case 2: printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    insertEnd(&head, value);
                    break;
            case 3: printf("Enter the value to be inserted: ");
                    scanf("%d", &value);
                    printf("Enter the position: ");
                    scanf("%d", &position);
                    insertPos(&head, value, position);
                    break;
            case 4: printf("Enter the key to be deleted: ");
                    scanf("%d", &value);
                    deleteNode(&head, value);
                    break;
            case 5: display(head);
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}