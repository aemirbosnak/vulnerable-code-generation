//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure for a candidate
typedef struct Candidate {
    char name[20];
    int voteCount;
} Candidate;

// Function to get the number of candidates
int getCandidateCount() {
    int candidateCount;
    printf("Enter the number of candidates: ");
    scanf("%d", &candidateCount);
    return candidateCount;
}

// Function to get the candidate names and initialize vote count to zero
void getCandidateDetails(Candidate *candidates, int candidateCount, int currentIndex) {
    if (currentIndex >= candidateCount) {
        return;
    }
    printf("Enter the name of candidate %d: ", currentIndex + 1);
    scanf("%s", &(candidates[currentIndex].name));
    candidates[currentIndex].voteCount = 0;
    getCandidateDetails(candidates, candidateCount, currentIndex + 1);
}

// Function to display the candidate list
void displayCandidates(Candidate *candidates, int candidateCount, int currentIndex) {
    if (currentIndex >= candidateCount) {
        return;
    }
    printf("%d. %s\n", currentIndex + 1, candidates[currentIndex].name);
    displayCandidates(candidates, candidateCount, currentIndex + 1);
}

// Function to get the user's vote
void getVote(Candidate *candidates, int candidateCount) {
    int vote;
    printf("Enter your vote (candidate number): ");
    scanf("%d", &vote);
    if (vote < 1 || vote > candidateCount) {
        printf("Invalid vote. Try again.\n");
        getVote(candidates, candidateCount);
    } else {
        candidates[vote - 1].voteCount++;
        printf("Vote recorded. Thank you!\n");
    }
}

// Function to display the election results
void displayResults(Candidate *candidates, int candidateCount, int currentIndex) {
    if (currentIndex >= candidateCount) {
        return;
    }
    printf("%d. %s - %d votes\n", currentIndex + 1, candidates[currentIndex].name,
           candidates[currentIndex].voteCount);
    displayResults(candidates, candidateCount, currentIndex + 1);
}

// Main function
int main() {
    int candidateCount = getCandidateCount();
    Candidate *candidates = malloc(candidateCount * sizeof(Candidate));
    getCandidateDetails(candidates, candidateCount, 0);
    printf("Candidate list:\n");
    displayCandidates(candidates, candidateCount, 0);
    while (1) {
        getVote(candidates, candidateCount);
        printf("Do you want to continue voting? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }
    printf("Election Results:\n");
    displayResults(candidates, candidateCount, 0);
    free(candidates);
    return 0;
}