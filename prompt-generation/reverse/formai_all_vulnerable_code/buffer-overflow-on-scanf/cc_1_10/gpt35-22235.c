//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define candidate structure
struct Candidate {
    char name[50];
    int vote_count;
};

// Define vote structure
struct Vote {
    char name[50];
};

// Declare candidate array
struct Candidate candidates[MAX_CANDIDATES];

// Declare vote array
struct Vote votes[MAX_VOTERS];

// Declare global variable to keep track of number of candidates and votes
int num_candidates = 0;
int num_voters = 0;

// Define function to add candidate
void addCandidate() {
    // Check if maximum number of candidates has been reached
    if (num_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    // Prompt user to enter candidate name
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    // Initialize vote count to zero
    candidates[num_candidates].vote_count = 0;
    // Increment number of candidates
    num_candidates++;
    printf("Candidate added successfully!\n");
}

// Define function to add vote
void addVote() {
    // Check if maximum number of voters has been reached
    if (num_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }
    // Prompt user to enter vote
    printf("Enter vote: ");
    scanf("%s", votes[num_voters].name);
    // Check if candidate exists
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(votes[num_voters].name, candidates[i].name) == 0) {
            candidate_index = i;
            break;
        }
    }
    // If candidate exists, increment their vote count
    if (candidate_index != -1) {
        candidates[candidate_index].vote_count++;
        printf("Vote counted successfully!\n");
        // Increment number of voters
        num_voters++;
    } else {
        printf("Candidate not found.\n");
    }
}

// Define function to display results
void displayResults() {
    // Sort candidates by vote count in descending order
    for (int i = 0; i < num_candidates; i++) {
        for (int j = i + 1; j < num_candidates; j++) {
            if (candidates[i].vote_count < candidates[j].vote_count) {
                struct Candidate temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
        }
    }
    // Display results
    printf("Results: \n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

// Define function to display menu
void displayMenu() {
    printf("Electronic Voting System\n");
    printf("------------------------\n");
    printf("1. Add Candidate\n");
    printf("2. Add Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
}

int main() {
    int choice;
    do {
        // Display menu
        displayMenu();
        // Prompt user to enter choice
        printf("Enter choice: ");
        scanf("%d", &choice);
        // Call relevant function based on choice
        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                addVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                // Exit program
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}