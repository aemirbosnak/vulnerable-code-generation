//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: genius
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} node;

typedef struct {
    node *data;
    int size;
    int capacity;
} heap;

heap *create_heap(int capacity) {
    heap *h = malloc(sizeof(heap));
    h->data = malloc(sizeof(node) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void destroy_heap(heap *h) {
    free(h->data);
    free(h);
}

void swap(node *a, node *b) {
    node temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h->size && h->data[left].key < h->data[smallest].key) {
        smallest = left;
    }

    if (right < h->size && h->data[right].key < h->data[smallest].key) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&h->data[i], &h->data[smallest]);
        heapify(h, smallest);
    }
}

void insert(heap *h, node n) {
    if (h->size == h->capacity) {
        h->data = realloc(h->data, sizeof(node) * h->capacity * 2);
        h->capacity *= 2;
    }

    h->data[h->size] = n;
    h->size++;

    int i = h->size - 1;
    while (i > 0 && h->data[i].key < h->data[(i - 1) / 2].key) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

node extract_min(heap *h) {
    if (h->size == 0) {
        fprintf(stderr, "Error: heap is empty\n");
        exit(1);
    }

    node min = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;

    heapify(h, 0);

    return min;
}

void print_heap(heap *h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d %d\n", h->data[i].key, h->data[i].value);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    heap *h = create_heap(n);

    for (int i = 0; i < n; i++) {
        int key, value;
        scanf("%d %d", &key, &value);
        node n = {key, value};
        insert(h, n);
    }

    print_heap(h);

    destroy_heap(h);

    return 0;
}