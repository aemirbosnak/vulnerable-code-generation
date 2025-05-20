//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int candidate_count = 0;
int voter_count = 0;

void registerCandidate(char name[]) {
    strcpy(candidates[candidate_count].name, name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
}

void registerVoter(char name[]) {
    strcpy(voters[voter_count].name, name);
    voters[voter_count].voted = 0;
    voter_count++;
}

void castVote(char voterName[], char candidateName[]) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted) {
                printf("Sorry %s, you have already voted!\n", voterName);
                return;
            } else {
                voters[i].voted = 1;
                for (int j = 0; j < candidate_count; j++) {
                    if (strcmp(candidates[j].name, candidateName) == 0) {
                        candidates[j].votes++;
                        printf("Thank you %s, your vote for %s has been recorded!\n", voterName, candidateName);
                        return;
                    }
                }
            }
        }
    }
    printf("Voter not found.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void showMenu() {
    printf("\nWelcome to the Electronic Voting System\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Please select an option: ");
}

int main() {
    while (1) {
        showMenu();
        int choice;
        scanf("%d", &choice);
        getchar(); // consume newline left in the input buffer

        if (choice == 1) {
            char candidateName[MAX_NAME_LENGTH];
            printf("Enter candidate's name: ");
            fgets(candidateName, MAX_NAME_LENGTH, stdin);
            candidateName[strcspn(candidateName, "\n")] = 0; // remove newline character
            registerCandidate(candidateName);
            printf("Candidate %s registered successfully!\n", candidateName);
        } else if (choice == 2) {
            char voterName[MAX_NAME_LENGTH];
            printf("Enter voter's name: ");
            fgets(voterName, MAX_NAME_LENGTH, stdin);
            voterName[strcspn(voterName, "\n")] = 0; // remove newline character
            registerVoter(voterName);
            printf("Voter %s registered successfully!\n", voterName);
        } else if (choice == 3) {
            char voterName[MAX_NAME_LENGTH];
            char candidateName[MAX_NAME_LENGTH];
            printf("Enter voter's name: ");
            fgets(voterName, MAX_NAME_LENGTH, stdin);
            voterName[strcspn(voterName, "\n")] = 0; // remove newline character
            printf("Enter candidate's name: ");
            fgets(candidateName, MAX_NAME_LENGTH, stdin);
            candidateName[strcspn(candidateName, "\n")] = 0; // remove newline character
            castVote(voterName, candidateName);
        } else if (choice == 4) {
            displayResults();
        } else if (choice == 5) {
            printf("Thank you for using the Electronic Voting System. Farewell!\n");
            break; // exit the loop
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}