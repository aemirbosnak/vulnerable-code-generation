//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 50
#define FILENAME "votes.txt"

typedef struct {
    char name[NAME_LENGTH];
    int vote_count;
} Candidate;

void displayCandidates(Candidate candidates[], int count);
int castVote(Candidate candidates[], int count);
void displayResults(Candidate candidates[], int count);
void saveResultsToFile(Candidate candidates[], int count);
void loadResultsFromFile(Candidate candidates[], int *count);

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;
    int option;

    // Loading candidates from a file
    loadResultsFromFile(candidates, &candidateCount);
    
    // Main menu
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Display Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (candidateCount < MAX_CANDIDATES) {
                    printf("Enter candidate name: ");
                    scanf("%s", candidates[candidateCount].name);
                    candidates[candidateCount].vote_count = 0;
                    candidateCount++;
                    printf("Candidate added successfully!\n");
                } else {
                    printf("Maximum candidates reached!\n");
                }
                break;
            case 2:
                displayCandidates(candidates, candidateCount);
                break;
            case 3:
                castVote(candidates, candidateCount);
                break;
            case 4:
                displayResults(candidates, candidateCount);
                break;
            case 5:
                saveResultsToFile(candidates, candidateCount);
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}

void displayCandidates(Candidate candidates[], int count) {
    printf("\nCandidates:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int castVote(Candidate candidates[], int count) {
    int choice;
    printf("Choose a candidate to vote for (1 to %d): ", count);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= count) {
        candidates[choice - 1].vote_count++;
        printf("Vote cast for %s!\n", candidates[choice - 1].name);
        return 1;
    } else {
        printf("Invalid choice!\n");
        return 0;
    }
}

void displayResults(Candidate candidates[], int count) {
    printf("\nElection Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

void saveResultsToFile(Candidate candidates[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error saving results!\n");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", candidates[i].name, candidates[i].vote_count);
    }
    
    fclose(file);
    printf("Results saved to %s.\n", FILENAME);
}

void loadResultsFromFile(Candidate candidates[], int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        *count = 0; // No previous results to load
        return;
    }

    while (fscanf(file, "%s %d", candidates[*count].name, &candidates[*count].vote_count) == 2) {
        (*count)++;
    }

    fclose(file);
    printf("Results loaded from %s.\n", FILENAME);
}