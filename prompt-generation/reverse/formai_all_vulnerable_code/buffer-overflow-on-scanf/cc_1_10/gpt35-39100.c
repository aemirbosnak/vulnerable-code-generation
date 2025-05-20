//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Declare the global variables
int candidate1_votes = 0;
int candidate2_votes = 0;
int candidate3_votes = 0;

int main() {

    char voter_name[20];
    int voter_age;
    int vote;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your name: ");
    scanf("%s", voter_name);
    printf("Please enter your age: ");
    scanf("%d", &voter_age);

    // Check if the voter is eligible to vote
    if(voter_age < 18) {
        printf("Sorry %s, you are not eligible to vote!\n", voter_name);
        return 0;
    } else {
        printf("Thank you for verifying your details!\n");
        printf("Please select the candidate you want to vote for:\n");
        printf("1. Romeo\n");
        printf("2. Juliet\n");
        printf("3. Paris\n");
        scanf("%d", &vote);

        // Update the vote count for the selected candidate
        switch(vote) {
            case 1:
                candidate1_votes++;
                printf("Thank you for voting for Romeo, %s!\n", voter_name);
                break;
            case 2:
                candidate2_votes++;
                printf("Thank you for voting for Juliet, %s!\n", voter_name);
                break;
            case 3:
                candidate3_votes++;
                printf("Thank you for voting for Paris, %s!\n", voter_name);
                break;
            default:
                printf("Invalid vote! Please select a valid candidate.\n");
                break;
        }

        // Display the current vote counts
        printf("Current Vote Count:\n");
        printf("Romeo - %d votes\n", candidate1_votes);
        printf("Juliet - %d votes\n", candidate2_votes);
        printf("Paris - %d votes\n", candidate3_votes);
        printf("Thank you for using the Electronic Voting System!\n");

        return 0;
    }
}