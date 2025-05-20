//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct bit_field {
    int value;
    int bit_pos;
} bit_field_t;

void *set_bit(void *param) {
    bit_field_t *bit_field = (bit_field_t *) param;
    int bit_mask = 1 << bit_field->bit_pos;
    bit_field->value |= bit_mask;
    return NULL;
}

void *clear_bit(void *param) {
    bit_field_t *bit_field = (bit_field_t *) param;
    int bit_mask = ~(1 << bit_field->bit_pos);
    bit_field->value &= bit_mask;
    return NULL;
}

void *toggle_bit(void *param) {
    bit_field_t *bit_field = (bit_field_t *) param;
    int bit_mask = 1 << bit_field->bit_pos;
    bit_field->value ^= bit_mask;
    return NULL;
}

int main() {
    int num_threads = 10;
    pthread_t threads[num_threads];
    bit_field_t bit_fields[num_threads];

    for (int i = 0; i < num_threads; i++) {
        bit_fields[i].value = 0;
        bit_fields[i].bit_pos = rand() % 32;
        pthread_create(&threads[i], NULL, set_bit, &bit_fields[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        bit_fields[i].value = 0;
        bit_fields[i].bit_pos = rand() % 32;
        pthread_create(&threads[i], NULL, clear_bit, &bit_fields[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_threads; i++) {
        bit_fields[i].value = 0;
        bit_fields[i].bit_pos = rand() % 32;
        pthread_create(&threads[i], NULL, toggle_bit, &bit_fields[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}