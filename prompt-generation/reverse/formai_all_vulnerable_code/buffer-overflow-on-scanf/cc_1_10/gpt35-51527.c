//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//structure to hold candidate information
typedef struct {
    char name[50];
    int votes;
} Candidate;

//function to display the menu
void displayMenu() {
    printf("\n\n\t\t--- ELECTION MENU ---");
    printf("\n\n\t1. Register candidate");
    printf("\n\t2. Vote for candidate");
    printf("\n\t3. Display candidate details");
    printf("\n\t4. Display election results");
    printf("\n\t5. Exit");
}

//function to register a candidate
void registerCandidate(Candidate **candidates, int *numCandidates) {
    printf("\n\n\t--- REGISTRATION ---");
    printf("\n\n\tEnter candidate name: ");
    scanf("%s", (*candidates)[*numCandidates].name);
    (*candidates)[*numCandidates].votes = 0;
    (*numCandidates)++;
    printf("\n\tCandidate registered successfully!");
}

//function to vote for a candidate
void voteForCandidate(Candidate *candidates, int numCandidates) {
    printf("\n\n\t--- VOTING ---");
    printf("\n\n\tList of candidates:");
    for(int i=0;i<numCandidates;i++) {
        printf("\n\t%d. %s", i+1, candidates[i].name);
    }
    printf("\n\n\tEnter candidate number to vote for: ");
    int candidateNum;
    scanf("%d", &candidateNum);
    if(candidateNum>0 && candidateNum<=numCandidates) {
        candidates[candidateNum-1].votes++;
        printf("\n\tVote casted successfully!");
    } else {
        printf("\n\tInvalid candidate number!");
    }
}

//function to display candidate details
void displayCandidates(Candidate *candidates, int numCandidates) {
    printf("\n\n\t--- CANDIDATE DETAILS ---");
    for(int i=0;i<numCandidates;i++) {
        printf("\n\tCandidate %d:", i+1);
        printf("\n\tName: %s", candidates[i].name);
        printf("\n\tVotes: %d", candidates[i].votes);
    }
}

//function to display election results
void displayElectionResults(Candidate *candidates, int numCandidates) {
    printf("\n\n\t--- ELECTION RESULTS ---");
    int maxVotes = -1;
    int winnerIndex = -1;
    for(int i=0;i<numCandidates;i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }
    if(winnerIndex != -1) {
        printf("\n\tThe winner is %s with %d votes!", candidates[winnerIndex].name, candidates[winnerIndex].votes);
    } else {
        printf("\n\tNo winner declared.");
    }
}

int main() {
    Candidate *candidates = NULL;
    int numCandidates = 0;
    int choice;
    do {
        displayMenu();
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                registerCandidate(&candidates, &numCandidates);
                break;
            case 2:
                voteForCandidate(candidates, numCandidates);
                break;
            case 3:
                displayCandidates(candidates, numCandidates);
                break;
            case 4:
                displayElectionResults(candidates, numCandidates);
                break;
            case 5:
                printf("\n\n\tExiting...");
                break;
            default:
                printf("\n\n\tInvalid choice!");
        }
        printf("\n\n\tPress Enter key to continue...");
        getchar();
        getchar();
        system("clear");
    } while(choice != 5);
    free(candidates);
    return 0;
}