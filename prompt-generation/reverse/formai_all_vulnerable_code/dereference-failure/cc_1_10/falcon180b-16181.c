//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList *list, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    list->size++;
}

void printLinkedList(LinkedList *list) {
    Node *current = list->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList *list = createLinkedList();

    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);

    printf("Linked List:\n");
    printLinkedList(list);

    free(list->head);
    free(list);

    return 0;
}