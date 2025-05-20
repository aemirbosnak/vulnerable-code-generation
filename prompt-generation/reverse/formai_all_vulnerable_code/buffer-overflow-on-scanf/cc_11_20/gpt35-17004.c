//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int voted;
};

int main() {
    int num_candidates, num_voters, i, j, k;
    char temp[50];
    
    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    // Initialize the candidates array
    struct candidate candidates[MAX_CANDIDATES];
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    
    // Initialize the voters array
    struct voter voters[MAX_VOTERS];
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
    
    // Allow the voters to vote
    for (i = 0; i < num_voters; i++) {
        while (1) {
            printf("Voter %s, please enter the name of your candidate: ", voters[i].name);
            scanf("%s", temp);
            for (j = 0; j < num_candidates; j++) {
                if (strcmp(temp, candidates[j].name) == 0) {
                    candidates[j].votes++;
                    voters[i].voted = 1;
                    break;
                }
            }
            if (j != num_candidates) {
                break;
            }
            printf("Invalid candidate name. Please try again.\n");
        }
    }
    
    // Print the results
    printf("Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
    
    // Find the winner
    int max_votes = -1;
    int max_index = -1;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            max_index = i;
        }
    }
    if (max_index >= 0) {
        printf("Winner: %s\n", candidates[max_index].name);
    }
    else {
        printf("No winner.\n");
    }
    
    return 0;
}