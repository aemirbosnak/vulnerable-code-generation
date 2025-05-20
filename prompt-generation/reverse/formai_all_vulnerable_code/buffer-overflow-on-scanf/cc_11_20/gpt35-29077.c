//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("**********************************************\n");
    printf("**Welcome to the Shape-Shifting Voting System!**\n");
    printf("**********************************************\n");

    int candidates = 4;
    char candidateNames[4][20] = {"John Smith", "Jane Doe", "Bob Johnson", "Emily Thompson"};
    int votes[4] = {0, 0, 0, 0};
    int voterID = -1;
    int currentVote = -1;
    int totalVotes = 0;

    while (1) {
        printf("\nPlease enter your voter ID: ");
        scanf("%d", &voterID);

        if (voterID == -1) {
            printf("Thank you for using the Shape-Shifting Voting System!\n");
            printf("Total votes cast: %d\n", totalVotes);
            for (int i = 0; i < candidates; i++) {
                printf("%s received %d votes\n", candidateNames[i], votes[i]);
            }
            exit(0);
        }

        printf("\nWelcome Voter %d!\n", voterID);

        while (1) {
            printf("\nPlease select a candidate by typing their number:\n");
            for (int i = 0; i < candidates; i++) {
                printf("%d. %s\n", i + 1, candidateNames[i]);
            }

            int choice = 0;
            scanf("%d", &choice);

            if (choice == 0) {
                printf("\nInvalid choice. Please try again.\n");
                continue;
            } else if (choice == 9) {
                printf("\nShapeshift activated! Candidates now have different names and appearances.\n");
                char newNames[4][20] = {"Samantha Lee", "David Wang", "Linda Chen", "Daniel Kim"};
                for (int i = 0; i < candidates; i++) {
                    strcpy(candidateNames[i], newNames[i]);
                }
                continue;
            } else if (choice == 8) {
                printf("\nShapeshift deactivated! Candidates names and appearances have returned to normal.\n");
                char oldNames[4][20] = {"John Smith", "Jane Doe", "Bob Johnson", "Emily Thompson"};
                for (int i = 0; i < candidates; i++) {
                    strcpy(candidateNames[i], oldNames[i]);
                }
                continue;
            } else if (choice > candidates) {
                printf("\nInvalid choice. Please try again.\n");
                continue;
            }

            currentVote = choice - 1;
            printf("\nYou are voting for %s. Confirm? (Y/N)", candidateNames[currentVote]);
            char confirm;
            scanf(" %c", &confirm);

            if (confirm == 'Y' || confirm == 'y') {
                votes[currentVote]++;
                totalVotes++;
                printf("\nThank you for voting! Your vote for %s has been recorded.\n", candidateNames[currentVote]);
                break;
            } else if (confirm == 'N' || confirm == 'n') {
                printf("\nVote cancelled. Please make another selection.\n");
                currentVote = -1;
            } else {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
    }
}