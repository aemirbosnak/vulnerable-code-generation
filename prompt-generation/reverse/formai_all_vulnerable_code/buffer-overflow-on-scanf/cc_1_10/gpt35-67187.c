//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Structure for candidate information
struct candidate {
    char name[30];
    int votes;
};

// Function to display candidate names and vote counts
void display_records(struct candidate candidates[], int num_of_candidates) {
    printf("Candidate\tVotes\n");
    for(int i=0; i<num_of_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to get user vote choice
int get_vote_choice(int num_of_candidates) {
    int choice;
    printf("Enter the number of the candidate you wish to vote for (1-%d): ", num_of_candidates);
    scanf("%d", &choice);
    while(choice < 1 || choice > num_of_candidates) {
        printf("Invalid choice, please enter a number between 1 and %d: ", num_of_candidates);
        scanf("%d", &choice);
    }
    return choice;
}

int main() {
    int num_of_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_of_candidates);
    
    // Allocate memory for candidate array based on user input
    struct candidate* candidates = (struct candidate*)malloc(num_of_candidates * sizeof(struct candidate));
    
    // Get candidate names from user and initialize vote count to 0
    for(int i=0; i<num_of_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    
    printf("\n----- Voting Begins -----\n");
    
    // Loop to take user input for voting and increment candidate vote count
    int num_of_votes = 0;
    while(1) {
        int vote_choice = get_vote_choice(num_of_candidates);
        candidates[vote_choice-1].votes++;
        num_of_votes++;
        printf("Thank you for voting!\n");
        char choice;
        printf("Do you wish to continue voting? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'n') {
            break;
        }
    }
    
    printf("\n----- Voting Ends -----\n");
    
    // Display final vote counts and winner
    display_records(candidates, num_of_candidates);
    int max_votes = 0;
    for(int i=0; i<num_of_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    printf("\nTotal number of votes: %d\n", num_of_votes);
    printf("Winner(s):\n");
    for(int i=0; i<num_of_candidates; i++) {
        if(candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }
    
    free(candidates); // Free memory allocated for candidate array
    
    return 0;
}