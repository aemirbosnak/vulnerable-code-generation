//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Global variables
int num_candidates;
char **candidate_names;
int *candidate_votes;
int total_votes;
int max_votes;
pthread_mutex_t vote_mutex;

// Function prototypes
void *count_votes(void *arg);
void print_results();

int main() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidate_names = (char **)malloc(num_candidates * sizeof(char *));
    candidate_votes = (int *)malloc(num_candidates * sizeof(int));

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidate_names[i]);
        candidate_votes[i] = 0;
    }

    max_votes = num_candidates;
    total_votes = 0;

    printf("\nVoting has started...\n");

    pthread_mutex_init(&vote_mutex, NULL);

    int voter_id = 1;
    while (total_votes < max_votes) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, count_votes, (void *)&voter_id);
        voter_id++;
    }

    printf("\nVoting has ended.\n");
    print_results();

    return 0;
}

void *count_votes(void *arg) {
    int voter_id = *((int *)arg);

    printf("\nVoter %d is voting...\n", voter_id);
    sleep(1);

    pthread_mutex_lock(&vote_mutex);

    printf("Enter the ID of the candidate you want to vote for: ");
    int candidate_id;
    scanf("%d", &candidate_id);

    candidate_votes[candidate_id - 1]++;
    total_votes++;

    printf("\nThank you for voting, Voter %d.\n", voter_id);

    pthread_mutex_unlock(&vote_mutex);

    return NULL;
}

void print_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidate_names[i], candidate_votes[i]);
    }
}