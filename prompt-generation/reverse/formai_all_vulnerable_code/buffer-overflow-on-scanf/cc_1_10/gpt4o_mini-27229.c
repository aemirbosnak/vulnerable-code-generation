//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50
#define MAX_VOTERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void initializeCandidates() {
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);
    getchar(); // clear newline

    for (int i = 0; i < candidate_count; i++) {
        printf("Enter name for candidate %d: ", i + 1);
        fgets(candidates[i].name, MAX_NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0'; // Remove newline
        candidates[i].votes = 0;
    }
}

void registerVoter() {
    printf("Enter your name: ");
    fgets(voters[voter_count].name, MAX_NAME_LENGTH, stdin);
    voters[voter_count].name[strcspn(voters[voter_count].name, "\n")] = '\0'; // Remove newline
    voters[voter_count].hasVoted = 0;
    voter_count++;
}

int findVoter(char *name) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Voter not found
}

void castVote() {
    char voterName[MAX_NAME_LENGTH];
    printf("Enter your name to vote: ");
    fgets(voterName, MAX_NAME_LENGTH, stdin);
    voterName[strcspn(voterName, "\n")] = '\0'; // Remove newline

    int voterIndex = findVoter(voterName);
    if (voterIndex == -1) {
        printf("You are not registered. Please register first.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int vote;
    printf("Enter the candidate number you want to vote for: ");
    scanf("%d", &vote);
    getchar(); // clear newline

    if (vote < 1 || vote > candidate_count) {
        printf("Invalid candidate number!\n");
        return;
    }

    candidates[vote - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Thank you for voting, %s!\n", voterName);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void electionProcess() {
    printf("Welcome to the Electronic Voting System!\n");

    char choice;
    do {
        printf("\nOptions:\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Show Results\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf(" %c", &choice);
        getchar(); // clear newline

        switch (choice) {
            case '1':
                if (voter_count < MAX_VOTERS) {
                    registerVoter();
                } else {
                    printf("Maximum voter limit reached!\n");
                }
                break;
            case '2':
                castVote();
                break;
            case '3':
                displayResults();
                break;
            case '4':
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != '4');
}

int main() {
    initializeCandidates();
    electionProcess();
    return 0;
}