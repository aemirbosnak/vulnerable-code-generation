//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for each candidate
struct Candidate {
    char name[50];
    int votes;
};

int main() {

    // Declare and initialize candidates
    struct Candidate candidate1 = {"John Doe", 0};
    struct Candidate candidate2 = {"Jane Smith", 0};
    struct Candidate candidate3 = {"Bob Johnson", 0};

    // Declare and initialize total number of voters and loop counter
    int numberOfVoters = 0;
    int i;

    // Get number of voters from user
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of voters: ");
    scanf("%d", &numberOfVoters);

    // Loop through each voter
    for (i = 1; i <= numberOfVoters; i++) {
        printf("Voter %d, please select your candidate:\n", i);
        printf("Enter 1 for %s\n", candidate1.name);
        printf("Enter 2 for %s\n", candidate2.name);
        printf("Enter 3 for %s\n", candidate3.name);

        // Declare and initialize vote variable
        int vote = 0;

        // Get vote from user and update candidate structure accordingly
        scanf("%d", &vote);

        switch (vote) {
            case 1:
                candidate1.votes++;
                printf("Thank you for voting for %s!\n", candidate1.name);
                break;
            case 2:
                candidate2.votes++;
                printf("Thank you for voting for %s!\n", candidate2.name);
                break;
            case 3:
                candidate3.votes++;
                printf("Thank you for voting for %s!\n", candidate3.name);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                i--;
                break;
        }
    }

    // Determine winner
    printf("\n\nVoting has ended. Here are the results:\n");
    printf("%s: %d votes\n", candidate1.name, candidate1.votes);
    printf("%s: %d votes\n", candidate2.name, candidate2.votes);
    printf("%s: %d votes\n", candidate3.name, candidate3.votes);

    if (candidate1.votes > candidate2.votes && candidate1.votes > candidate3.votes) {
        printf("\n%s is the winner with %d votes!\n", candidate1.name, candidate1.votes);
    } else if (candidate2.votes > candidate1.votes && candidate2.votes > candidate3.votes) {
        printf("\n%s is the winner with %d votes!\n", candidate2.name, candidate2.votes);
    } else if (candidate3.votes > candidate1.votes && candidate3.votes > candidate2.votes) {
        printf("\n%s is the winner with %d votes!\n", candidate3.name, candidate3.votes);
    } else {
        printf("\nThere is a tie!\n");
    }
    
    return 0;
}