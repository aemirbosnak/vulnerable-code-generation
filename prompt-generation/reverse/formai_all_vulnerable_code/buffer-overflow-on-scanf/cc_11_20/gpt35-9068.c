//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Function to print the menu of the program
void print_menu() {
    printf("\n-------------ELECTRONIC VOTING SYSTEM-------------\n");
    printf("1. Add a candidate\n");
    printf("2. Remove a candidate\n");
    printf("3. Display all candidates\n");
    printf("4. Start voting\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

// Structure to store candidate details
typedef struct {
    char name[50];
    int votes;
} candidate;

int main() {

    candidate candidates[MAX_CANDIDATES]; // Array of all the candidates
    int num_candidates = 0; // Number of candidates added so far
    int num_voters = 0; // Number of voters
    int vote_count[MAX_CANDIDATES] = {0}; // Array to store the number of votes for each candidate
    int choice; // User's choice from the menu
    char temp; // Used to clear the input buffer
    char vote[MAX_VOTERS][50]; // Array to store the names of the candidates voted by each voter

    // Print the main menu
    print_menu();

    // Loop to take user input until program is exited
    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add a candidate
                if (num_candidates < MAX_CANDIDATES) {
                    printf("\nEnter the name of the candidate: ");
                    scanf("%c", &temp); // Clear the input buffer
                    fgets(candidates[num_candidates].name, 50, stdin); // Take input
                    candidates[num_candidates].votes = 0; // Initialize vote count to 0
                    num_candidates++; // Increment the number of candidates
                    printf("\nCandidate added successfully!\n");
                } else {
                    printf("\nMaximum number of candidates reached!\n");
                }
                break;

            case 2: // Remove a candidate
                if (num_candidates > 0) {
                    printf("\nEnter the name of the candidate to remove: ");
                    scanf("%c", &temp); // Clear the input buffer
                    char name_to_remove[50];
                    fgets(name_to_remove, 50, stdin); // Take input

                    int candidate_found = 0;
                    for (int i = 0; i < num_candidates; i++) {
                        // If candidate found, remove from the array
                        if (strcmp(name_to_remove, candidates[i].name) == 0) {
                            for (int j = i+1; j < num_candidates; j++) {
                                candidates[j-1] = candidates[j];
                            }
                            num_candidates--;
                            candidate_found = 1;
                            printf("\nCandidate removed successfully!\n");
                            break;
                        }
                    }
                    if (!candidate_found) {
                        printf("\nThe candidate doesn't exist!\n");
                    }
                } else {
                    printf("\nNo candidates to remove!\n");
                }
                break;

            case 3: // Display all candidates
                if (num_candidates > 0) {
                    printf("\n-------------ALL CANDIDATES-------------\n");
                    for (int i = 0; i < num_candidates; i++) {
                        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
                    }
                } else {
                    printf("\nNo candidates to display!\n");
                }
                break;

            case 4: // Start voting
                if (num_candidates > 0) {
                    printf("\n-------------VOTING-------------\n");
                    printf("Enter the number of voters: ");
                    scanf("%d", &num_voters);

                    // Loop to take the votes from all the voters
                    for (int i = 0; i < num_voters; i++) {
                        printf("\nVOTER-%d\n", i+1);
                        printf("Select the candidate number you want to vote for (1-%d): ", num_candidates);
                        int candidate_choice;
                        scanf("%d", &candidate_choice);

                        // Check if candidate number is valid
                        if (candidate_choice < 1 || candidate_choice > num_candidates) {
                            printf("Invalid candidate number! Please try again.\n");
                            i--; // Decrement the index to take vote from the same voter again
                            continue; // Continue to avoid recording the vote
                        }

                        // Record the vote in the array
                        strcpy(vote[i], candidates[candidate_choice-1].name);
                        vote_count[candidate_choice-1]++;
                        printf("Vote recorded!\n");
                    }

                    // Print the election results
                    printf("\n-------------ELECTION RESULTS-------------\n");
                    for (int i = 0; i < num_candidates; i++) {
                        printf("%s - %d votes\n", candidates[i].name, vote_count[i]);
                    }

                    // Print the names of candidates who won
                    int max_votes = 0;
                    for (int i = 0; i < num_candidates; i++) {
                        if (vote_count[i] > max_votes) {
                            max_votes = vote_count[i];
                        }
                    }
                    printf("\nWINNERS: ");
                    for (int i = 0; i < num_candidates; i++) {
                        if (vote_count[i] == max_votes) {
                            printf("%s, ", candidates[i].name);
                        }
                    }

                } else {
                    printf("\nNo candidates added yet!\n");
                }
                break;

            case 5: // Exit
                printf("\nThank you for using the Electronic Voting System!\n");
                exit(0); // Exit the program with status code 0

            default: // Invalid choice
                printf("\nInvalid choice! Please try again.\n");
        }

        // Print the menu again to take another choice
        print_menu();
    }

    return 0;
}