//Falcon2-11B DATASET v1.0 Category: Word Frequency Counter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORD_SIZE 100

void* count_word_frequency(void* word) {
    char* word_str = (char*)word;
    int word_len = strlen(word_str);
    int word_count = 0;
    char* word_buffer[word_len + 1];

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }

    while (fscanf(file, "%s", word_buffer[word_len]) == 1) {
        if (strcmp(word_buffer[word_len], word_str) == 0) {
            word_count++;
        }
        word_len--;
    }

    fclose(file);

    printf("Word: %s, Frequency: %d\n", word_str, word_count);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_WORD_SIZE];
    int thread_count = 0;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    char* words[MAX_WORD_SIZE];
    int word_count = 0;

    while (fscanf(file, "%s", words[word_count]) == 1) {
        word_count++;
    }

    fclose(file);

    for (int i = 0; i < word_count; i++) {
        int thread_id = i;
        if (pthread_create(&threads[thread_id], NULL, count_word_frequency, (void*)words[i])!= 0) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }

    for (int i = 0; i < word_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}