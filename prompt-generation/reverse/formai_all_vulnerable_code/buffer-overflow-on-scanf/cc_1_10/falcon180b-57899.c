//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100

typedef struct {
    int capacity;
    int count;
    int *values;
} PriorityQueue;

void initialize(PriorityQueue *queue) {
    queue->capacity = MAX_CAPACITY;
    queue->count = 0;
    queue->values = (int *) malloc(queue->capacity * sizeof(int));
}

void insert(PriorityQueue *queue, int value) {
    if (queue->count == queue->capacity) {
        printf("Priority queue is full. Cannot insert %d.\n", value);
        return;
    }
    queue->values[queue->count++] = value;
}

int extract_min(PriorityQueue *queue) {
    if (queue->count == 0) {
        printf("Priority queue is empty.\n");
        return -1;
    }
    int min_value = queue->values[0];
    for (int i = 0; i < queue->count - 1; i++) {
        queue->values[i] = queue->values[i + 1];
    }
    queue->count--;
    return min_value;
}

int main() {
    PriorityQueue queue;
    initialize(&queue);
    int choice, value;
    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert\n2. Extract Min\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            insert(&queue, value);
            break;
        case 2:
            value = extract_min(&queue);
            if (value!= -1) {
                printf("Extracted value: %d\n", value);
            }
            break;
        case 3:
            printf("Current priority queue:\n");
            for (int i = 0; i < queue.count; i++) {
                printf("%d ", queue.values[i]);
            }
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);
    return 0;
}