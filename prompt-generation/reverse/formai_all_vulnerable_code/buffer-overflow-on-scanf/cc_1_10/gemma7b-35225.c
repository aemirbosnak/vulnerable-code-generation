//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char voter_id, int candidate_id) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == voter_id) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int i, j, total_votes = 0;
    time_t t;
    char voter_id[20];
    int candidate_id;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Get the current time
    t = time(NULL);

    // Start the voting process
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    printf("Enter the candidate ID you want to vote for: ");
    scanf("%d", &candidate_id);

    vote(voter_id, candidate_id);

    // Calculate the total number of votes
    for (i = 0; i < MAX_CANDIDATES; i++) {
        total_votes += candidates[i].votes;
    }

    // Print the results
    printf("The total number of votes is: %d", total_votes);

    return 0;
}