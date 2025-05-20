//MISTRAL-7B DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUF_SIZE 10
#define WINDOW_SIZE 5

typedef struct {
    float buffer[BUF_SIZE];
    int head;
    int tail;
} CircularBuffer;

void init_buffer(CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
}

int is_full(CircularBuffer *cb) {
    return ((cb->head + 1) % BUF_SIZE == cb->tail);
}

void push(CircularBuffer *cb, float sample) {
    if (is_full(cb)) {
        printf("Buffer is full. Dropping sample.\n");
        return;
    }

    cb->buffer[cb->head] = sample;
    cb->head = (cb->head + 1) % BUF_SIZE;
}

float moving_average(CircularBuffer *cb, int window_size) {
    float sum = 0.0f;
    int i;

    if (cb->head > cb->tail && (cb->head - cb->tail) >= window_size) {
        for (i = 0; i < window_size; i++) {
            sum += cb->buffer[(cb->tail + i) % BUF_SIZE];
        }

        sum /= window_size;
    }

    return sum;
}

int main() {
    CircularBuffer cb;
    float input, ma;
    int i;

    init_buffer(&cb);

    printf("Moving Average Filter\n");
    printf("Window Size: %d\n", WINDOW_SIZE);

    for (i = 0; i < 20; i++) {
        printf("Enter sample %d: ", i + 1);
        scanf("%f", &input);

        push(&cb, input);
        ma = moving_average(&cb, WINDOW_SIZE);

        printf("Input: %.2f, Moving Average: %.2f\n", input, ma);
    }

    return 0;
}