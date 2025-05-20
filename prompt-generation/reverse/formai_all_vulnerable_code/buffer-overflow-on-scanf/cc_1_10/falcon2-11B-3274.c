//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_VOTERS 10
#define NUM_OPTIONS 3

int voter_id[NUM_VOTERS];
int options[NUM_VOTERS][NUM_OPTIONS];
int votes[NUM_VOTERS][NUM_OPTIONS];

pthread_mutex_t lock;

void* vote(void* v) {
    int voter_id = *(int*)v;
    for (int i = 0; i < NUM_OPTIONS; i++) {
        printf("Enter your vote for option %d: ", i+1);
        scanf("%d", &votes[voter_id][i]);
        printf("\n");
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    pthread_t threads[NUM_VOTERS];
    int thread_id;

    for (int i = 0; i < NUM_VOTERS; i++) {
        voter_id[i] = i + 1;
        for (int j = 0; j < NUM_OPTIONS; j++) {
            options[i][j] = rand() % 100;
        }
        thread_id = i + 1;
        pthread_create(&threads[i], NULL, vote, &thread_id);
    }

    for (int i = 0; i < NUM_VOTERS; i++) {
        pthread_join(threads[i], NULL);
    }

    int max_votes = 0;
    int winning_option = 0;
    for (int i = 0; i < NUM_OPTIONS; i++) {
        int max_votes_option = 0;
        for (int j = 0; j < NUM_VOTERS; j++) {
            if (votes[j][i] > max_votes_option) {
                max_votes_option = votes[j][i];
            }
        }
        if (max_votes_option > max_votes) {
            max_votes = max_votes_option;
            winning_option = i;
        }
    }

    printf("Winning option: %d\n", winning_option+1);

    return 0;
}