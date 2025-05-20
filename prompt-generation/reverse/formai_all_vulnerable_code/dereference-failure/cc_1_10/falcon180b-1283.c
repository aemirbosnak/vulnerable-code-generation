//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_WORD_LENGTH 50
#define MAX_FILE_SIZE 10000000 // 10MB

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    FILE *file;
    char *filename;
    int lines_processed;
    int total_words;
} ThreadData;

void *count_words_thread(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    char line[MAX_FILE_SIZE];
    char *token;
    WordCount word_counts[26] = { 0 }; // assuming only lowercase letters
    int i;

    while (fgets(line, MAX_FILE_SIZE, thread_data->file)!= NULL) {
        thread_data->lines_processed++;

        token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (token[0] >= 'a' && token[0] <= 'z') {
                i = token[0] - 'a';
                word_counts[i].count++;
            }
            token = strtok(NULL, ",.?!;:");
        }
    }

    for (i = 0; i < 26; i++) {
        if (word_counts[i].count > 0) {
            printf("%c: %d\n", i + 'a', word_counts[i].count);
        }
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100];
    int total_lines = 0, total_words = 0;
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int i, j, ret;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    total_lines = ftell(file);
    rewind(file);

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].file = file;
        strcpy(thread_data[i].filename, filename);
        thread_data[i].lines_processed = 0;
        thread_data[i].total_words = 0;
        ret = pthread_create(&threads[i], NULL, count_words_thread, &thread_data[i]);
        if (ret!= 0) {
            printf("Error creating thread %d\n", i);
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total lines: %d\n", total_lines);
    printf("Total words: %d\n", total_words);

    return 0;
}