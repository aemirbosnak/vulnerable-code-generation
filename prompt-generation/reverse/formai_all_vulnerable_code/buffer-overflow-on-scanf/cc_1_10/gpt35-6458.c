//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include <stdio.h>

struct candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates, num_voters, num_votes = 0;
    printf("Welcome to the Electronic Voting System\n\n");
    
    // Get number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate candidates[num_candidates];
    
    // Get candidate names
    printf("\nEnter the names of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    // Get number of voters
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);
    
    // Conduct election
    for (int i = 0; i < num_voters; i++) {
        printf("\nVoter %d, please enter your candidate choice:\n", i+1);
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        int choice;
        scanf("%d", &choice);
        candidates[choice-1].votes++;
        num_votes++;
    }
    
    // Display results
    printf("\nELECTION RESULTS\n");
    printf("Total votes cast: %d\n", num_votes);
    printf("Candidate\tVotes Received\tPercentage\n");
    for (int i = 0; i < num_candidates; i++) {
        float percentage = (float) candidates[i].votes / num_votes * 100;
        printf("%s\t\t%d\t\t%.2f%%\n", candidates[i].name, candidates[i].votes, percentage);
    }
    return 0;
}