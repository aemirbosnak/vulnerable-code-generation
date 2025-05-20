//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int totalCandidates;
} Election;

void initializeElection(Election *election) {
    election->totalCandidates = 0;
}

void addCandidate(Election *election, const char *name) {
    if (election->totalCandidates < MAX_CANDIDATES) {
        strcpy(election->candidates[election->totalCandidates].name, name);
        election->candidates[election->totalCandidates].votes = 0;
        election->totalCandidates++;
    } else {
        printf("Maximum candidates reached!\n");
    }
}

void vote(Election *election) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the candidate you want to vote for: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Remove newline character

    int found = 0;
    for (int i = 0; i < election->totalCandidates; i++) {
        if (strcmp(election->candidates[i].name, name) == 0) {
            election->candidates[i].votes++;
            found = 1;
            printf("Vote cast for %s!\n", name);
            break;
        }
    }

    if (!found) {
        printf("Candidate not found! Please try again.\n");
    }
}

void displayResults(const Election *election) {
    printf("\nElection Results:\n");
    for (int i = 0; i < election->totalCandidates; i++) {
        printf("%s: %d votes\n", election->candidates[i].name, election->candidates[i].votes);
    }
}

int main() {
    Election election;
    initializeElection(&election);

    int choice;
    while (1) {
        printf("\n1. Add Candidate\n2. Vote\n3. Display Results\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character after choice

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                printf("Enter candidate name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                addCandidate(&election, name);
                break;
            }
            case 2:
                vote(&election);
                break;
            case 3:
                displayResults(&election);
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}