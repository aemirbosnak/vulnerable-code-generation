//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define BUFFER_SIZE 10000

typedef struct {
    char* text;
    int word_count;
    pthread_mutex_t mutex;
} word_count_t;

void* count_words(void* arg) {
    word_count_t* wc = (word_count_t*) arg;
    char* text = wc->text;
    int word_count = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            word_count++;
        }
    }

    pthread_mutex_lock(&wc->mutex);
    wc->word_count = word_count;
    pthread_mutex_unlock(&wc->mutex);

    return NULL;
}

int main() {
    FILE* fp;
    char ch;
    int word_count = 0;
    word_count_t wc;

    fp = fopen("example.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    wc.text = (char*) malloc(BUFFER_SIZE);
    wc.word_count = 0;
    pthread_mutex_init(&wc.mutex, NULL);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, count_words, &wc);

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            word_count++;
        }
    }

    pthread_join(thread_id, NULL);

    printf("Total word count: %d\n", word_count + wc.word_count);

    fclose(fp);
    free(wc.text);
    pthread_mutex_destroy(&wc.mutex);

    return 0;
}