//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000

struct candidate {
    char name[20];
    int votes;
};

struct voter {
    char id[10];
    int voted;
};

struct candidate candidates[10];
struct voter voters[MAX_VOTERS];

int main() {
    // Initialize candidates
    strcpy(candidates[0].name, "John");
    candidates[0].votes = 0;
    strcpy(candidates[1].name, "Jane");
    candidates[1].votes = 0;
    int num_candidates = 2;

    // Initialize voters
    int num_voters = 0;

    // Main menu loop
    int choice;
    do {
        printf("Welcome to the Electronic Voting System\n");
        printf("1. Add Voter\n");
        printf("2. List Candidates\n");
        printf("3. Cast Vote\n");
        printf("4. View Results\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Add Voter
                if (num_voters >= MAX_VOTERS) {
                    printf("Sorry, the voter registry is full.\n");
                    break;
                }
                printf("Enter voter ID: ");
                scanf("%s", voters[num_voters].id);
                voters[num_voters].voted = 0;
                num_voters += 1;
                printf("Voter added successfully.\n");
                break;
            }
            case 2: { // List Candidates
                printf("List of Candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%d. %s\n", i+1, candidates[i].name);
                }
                break;
            }
            case 3: { // Cast Vote
                char voter_id[10];
                printf("Enter your voter ID: ");
                scanf("%s", voter_id);
                int voter_index = -1;
                for (int i = 0; i < num_voters; i++) {
                    if (strcmp(voters[i].id, voter_id) == 0) {
                        if (voters[i].voted) {
                            printf("You have already voted.\n");
                            break;
                        }
                        voter_index = i;
                        break;
                    }
                }
                if (voter_index == -1) {
                    printf("Sorry, there is no voter with that ID.\n");
                    break;
                }
                int candidate_choice;
                printf("Enter the candidate number to vote for: ");
                scanf("%d", &candidate_choice);
                if (candidate_choice < 1 || candidate_choice > num_candidates) {
                    printf("Sorry, that is not a valid candidate number.\n");
                    break;
                }
                candidates[candidate_choice-1].votes += 1;
                voters[voter_index].voted = 1;
                printf("Thank you for voting.\n");
                break;
            }
            case 4: { // View Results
                printf("Election Results:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;
            }
            case 5: // Quit
                printf("Thank you for using the Electronic Voting System.\n");
                break;
            default:
                printf("Sorry, that is not a valid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}