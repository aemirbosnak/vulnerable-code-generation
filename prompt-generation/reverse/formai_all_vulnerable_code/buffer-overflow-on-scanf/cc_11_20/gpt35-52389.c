//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[20];
    int votes;
};

int main() {
    int num_candidates, num_voters, i, j, k, voter_id, vote_count;
    char temp_name[20];
    struct candidate *candidates;
    int *voter_votes;
    FILE *fp;
    
    // Read in number of candidates and allocate memory for candidates array
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));
    
    // Read in candidate names and initialize votes to 0
    for (i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    // Read in number of voters and allocate memory for voter_votes array
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    voter_votes = (int*) malloc(num_voters * sizeof(int));
    
    // Read in voter IDs and initialize votes to -1
    for (i = 0; i < num_voters; i++) {
        printf("Enter ID of voter %d: ", i+1);
        scanf("%d", &voter_id);
        voter_votes[i] = -1;
    }
    
    // Allow each voter to cast their vote
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d, here are your choices:\n", i+1);
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your vote (1-%d): ", num_candidates);
        scanf("%d", &vote_count);
        
        // Check if vote is valid
        if (vote_count < 1 || vote_count > num_candidates) {
            printf("Invalid vote.\n");
            i--;
            continue;
        }
        
        // Check if voter has already voted
        if (voter_votes[i] != -1) {
            printf("You have already voted.\n");
            i--;
            continue;
        }
        
        // Update vote count for candidate and mark voter as voted
        candidates[vote_count-1].votes++;
        voter_votes[i] = vote_count-1;
    }
    
    // Output election results to file
    fp = fopen("election_results.txt", "w");
    fprintf(fp, "Election Results:\n\n");
    for (i = 0; i < num_candidates; i++) {
        fprintf(fp, "%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    
    // Output candidate with highest number of votes
    int max_votes = -1;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            strcpy(temp_name, candidates[i].name);
        }
    }
    fprintf(fp, "\nWinner: %s\n", temp_name);
    fclose(fp);
    
    // Free allocated memory
    free(candidates);
    free(voter_votes);
    
    return 0;
}