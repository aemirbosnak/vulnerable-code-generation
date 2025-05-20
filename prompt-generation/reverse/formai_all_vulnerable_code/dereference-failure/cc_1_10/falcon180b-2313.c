//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000

typedef struct {
    int thread_id;
    char *filename;
} ThreadData;

void *count_words(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    FILE *file = fopen(thread_data->filename, "r");
    char line[MAX_LINE_LENGTH];
    int word_count = 0;

    if (file == NULL) {
        printf("Error: Could not open file %s\n", thread_data->filename);
        exit(1);
    }

    int thread_id = thread_data->thread_id;
    char *filename_copy = strdup(thread_data->filename);
    char *filename_copy_basename = basename(filename_copy);
    char *thread_name = malloc(strlen(filename_copy_basename) + 10);
    sprintf(thread_name, "Thread %d - %s", thread_id, filename_copy_basename);
    pthread_setname_np(thread_name);

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }
    }

    printf("Thread %d: Word count for %s is %d\n", thread_id, filename_copy_basename, word_count);
    fclose(file);
    free(thread_name);
    free(filename_copy);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    if (argc < 3) {
        printf("Usage: %s <number_of_threads> <filename1> [<filename2>...]\n", argv[0]);
        exit(1);
    }

    int num_threads = atoi(argv[1]);
    int i = 0;

    for (i = 0; i < num_threads && i < argc - 2; i++) {
        thread_data[i].thread_id = i + 1;
        thread_data[i].filename = argv[i + 2];
        pthread_create(&threads[i], NULL, count_words, &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}