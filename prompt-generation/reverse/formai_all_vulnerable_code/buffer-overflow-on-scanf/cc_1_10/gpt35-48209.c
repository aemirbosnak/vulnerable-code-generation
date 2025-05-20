//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

// Structure to store candidate information
struct Candidate {
    int id;
    char name[50];
    int votes;
};

// Structure to store voter information
struct Voter {
    int id;
    int voted_for;
};

// Function to display main menu
void displayMenu() {
    printf("========== MENU ==========\n");
    printf("1. Register candidate\n");
    printf("2. Register voter\n");
    printf("3. Cast vote\n");
    printf("4. Display result\n");
    printf("5. Exit\n");
    printf("==========================\n");
}

// Function to register a candidate
void registerCandidate(struct Candidate candidates[], int *numCandidates) {
    if (*numCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[*numCandidates].name);
        candidates[*numCandidates].id = (*numCandidates) + 1;
        candidates[*numCandidates].votes = 0;
        printf("Candidate registered successfully!\n");
        (*numCandidates)++;
    } else {
        printf("Maximum candidate limit reached!\n");
    }
}

// Function to register a voter
void registerVoter(struct Voter voters[], int *numVoters) {
    if (*numVoters < MAX_VOTERS) {
        printf("Enter voter ID: ");
        scanf("%d", &voters[*numVoters].id);
        voters[*numVoters].voted_for = 0;
        printf("Voter registered successfully!\n");
        (*numVoters)++;
    } else {
        printf("Maximum voter limit reached!\n");
    }
}

// Function to display list of candidates
void displayCandidates(struct Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates registered yet!\n");
    } else {
        printf("======== CANDIDATES ========\n");
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", candidates[i].id, candidates[i].name);
        }
        printf("============================\n");
    }
}

// Function to cast a vote
void castVote(struct Candidate candidates[], int numCandidates, struct Voter voters[], int numVoters) {
    int voterID, candidateID;
    printf("Enter voter ID: ");
    scanf("%d", &voterID);

    // Check if voter already voted
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == voterID) {
            if (voters[i].voted_for != 0) {
                printf("You have already voted for candidate %d\n", voters[i].voted_for);
                return;
            }
            break;
        }
    }

    printf("Enter candidate ID: ");
    scanf("%d", &candidateID);

    // Check if candidate exists
    int foundCandidate = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].id == candidateID) {
            candidates[i].votes++;
            foundCandidate = 1;
            break;
        }
    }

    // Check if candidate not found
    if (!foundCandidate) {
        printf("Candidate not found!\n");
        return;
    }

    // Record the vote
    for (int i = 0; i < numVoters; i++) {
        if (voters[i].id == voterID) {
            voters[i].voted_for = candidateID;
            printf("Vote recorded successfully!\n");
            return;
        }
    }
}

// Function to display result
void displayResults(struct Candidate candidates[], int numCandidates) {
    if (numCandidates == 0) {
        printf("No candidates registered yet!\n");
        return;
    }

    printf("======== RESULTS ========\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("==========================\n");
}

// Main function
int main() {
    struct Candidate candidates[MAX_CANDIDATES];
    struct Voter voters[MAX_VOTERS];
    int numCandidates = 0, numVoters = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerCandidate(candidates, &numCandidates);
                break;
            case 2:
                registerVoter(voters, &numVoters);
                break;
            case 3:
                castVote(candidates, numCandidates, voters, numVoters);
                break;
            case 4:
                displayResults(candidates, numCandidates);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    } while (choice != 5);

    return 0;
}