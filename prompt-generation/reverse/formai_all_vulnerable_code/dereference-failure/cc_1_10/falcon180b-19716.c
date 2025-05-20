//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    if (newList == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void deleteNode(LinkedList* list, int data) {
    Node* prev = NULL;
    Node* current = list->head;
    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    list->size--;
}

void printList(LinkedList* list) {
    Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    printList(list);
    deleteNode(list, 2);
    printList(list);
    deleteNode(list, 1);
    printList(list);
    deleteNode(list, 3);
    printList(list);
    return 0;
}