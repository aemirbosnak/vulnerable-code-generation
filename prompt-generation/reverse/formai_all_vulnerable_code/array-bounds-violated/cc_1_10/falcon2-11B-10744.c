//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Define the candidate names and their respective ID
char *candidate_names[] = {"Candidate A", "Candidate B", "Candidate C", "Candidate D"};
int candidate_ids[] = {1, 2, 3, 4};

// Define the number of candidates
int num_candidates = sizeof(candidate_ids) / sizeof(int);

// Define the number of votes
int num_votes = 10;

// Function to cast a vote
void cast_vote(int candidate_id) {
    // Randomly select the voter's name
    char voter_name[50];
    strcpy(voter_name, "Voter");
    srand(time(NULL));
    int rand_num = rand() % (num_candidates + 1);
    if (rand_num == 0) {
        strcat(voter_name, " (0)");
    } else {
        strcat(voter_name, " (");
        strcat(voter_name, candidate_names[candidate_ids[rand_num] - 1]);
        strcat(voter_name, ")");
    }

    // Print the voter's name and the vote
    printf("%s voted for %s\n", voter_name, candidate_names[candidate_id - 1]);
}

// Main function
int main() {
    int vote_id = 1;
    while (vote_id <= num_votes) {
        printf("Vote %d: Who did you vote for? (1-%d): ", vote_id, num_candidates);
        int candidate_id = 0;
        while (candidate_id <= num_candidates) {
            printf("%s ", candidate_names[candidate_id - 1]);
            candidate_id = scanf("%d", &candidate_id);
            if (candidate_id!= -1) {
                break;
            }
        }
        cast_vote(candidate_id);
        vote_id++;
    }
    return 0;
}