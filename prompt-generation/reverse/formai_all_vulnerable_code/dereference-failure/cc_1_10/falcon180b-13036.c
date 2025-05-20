//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_WORDS 1000
#define MAX_THREADS 10

// global variables
int num_threads;
char **words;

void *thread_func(void *arg) {
    char *word = *(char **) arg;
    int count = 0;
    int i;

    for (i = 0; i < strlen(word); i++) {
        printf("%c", word[i]);
        count++;
        if (count % 10 == 0) {
            printf("\n");
        }
    }

    pthread_exit(NULL);
}

int main() {
    FILE *fp;
    char line[256];
    int i, j;
    int word_count = 0;

    // open file
    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read words from file
    while (fgets(line, 256, fp)!= NULL) {
        words[word_count] = strdup(line);
        word_count++;
    }

    // close file
    fclose(fp);

    // prompt user for number of threads
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    // create threads
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[thread_count], NULL, thread_func, (void *) &words[i]);
        thread_count++;
    }

    // wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}