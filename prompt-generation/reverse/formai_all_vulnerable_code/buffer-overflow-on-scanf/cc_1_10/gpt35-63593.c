//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// structure to hold candidate information
typedef struct {
    char name[50];
    int votes;
} Candidate;

// function to add a candidate
void addCandidate(Candidate *candidates, int *numCandidates) {
    printf("Enter candidate name: ");
    scanf("%s", candidates[*numCandidates].name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

// function to display all candidates
void displayCandidates(Candidate *candidates, int numCandidates) {
    printf("List of candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d.%s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

// function to cast a vote
void castVote(Candidate *candidates, int numCandidates) {
    printf("Enter candidate number to vote for: ");
    int candidateNum;
    scanf("%d", &candidateNum);
    if (candidateNum < 1 || candidateNum > numCandidates) {
        printf("Invalid candidate number!\n");
        return;
    }
    candidates[candidateNum-1].votes++;
    printf("Vote cast for %s.\n", candidates[candidateNum-1].name);
}

// function to display the winner
void displayWinner(Candidate *candidates, int numCandidates) {
    int maxVotes = -1, maxVotesIndex;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            maxVotesIndex = i;
        }
    }
    printf("%s wins with %d votes!\n", candidates[maxVotesIndex].name, candidates[maxVotesIndex].votes);
}

int main() {
    int numCandidates = 0;
    Candidate candidates[10];

    while (1) {
        printf("\n1.Add candidate\n2.Display candidates\n3.Cast vote\n4.Display winner\n5.Exit\nEnter option: ");
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addCandidate(candidates, &numCandidates);
                break;
            case 2:
                displayCandidates(candidates, numCandidates);
                break;
            case 3:
                castVote(candidates, numCandidates);
                break;
            case 4:
                displayWinner(candidates, numCandidates);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}