//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_JSON_SIZE 1000000

typedef struct {
    char *json_str;
    int start;
    int end;
} json_data;

void *parse_json(void *arg) {
    json_data *data = (json_data *) arg;
    int i = data->start;
    int j = data->end;
    char *json_str = data->json_str;

    while (i <= j) {
        if (json_str[i] == '{' || json_str[i] == '[') {
            printf("Thread %d found an object/array at position %d\n", pthread_self(), i);
        } else if (json_str[i] == '}' || json_str[i] == ']') {
            printf("Thread %d found the end of an object/array at position %d\n", pthread_self(), i);
        }
        i++;
    }

    return NULL;
}

int main() {
    char json_str[MAX_JSON_SIZE];
    int json_size;
    int num_threads;

    printf("Enter the size of the JSON string: ");
    scanf("%d", &json_size);

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the JSON string: ");
    scanf("%s", json_str);

    pthread_t threads[MAX_THREADS];
    json_data data[MAX_THREADS];

    int thread_count = 0;
    int start = 0;
    int end = json_size - 1;
    int chunk_size = json_size / num_threads;

    for (int i = 0; i < num_threads; i++) {
        data[i].json_str = json_str;
        data[i].start = start;
        data[i].end = (i == num_threads - 1)? end : start + chunk_size - 1;

        int rc = pthread_create(&threads[i], NULL, parse_json, (void *)&data[i]);
        if (rc) {
            printf("Error: Unable to create thread, %d\n", rc);
            exit(-1);
        }

        start = data[i].end + 1;
        thread_count++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}