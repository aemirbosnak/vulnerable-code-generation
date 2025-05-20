//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000
#define NUM_THREADS 4

typedef struct {
    char input_string[MAX_STRING_LENGTH];
    char output_string[MAX_STRING_LENGTH];
    pthread_t thread_id;
} thread_data_t;

void *translate_string(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;

    strcpy(data->output_string, "");
    int i = 0;

    while (data->input_string[i]!= '\0') {
        if (isalpha(data->input_string[i])) {
            data->output_string[i] = tolower(data->input_string[i]);
            i++;
        } else {
            data->output_string[i] = data->input_string[i];
            i++;
        }
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Enter string to translate (thread %d): ", i + 1);
        scanf("%s", data[i].input_string);

        pthread_create(&threads[i], NULL, translate_string, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);

        printf("Translated string (thread %d): %s\n", i + 1, data[i].output_string);
    }

    return 0;
}