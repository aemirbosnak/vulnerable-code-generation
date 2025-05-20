//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int choice, voterID, candidates[4] = {0};
    char vote_again;
    FILE *voters_database;
    voters_database = fopen("voters.txt", "a+");

    printf("\nWelcome to the Electronic Voting System!\n");

    do {
        printf("\nPlease select your candidate:\n\n");
        printf("1. Candidate 1\n");
        printf("2. Candidate 2\n");
        printf("3. Candidate 3\n");
        printf("4. Candidate 4\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        printf("Enter your voter ID: ");
        scanf("%d", &voterID);
        fflush(stdin);

        while (!feof(voters_database)) {
            int id = 0;
            fscanf(voters_database, "%d", &id);
            if (id == voterID) {
                printf("\nYou have already voted. Your vote cannot be submitted again.\n");
                break;
            }
        }

        if (choice == 1) {
            candidates[0] += 1;
            printf("\nYou have successfully voted for Candidate 1.\n");
        } else if (choice == 2) {
            candidates[1] += 1;
            printf("\nYou have successfully voted for Candidate 2.\n");
        } else if (choice == 3) {
            candidates[2] += 1;
            printf("\nYou have successfully voted for Candidate 3.\n");
        } else if (choice == 4) {
            candidates[3] += 1;
            printf("\nYou have successfully voted for Candidate 4.\n");
        } else {
            printf("\nInvalid choice. Please select a candidate from the list.\n");
        }

        fprintf(voters_database, "%d\n", voterID);
        printf("\nThank you for voting!\n");

        printf("\nDo you want to vote again? (Y/N): ");
        scanf("%c", &vote_again);
        fflush(stdin);
    } while (vote_again == 'Y' || vote_again == 'y');

    printf("\nVoting results:\n\n");
    printf("Candidate 1: %d votes\n", candidates[0]);
    printf("Candidate 2: %d votes\n", candidates[1]);
    printf("Candidate 3: %d votes\n", candidates[2]);
    printf("Candidate 4: %d votes\n", candidates[3]);

    fclose(voters_database);

    return 0;
}