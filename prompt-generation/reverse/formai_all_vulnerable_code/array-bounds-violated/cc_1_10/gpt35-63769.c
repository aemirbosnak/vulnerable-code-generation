//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_OF_CANDIDATES 5
#define NUM_OF_VOTERS 50

pthread_mutex_t mutex_lock;
int vote_count[NUM_OF_CANDIDATES];

void *vote_function(void *arg) {
    int candidate_index = (int)arg;
    int voter_id;
    for(voter_id = 0; voter_id < NUM_OF_VOTERS; voter_id++) {
        pthread_mutex_lock(&mutex_lock);
        vote_count[candidate_index]++;
        pthread_mutex_unlock(&mutex_lock);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_OF_CANDIDATES];
    pthread_attr_t attr;
    int index;

    /* Initialize mutex */
    pthread_mutex_init(&mutex_lock, NULL);

    /* Initialize attributes */
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    /* Create threads */
    for (index = 0; index < NUM_OF_CANDIDATES; index++) {
        int candidate_number = index+1;
        pthread_create(&threads[index], &attr, vote_function, (void*)candidate_number);
    }

    /* Wait for all threads to complete */
    for (index = 0; index < NUM_OF_CANDIDATES; index++) {
        pthread_join(threads[index], NULL);
    }

    /* Destroy mutex and attribute objects */
    pthread_mutex_destroy(&mutex_lock);
    pthread_attr_destroy(&attr);

    /* Display the vote count for each candidate */
    for(index = 0; index < NUM_OF_CANDIDATES; index++) {
        printf("Candidate[%d]: %d\n", index+1, vote_count[index]);
    }

    pthread_exit(NULL);
}