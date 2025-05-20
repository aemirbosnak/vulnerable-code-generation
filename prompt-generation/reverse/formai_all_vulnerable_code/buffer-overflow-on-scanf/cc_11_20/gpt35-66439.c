//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} Candidate;

int main() {
    srand(time(NULL));
    Candidate candidates[4];
    candidates[0] = (Candidate){"Donald Duck", 0};
    candidates[1] = (Candidate){"Mickey Mouse", 0};
    candidates[2] = (Candidate){"Bugs Bunny", 0};
    candidates[3] = (Candidate){"SpongeBob SquarePants", 0};

    printf("Welcome to the Electronic Voting System! Please input your name to begin.\n");
    char name[50];
    scanf("%s", name);

    printf("Welcome, %s! Here are the candidates:\n", name);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Please enter the number of your chosen candidate: ");
    int candidateNum;
    scanf("%d", &candidateNum);

    if (candidateNum < 1 || candidateNum > 4) {
        printf("Error: Invalid candidate number selected.\n");
        return 1;
    } else {
        printf("You have voted for %s!\n", candidates[candidateNum - 1].name);
        candidates[candidateNum - 1].votes++;
    }

    printf("Thank you for voting! Here are the total votes for each candidate:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("\nAnd the winner is...");
    int maxVotes = 0;
    for (int i = 0; i < 4; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
        }
    }
    int winners[4];
    int numWinners = 0;
    for (int i = 0; i < 4; i++) {
        if (candidates[i].votes == maxVotes) {
            winners[numWinners] = i;
            numWinners++;
        }
    }
    printf("\n");
    if (numWinners == 1) {
        printf("%s is the winner with %d votes!\n", candidates[winners[0]].name, maxVotes);
    } else {
        printf("It's a tie between ");
        for (int i = 0; i < numWinners; i++) {
            printf("%s", candidates[winners[i]].name);
            if (i != numWinners - 1) {
                printf(" and ");
            }
        }
        printf(" with %d votes each!\n", maxVotes);
    }
    return 0;
}