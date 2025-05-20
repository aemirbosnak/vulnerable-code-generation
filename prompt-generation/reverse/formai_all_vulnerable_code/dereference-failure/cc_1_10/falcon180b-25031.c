//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SAMPLES 100
#define MIN_THRESHOLD 0.5
#define MAX_THRESHOLD 0.9

struct sample {
    double value;
    struct sample *next;
};

struct sample *head = NULL;
int sample_count = 0;

void add_sample(double value) {
    struct sample *new_sample = malloc(sizeof(struct sample));
    new_sample->value = value;
    new_sample->next = NULL;

    if (head == NULL) {
        head = new_sample;
    } else {
        struct sample *last_sample = head;
        while (last_sample->next!= NULL) {
            last_sample = last_sample->next;
        }
        last_sample->next = new_sample;
    }

    sample_count++;

    if (sample_count > MAX_SAMPLES) {
        head = head->next;
        sample_count--;
    }
}

double calculate_average() {
    double sum = 0;
    struct sample *current_sample = head;

    while (current_sample!= NULL) {
        sum += current_sample->value;
        current_sample = current_sample->next;
    }

    return sum / sample_count;
}

int main() {
    srand(time(NULL));

    int num_samples = rand() % (MAX_SAMPLES - 1) + 1;

    double min_threshold = MIN_THRESHOLD + (MAX_THRESHOLD - MIN_THRESHOLD) * rand() / RAND_MAX;
    double max_threshold = MAX_THRESHOLD + (MAX_THRESHOLD - MIN_THRESHOLD) * rand() / RAND_MAX;

    printf("Generating %d random samples between 0 and 1...\n", num_samples);

    for (int i = 0; i < num_samples; i++) {
        double value = rand() / RAND_MAX;
        add_sample(value);
        printf("Sample %d: %.2f\n", i + 1, value);
    }

    printf("\nCalculating average and checking if it falls within the threshold...\n");

    double average = calculate_average();

    if (average >= min_threshold && average <= max_threshold) {
        printf("Average is within the threshold! Network quality is good.\n");
    } else {
        printf("Average is outside the threshold! Network quality is poor.\n");
    }

    return 0;
}