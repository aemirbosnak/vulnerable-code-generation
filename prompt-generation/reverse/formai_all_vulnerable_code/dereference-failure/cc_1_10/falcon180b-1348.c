//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
    Node* tail;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void removeNode(LinkedList* list, int data) {
    Node* currNode = list->head;
    Node* prevNode = NULL;
    while (currNode!= NULL && currNode->data!= data) {
        prevNode = currNode;
        currNode = currNode->next;
    }
    if (currNode == NULL) {
        printf("Node not found\n");
    } else if (prevNode == NULL) {
        list->head = currNode->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(currNode);
    } else {
        prevNode->next = currNode->next;
        if (currNode->next == NULL) {
            list->tail = prevNode;
        }
        free(currNode);
    }
    list->size--;
}

void printList(LinkedList* list) {
    Node* currNode = list->head;
    while (currNode!= NULL) {
        printf("%d -> ", currNode->data);
        currNode = currNode->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    printList(list);
    removeNode(list, 2);
    printList(list);
    removeNode(list, 1);
    printList(list);
    removeNode(list, 3);
    printList(list);
    free(list);
    return 0;
}