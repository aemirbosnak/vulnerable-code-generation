//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

int main()
{
    int num_voters, num_candidates;
    int i, j, k;
    int voter_id[MAX_VOTERS] = {0};
    int candidate_id[MAX_CANDIDATES] = {0};
    int vote_count[MAX_CANDIDATES] = {0};
    char voter_name[MAX_VOTERS][100];
    char candidate_name[MAX_CANDIDATES][100];

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Input the voter details
    printf("\nEnter the details of the voters:\n");
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of the voter %d: ", i + 1);
        scanf("%s", voter_name[i]);
        voter_id[i] = i + 1;
    }

    // Input the candidate details
    printf("\nEnter the details of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of the candidate %d: ", i + 1);
        scanf("%s", candidate_name[i]);
        candidate_id[i] = i + 1;
    }

    // Loop for the voting process
    for (i = 0; i < num_voters; i++) {
        printf("\nVoter %s, Please enter your choice of candidate by entering their ID Number:\n", voter_name[i]);
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", candidate_id[j], candidate_name[j]);
        }
        scanf("%d", &k);
        if (k > num_candidates) {
            printf("Invalid Candidate ID. Please re-enter.\n");
            i--;
            continue;
        }
        vote_count[k - 1]++;
        printf("Your vote has been registered successfully.\n");
    }

    // Display the voting results
    printf("\nVoting results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidate_name[i], vote_count[i]);
    }

    // Determine the winning candidate
    int winner = 0;
    for (i = 1; i < num_candidates; i++) {
        if (vote_count[i] > vote_count[winner]) {
            winner = i;
        }
    }
    printf("\nThe winner is: %s with %d votes.\n", candidate_name[winner], vote_count[winner]);

    return 0;
}