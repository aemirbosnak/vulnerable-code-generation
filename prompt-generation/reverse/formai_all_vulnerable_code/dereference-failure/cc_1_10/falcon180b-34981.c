//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

List* createList() {
    List* newList = (List*) malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

void addNode(List* list, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size++;
}

void printList(List* list) {
    Node* current = list->head;
    printf("List: ");

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void freeList(List* list) {
    Node* current = list->head;
    Node* next;

    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

int main() {
    List* myList = createList();
    addNode(myList, 1);
    addNode(myList, 2);
    addNode(myList, 3);
    addNode(myList, 4);
    addNode(myList, 5);

    printf("Original List:\n");
    printList(myList);

    Node* temp = myList->head;
    myList->head = myList->tail;
    myList->tail = temp;

    printf("Reversed List:\n");
    printList(myList);

    freeList(myList);
    return 0;
}