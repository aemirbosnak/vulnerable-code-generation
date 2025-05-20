//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LEN 100

char input_strings[MAX_THREADS][MAX_STRING_LEN];
int string_lens[MAX_THREADS];
int num_threads;

void *check_palindrome(void *arg) {
    int i;
    char *input_string = (char *) arg;
    int string_len = strlen(input_string);

    // Check if the input string is a palindrome
    for (i = 0; i < string_len / 2; i++) {
        if (input_string[i]!= input_string[string_len - i - 1]) {
            return 0;
        }
    }

    // If the input string is a palindrome, print a message to the console
    printf("Thread %d: %s is a palindrome.\n", pthread_self(), input_string);

    return 1;
}

int main() {
    int i;
    char input_string;

    // Get the number of threads from the user
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Get the input strings from the user
    for (i = 0; i < num_threads; i++) {
        printf("Enter string for thread %d: ", i);
        scanf("%s", input_strings[i]);
        string_lens[i] = strlen(input_strings[i]);
    }

    // Create the threads
    pthread_t threads[MAX_THREADS];
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, check_palindrome, (void *) input_strings[i]);
    }

    // Join the threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}