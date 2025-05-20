//FormAI DATASET v1.0 Category: Spam Detection System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_SPAM_WORDS 100

typedef struct {
    char spam_words[MAX_SPAM_WORDS][25];
    int count;
} SpamDictionary;

char messages[100][200];
int num_messages = 0;

int isSpam(const char *message, SpamDictionary *spamDictionary) {
    char *token = strtok(message, " ");
    while (token != NULL) {
        for (int i = 0; i < spamDictionary->count; i++) {
            if (strcmp(token, spamDictionary->spam_words[i]) == 0) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

void *threadFunction(void *spamDictionary) {
    SpamDictionary *dict = (SpamDictionary*)spamDictionary;
    int count = 0;
    for (int i = 0; i < num_messages; i++) {
        if (isSpam(messages[i], dict)) {
            count++;
        }
    }
    printf("Thread processed %d messages and found %d spam messages.\n", num_messages, count);
    pthread_exit(NULL);
}

void loadSpamDictionary(char *filename, SpamDictionary *spamDictionary) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int index = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        line[strlen(line) - 1] = '\0'; // remove new line character
        strcpy(spamDictionary->spam_words[index++], line);
        spamDictionary->count++;
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main() {
    srand(time(NULL));
    SpamDictionary spamDictionary;
    loadSpamDictionary("spam_words.txt", &spamDictionary);

    // generate messages
    for (int i = 0; i < 100; i++) {
        int len = rand() % 200 + 1;
        for (int j = 0; j < len; j++) {
            messages[i][j] = rand() % 26 + 'a'; // generate a random character between a and z
        }
        messages[i][len] = '\0';
        num_messages++;
    }

    // create threads
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunction, (void *)&spamDictionary);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL);

    return 0;
}