//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} LinkedList;

void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->size = 0;
}

void pushLinkedList(LinkedList* list, int data) {
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

void popLinkedList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    list->head = temp->next;
    free(temp);

    list->size--;
}

void printLinkedList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    LinkedList list;
    initLinkedList(&list);

    pushLinkedList(&list, 1);
    pushLinkedList(&list, 2);
    pushLinkedList(&list, 3);
    pushLinkedList(&list, 4);
    pushLinkedList(&list, 5);

    printLinkedList(&list);

    popLinkedList(&list);
    popLinkedList(&list);

    printLinkedList(&list);

    return 0;
}