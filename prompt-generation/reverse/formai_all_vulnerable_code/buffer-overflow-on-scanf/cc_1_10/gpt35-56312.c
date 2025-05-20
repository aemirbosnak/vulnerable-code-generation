//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
// Romeo and Juliet: An electronic voting system for the Capulet and Montague factions

#include <stdio.h>
#include <stdlib.h>

// Function to display results of the election
void display_results(int votes_montague, int votes_capulet) {
    printf("\n---Election Results---\n");
    printf("Montague: %d votes\n", votes_montague);
    printf("Capulet: %d votes\n", votes_capulet);
    if (votes_montague > votes_capulet) {
        printf("Montague wins the election!\n");
    } else if (votes_montague < votes_capulet) {
        printf("Capulet wins the election!\n");
    } else {
        printf("It's a tie!\n");
    }
}

// Main function
int main() {
    int num_voters;
    int votes_montague = 0;
    int votes_capulet = 0;
    int i;

    printf("Welcome to the electronic voting system for the Montague and Capulet factions!\n");
    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);

    // Loop through each voter and record their vote
    for (i = 0; i < num_voters; i++) {
        printf("Voter %d, please enter your faction's candidate (M for Montague, C for Capulet): ", i+1);
        char vote;
        scanf(" %c", &vote);
        
        // Ensure a valid vote is recorded
        while (vote != 'M' && vote != 'C') {
            printf("Invalid candidate selected. Please enter your faction's candidate (M for Montague, C for Capulet): ");
            scanf(" %c", &vote);
        }
        
        // Record the vote
        if (vote == 'M') {
            votes_montague++;
            printf("Thank you, your vote for the Montague faction has been recorded.\n");
        } else {
            votes_capulet++;
            printf("Thank you, your vote for the Capulet faction has been recorded.\n");
        }
    }

    // Display results and declare a winner
    display_results(votes_montague, votes_capulet);

    return 0;
}