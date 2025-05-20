//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 10

typedef struct {
    char word[MAX_WORD_LEN];
    int len;
} Word;

void *type(void *arg) {
    char *word = (char *) arg;
    int len = strlen(word);
    printf("%s", word);
    for (int i = 0; i < len; i++) {
        printf("\b");
    }
    printf("\n");
    return NULL;
}

int main() {
    Word words[MAX_WORDS];
    int num_words = 0;

    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }
        strcpy(words[num_words].word, word);
        words[num_words].len = strlen(word);
        num_words++;
    }

    fclose(fp);

    pthread_t threads[num_words];

    for (int i = 0; i < num_words; i++) {
        pthread_create(&threads[i], NULL, type, words[i].word);
        sleep(1);
    }

    for (int i = 0; i < num_words; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}