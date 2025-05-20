//Falcon-180B DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 100

typedef struct {
    int *array;
    int capacity;
    int size;
} Heap;

void init(Heap *heap) {
    heap->array = (int *)malloc(HEAP_SIZE * sizeof(int));
    heap->capacity = HEAP_SIZE;
    heap->size = 0;
}

void resize(Heap *heap) {
    heap->capacity *= 2;
    heap->array = (int *)realloc(heap->array, heap->capacity * sizeof(int));
}

void push(Heap *heap, int value) {
    if (heap->size == heap->capacity) {
        resize(heap);
    }
    heap->array[heap->size++] = value;
}

int pop(Heap *heap) {
    int value = heap->array[0];
    heap->array[0] = heap->array[--heap->size];
    heap->array[heap->size] = 0;
    return value;
}

void heapify(Heap *heap, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    if (largest!= i) {
        heap->array[i] = heap->array[largest];
        heap->array[largest] = heap->array[i];
        heapify(heap, largest);
    }
}

void heap_sort(Heap *heap) {
    for (int i = heap->size / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }

    for (int i = heap->size - 1; i >= 0; i--) {
        int temp = pop(heap);
        heap->array[i] = temp;
        heapify(heap, 0);
    }
}

int main() {
    Heap heap;
    init(&heap);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(&heap, value);
    }

    heap_sort(&heap);

    printf("Sorted array: ");
    for (int i = 0; i < heap.size; i++) {
        printf("%d ", heap.array[i]);
    }
    printf("\n");

    free(heap.array);
    return 0;
}