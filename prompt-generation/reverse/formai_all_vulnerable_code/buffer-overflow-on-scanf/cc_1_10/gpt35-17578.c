//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define structure for candidate
struct Candidate {
    int id;
    char name[20];
    int voteCount;
};

// Define structure for voter
struct Voter {
    int id;
    char name[20];
    int voted;
};

// Define global variables
int numCandidates, numVoters;
struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];

// Function to add candidates
void addCandidate() {
    if (numCandidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", &candidates[numCandidates].name);
    candidates[numCandidates].id = numCandidates + 1; // Assign unique ID to candidate
    candidates[numCandidates].voteCount = 0;
    numCandidates++;
    printf("Candidate added successfully.\n");
}

// Function to display candidates
void displayCandidates() {
    printf("\n*********************************************************\n");
    printf("List of Candidates\n");
    printf("*********************************************************\n");
    printf("ID\tName\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%s\n", candidates[i].id, candidates[i].name);
    }
    printf("*********************************************************\n");
}

// Function to add voters
void addVoter() {
    if (numVoters == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    printf("Enter voter name: ");
    scanf("%s", &voters[numVoters].name);
    voters[numVoters].id = numVoters + 1; // Assign unique ID to voter
    voters[numVoters].voted = 0; // Set voted status to 0 (not voted yet)
    numVoters++;
    printf("Voter added successfully.\n");
}

// Function to display voters
void displayVoters() {
    printf("\n*********************************************************\n");
    printf("List of Voters\n");
    printf("*********************************************************\n");
    printf("ID\tName\tVoted\n");
    for (int i = 0; i < numVoters; i++) {
        printf("%d\t%s\t%s\n", voters[i].id, voters[i].name, voters[i].voted ? "Yes" : "No");
    }
    printf("*********************************************************\n");
}

// Function to cast vote
void castVote() {
    int voterID, candidateID;
    printf("Enter voter ID: ");
    scanf("%d", &voterID);
    if (voterID < 1 || voterID > numVoters) {
        printf("Invalid voter ID. Please try again.\n");
        return;
    }
    if (voters[voterID-1].voted == 1) {
        printf("You have already voted. Thank you!\n");
        return;
    }
    printf("Enter candidate ID: ");
    scanf("%d", &candidateID);
    if (candidateID < 1 || candidateID > numCandidates) {
        printf("Invalid candidate ID. Please try again.\n");
        return;
    }
    candidates[candidateID-1].voteCount++;
    voters[voterID-1].voted = 1;
    printf("Vote casted successfully. Thank you for voting!\n");
}

// Function to show result
void showResult() {
    printf("\n*********************************************************\n");
    printf("Election Result\n");
    printf("*********************************************************\n");
    printf("ID\tName\tVote Count\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].voteCount);
    }
    printf("*********************************************************\n");
}

int main() {
    int choice;
    while (1) {
        // Display menu options
        printf("\nElectronic Voting System\n");
        printf("\n1. Add Candidate");
        printf("\n2. Display Candidates");
        printf("\n3. Add Voter");
        printf("\n4. Display Voters");
        printf("\n5. Cast Vote");
        printf("\n6. Show Result");
        printf("\n7. Exit");
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                addVoter();
                break;
            case 4:
                displayVoters();
                break;
            case 5:
                castVote();
                break;
            case 6:
                showResult();
                break;
            case 7:
                printf("Thank you for using Electronic Voting System.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}