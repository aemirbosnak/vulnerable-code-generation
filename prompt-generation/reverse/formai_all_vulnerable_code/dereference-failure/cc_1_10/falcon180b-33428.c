//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int size;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

void initList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->size = 1;
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
    Node* prev = NULL;
    Node* curr = list->head;
    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    list->size--;
}

void printList(LinkedList* list) {
    Node* curr = list->head;
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    LinkedList lst;
    initList(&lst);
    addNode(&lst, 1);
    addNode(&lst, 2);
    addNode(&lst, 3);
    printList(&lst);
    deleteNode(&lst, 2);
    printList(&lst);
    return 0;
}