//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_VOTERS 5
#define NUM_CANDIDATES 3
#define MAX_VOTES 10

// Global variables
int num_votes[NUM_CANDIDATES] = {0};
int num_voters = 0;
int finished_voters = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *voter(void *arg) {
    int candidate;
    scanf("%d", &candidate);

    // Lock the mutex to ensure only one voter at a time
    pthread_mutex_lock(&lock);

    num_votes[candidate - 1]++;
    num_voters++;

    // Unlock the mutex
    pthread_mutex_unlock(&lock);

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_VOTERS];
    int i;

    for (i = 0; i < NUM_VOTERS; i++) {
        pthread_create(&threads[i], NULL, voter, (void *)i + 1);
    }

    for (i = 0; i < NUM_VOTERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the results
    printf("Election results:\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d received %d votes.\n", i + 1, num_votes[i]);
    }

    return 0;
}