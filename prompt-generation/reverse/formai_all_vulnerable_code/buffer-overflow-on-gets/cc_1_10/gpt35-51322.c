//FormAI DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STR_LENGTH 100

int thread_count = 0;   // keep track of threads created
int word_count[MAX_THREADS];    // array to store word counts for each thread
char word[MAX_THREADS][MAX_STR_LENGTH];   // array to store word for each thread


// function to count number of words in a string
int count_words(char *str) {
    int count = 0;
    char *p = strtok(str, " ");

    while (p != NULL) {
        count++;
        p = strtok(NULL, " ");
    }
    return count;
}

// thread function to count occurence of a word in a string
void* word_occurence(void* param) {
    int tid = *(int*)param;
    int count = 0;

    for (int i = 0; i < strlen(word[tid]); i++) {
        if (word[tid][i] == 'C' || word[tid][i] == 'c') {
            count++;
        }
    }
    word_count[tid] = count;
    pthread_exit(0);
}

int main() {
    int num_threads;
    char str[MAX_STR_LENGTH];
    pthread_t threads[MAX_THREADS];
    int tids[MAX_THREADS];

    printf("Enter number of strings: ");
    scanf("%d", &num_threads);

    printf("Enter %d strings:\n", num_threads);

    for (int i = 0; i < num_threads; i++) {
        getchar();  // consume the newline character left behind by scanf
        printf("String #%d: ", i+1);
        gets(str);
        strcpy(word[i], str);
        tids[i] = i;
        thread_count++;
        pthread_create(&threads[i], NULL, word_occurence, &tids[i]);  // create a new thread to count words
    }

    // wait for all threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // display word counts for each string
    printf("\nWord count for each string:\n");

    for (int i = 0; i < num_threads; i++) {
        printf("String #%d: %d\n", i+1, word_count[i]);
    }

    return 0;
}