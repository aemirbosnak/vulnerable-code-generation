//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int is_correct;
} word_t;

typedef struct {
    char *filename;
    FILE *file;
    int line_number;
    int word_count;
    word_t words[MAX_DICTIONARY_SIZE];
} thread_data_t;

pthread_mutex_t dictionary_mutex = PTHREAD_MUTEX_INITIALIZER;

void *spell_checker(void *data) {
    thread_data_t *thread_data = data;
    FILE *dictionary_file;
    char line[MAX_WORD_LENGTH];
    int i;

    dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, dictionary_file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        for (i = 0; i < MAX_DICTIONARY_SIZE && thread_data->word_count < MAX_DICTIONARY_SIZE; i++) {
            if (strcmp(line, thread_data->words[i].word) == 0) {
                thread_data->words[i].is_correct = 1;
                break;
            }
        }
    }

    fclose(dictionary_file);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];
    char filename[MAX_THREADS][MAX_WORD_LENGTH];
    int i, j, word_count;

    printf("Enter filenames to spell check:\n");
    for (i = 0; i < MAX_THREADS; i++) {
        scanf("%s", filename[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].filename = filename[i];
        thread_data[i].file = fopen(filename[i], "r");
        if (thread_data[i].file == NULL) {
            printf("Error: Could not open file %s.\n", filename[i]);
            exit(1);
        }
        thread_data[i].line_number = 1;
        thread_data[i].word_count = 0;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, spell_checker, &thread_data[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Spell checking complete.\n");

    return 0;
}