//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 50
#define NAME_LENGTH 100
#define VOTE_FILE "votes.dat"

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[], int *count) {
    FILE *file = fopen(VOTE_FILE, "rb");
    if (file) {
        *count = fread(candidates, sizeof(Candidate), MAX_CANDIDATES, file);
        fclose(file);
    } else {
        *count = 0; // No file found, start with an empty array
    }
}

void saveCandidates(Candidate candidates[], int count) {
    FILE *file = fopen(VOTE_FILE, "wb");
    if (file) {
        fwrite(candidates, sizeof(Candidate), count, file);
        fclose(file);
    } else {
        printf("Unable to save candidates.\n");
    }
}

void addCandidate(Candidate candidates[], int *count) {
    if (*count >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf(" %[^\n]", candidates[*count].name);
    candidates[*count].votes = 0;
    (*count)++;
    saveCandidates(candidates, *count);
    printf("Candidate '%s' added successfully!\n", candidates[*count - 1].name);
}

void castVote(Candidate candidates[], int count) {
    printf("Candidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, candidates[i].name);
    }
    
    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[choice - 1].votes++;
    saveCandidates(candidates, count);
    printf("Vote cast for '%s'!\n", candidates[choice - 1].name);
}

void displayResults(Candidate candidates[], int count) {
    printf("\nVoting Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;
    initializeCandidates(candidates, &candidateCount);

    int choice;
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCandidate(candidates, &candidateCount);
                break;
            case 2:
                castVote(candidates, candidateCount);
                break;
            case 3:
                displayResults(candidates, candidateCount);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}