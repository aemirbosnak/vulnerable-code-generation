//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define MAX_WORDS 1000
#define MAX_THREADS 4

void *count_words(void *arg);

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[50];
    char line[100];
    int word_count = 0;
    int thread_count = 0;
    pthread_t threads[MAX_THREADS];
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Count number of words in file
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            word_count++;
            token = strtok(NULL, ",.?!;:");
        }
    }

    // Create threads to count words
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, count_words, (void *)&word_count);
        thread_count++;
    }

    // Join threads
    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close file
    fclose(fp);

    // Print word count
    printf("Word count: %d\n", word_count);

    return 0;
}

void *count_words(void *arg) {
    int *word_count = (int *)arg;
    char ch;

    // Get a word from the file
    while (fscanf(stdin, "%c", &ch)!= EOF) {
        if (isalpha(ch)) {
            (*word_count)++;
        }
    }

    return NULL;
}