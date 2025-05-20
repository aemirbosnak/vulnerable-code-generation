//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

char strings[MAX_THREADS][MAX_STRING_LENGTH];
int string_lengths[MAX_THREADS];
pthread_t threads[MAX_THREADS];

void *palindrome_checker(void *arg) {
    int thread_id = *(int *) arg;
    int i, j;

    for (i = thread_id * MAX_STRING_LENGTH / MAX_THREADS;
         i < (thread_id + 1) * MAX_STRING_LENGTH / MAX_THREADS;
         i++) {
        if (i >= string_lengths[thread_id])
            break;

        for (j = 0; j < string_lengths[thread_id] - i; j++) {
            if (strings[thread_id][i + j]!= strings[thread_id][i - j - 1]) {
                printf("Thread %d: Not a palindrome\n", thread_id);
                pthread_exit(0);
            }
        }
    }

    printf("Thread %d: Palindrome\n", thread_id);
    pthread_exit(0);
}

int main() {
    int i, num_strings;

    printf("Enter the number of strings: ");
    scanf("%d", &num_strings);

    if (num_strings > MAX_THREADS || num_strings <= 0) {
        printf("Invalid number of strings\n");
        exit(1);
    }

    for (i = 0; i < num_strings; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
        string_lengths[i] = strlen(strings[i]);
    }

    for (i = 0; i < num_strings; i++) {
        pthread_create(&threads[i], NULL, palindrome_checker, (void *) &i);
    }

    for (i = 0; i < num_strings; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}