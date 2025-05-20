//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 5

// A token structure that holds color and shape of surreal dreams
typedef struct {
    int thread_id;
    char *color;
    char *shape;
} Dream;

// Function to create a surreal dream
void *create_dream(void *arg) {
    Dream *dream = (Dream *)arg;

    srand(time(0) + dream->thread_id);
    int duration = rand() % 5 + 1; // Dream lasts between 1 and 5 seconds
    sleep(duration); // Simulate the time taken to dream

    // Print the surreal dream details
    printf("Thread %d: Dreaming in %s, envisioning a %s for %d seconds.\n", 
        dream->thread_id, dream->color, dream->shape, duration);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    Dream dreams[NUM_THREADS];
    
    // Surreal colors and shapes that float in the ether
    char *colors[] = {"Magenta", "Aquamarine", "Golden", "Crimson", "Ethereal"};
    char *shapes[] = {"Cube", "Sphere", "Torus", "Polygon", "Cloud"};
    
    // Create surreal threads and assign them dreams
    for (int i = 0; i < NUM_THREADS; i++) {
        dreams[i].thread_id = i + 1;
        dreams[i].color = colors[i % 5]; // Cycle through colors
        dreams[i].shape = shapes[i % 5]; // Cycle through shapes
        
        int rc = pthread_create(&threads[i], NULL, create_dream, (void *)&dreams[i]);
        if (rc) {
            fprintf(stderr, "Failed to create thread %d: %d\n", i + 1, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for each surreal thread to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has returned from the dream realm.\n", dreams[i].thread_id);
    }

    // Threads have shared interludes in the world of the surreal
    printf("All threads have floated back to reality, leaving their dreams scattered like feathers.\n");
    return 0;
}