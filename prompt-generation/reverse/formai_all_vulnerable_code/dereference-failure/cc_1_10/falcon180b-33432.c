//Falcon-180B DATASET v1.0 Category: Memory management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* freeList = (Node*)0;

void init() {
    freeList = (Node*)malloc(sizeof(Node));
    freeList->data = -1;
    freeList->next = (Node*)0;
}

Node* getFreeNode() {
    Node* current = freeList;
    while (current->next!= (Node*)0) {
        current = current->next;
    }
    return current;
}

void addToFreeList(Node* node) {
    node->next = (Node*)0;
    Node* last = freeList;
    while (last->next!= (Node*)0) {
        last = last->next;
    }
    last->next = node;
}

int main() {
    init();

    int* p1 = (int*)malloc(sizeof(int));
    int* p2 = (int*)malloc(sizeof(int));
    int* p3 = (int*)malloc(sizeof(int));

    *p1 = 42;
    *p2 = 13;
    *p3 = 7;

    printf("Values: %d %d %d\n", *p1, *p2, *p3);

    free(p1);
    free(p2);
    free(p3);

    return 0;
}