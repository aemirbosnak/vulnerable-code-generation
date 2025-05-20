//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_STR_LEN 100

typedef struct {
    char *str;
    int start;
    int end;
    int is_palindrome;
} thread_args;

void *check_palindrome(void *args) {
    thread_args *arg = (thread_args *)args;
    arg->is_palindrome = 1;
    for (int i = arg->start; i <= arg->end; i++) {
        if (arg->str[i] != arg->str[arg->end - i]) {
            arg->is_palindrome = 0;
            break;
        }
    }
    return NULL;
}

int main() {
    char str[MAX_STR_LEN];
    int len;

    // Get the input string
    printf("Enter a string: ");
    scanf("%s", str);

    // Get the length of the string
    len = strlen(str);

    // Create an array of thread arguments
    thread_args args[MAX_THREADS];

    // Divide the string into equal parts and create threads
    int part_size = len / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        args[i].str = str;
        args[i].start = i * part_size;
        args[i].end = (i + 1) * part_size - 1;
    }

    // Create threads
    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, check_palindrome, &args[i]);
    }

    // Join threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check if the string is a palindrome
    int is_palindrome = 1;
    for (int i = 0; i < MAX_THREADS; i++) {
        is_palindrome &= args[i].is_palindrome;
    }

    // Print the result
    printf("Is the string a palindrome? %s\n", is_palindrome ? "Yes" : "No");

    return 0;
}