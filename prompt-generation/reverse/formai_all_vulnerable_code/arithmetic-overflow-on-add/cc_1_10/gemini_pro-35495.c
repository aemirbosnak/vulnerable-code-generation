//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[30];
    int votes;
    int lost;
};

struct election {
    struct candidate candidates[10];
    int num_candidates;
    int num_voters;
};

int main() {
    struct election election;
    
    // Initialize the election
    election.num_candidates = 0;
    election.num_voters = 0;
    
    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &election.num_candidates);
    
    // Get the names of the candidates
    for (int i = 0; i < election.num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", election.candidates[i].name);
    }
    
    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &election.num_voters);
    
    // Get the votes of the voters
    for (int i = 0; i < election.num_voters; i++) {
        int vote;
        printf("Enter the vote of voter %d: ", i + 1);
        scanf("%d", &vote);
        if (vote >= 1 && vote <= election.num_candidates) {
            election.candidates[vote - 1].votes++;
        } else {
            printf("Invalid vote\n");
        }
    }
    
    // Find the winning candidate
    int max_votes = 0;
    int winning_candidate = -1;
    for (int i = 0; i < election.num_candidates; i++) {
        if (election.candidates[i].votes > max_votes) {
            max_votes = election.candidates[i].votes;
            winning_candidate = i;
        }
    }
    
    // Print the winning candidate
    if (winning_candidate != -1) {
        printf("The winning candidate is %s.\n", election.candidates[winning_candidate].name);
    } else {
        printf("There was no majority winner.\n");
    }
    
    return 0;
}