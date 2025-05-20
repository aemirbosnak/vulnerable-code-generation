//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

void insert(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while(temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete(int data) {
    Node* temp = head;
    Node* prev = NULL;
    if(temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void search(int data) {
    Node* temp = head;
    while(temp!= NULL) {
        if(temp->data == data) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

void display() {
    Node* temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while(1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                search(data);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}