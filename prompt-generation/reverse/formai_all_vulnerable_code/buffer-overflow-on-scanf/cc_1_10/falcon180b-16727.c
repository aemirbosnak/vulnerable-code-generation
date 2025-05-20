//Falcon-180B DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* head = NULL;

void addNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));

    if(newNode == NULL) {
        printf("Memory Error\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        node* temp = head;

        while(temp->next!= NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteNode(int data) {
    node* temp = head;
    node* prev = NULL;

    if(head!= NULL && head->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Node not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    node* temp = head;

    if(head == NULL) {
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

    do {
        printf("1. Add node\n");
        printf("2. Delete node\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                addNode(data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                deleteNode(data);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 4);

    return 0;
}