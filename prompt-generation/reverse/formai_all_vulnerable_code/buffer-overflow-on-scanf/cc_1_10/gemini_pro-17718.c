//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// Candidate struct
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Voter struct
typedef struct voter {
    char name[50];
    int voted;
    candidate_t *candidate;
} voter_t;

// Global variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
candidate_t candidates[3] = {{"Alice", 0}, {"Bob", 0}, {"Eve", 0}};
voter_t voters[100];
int num_voters = 0;

// Function to add a voter
void add_voter(char *name) {
    pthread_mutex_lock(&mutex);
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted = 0;
    voters[num_voters].candidate = NULL;
    num_voters++;
    pthread_mutex_unlock(&mutex);
}

// Function to vote for a candidate
void vote(char *name, char *candidate_name) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            if (voters[i].voted == 1) {
                printf("Error: Voter has already voted\n");
            } else {
                for (int j = 0; j < 3; j++) {
                    if (strcmp(candidates[j].name, candidate_name) == 0) {
                        voters[i].candidate = &candidates[j];
                        voters[i].voted = 1;
                        candidates[j].votes++;
                        printf("Vote cast successfully\n");
                        break;
                    }
                }
            }
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
}

// Function to count the votes
void count_votes() {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < 3; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    pthread_mutex_unlock(&mutex);
}

// Main function
int main() {
    char command[100];
    while (1) {
        printf("Enter command (add, vote, count, exit): ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char name[50];
            printf("Enter voter name: ");
            scanf("%s", name);
            add_voter(name);
        } else if (strcmp(command, "vote") == 0) {
            char name[50], candidate_name[50];
            printf("Enter voter name: ");
            scanf("%s", name);
            printf("Enter candidate name: ");
            scanf("%s", candidate_name);
            vote(name, candidate_name);
        } else if (strcmp(command, "count") == 0) {
            count_votes();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}