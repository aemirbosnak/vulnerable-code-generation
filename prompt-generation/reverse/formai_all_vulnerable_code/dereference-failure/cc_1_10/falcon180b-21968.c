//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

enum {
    RED,
    GREEN,
    BLUE
};

typedef struct node {
    int data;
    int color;
    struct node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

void addNode(LinkedList* list, int data, int color) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->color = color;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("Data: %d, Color: %d\n", temp->data, temp->color);
        temp = temp->next;
    }
}

void main() {
    LinkedList* list = createLinkedList();

    addNode(list, 1, RED);
    addNode(list, 2, GREEN);
    addNode(list, 3, BLUE);

    printList(list);
}