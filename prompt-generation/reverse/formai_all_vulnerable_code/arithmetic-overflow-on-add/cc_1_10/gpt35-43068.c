//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to hold candidate information
struct Candidate {
    char name[20];
    int votes;
};

int main() {
    int num_candidates, num_votes = 0;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct Candidate candidates[num_candidates];

    // loop through each candidate and get their name
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // loop through each voter and cast their vote
    while (1) {
        int choice;
        printf("Enter your vote (1-%d) or 0 to exit: ", num_candidates);
        scanf("%d", &choice);

        if (choice == 0) break;
        else if (choice <= num_candidates) {
            candidates[choice-1].votes++;
            num_votes++;
        }
        else {
            printf("Invalid choice, please try again.");
        }
    }

    // display results
    printf("\nResults:\n");
    printf("Total Votes: %d\n", num_votes);
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }

    // determine winner
    int max_votes = 0, max_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            max_index = i;
        }
    }
    if (max_index == -1) {
        printf("No winner.\n");
    }
    else {
        printf("%s is the winner with %d votes!\n", candidates[max_index].name, max_votes);
    }

    return 0;
}