//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 5

// Function to print a character pattern horizontally
void *printHorizontalLine(void *arg) {
    int thread_id = *((int *)arg);
    char character = 'A' + thread_id; // character from 'A'
    for (int j = 0; j < 5; j++) {
        printf("%c ", character);
        fflush(stdout);
        usleep(200000); // Sleep for 200 milliseconds
    }
    printf("\n");
    pthread_exit(NULL);
}

// Function to print a character pattern vertically
void *printVerticalLine(void *arg) {
    int thread_id = *((int *)arg);
    char character = 'A' + thread_id; // character from 'A'
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < thread_id; k++) {
            printf("  "); // Printing spaces for alignment
        }
        printf("%c\n", character);
        fflush(stdout);
        usleep(200000); // Sleep for 200 milliseconds
    }
    pthread_exit(NULL);
}

// Function to print a pyramid pattern
void *printPyramid(void *arg) {
    int thread_id = *((int *)arg);
    char character = 'A' + thread_id; // character from 'A'
    for (int j = 0; j < 5; j++) {
        for (int k = 0; k < 5 - j; k++) {
            printf("  "); // Printing spaces for alignment
        }
        for (int k = 0; k <= j; k++) {
            printf("%c ", character);
        }
        printf("\n");
        fflush(stdout);
        usleep(200000); // Sleep for 200 milliseconds
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    char patternType[20];

    printf("Choose a pattern type (horizontal, vertical, pyramid): ");
    scanf("%s", patternType);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i; // Assign thread id
        if (strcmp(patternType, "horizontal") == 0) {
            pthread_create(&threads[i], NULL, printHorizontalLine, (void *)&thread_ids[i]);
        } else if (strcmp(patternType, "vertical") == 0) {
            pthread_create(&threads[i], NULL, printVerticalLine, (void *)&thread_ids[i]);
        } else if (strcmp(patternType, "pyramid") == 0) {
            pthread_create(&threads[i], NULL, printPyramid, (void *)&thread_ids[i]);
        } else {
            printf("Invalid pattern type!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Joining threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Completed printing the %s pattern.\n", patternType);
    return 0;
}