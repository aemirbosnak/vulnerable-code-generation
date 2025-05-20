//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 1000

// Mutex for critical section
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to be executed by each thread
void *count_vowels(void *arg) {
    char *string = (char *) arg;
    int count = 0;

    // Iterate through the string and count vowels
    for (int i = 0; string[i]!= '\0'; i++) {
        if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u') {
            count++;
        }
    }

    // Print the result
    printf("Thread %d counted %d vowels in the string '%s'\n", (int) pthread_self(), count, string);

    return NULL;
}

int main() {
    char input_string[MAX_STRING_LENGTH];

    // Get input string from user
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    // Remove newline character from input string
    input_string[strcspn(input_string, "\n")] = '\0';

    // Create threads
    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    // Split input string into substrings for each thread
    int substring_length = strlen(input_string) / MAX_THREADS;
    for (int i = 0; i < MAX_THREADS; i++) {
        if (i == MAX_THREADS - 1) {
            substring_length = strlen(input_string) - (MAX_THREADS - 1) * substring_length;
        }

        // Create substring
        char *substring = (char *) malloc(substring_length + 1);
        strncpy(substring, input_string + i * substring_length, substring_length);
        substring[substring_length] = '\0';

        // Create thread
        pthread_create(&threads[thread_count], NULL, count_vowels, (void *) substring);
        thread_count++;
    }

    // Join threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}