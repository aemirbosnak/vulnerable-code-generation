//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addNode(LinkedList *list, char data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }

    list->size++;
}

void printLinkedList(LinkedList *list) {
    Node *temp = list->head;
    printf("Linked List: ");

    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }

    printf("\nSize: %d", list->size);
}

int main() {
    LinkedList *list = createLinkedList();

    addNode(list, 'a');
    addNode(list, 'b');
    addNode(list, 'c');
    addNode(list, 'd');

    printLinkedList(list);

    free(list->head);
    free(list);

    return 0;
}