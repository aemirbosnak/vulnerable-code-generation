//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int data;
    int size;
    struct node *next;
} Node;

Node *freeList = (void*)0;

void init() {
    freeList = (Node*)malloc(sizeof(Node));
    freeList->data = -1;
    freeList->size = MAX_SIZE;
    freeList->next = (void*)0;
}

void *myMalloc(int size) {
    Node *current = freeList;
    Node *prev = (void*)0;

    while (current!= (void*)0 && current->size < size) {
        prev = current;
        current = current->next;
    }

    if (current == (void*)0) {
        current = (Node*)malloc(sizeof(Node));
        current->data = -1;
        current->size = MAX_SIZE;
        current->next = (void*)0;
        prev->next = current;
    }

    void *result = (char*)current + sizeof(Node);
    current->size -= size;
    current->data = size;

    return result;
}

void myFree(void *ptr) {
    if (ptr == (void*)0)
        return;

    Node *block = (Node*)ptr;
    block -= sizeof(Node);

    Node *current = freeList;
    Node *prev = (void*)0;

    while (current!= (void*)0 && current!= block) {
        prev = current;
        current = current->next;
    }

    if (current == (void*)0)
        return;

    if (prev!= (void*)0)
        prev->next = current->next;
    else
        freeList = current->next;

    free(current);
}

int main() {
    init();

    int *a = myMalloc(10);
    int *b = myMalloc(20);
    int *c = myMalloc(30);

    printf("%d\n", *a);
    printf("%d\n", *b);
    printf("%d\n", *c);

    myFree(a);
    myFree(b);
    myFree(c);

    return 0;
}