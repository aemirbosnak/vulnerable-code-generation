//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int num_voters = 0;
int num_candidates = 0;
int *candidate_names;
int *candidate_votes;

void *vote(void *arg) {
    int *votes = (int *)arg;
    int voter_id = *((int *)arg);
    char candidate[100];
    int i;

    printf("Voter %d, please enter your vote for the candidate of your choice: ", voter_id);
    fflush(stdout);
    gets(candidate);

    for (i = 0; i < num_candidates; i++) {
        if (strcmp(candidate, candidate_names[i]) == 0) {
            candidate_votes[i]++;
        }
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    int i, j;

    candidate_names = (int *)malloc(num_candidates * sizeof(int));
    candidate_votes = (int *)malloc(num_candidates * sizeof(int));

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);
    fflush(stdin);

    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    fflush(stdin);

    for (i = 0; i < num_candidates; i++) {
        printf("Please enter the name of candidate %d: ", i + 1);
        fflush(stdout);
        gets(candidate_names[i]);
    }

    printf("\n");

    for (i = 0; i < num_candidates; i++) {
        printf("%s has %d votes\n", candidate_names[i], candidate_votes[i]);
    }

    for (i = 0; i < num_voters; i++) {
        int voter_id = i;
        pthread_t thread;
        int *votes = (int *)malloc(sizeof(int));
        *votes = voter_id;

        pthread_create(&thread, NULL, vote, votes);
        pthread_join(thread, NULL);
    }

    for (i = 0; i < num_candidates; i++) {
        if (candidate_votes[i] > 0) {
            printf("%s wins!\n", candidate_names[i]);
        }
    }

    return 0;
}