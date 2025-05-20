//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int num_voters = 0;
int num_candidates = 0;
int* candidates = NULL;
int* votes = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* cast_vote(void* arg) {
    int* vote = (int*)arg;
    pthread_mutex_lock(&lock);
    int candidate_id = *vote;
    if (candidate_id < 0 || candidate_id >= num_candidates) {
        fprintf(stderr, "Invalid candidate ID: %d\n", candidate_id);
        exit(1);
    }
    votes[candidate_id]++;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[num_voters];
    int num_threads = 0;

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidates = (int*)malloc(sizeof(int) * num_candidates);
    votes = (int*)malloc(sizeof(int) * num_candidates);

    printf("Enter the candidate IDs (separated by space): ");
    fflush(stdout);
    fgets(candidates, num_candidates * sizeof(int), stdin);
    sscanf(candidates, "%*s %d %*s %d %*s %d %*s %d", &candidates[0], &candidates[1], &candidates[2], &candidates[3]);

    printf("Enter the votes (separated by space): ");
    fflush(stdout);
    fgets(votes, num_voters * sizeof(int), stdin);
    sscanf(votes, "%*s %d %*s %d %*s %d %*s %d", &votes[0], &votes[1], &votes[2], &votes[3]);

    for (int i = 0; i < num_voters; i++) {
        int* vote = &votes[i];
        pthread_create(&threads[num_threads], NULL, cast_vote, (void*)vote);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: %d votes\n", i + 1, votes[i]);
    }

    return 0;
}