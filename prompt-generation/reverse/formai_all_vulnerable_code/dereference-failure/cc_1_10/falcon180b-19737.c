//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head;

void initialize() {
    head = NULL;
}

void insert(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory Error\n");
        exit(0);
    }
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    }
    else {
        Node *ptr = head;
        while (ptr->next!= NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void delete(int data) {
    Node *temp = head;
    Node *prev = NULL;
    if (temp!= NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display() {
    Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    initialize();
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    delete(30);
    delete(50);
    display();
    return 0;
}