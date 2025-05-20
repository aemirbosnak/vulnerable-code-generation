//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

typedef struct thread_data {
    char *string;
    int start_index;
    int end_index;
    int thread_id;
} thread_data_t;

void *process_string(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int start_index = data->start_index;
    int end_index = data->end_index;
    int thread_id = data->thread_id;

    char *string = data->string;

    for (int i = start_index; i <= end_index; i++) {
        if (isalpha(string[i])) {
            string[i] = toupper(string[i]);
        }
    }

    printf("Thread %d processed string from index %d to %d\n", thread_id, start_index, end_index);

    return NULL;
}

int main() {
    char input_string[MAX_STRING_LENGTH];
    printf("Enter a string: ");
    scanf("%s", input_string);

    int num_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];

    int string_length = strlen(input_string);
    int chunk_size = string_length / num_threads;

    thread_data_t data[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        int start_index = i * chunk_size;
        int end_index = (i == num_threads - 1)? string_length : (i + 1) * chunk_size;

        data[i].string = input_string;
        data[i].start_index = start_index;
        data[i].end_index = end_index;
        data[i].thread_id = i + 1;

        pthread_create(&threads[i], NULL, process_string, (void *) &data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("String processing completed\n");

    return 0;
}