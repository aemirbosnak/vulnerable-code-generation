//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[100];
    int votes;
} Candidate;

typedef struct {
    char voter_id[20];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_voters = 0, total_candidates = 0;

// Function to create candidates
void create_candidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
    getchar(); // Clear newline from buffer

    for (int i = 0; i < total_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Remove newline
        candidates[i].votes = 0;
    }
}

// Function to register voters
void register_voters() {
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &total_voters);
    getchar(); // Clear newline from buffer

    for (int i = 0; i < total_voters; i++) {
        printf("Enter voter ID for voter %d: ", i + 1);
        fgets(voters[i].voter_id, sizeof(voters[i].voter_id), stdin);
        voters[i].voter_id[strcspn(voters[i].voter_id, "\n")] = 0; // Remove newline
        voters[i].has_voted = 0;
    }
}

// Function to display candidates
void display_candidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

// Function to cast a vote
void cast_vote() {
    char voter_id[20];
    int choice;

    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            if (voters[i].has_voted) {
                printf("You have already voted!\n");
                return;
            } else {
                display_candidates();
                printf("Select candidate number: ");
                scanf("%d", &choice);

                if (choice < 1 || choice > total_candidates) {
                    printf("Invalid choice. Please try again.\n");
                    return;
                }

                candidates[choice - 1].votes++;
                voters[i].has_voted = 1;
                printf("Thank you for voting!\n");
                return;
            }
        }
    }
    printf("Voter ID not found!\n");
}

// Function to display results
void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    // Seed the random number generator
    srand(time(NULL));

    while (1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Create Candidates\n");
        printf("2. Register Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_candidates();
                break;
            case 2:
                register_voters();
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please select again.\n");
        }
    }
    return 0;
}