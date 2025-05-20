//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 3

void *perform_task(void *threadid) {
    long tid = (long)threadid;
    int sleep_time;

    // Generate a random sleep time for each thread
    srand(time(NULL) + tid);
    sleep_time = rand() % 5 + 1; // Sleep for 1 to 5 seconds

    printf("Thread %ld: Preparing for a wild ride! Sleeping for %d seconds...\n", tid, sleep_time);
    sleep(sleep_time);

    printf("Thread %ld: Whoa! I just woke up! Doing something crazy...\n", tid);
    
    // Each thread behaves differently based on its ID
    switch (tid) {
        case 0:
            printf("Thread %ld: I'm the thinker! Solving the riddle of the universe...\n", tid);
            break;
        case 1:
            printf("Thread %ld: I'm the joker! Telling jokes to lighten the mood...\n", tid);
            break;
        case 2:
            printf("Thread %ld: I'm the dreamer! Spreading positivity and good vibes!\n", tid);
            break;
        default:
            printf("Thread %ld: Who knows what I’m up to...\n", tid);
            break;
    }

    printf("Thread %ld: Task complete! What’s next? Let’s join the party!\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    printf("Hey there! Welcome to the thrilling world of Multi-threading Madness!\n");

    // Creating threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Main: Creating thread %ld...\n", t);
        rc = pthread_create(&threads[t], NULL, perform_task, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Joining threads
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Main: Waiting for thread %ld to finish...\n", t);
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: Thread %ld has finished its deliciously chaotic task!\n", t);
    }

    printf("All threads have completed their journeys! What a ride!\n");
    pthread_exit(NULL);
}