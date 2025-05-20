//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void addNode(LinkedList* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

void printList(LinkedList* list) {
    Node* node = list->head;
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(LinkedList* list) {
    Node* node = list->head;
    while (node!= NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    srand(time(NULL));

    LinkedList* list = createLinkedList();

    for (int i = 0; i < MAX_SIZE; i++) {
        addNode(list, rand() % 100);
    }

    printf("Original list:\n");
    printList(list);

    Node* temp = list->head;
    while (temp!= NULL) {
        printf("Swapping %d with %d\n", temp->data, rand() % 100);
        int tempData = temp->data;
        temp->data = rand() % 100;
        temp = temp->next;
    }

    printf("Shuffled list:\n");
    printList(list);

    freeList(list);

    return 0;
}