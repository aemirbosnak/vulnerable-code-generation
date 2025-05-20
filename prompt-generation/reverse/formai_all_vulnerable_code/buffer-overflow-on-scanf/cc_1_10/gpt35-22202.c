//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a candidate
typedef struct candidate {
    char name[100];
    int votes;
} Candidate;

// Function to add a new candidate to the candidate list
void addCandidate(Candidate* candidates, int* numCandidates) {
    printf("Enter candidate name: ");
    scanf("%s", candidates[*numCandidates].name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

// Function to print the names and votes of all candidates
void displayCandidates(Candidate* candidates, int numCandidates) {
    printf("Candidate\tVotes\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote for a given candidate
void castVote(Candidate* candidates, int numCandidates) {
    char name[100];
    printf("Enter candidate name: ");
    scanf("%s", name);
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            printf("Vote cast for %s\n", candidates[i].name);
            return;
        }
    }
    printf("Candidate not found\n");
}

// Function to display the winner of the election
void displayWinner(Candidate* candidates, int numCandidates) {
    Candidate winner = candidates[0];
    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > winner.votes) {
            winner = candidates[i];
        }
    }
    printf("Winner is %s with %d votes\n", winner.name, winner.votes);
}

// Main function to run the voting system
int main() {
    int numCandidates = 0;
    Candidate candidates[100];
    int choice;
    do {
        printf("\n1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Display Winner\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}