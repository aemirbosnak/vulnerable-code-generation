//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define NAME_LENGTH 50

struct Candidate {
    char name[NAME_LENGTH];
    int votes;
};

struct Voter {
    int id;
    int has_voted;
};

struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void initializeCandidates() {
    printf("Enter number of candidates: ");
    scanf("%d", &candidate_count);
    getchar(); // consume newline
    for (int i = 0; i < candidate_count; i++) {
        printf("Enter candidate %d name: ", i + 1);
        fgets(candidates[i].name, NAME_LENGTH, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // remove newline
        candidates[i].votes = 0;
    }
}

void registerVoter() {
    if (voter_count < MAX_VOTERS) {
        voters[voter_count].id = voter_count + 1;
        voters[voter_count].has_voted = 0;
        voter_count++;
    } else {
        printf("Voter registration full!\n");
    }
}

int findVoter(int voterId) {
    for (int i = 0; i < voter_count; i++) {
        if (voters[i].id == voterId) {
            return i;
        }
    }
    return -1; // Voter not found
}

void castVote() {
    int voterId, candidateIndex;
    printf("Enter your voter ID: ");
    scanf("%d", &voterId);
    int voterIndex = findVoter(voterId);
    
    if (voterIndex == -1) {
        printf("Voter not registered!\n");
        return;
    }

    if (voters[voterIndex].has_voted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Choose a candidate by number: ");
    scanf("%d", &candidateIndex);
    
    if (candidateIndex < 1 || candidateIndex > candidate_count) {
        printf("Invalid candidate number!\n");
        return;
    }
    
    candidates[candidateIndex - 1].votes++;
    voters[voterIndex].has_voted = 1;
    printf("Vote cast for %s!\n", candidates[candidateIndex - 1].name);
}

void displayResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\n--- E-Voting System ---\n");
    printf("1. Register Voter\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    initializeCandidates();

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerVoter();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid option! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}