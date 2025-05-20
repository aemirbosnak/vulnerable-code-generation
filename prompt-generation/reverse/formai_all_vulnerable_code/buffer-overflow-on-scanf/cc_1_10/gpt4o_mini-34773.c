//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int hasVoted;
} Voter;

void initializeCandidates(Candidate candidates[], int num) {
    for(int i = 0; i < num; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Strip newline
        candidates[i].votes = 0;
    }
}

void displayCandidates(Candidate candidates[], int num) {
    printf("\nCandidates:\n");
    for(int i = 0; i < num; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int numCandidates, numVoters, totalVoters = 0;

    printf("Welcome to the Electronic Voting System!\n");
    printf("How many candidates are there? ");
    scanf("%d", &numCandidates);
    getchar(); // Consume the newline left by scanf

    if(numCandidates > MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates is %d.\n", MAX_CANDIDATES);
        return 1;
    }

    initializeCandidates(candidates, numCandidates);

    printf("How many voters are there? ");
    scanf("%d", &numVoters);
    getchar(); // Consume the newline left by scanf

    if(numVoters > MAX_VOTERS) {
        printf("Error: Maximum number of voters is %d.\n", MAX_VOTERS);
        return 1;
    }

    // Initialize voters
    for(int i = 0; i < numVoters; i++) {
        printf("Enter name of voter %d: ", i + 1);
        fgets(voters[i].name, sizeof(voters[i].name), stdin);
        voters[i].name[strcspn(voters[i].name, "\n")] = 0; // Strip newline
        voters[i].hasVoted = 0;
    }

    for(int i = 0; i < numVoters; i++) {
        if(voters[i].hasVoted == 0) {
            displayCandidates(candidates, numCandidates);
            int choice;
            printf("Vote for your choice (1-%d): ", numCandidates);
            scanf("%d", &choice);
            getchar(); // Consume the newline left by scanf

            if(choice >= 1 && choice <= numCandidates) {
                candidates[choice - 1].votes++;
                voters[i].hasVoted = 1;
                totalVoters++;
                printf("Thank you for voting, %s!\n", voters[i].name);
            } else {
                printf("Invalid choice. You didn't vote.\n");
            }
        } else {
            printf("%s has already voted.\n", voters[i].name);
        }
    }

    // Display results
    printf("\nElection Results:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("Total voters participated: %d\n", totalVoters);
    if(totalVoters > 0) {
        for(int i = 0; i < numCandidates; i++) {
            float percentage = (float)candidates[i].votes / totalVoters * 100;
            printf("%s received %.2f%% of the votes.\n", candidates[i].name, percentage);
        }
    }

    printf("Thank you for using the Electronic Voting System!\n");
    return 0;
}