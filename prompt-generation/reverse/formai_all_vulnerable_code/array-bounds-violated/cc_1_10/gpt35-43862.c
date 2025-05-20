//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_THREADS 4
#define MAX_STRLEN 1000

char input_string[MAX_STRLEN];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *string_reverse(void *arg) {
    pthread_mutex_lock(&lock);
    char *str = (char *) arg;
    char *temp_str = strdup(str);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = temp_str[strlen(temp_str) - i - 1];
    }
    printf("Thread ID %ld reversed string: %s\n", pthread_self(), str);
    free(temp_str);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    printf("Enter a string to reverse: ");
    fgets(input_string, MAX_STRLEN, stdin);

    pthread_t threads[MAX_THREADS];

    int length = strlen(input_string);
    if (input_string[length - 1] == '\n') {
        input_string[length - 1] = '\0';
    }

    int segment_size = length / MAX_THREADS;
    int segment_start = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        int segment_end = segment_start + segment_size;
        if (i == MAX_THREADS - 1) {
            segment_end = length;
        }
        char *segment_string = strndup(&input_string[segment_start], segment_end - segment_start);
        pthread_create(&threads[i], NULL, string_reverse, (void *) segment_string);
        segment_start = segment_end;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}