//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

typedef struct {
    int id;
    char name[25];
    int voteCount;
} Candidate;

typedef struct {
    int id;
    char name[25];
    bool hasVoted;
} Voter;

// Function to print the list of candidates
void printCandidates(Candidate candidates[], int numCandidates) {
    printf("\n==== LIST OF CANDIDATES ====\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].voteCount);
    }
    printf("===========================\n");
}

// Function to print the list of voters
void printVoters(Voter voters[], int numVoters) {
    printf("\n==== LIST OF VOTERS ====\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d. %s - Has Voted: %s\n", voters[i].id, voters[i].name, voters[i].hasVoted ? "Yes" : "No");
    }
    printf("========================\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates = 0;
    int numVoters = 0;
    int choice, candChoice, voterChoice;

    printf("\nWelcome to the Electronic Voting System!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add a Candidate\n");
        printf("2. Add a Voter\n");
        printf("3. Vote\n");
        printf("4. View Results\n");
        printf("5. Exit the Program\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the Candidate Details:\n");
                printf("Name: ");
                scanf("%s", candidates[numCandidates].name);
                candidates[numCandidates].id = numCandidates + 1;
                candidates[numCandidates].voteCount = 0;
                numCandidates++;
                printf("Candidate Added Successfully!\n");
                break;
            case 2:
                printf("\nEnter the Voter Details:\n");
                printf("Name: ");
                scanf("%s", voters[numVoters].name);
                voters[numVoters].id = numVoters + 1;
                voters[numVoters].hasVoted = false;
                numVoters++;
                printf("Voter Added Successfully!\n");
                break;
            case 3:
                printf("\nPlease select a Voter:\n");
                printVoters(voters, numVoters);
                printf("Choice: ");
                scanf("%d", &voterChoice);
                if (voters[voterChoice - 1].hasVoted) {
                    printf("\nThis Voter Has Already Voted!\n");
                    break;
                }
                printf("\nPlease select a Candidate:\n");
                printCandidates(candidates, numCandidates);
                printf("Choice: ");
                scanf("%d", &candChoice);
                candidates[candChoice - 1].voteCount++;
                printf("\nVote Recorded!\n");
                voters[voterChoice - 1].hasVoted = true;
                break;
            case 4:
                printf("\n==== ELECTION RESULTS ====\n");
                if (numCandidates == 0) {
                    printf("No Candidates Added Yet!\n");
                    break;
                }
                int maxVotes = -1;
                int winnerId = -1;
                for (int i = 0; i < numCandidates; i++) {
                    printf("%d. %s - Votes: %d\n", candidates[i].id, candidates[i].name, candidates[i].voteCount);
                    if (candidates[i].voteCount > maxVotes) {
                        maxVotes = candidates[i].voteCount;
                        winnerId = candidates[i].id;
                    } else if (candidates[i].voteCount == maxVotes) {
                        winnerId = -1; // No clear winner
                    }
                }
                if (winnerId == -1) {
                    printf("There is no clear winner. Please hold a re-election.\n");
                } else {
                    printf("The Winner is Candidate %d!\n", winnerId);
                }
                printf("===========================\n");
                break;
            case 5:
                printf("\nExiting the Electronic Voting System...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\n");
        }
    } while (true);

    return 0;
}