//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_VOTERS 10
#define VOTE_LENGTH 2

pid_t voter_pids[NUM_VOTERS];

void generate_random_vote(int voter_id) {
    int vote[VOTE_LENGTH];
    srand(time(NULL) + voter_id);
    for (int i = 0; i < VOTE_LENGTH; i++) {
        vote[i] = rand() % 3;
    }
    write(voter_pids[voter_id], vote, sizeof(vote));
}

int main() {
    int parent_pipe[2];
    pipe(parent_pipe);

    for (int i = 0; i < NUM_VOTERS; i++) {
        pid_t voter_pid = fork();
        if (voter_pid == 0) {
            close(parent_pipe[0]);
            generate_random_vote(i);
            exit(0);
        } else {
            voter_pids[i] = voter_pid;
            close(parent_pipe[1]);
        }
    }

    int result[VOTE_LENGTH] = {0};
    int num_votes = 0;

    for (int i = 0; i < NUM_VOTERS; i++) {
        pid_t voter_pid = voter_pids[i];
        wait(NULL);
        int vote[VOTE_LENGTH];
        read(parent_pipe[0], vote, sizeof(vote));
        for (int j = 0; j < VOTE_LENGTH; j++) {
            result[j] += vote[j];
        }
        num_votes++;
    }

    close(parent_pipe[0]);

    printf("Result: ");
    for (int i = 0; i < VOTE_LENGTH; i++) {
        printf("%d ", result[i] / num_votes);
    }
    printf("\n");

    return 0;
}