//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent the candidate in the election
struct Candidate {
    char name[30];
    int votes;
};

// Function to print the menu options
void print_menu_options() {
    printf("1. Add Candidate\n");
    printf("2. Display Candidates\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

int main() {
    int num_candidates = 0; // number of candidates
    char vote_buffer[30]; // buffer for vote input
    int num_votes = 0; // number of votes cast
    struct Candidate candidates[10]; // array of candidates
    int menu_choice = 0; // user menu choice
    
    printf("Welcome to the Electronic Voting System!\n");
    
    while (menu_choice != 5) {
        print_menu_options();
        printf("Please choose an option: ");
        scanf("%d", &menu_choice);
        
        switch (menu_choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", candidates[num_candidates].name);
                candidates[num_candidates].votes = 0;
                num_candidates++;
                printf("Candidate added!\n");
                break;
            case 2:
                printf("List of candidates:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%d. %s\n", i+1, candidates[i].name);
                }
                printf("\n");
                break;
            case 3:
                printf("Enter candidate name to cast vote: ");
                scanf("%s", vote_buffer);
                for (int i = 0; i < num_candidates; i++) {
                    if (strcmp(vote_buffer, candidates[i].name) == 0) {
                        candidates[i].votes++;
                        num_votes++;
                        printf("Vote cast for %s!\n", candidates[i].name);
                        break;
                    }
                }
                break;
            case 4:
                printf("Results:\n");
                for (int i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                printf("Total number of votes: %d\n", num_votes);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    
    return 0;
}