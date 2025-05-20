//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold candidate information
typedef struct Candidate {
    char name[50];
    int votes;
} Candidate;

// function prototypes
int getNumCandidates();
void getCandidates(Candidate candidates[], int num);
void printCandidates(Candidate candidates[], int num);
int castVote(Candidate candidates[], int num, int choice);

int main() {
    // get number of candidates from user
    int numCandidates = getNumCandidates();
    
    // allocate memory for candidates
    Candidate *candidates = (Candidate*) malloc(numCandidates * sizeof(Candidate));
    
    // get candidate information from user
    getCandidates(candidates, numCandidates);
    
    // display candidate information
    printCandidates(candidates, numCandidates);
    
    // initialize vote count
    int totalVotes = 0;
    
    // loop to allow users to cast votes
    int vote = 0;
    while (vote != -1) {
        printf("Enter your vote (1-%d or -1 to quit): ", numCandidates);
        scanf("%d", &vote);
        
        // validate vote choice
        if (vote >= 1 && vote <= numCandidates) {
            // increment candidate's vote count
            candidates[vote-1].votes++;
            
            // increment total vote count
            totalVotes++;
            
            printf("Vote recorded for %s.\n", candidates[vote-1].name);
        } else if (vote == -1) {
            printf("Exiting voting system.\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    // display final voting results
    printf("\nVoting Results\n");
    printf("---------------------------\n");
    printf("Total Votes: %d\n", totalVotes);
    printf("---------------------------\n");
    
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, ((float) candidates[i].votes / totalVotes) * 100);
    }
    
    // free memory
    free(candidates);
    
    return 0;
}

int getNumCandidates() {
    int num;
    printf("Enter number of candidates: ");
    scanf("%d", &num);
    return num;
}

void getCandidates(Candidate candidates[], int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter name for candidate #%d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void printCandidates(Candidate candidates[], int num) {
    printf("Candidates\n");
    printf("---------------------------\n");
    for (int i = 0; i < num; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("---------------------------\n");
}

int castVote(Candidate candidates[], int num, int choice) {
    if (choice >= 1 && choice <= num) {
        candidates[choice-1].votes++;
        return 1;
    } else {
        return 0;
    }
}