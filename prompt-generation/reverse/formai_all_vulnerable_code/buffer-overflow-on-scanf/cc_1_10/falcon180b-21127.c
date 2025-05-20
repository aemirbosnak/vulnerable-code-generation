//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_candidates, num_voters, i, j, choice, valid_vote = 0;
    char candidates[100][100];
    char voters[100][100];

    printf("Welcome to the Retro Electronic Voting System!\n\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for(i=0; i<num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i]);
    }

    printf("\nPlease enter the number of voters: ");
    scanf("%d", &num_voters);

    for(i=0; i<num_voters; i++) {
        printf("\nEnter voter %d's name: ", i+1);
        scanf("%s", voters[i]);
    }

    srand(time(NULL));
    for(i=0; i<num_voters; i++) {
        printf("\n%s, please cast your vote:\n", voters[i]);
        for(j=0; j<num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j]);
        }
        printf("Your choice: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= num_candidates) {
            valid_vote = 1;
        } else {
            printf("\nInvalid choice, please try again.\n");
            i--;
        }
    }

    if(valid_vote == 1) {
        printf("\nThank you for using the Retro Electronic Voting System!\n");
    } else {
        printf("\nSorry, there was an error with your vote.\n");
    }

    return 0;
}