//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct CircularBuffer {
    int buffer[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

void initCircularBuffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
}

bool isFull(CircularBuffer *cb) {
    if ((cb->tail + 1) % BUFFER_SIZE == cb->head) {
        return true;
    }
    return false;
}

bool enqueue(CircularBuffer *cb, int value) {
    if (isFull(cb)) {
        return false;
    }

    cb->buffer[cb->tail] = value;
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;

    return true;
}

int dequeue(CircularBuffer *cb) {
    if (cb->head == cb->tail) {
        printf("Circular Buffer is empty.\n");
        return -1;
    }

    int value = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % BUFFER_SIZE;

    return value;
}

int searchCircularBuffer(CircularBuffer *cb, int value) {
    int index = cb->head;

    do {
        if (cb->buffer[index] == value) {
            return index;
        }
        index = (index + 1) % BUFFER_SIZE;
    } while (index != cb->tail);

    return -1;
}

int main() {
    CircularBuffer cb;
    initCircularBuffer(&cb);

    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 11; i++) {
        enqueue(&cb, values[i]);
    }

    int searchValue = 5;
    int index = searchCircularBuffer(&cb, searchValue);

    if (index != -1) {
        printf("Found %d at index %d.\n", searchValue, index);
    } else {
        printf("%d not found.\n", searchValue);
    }

    int dequeuedValue = dequeue(&cb);
    printf("Dequeued value: %d\n", dequeuedValue);

    return 0;
}