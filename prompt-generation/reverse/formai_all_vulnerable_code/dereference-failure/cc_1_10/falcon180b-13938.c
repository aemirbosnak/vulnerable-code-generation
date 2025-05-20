//Falcon-180B DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BLOCK_SIZE 1000

typedef struct {
    int *data;
    int size;
} List;

void init(List *list) {
    list->data = (int *)malloc(BLOCK_SIZE * sizeof(int));
    list->size = 0;
}

void resize(List *list) {
    list->data = (int *)realloc(list->data, list->size * sizeof(int));
}

void push(List *list, int value) {
    if (list->size == MAX_SIZE) {
        printf("Error: List is full!\n");
        return;
    }
    if (list->size == 0) {
        init(list);
    } else if (list->size == BLOCK_SIZE) {
        resize(list);
    }
    list->data[list->size++] = value;
}

int pop(List *list) {
    if (list->size == 0) {
        printf("Error: List is empty!\n");
        return -1;
    }
    int value = list->data[--list->size];
    if (list->size < BLOCK_SIZE / 4) {
        resize(list);
    }
    return value;
}

void print(List *list) {
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    List list;
    init(&list);
    for (int i = 0; i < 100; i++) {
        int value = rand() % 100;
        push(&list, value);
        print(&list);
    }
    for (int i = 0; i < 50; i++) {
        int value = pop(&list);
        printf("Popped: %d\n", value);
        print(&list);
    }
    return 0;
}