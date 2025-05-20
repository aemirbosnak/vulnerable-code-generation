//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void main() {
    int num_candidates, i;
    candidate candidates[10]; // assuming maximum of 10 candidates
    FILE *fp;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Read candidate names and store them in an array
    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", candidates[i].name);
    }

    // Initialize all votes to zero
    for (i = 0; i < num_candidates; i++) {
        candidates[i].votes = 0;
    }

    // Open the file to write the results
    fp = fopen("results.txt", "w");

    // Loop until the user decides to stop
    while (1) {
        printf("\n");
        printf("1. Vote\n");
        printf("2. View Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                // Ask user to enter the candidate number
                printf("Enter the candidate number: ");
                scanf("%d", &i);

                // Increment the vote count of the selected candidate
                candidates[i-1].votes++;

                // Write the results to the file
                fprintf(fp, "Candidate %s received %d votes.\n", candidates[i-1].name, candidates[i-1].votes);
                break;

            case 2:
                // Display the current results
                printf("\nCurrent Results:\n");
                for (i = 0; i < num_candidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;

            case 3:
                fclose(fp);
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}