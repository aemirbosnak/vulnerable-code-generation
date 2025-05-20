//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_CANDIDATES 4
#define MAX_VOTERS 10000

typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

Candidate candidates[TOTAL_CANDIDATES];
int totalVotes;
int voterIds[MAX_VOTERS];
int totalVoters = 0;

void displayCandidates() {
    printf("\nCandidates: \n\n");
    for (int i = 0; i < TOTAL_CANDIDATES; i++) {
        printf("%d.\t%s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

void submitVote(int candidateId, int voterId) {
    for (int i = 0; i < TOTAL_CANDIDATES; i++) {
        if (candidates[i].id == candidateId) {
            candidates[i].votes++;
            break;
        }
    }
    voterIds[totalVoters++] = voterId;
    totalVotes++;
}

int isVoterValid(int voterId) {
    for (int i = 0; i < totalVoters; i++) {
        if (voterIds[i] == voterId) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int voterId, candidateId;
    int option;

    srand(time(0));
    for (int i = 0; i < TOTAL_CANDIDATES; i++) {
        candidates[i].id = i;
        candidates[i].votes = 0;
    }

    while (1) {
        printf("Electronic Voting System\n\n");
        printf("1. Display Candidates\n");
        printf("2. Submit Vote\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayCandidates();
                break;

            case 2:
                printf("Enter your voter id: ");
                scanf("%d", &voterId);

                if (!isVoterValid(voterId)) {
                    printf("You have already voted.\n\n");
                    break;
                }

                printf("\n");
                displayCandidates();
                printf("Enter the candidate id: ");
                scanf("%d", &candidateId);

                if (candidateId < 0 || candidateId >= TOTAL_CANDIDATES) {
                    printf("Invalid Candidate Id.\n\n");
                    break;
                }

                submitVote(candidateId, voterId);
                printf("\nThanks for voting!\n\n");
                break;

            case 3:
                printf("\nTotal Votes: %d\n", totalVotes);
                printf("Results: \n\n");

                for (int i = 0; i < TOTAL_CANDIDATES; i++) {
                    printf("%s - %d Votes\n", candidates[i].name, candidates[i].votes);
                }

                printf("\nThanks for using the Electronic Voting System.\n");
                exit(0);

            default:
                printf("Invalid Option.\n\n");
                break;
        }
    }

    return 0;
}