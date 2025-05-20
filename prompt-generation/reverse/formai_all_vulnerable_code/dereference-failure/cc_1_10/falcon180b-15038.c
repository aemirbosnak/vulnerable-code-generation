//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SENTENCES 1000
#define MAX_WORDS 100
#define MAX_THREADS 10

typedef struct {
    char sentence[MAX_SENTENCES];
    int length;
    int *word_count;
} Sentence;

void *count_words(void *arg) {
    Sentence *sentence = (Sentence *) arg;
    char *token = strtok(sentence->sentence, " ");
    int count = 0;

    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    sentence->word_count[0] = count;
    pthread_exit(0);
}

int main() {
    FILE *file;
    char line[MAX_SENTENCES];
    Sentence sentences[MAX_SENTENCES];
    pthread_t threads[MAX_THREADS];
    int i, j, num_sentences = 0;
    int *word_counts = (int *) malloc(MAX_SENTENCES * sizeof(int));

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_SENTENCES, file)!= NULL) {
        strcpy(sentences[num_sentences].sentence, line);
        sentences[num_sentences].length = strlen(line);
        num_sentences++;
    }

    fclose(file);

    for (i = 0; i < num_sentences; i++) {
        pthread_create(&threads[i], NULL, count_words, &sentences[i]);
    }

    for (i = 0; i < num_sentences; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_sentences; i++) {
        printf("Sentence %d has %d words.\n", i + 1, word_counts[i]);
    }

    free(word_counts);
    return 0;
}