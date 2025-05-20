//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdbool.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define a candidate struct
typedef struct {
    int id;
    char name[50];
    int votes;
} candidate;

// Define a voter struct
typedef struct {
    int id;
    bool voted;
    int vote;
} voter;

int main() {
    // Declare variables
    candidate candidates[MAX_CANDIDATES]; // Array of candidates
    voter voters[MAX_VOTERS]; // Array of voters
    int num_candidates; // Number of candidates
    int num_voters; // Number of voters
    int i, j; // Loop counters

    // Get input from user
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the voter IDs:\n");
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d: ", i+1);
        scanf("%d", &voters[i].id);
        voters[i].voted = false;
        voters[i].vote = 0;
    }

    // Voting system loop
    int choice;
    while (true) {
        // Prompt user for action
        printf("\nEnter 1 to vote, 2 to see current results, or 3 to exit: ");
        scanf("%d", &choice);

        // Perform action based on user choice
        if (choice == 1) {
            // Check if voter has already voted
            int voter_id;
            printf("\nEnter your voter ID: ");
            scanf("%d", &voter_id);

            bool voter_found = false;
            for (i = 0; i < num_voters; i++) {
                if (voters[i].id == voter_id) {
                    if (voters[i].voted) {
                        printf("You have already voted.\n");
                    } else {
                        printf("Select a candidate to vote for:\n");
                        for (j = 0; j < num_candidates; j++) {
                            printf("%d. %s\n", j+1, candidates[j].name);
                        }
                        int candidate_choice;
                        scanf("%d", &candidate_choice);

                        if (candidate_choice > 0 && candidate_choice <= num_candidates) {
                            candidates[candidate_choice-1].votes++;
                            voters[i].voted = true;
                            voters[i].vote = candidate_choice;
                            printf("Thank you! Your vote has been recorded.\n");
                        } else {
                            printf("Invalid choice.\n");
                        }
                    }
                    voter_found = true;
                    break;
                }
            }
            if (!voter_found) {
                printf("Voter not found.\n");
            }
        } else if (choice == 2) {
            // Display current results
            printf("\nCurrent results:\n");
            for (i = 0; i < num_candidates; i++) {
                printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
            }
        } else if (choice == 3) {
            // Exit program
            printf("\nGoodbye!\n");
            break;
        } else {
            // Invalid choice
            printf("\nInvalid choice.\n");
        }
    }

    return 0;
}