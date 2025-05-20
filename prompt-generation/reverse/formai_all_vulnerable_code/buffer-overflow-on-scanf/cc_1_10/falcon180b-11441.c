//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORD_LENGTH 100

char words[MAX_THREADS][MAX_WORD_LENGTH];
int word_lengths[MAX_THREADS];
int num_threads;

void *check_palindrome(void *arg) {
    int i = *(int *) arg;
    char *word = words[i];
    int length = word_lengths[i];

    if (is_palindrome(word, length)) {
        printf("Thread %d found a palindrome: %s\n", i, word);
    } else {
        printf("Thread %d did not find a palindrome: %s\n", i, word);
    }

    return NULL;
}

int is_palindrome(char *word, int length) {
    for (int i = 0; i < length / 2; i++) {
        if (word[i]!= word[length - i - 1]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    printf("Enter the words to check for palindromes:\n");
    for (int i = 0; i < num_threads; i++) {
        scanf("%s", words[i]);
        word_lengths[i] = strlen(words[i]);
    }

    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, check_palindrome, (void *) &i);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}