//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList *list, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

void removeNode(LinkedList *list, int data) {
    Node *curr = list->head;
    Node *prev = NULL;

    while (curr!= NULL && curr->data!= data) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Node with data %d not found\n", data);
        return;
    }

    if (prev == NULL) {
        list->head = curr->next;
    } else {
        prev->next = curr->next;
    }

    if (curr == list->tail) {
        list->tail = prev;
    }

    free(curr);
    list->size--;
}

void traverseList(LinkedList *list) {
    Node *curr = list->head;

    printf("List: ");
    while (curr!= NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    LinkedList *list = createLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);

    traverseList(list);

    removeNode(list, 2);

    traverseList(list);

    free(list);
    return 0;
}