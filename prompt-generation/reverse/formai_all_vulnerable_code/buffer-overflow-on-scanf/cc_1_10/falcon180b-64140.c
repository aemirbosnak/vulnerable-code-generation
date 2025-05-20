//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORD_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void *countWords(void *arg);

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    char filename[MAX_FILE_SIZE];
    int numThreads = 1;
    pthread_t threads[MAX_THREADS];
    WordCount wc[26];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter the number of threads (1-10): ");
    scanf("%d", &numThreads);

    for (int i = 0; i < numThreads; i++) {
        wc[i].word[0] = (char) ('a' + i);
        wc[i].count = 0;
        pthread_create(&threads[i], NULL, countWords, (void *) &wc[i]);
    }

    while ((ch = fgetc(fp))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a';
            wc[index].count++;
        }
    }

    fclose(fp);

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Word count:\n");
    for (int i = 0; i < numThreads; i++) {
        printf("%c: %d\n", wc[i].word[0], wc[i].count);
    }

    return 0;
}

void *countWords(void *arg) {
    WordCount *wc = (WordCount *) arg;

    while (1) {
        if (wc->count > 0) {
            printf("%c: %d\n", wc->word[0], wc->count);
            wc->count = 0;
        }
    }

    return NULL;
}