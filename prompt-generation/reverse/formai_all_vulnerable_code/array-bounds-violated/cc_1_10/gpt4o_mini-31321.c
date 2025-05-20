//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: multi-threaded
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define NUM_THREADS 4

char inputString[MAX_LENGTH];
int isPalindrome = 1; // Flag to indicate if the string is a palindrome
pthread_mutex_t mutex;

typedef struct {
    int start;
    int end;
} ThreadData;

void *checkPalindrome(void *data) {
    ThreadData *threadData = (ThreadData *)data;
    int start = threadData->start;
    int end = threadData->end;

    for (int i = start; i < end; i++) {
        // Compare characters from start and end moving towards the center
        if (tolower(inputString[i]) != tolower(inputString[end - 1 - i + start])) {
            pthread_mutex_lock(&mutex);
            isPalindrome = 0; // Set flag to false if mismatch found
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData threadData[NUM_THREADS];
    int len, segment, remainder;

    printf("Enter a string (max %d characters): ", MAX_LENGTH);
    fgets(inputString, MAX_LENGTH, stdin);
    len = strlen(inputString);
    
    // Remove newline character if present
    if (inputString[len - 1] == '\n') {
        inputString[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("String is empty!\n");
        return 0;
    }

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    segment = len / NUM_THREADS;
    remainder = len % NUM_THREADS;

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadData[i].start = i * segment;
        threadData[i].end = (i + 1) * segment;

        // Handle the last thread to include any remaining characters
        if (i == NUM_THREADS - 1) {
            threadData[i].end += remainder;
        }

        // Check bounds of the end for the last segment
        if (threadData[i].end > len) {
            threadData[i].end = len;
        }

        pthread_create(&threads[i], NULL, checkPalindrome, (void *)&threadData[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check the final result
    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", inputString);
    } else {
        printf("\"%s\" is not a palindrome.\n", inputString);
    }

    // Cleanup
    pthread_mutex_destroy(&mutex);
    return 0;
}