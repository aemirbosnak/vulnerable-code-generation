//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

/* Define a constant for the maximum number of candidates. */
#define MAX_CANDIDATES 10

/* Define Candidate struct. */
typedef struct Candidate {
    int id;
    char name[50];
    int voteCount;
} Candidate;

/* Define Election struct. */
typedef struct Election {
    Candidate candidates[MAX_CANDIDATES];
    int numOfCandidates;
} Election;

/* Function to display main menu. */
void displayMainMenu() {
    printf("\n********** Welcome to Electronic Voting System **********\n\n");
    printf("1. Create Election\n");
    printf("2. Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
}

/* Function to initialize election data. */
void initializeElection(Election *election) {
    election->numOfCandidates = 0;
}

/* Function to add candidate to the election. */
void addCandidate(Election *election) {
    if (election->numOfCandidates < MAX_CANDIDATES) {
        Candidate candidate;
        candidate.id = election->numOfCandidates + 1;
        printf("\nEnter name for candidate %d: ", candidate.id);
        scanf("%s", candidate.name);
        candidate.voteCount = 0;
        election->candidates[election->numOfCandidates++] = candidate;
        printf("\n%s added to the election successfully!\n", candidate.name);
    } else {
        printf("\nSorry, maximum number of candidates reached!\n");
    }
}

/* Function to cast vote. */
void castVote(Election *election) {
    if (election->numOfCandidates > 0) {
        printf("\n--- List of candidates ---\n\n");
        for (int i = 0; i < election->numOfCandidates; i++) {
            printf("%d. %s\n", election->candidates[i].id, election->candidates[i].name);
        }
        printf("\nEnter candidate ID to cast your vote: ");
        int id;
        scanf("%d", &id);
        for (int i = 0; i < election->numOfCandidates; i++) {
            if (election->candidates[i].id == id) {
                election->candidates[i].voteCount++;
                printf("\nVote casted for %s successfully!\n", election->candidates[i].name);
                return;
            }
        }
        printf("\nSorry, candidate with ID %d not found!\n", id);
    } else {
        printf("\nSorry, no candidates found!\n");
    }
}

/* Function to sort candidates by vote count. */
void sortCandidates(Election *election) {
    for (int i = 0; i < election->numOfCandidates - 1; i++) {
        for (int j = 0; j < election->numOfCandidates - i - 1; j++) {
            if (election->candidates[j].voteCount < election->candidates[j + 1].voteCount) {
                Candidate temp = election->candidates[j];
                election->candidates[j] = election->candidates[j + 1];
                election->candidates[j + 1] = temp;
            }
        }
    }
}

/* Function to display election results. */
void displayResults(Election *election) {
    if (election->numOfCandidates > 0) {
        sortCandidates(election);
        printf("\n--- Election Results ---\n\n");
        printf("Candidate Name\tVotes\n");
        for (int i = 0; i < election->numOfCandidates; i++) {
            printf("%s\t\t%d\n", election->candidates[i].name, election->candidates[i].voteCount);
        }
    } else {
        printf("\nSorry, no candidates found!\n");
    }
}

/* Main function. */
int main() {
    Election election;
    int choice = 0;
    initializeElection(&election);
    do {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCandidate(&election);
                break;
            case 2:
                castVote(&election);
                break;
            case 3:
                displayResults(&election);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    } while (choice != 4);
    return 0;
}