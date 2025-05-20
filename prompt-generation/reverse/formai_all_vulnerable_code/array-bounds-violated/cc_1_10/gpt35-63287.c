//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Candidate {
    int id;
    char name[50];
    int votes;
};

int main () {
    int num_of_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_of_candidates);
    
    struct Candidate candidates[num_of_candidates];
    
    // Input candidate information
    printf("Enter candidate information:\n");
    for (int i = 0; i < num_of_candidates; i++) {
        printf("Enter candidate %d ID: ", i+1);
        scanf("%d", &candidates[i].id);
        printf("Enter candidate %d Name: ", i+1);
        scanf("%s", &candidates[i].name);
        candidates[i].votes = 0;
    }
    
    // Voting process
    int voter_id;
    int candidate_id;
    while (1) {
        printf("\nEnter your voter ID (press -1 to stop): ");
        scanf("%d", &voter_id);
        if (voter_id == -1)
            break;
        printf("Enter the candidate ID you want to vote for: ");
        scanf("%d", &candidate_id);
        for (int i = 0; i < num_of_candidates; i++) {
            if (candidates[i].id == candidate_id) {
                candidates[i].votes++;
                printf("Your vote for candidate %d is recorded.", candidate_id);
                break;
            }
        }
    }

    // Count votes and declare winner
    int winner_index = 0;
    int max_votes = candidates[0].votes;
    int total_votes = candidates[0].votes;
    for (int i = 1; i < num_of_candidates; i++) {
        total_votes += candidates[i].votes;
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("\nTotal number of votes: %d", total_votes);
    printf("\nCandidate %d (%s) has won with %d votes!\n", 
            candidates[winner_index].id, candidates[winner_index].name, max_votes);

    return 0;
}