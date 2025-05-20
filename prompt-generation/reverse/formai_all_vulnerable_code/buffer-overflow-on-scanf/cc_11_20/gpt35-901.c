//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

typedef struct Voter {
    int id;
    bool hasVoted;
} Voter;

int main() {
    int numCandidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    Candidate candidates[numCandidates];
    for (int i = 0; i < numCandidates; i++) {
        printf("Enter name for candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }

    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    Voter voters[numVoters];
    for (int i = 0; i < numVoters; i++) {
        voters[i].id = i+1;
        voters[i].hasVoted = false;
    }

    printf("Voting is now open...\n");
    int voteCount = 0;
    while (voteCount < numVoters) {
        int voterId, candidateId;
        printf("Enter voter ID: ");
        scanf("%d", &voterId);

        bool validVoter = false;
        for (int i = 0; i < numVoters; i++) {
            if (voters[i].id == voterId) {
                if (voters[i].hasVoted) {
                    printf("Error: voter has already voted\n");
                    break;
                } else {
                    validVoter = true;
                    voters[i].hasVoted = true;
                    break;
                }
            }
        }
        if (!validVoter) {
            printf("Error: invalid voter ID\n");
            continue;
        }

        printf("Enter candidate ID to vote for: ");
        scanf("%d", &candidateId);

        bool validCandidate = false;
        for (int i = 0; i < numCandidates; i++) {
            if (candidates[i].id == candidateId) {
                validCandidate = true;
                candidates[i].votes++;
                break;
            }
        }
        if (!validCandidate) {
            printf("Error: invalid candidate ID\n");
            continue;
        }

        printf("Vote for candidate %d has been recorded\n", candidateId);
        voteCount++;
    }

    printf("Voting is now closed...\n");
    printf("Here are the results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }

    return 0;
}