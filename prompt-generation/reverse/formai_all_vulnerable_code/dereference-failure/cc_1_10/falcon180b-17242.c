//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void addNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int data) {
    struct node* temp = head;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    struct node* prev = head;
    while (prev->next!= temp) {
        prev = prev->next;
    }
    prev->next = temp->next;
    free(temp);
}

void displayList() {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    addNode(1);
    addNode(2);
    addNode(3);
    displayList();
    deleteNode(2);
    displayList();
    deleteNode(1);
    displayList();
    deleteNode(3);
    displayList();
    return 0;
}