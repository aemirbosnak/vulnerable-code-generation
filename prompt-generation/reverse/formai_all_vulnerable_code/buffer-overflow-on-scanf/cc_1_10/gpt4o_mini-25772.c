//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10  // Maximum number of threads to be used
#define MAX_HEIGHT 10   // Height of the pattern

typedef struct {
    int thread_id;
    int height;
} thread_data_t;

void *print_pyramid(void *threadarg) {
    thread_data_t *data = (thread_data_t *)threadarg;
    int i, j;

    for (i = 1; i <= data->height; i++) {
        // Print spaces for pyramid shape
        for (j = i; j < data->height; j++) {
            printf(" ");
        }

        // Print stars
        for (j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }

        printf("\n");
        sleep(1);  // Sleep to simulate some delay
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    int rc, height;

    // Get the height from the user
    printf("Enter the height of the pyramid (max %d): ", MAX_HEIGHT);
    scanf("%d", &height);
    if (height > MAX_HEIGHT) {
        fprintf(stderr, "Height exceeds maximum allowed (%d)\n", MAX_HEIGHT);
        return EXIT_FAILURE;
    }

    // Create threads for the pyramid printing
    for (int t = 0; t < NUM_THREADS; t++) {
        thread_data[t].thread_id = t;
        thread_data[t].height = height;

        // Create a new thread
        rc = pthread_create(&threads[t], NULL, print_pyramid, (void *)&thread_data[t]);
        if (rc) {
            fprintf(stderr, "Error: unable to create thread %d, %d\n", t, rc);
            return EXIT_FAILURE;
        }
    }

    // Wait for all threads to finish
    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Pyramid printed successfully!\n");
    pthread_exit(NULL);
    return 0;
}