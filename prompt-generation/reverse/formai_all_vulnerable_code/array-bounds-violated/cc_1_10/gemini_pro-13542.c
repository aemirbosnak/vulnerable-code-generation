//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Baggage statuses
#define ARRIVED 0
#define WAITING 1
#define LOADED 2
#define UNLOADED 3

// Baggage types
#define REGULAR 0
#define OVERSIZE 1
#define FRAGILE 2

// Belt speeds
#define SLOW 1
#define MEDIUM 2
#define FAST 3

// Constants
#define NUM_BAGS 100
#define NUM_BELTS 3
#define NUM_THREADS 10

// Global variables
int bags[NUM_BAGS];
int belts[NUM_BELTS];
pthread_mutex_t belt_mutexes[NUM_BELTS];
pthread_cond_t belt_conds[NUM_BELTS];

// Function to generate a random baggage type
int generate_baggage_type() {
    int type = rand() % 3;
    return type;
}

// Function to generate a random belt speed
int generate_belt_speed() {
    int speed = rand() % 3 + 1;
    return speed;
}

// Function to simulate the arrival of a baggage
void *arrive_baggage(void *arg) {
    int i = *(int *)arg;

    // Generate a random baggage type
    bags[i] = generate_baggage_type();
    
    printf("\033[KBaggage %d arrived: ", i); 
    printf((bags[i] == REGULAR) ? "Regular" : (bags[i] == OVERSIZE) ? "Oversize" : "Fragile");
    printf("\n");

    // Wait until there is space on a belt
    pthread_mutex_lock(&belt_mutexes[belts[i]]);
    while (belts[i] >= NUM_BAGS / NUM_BELTS) {
        pthread_cond_wait(&belt_conds[belts[i]], &belt_mutexes[belts[i]]);
    }
    
    // Put the baggage on the belt
    belts[i]++;
    printf("\033[KBaggage %d placed on belt %d\n", i, belts[i]); 
    
    // Signal that there is space on the belt
    pthread_cond_signal(&belt_conds[belts[i]]);
    pthread_mutex_unlock(&belt_mutexes[belts[i]]);

    return NULL;
}

// Function to simulate the loading of baggage onto a plane
void *load_baggage(void *arg) {
    int i = *(int *)arg;

    // Wait until there is baggage on the belt
    pthread_mutex_lock(&belt_mutexes[i]);
    while (belts[i] == 0) {
        pthread_cond_wait(&belt_conds[i], &belt_mutexes[i]);
    }

    // Take the baggage from the belt
    belts[i]--;
    printf("\033[KBaggage %d loaded onto plane %d\n", i, belts[i]); 
   
    // Signal that there is space on the belt
    pthread_cond_signal(&belt_conds[i]);
    pthread_mutex_unlock(&belt_mutexes[i]);

    return NULL;
}

// Function to simulate the unloading of baggage from a plane
void *unload_baggage(void *arg) {
    int i = *(int *)arg;

    // Wait until there is baggage on the belt
    pthread_mutex_lock(&belt_mutexes[i]);
    while (belts[i] == 0) {
        pthread_cond_wait(&belt_conds[i], &belt_mutexes[i]);
    }

    // Take the baggage from the belt
    belts[i]--;
    printf("\033[KBaggage %d unloaded from plane %d\n", i, belts[i]); 
   
    // Signal that there is space on the belt
    pthread_cond_signal(&belt_conds[i]);
    pthread_mutex_unlock(&belt_mutexes[i]);

    return NULL;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the belts
    for (int i = 0; i < NUM_BELTS; i++) {
        belts[i] = 0;
        pthread_mutex_init(&belt_mutexes[i], NULL);
        pthread_cond_init(&belt_conds[i], NULL);
    }

    // Create threads to simulate the arrival of baggage
    pthread_t arrive_threads[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        pthread_create(&arrive_threads[i], NULL, arrive_baggage, &i);
    }

    // Create threads to simulate the loading of baggage onto planes
    pthread_t load_threads[NUM_BELTS];
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_create(&load_threads[i], NULL, load_baggage, &i);
    }

    // Create threads to simulate the unloading of baggage from planes
    pthread_t unload_threads[NUM_BELTS];
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_create(&unload_threads[i], NULL, unload_baggage, &i);
    }

    // Join the threads
    for (int i = 0; i < NUM_BAGS; i++) {
        pthread_join(arrive_threads[i], NULL);
    }
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_join(load_threads[i], NULL);
    }
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_join(unload_threads[i], NULL);
    }

    // Destroy the mutexes and condition variables
    for (int i = 0; i < NUM_BELTS; i++) {
        pthread_mutex_destroy(&belt_mutexes[i]);
        pthread_cond_destroy(&belt_conds[i]);
    }

    return 0;
}