//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    int index;
} node;

typedef struct {
    node *data;
    int size;
} vector;

void init(vector *v);
void push_back(vector *v, int data);
void pop_back(vector *v);
void print(vector *v);

int main() {
    srand(time(NULL));

    vector v;
    init(&v);

    for (int i = 0; i < 10; i++) {
        push_back(&v, rand() % MAX_SIZE);
    }

    printf("Vector after pushing 10 elements:\n");
    print(&v);

    for (int i = 0; i < 5; i++) {
        pop_back(&v);
    }

    printf("\nVector after popping 5 elements:\n");
    print(&v);

    return 0;
}

void init(vector *v) {
    v->data = (node *) malloc(MAX_SIZE * sizeof(node));
    v->size = 0;
}

void push_back(vector *v, int data) {
    if (v->size >= MAX_SIZE) {
        printf("Vector is full!\n");
        return;
    }

    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->index = v->size;

    v->data[v->size++] = *new_node;
}

void pop_back(vector *v) {
    if (v->size == 0) {
        printf("Vector is empty!\n");
        return;
    }

    v->size--;
}

void print(vector *v) {
    for (int i = 0; i < v->size; i++) {
        printf("%d ", v->data[i].data);
    }

    printf("\n");
}