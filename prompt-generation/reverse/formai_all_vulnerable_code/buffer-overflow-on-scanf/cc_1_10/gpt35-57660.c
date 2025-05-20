//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct Candidate {
    char* name;
    int votes;
} Candidate;

int main() {
    int totalCandidates, totalVoters, i, flag = 0;
    printf("Enter total number of candidates: ");
    scanf("%d", &totalCandidates);
    
    Candidate candidates[totalCandidates];
    
    // get candidate names
    for(i = 0; i < totalCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        char* name = malloc(sizeof(char)*50);
        scanf("%s", name);
        candidates[i].name = name;
        candidates[i].votes = 0;
    }
    
    printf("Enter total number of voters: ");
    scanf("%d", &totalVoters);
    
    // get user input
    for(i = 0; i < totalVoters; i++) {
        printf("Vote for candidate number (1-%d): ", totalCandidates);
        int choice;
        scanf("%d", &choice);
        
        // validate input
        if(choice < 1 || choice > totalCandidates) {
            printf("Invalid input! Please vote for candidate number (1-%d)\n", totalCandidates);
            i--;
            continue;
        }
        
        candidates[choice-1].votes++;
        printf("Thank you for voting!\n");
    }
    
    // print results
    printf("############### RESULTS ###############\n");
    for(i = 0; i < totalCandidates; i++) {
        printf("%d. %s: %d votes\n", i+1, candidates[i].name, candidates[i].votes);
        if(candidates[i].votes > totalVoters / 2) {
            flag = 1;
            printf("Candidate %s WON!\n", candidates[i].name);
        }
    }
    
    if(flag == 0) {
        printf("No candidate received majority of votes. A runoff election will be held.\n");
    }

    return 0;
}