//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define VOTERS 5
#define CANDIDATES 3

int candidate_votes[CANDIDATES] = {0};
int total_votes = 0;
int max_votes = 0;
int winner = -1;

sem_t mutex;
sem_t vote_sem;
sem_t result_sem;

void init_semaphores() {
    sem_init(&mutex, 0, 1);
    sem_init(&vote_sem, 0, VOTERS - 1);
    sem_init(&result_sem, 0, 0);
}

void* vote(void* arg) {
    int candidate = *(int*) arg;
    sem_wait(&vote_sem);

    sem_wait(&mutex);
    candidate_votes[candidate]++;
    total_votes++;

    if (candidate_votes[candidate] > max_votes) {
        max_votes = candidate_votes[candidate];
        winner = candidate;
    }

    sem_post(&mutex);
    sem_post(&result_sem);
}

void* result(void* arg) {
    sem_wait(&result_sem);

    sem_wait(&mutex);
    printf("Total votes: %d\n", total_votes);
    printf("Max votes: %d\n", max_votes);
    printf("Winner: %d\n", winner);

    sem_post(&mutex);
}

int main() {
    pthread_t threads[VOTERS];
    int votes[VOTERS] = {1, 2, 3, 4, 5};

    init_semaphores();

    for (int i = 0; i < VOTERS; i++) {
        pthread_create(&threads[i], NULL, vote, &votes[i]);
    }

    for (int i = 0; i < VOTERS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_t result_thread;
    pthread_create(&result_thread, NULL, result, NULL);

    pthread_join(result_thread, NULL);

    return 0;
}