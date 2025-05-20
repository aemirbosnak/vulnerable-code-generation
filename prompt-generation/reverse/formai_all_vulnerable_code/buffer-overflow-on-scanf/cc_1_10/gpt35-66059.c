//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 20       // Maximum number of candidates
#define MAX_VOTERS 1000         // Maximum number of voters
#define MAX_CHOICE 5            // Maximum number of choices for each voter

// Candidate structure
typedef struct {
    int candidateID;
    char name[50];
    int voteCount;
} Candidate;

// Voter structure
typedef struct {
    int voterID;
    int choices[MAX_CHOICE];
} Voter;

Candidate candidates[MAX_CANDIDATES];    // Array of candidates
Voter voters[MAX_VOTERS];                 // Array of voters
int numCandidates = 0;                    // Number of candidates
int numVoters = 0;                        // Number of voters

// Function prototypes
void addCandidate();
void printCandidates();
void addVoter();
void printVoters();
void castVotes();
void displayResults();

int main() {
    int choice;

    // Main menu
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Print Candidates\n");
        printf("3. Add Voter\n");
        printf("4. Print Voters\n");
        printf("5. Cast Votes\n");
        printf("6. Display Results\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                printCandidates();
                break;
            case 3:
                addVoter();
                break;
            case 4:
                printVoters();
                break;
            case 5:
                castVotes();
                break;
            case 6:
                displayResults();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}

// Function to add a candidate
void addCandidate() {
    if (numCandidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached!\n");
        return;
    }

    Candidate candidate;

    printf("Enter candidate name: ");
    scanf("%s", candidate.name);
    candidate.candidateID = numCandidates + 1;
    candidate.voteCount = 0;

    candidates[numCandidates] = candidate;
    numCandidates++;

    printf("Candidate added successfully!\n");
}

// Function to print all candidates
void printCandidates() {
    if (numCandidates == 0) {
        printf("No candidates added yet!\n");
        return;
    }

    printf("List of Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", candidates[i].candidateID, candidates[i].name);
    }
}

// Function to add a voter
void addVoter() {
    if (numVoters == MAX_VOTERS) {
        printf("Maximum number of voters reached!\n");
        return;
    }

    Voter voter;

    printf("Enter voter ID: ");
    scanf("%d", &voter.voterID);
    printf("Enter your choices (maximum %d):\n", MAX_CHOICE);

    // Prompt the user to enter up to MAX_CHOICE choices
    for (int i = 0; i < MAX_CHOICE; i++) {
        printf("Choice %d: ", i + 1);
        scanf("%d", &voter.choices[i]);

        // If the choice is not valid, set it to -1
        if (voter.choices[i] < 1 || voter.choices[i] > numCandidates) {
            voter.choices[i] = -1;
        }
    }

    voters[numVoters] = voter;
    numVoters++;

    printf("Voter added successfully!\n");
}

// Function to print all voters
void printVoters() {
    if (numVoters == 0) {
        printf("No voters added yet!\n");
        return;
    }

    printf("List of Voters:\n");

    for (int i = 0; i < numVoters; i++) {
        printf("Voter %d (ID: %d)\n", i + 1, voters[i].voterID);

        for (int j = 0; j < MAX_CHOICE; j++) {
            if (voters[i].choices[j] == -1) {
                break;
            }
            printf("Choice %d: Candidate %d\n", j + 1, voters[i].choices[j]);
        }
    }
}

// Function to cast votes
void castVotes() {
    int choice;

    printf("Are you sure you want to cast the votes? (1 - Yes / 0 - No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        for (int i = 0; i < numVoters; i++) {
            for (int j = 0; j < MAX_CHOICE; j++) {
                if (voters[i].choices[j] != -1) {
                    candidates[voters[i].choices[j] - 1].voteCount++;
                } else {
                    break;
                }
            }
        }

        printf("Votes cast successfully!\n");
    }
}

// Function to display results
void displayResults() {
    if (numCandidates == 0) {
        printf("No candidates added yet!\n");
        return;
    }

    printf("Results:\n");

    // Bubble sort candidates based on vote count
    for (int i = 0; i < numCandidates - 1; i++) {
        for (int j = 0; j < numCandidates - i - 1; j++) {
            if (candidates[j].voteCount < candidates[j + 1].voteCount) {
                Candidate temp = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = temp;
            }
        }
    }

    // Print candidates in descending order of vote count
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s - %d votes\n", i + 1, candidates[i].name, candidates[i].voteCount);
    }
}