//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voteCount;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void registerVoter();
void registerCandidate();
void castVote();
void displayResults();
int getCandidateIndex(char *name);
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                registerCandidate();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the Voting System. Thank you for participating!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Register Voter\n");
    printf("2. Register Candidate\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum voter limit reached! Can't register more voters.\n");
        return;
    }
    
    Voter newVoter;
    printf("Enter voter name: ");
    scanf("%s", newVoter.name);
    newVoter.hasVoted = 0;
    
    voters[totalVoters] = newVoter;
    totalVoters++;
    printf("Voter '%s' registered successfully!\n", newVoter.name);
}

void registerCandidate() {
    if (totalCandidates >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached! Can't register more candidates.\n");
        return;
    }
    
    Candidate newCandidate;
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.voteCount = 0;
    
    candidates[totalCandidates] = newCandidate;
    totalCandidates++;
    printf("Candidate '%s' registered successfully!\n", newCandidate.name);
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    scanf("%s", voterName);

    int voterIndex = -1;
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            voterIndex = i;
            break;
        }
    }

    if (voterIndex == -1) {
        printf("You are not registered! Please register first.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("Sorry, '%s'. You have already voted!\n", voterName);
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int voteChoice;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &voteChoice);

    if (voteChoice < 1 || voteChoice > totalCandidates) {
        printf("Invalid choice. Vote not counted.\n");
        return;
    }

    candidates[voteChoice - 1].voteCount++;
    voters[voterIndex].hasVoted = 1;
    printf("Thank you for voting, '%s'! Your vote for '%s' has been counted.\n", voterName, candidates[voteChoice - 1].name);
}

void displayResults() {
    if (totalCandidates == 0) {
        printf("No candidates registered yet!\n");
        return;
    }

    printf("\n--- Election Results ---\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].voteCount);
    }
    
    // Determine winner
    int maxVotes = 0;
    char winner[MAX_NAME_LENGTH] = "None";

    for (int i = 0; i < totalCandidates; i++) {
        if (candidates[i].voteCount > maxVotes) {
            maxVotes = candidates[i].voteCount;
            strcpy(winner, candidates[i].name);
        }
    }

    if (maxVotes > 0) {
        printf("The winner is: %s with %d votes!\n", winner, maxVotes);
    } else {
        printf("No votes were cast.\n");
    }
}