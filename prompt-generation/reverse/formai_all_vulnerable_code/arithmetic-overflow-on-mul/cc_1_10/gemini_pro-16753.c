//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: visionary
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data structures
typedef struct {
    int steps;
    int distance;
    int calories;
    int heart_rate;
    time_t timestamp;
} fitness_data_t;

typedef struct {
    fitness_data_t *data;
    int size;
    int capacity;
} fitness_tracker_t;

// Function prototypes
fitness_tracker_t *fitness_tracker_create();
void fitness_tracker_destroy(fitness_tracker_t *tracker);
bool fitness_tracker_add_data(fitness_tracker_t *tracker, fitness_data_t *data);
fitness_data_t *fitness_tracker_get_data(fitness_tracker_t *tracker, int index);
int fitness_tracker_get_size(fitness_tracker_t *tracker);

// Implementation
fitness_tracker_t *fitness_tracker_create() {
    fitness_tracker_t *tracker = malloc(sizeof(fitness_tracker_t));
    if (tracker == NULL) {
        return NULL;
    }

    tracker->data = malloc(sizeof(fitness_data_t) * 10);
    if (tracker->data == NULL) {
        free(tracker);
        return NULL;
    }

    tracker->size = 0;
    tracker->capacity = 10;

    return tracker;
}

void fitness_tracker_destroy(fitness_tracker_t *tracker) {
    free(tracker->data);
    free(tracker);
}

bool fitness_tracker_add_data(fitness_tracker_t *tracker, fitness_data_t *data) {
    if (tracker->size == tracker->capacity) {
        tracker->data = realloc(tracker->data, sizeof(fitness_data_t) * tracker->capacity * 2);
        if (tracker->data == NULL) {
            return false;
        }

        tracker->capacity *= 2;
    }

    tracker->data[tracker->size++] = *data;

    return true;
}

fitness_data_t *fitness_tracker_get_data(fitness_tracker_t *tracker, int index) {
    if (index < 0 || index >= tracker->size) {
        return NULL;
    }

    return &tracker->data[index];
}

int fitness_tracker_get_size(fitness_tracker_t *tracker) {
    return tracker->size;
}

// Example usage
int main() {
    fitness_tracker_t *tracker = fitness_tracker_create();

    fitness_data_t data1 = {
        .steps = 1000,
        .distance = 1.0,
        .calories = 100,
        .heart_rate = 70,
        .timestamp = time(NULL),
    };

    fitness_data_t data2 = {
        .steps = 2000,
        .distance = 2.0,
        .calories = 200,
        .heart_rate = 80,
        .timestamp = time(NULL),
    };

    fitness_tracker_add_data(tracker, &data1);
    fitness_tracker_add_data(tracker, &data2);

    for (int i = 0; i < fitness_tracker_get_size(tracker); i++) {
        fitness_data_t *data = fitness_tracker_get_data(tracker, i);

        printf("Steps: %d, Distance: %f, Calories: %d, Heart rate: %d, Timestamp: %lld\n",
            data->steps, data->distance, data->calories, data->heart_rate, data->timestamp);
    }

    fitness_tracker_destroy(tracker);

    return 0;
}