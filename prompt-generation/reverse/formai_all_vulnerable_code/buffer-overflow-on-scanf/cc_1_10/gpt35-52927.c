//FormAI DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_STRING_LENGTH 50 // Max length of input string
#define MAX_THREADS 3 // Max number of threads

// Function to uppercase each character of a given string
void* upper_func(void* arg) {
    char* str = (char*) arg;
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }

    pthread_exit(NULL);
}

// Function to reverse a given string
void* reverse_func(void* arg) {
    char* str = (char*) arg;
    int len = strlen(str);

    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    pthread_exit(NULL);
}

// Main function
int main() {
    char input[MAX_STRING_LENGTH];
    pthread_t threads[MAX_THREADS];

    // Get input string from user
    printf("Enter a string of maximum length %d: ", MAX_STRING_LENGTH);
    scanf("%[^\n]", input);
    getchar(); // Consume newline character

    // Create threads for uppercase and reverse operations
    if (pthread_create(&threads[0], NULL, upper_func, input) != 0) {
        printf("Error creating thread 1!");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&threads[1], NULL, reverse_func, input) != 0) {
        printf("Error creating thread 2!");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    for (int i = 0; i < MAX_THREADS; ++i) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d!", i+1);
            exit(EXIT_FAILURE);
        }
    }

    // Print final output string
    printf("Output string: %s", input);

    return 0;
}