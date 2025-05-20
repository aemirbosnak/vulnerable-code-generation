//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
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
    list->size++;
}

void deleteNode(LinkedList* list, int data) {
    Node* temp = list->head;
    Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
    } else {
        if (prev == NULL) {
            list->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        list->size--;
    }
}

void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    printList(list);
    deleteNode(list, 3);
    printList(list);
    deleteNode(list, 1);
    printList(list);
    deleteNode(list, 2);
    printList(list);
    deleteNode(list, 4);
    printList(list);
    free(list);
    return 0;
}