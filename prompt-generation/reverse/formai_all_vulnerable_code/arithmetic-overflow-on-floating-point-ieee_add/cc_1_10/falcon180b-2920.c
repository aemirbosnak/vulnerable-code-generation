//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SAMPLES 100
#define WINDOW_SIZE 10
#define THRESHOLD 0.5

struct sample {
    double value;
    time_t time;
};

typedef struct {
    int size;
    int head;
    struct sample buffer[MAX_SAMPLES];
} buffer_t;

void init_buffer(buffer_t *buffer) {
    buffer->size = 0;
    buffer->head = 0;
}

int push_sample(buffer_t *buffer, double value) {
    if (buffer->size == MAX_SAMPLES) {
        return -1;
    }

    buffer->buffer[buffer->head].value = value;
    buffer->buffer[buffer->head].time = time(NULL);
    buffer->head = (buffer->head + 1) % MAX_SAMPLES;
    buffer->size++;

    return 0;
}

int pop_sample(buffer_t *buffer, double *value) {
    if (buffer->size == 0) {
        return -1;
    }

    *value = buffer->buffer[buffer->head].value;
    buffer->head = (buffer->head + 1) % MAX_SAMPLES;
    buffer->size--;

    return 0;
}

int get_buffer_size(buffer_t *buffer) {
    return buffer->size;
}

double get_average(buffer_t *buffer) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < MAX_SAMPLES; i++) {
        if (buffer->buffer[i].time > time(NULL) - WINDOW_SIZE) {
            sum += buffer->buffer[i].value;
            count++;
        }
    }

    return sum / count;
}

int main() {
    buffer_t buffer;
    init_buffer(&buffer);

    while (1) {
        double value;
        push_sample(&buffer, value);

        if (get_buffer_size(&buffer) >= WINDOW_SIZE) {
            double average = get_average(&buffer);

            if (average > THRESHOLD) {
                printf("Network Quality of Service (QoS) is poor.\n");
            } else {
                printf("Network Quality of Service (QoS) is good.\n");
            }
        }

        sleep(1);
    }

    return 0;
}