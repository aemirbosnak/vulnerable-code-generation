//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>

int totalVoters = 0;
int candidate1Votes = 0;
int candidate2Votes = 0;
int candidate3Votes = 0;

void printResult() {
    printf("-----------RESULT-----------\n");
    printf("Total Voters: %d\n", totalVoters);
    printf("Candidate 1 votes: %d\n", candidate1Votes);
    printf("Candidate 2 votes: %d\n", candidate2Votes);
    printf("Candidate 3 votes: %d\n", candidate3Votes);

    if (candidate1Votes > candidate2Votes && candidate1Votes > candidate3Votes) {
        printf("Candidate 1 has won the election!\n");
    } else if (candidate2Votes > candidate1Votes && candidate2Votes > candidate3Votes) {
        printf("Candidate 2 has won the election!\n");
    } else if (candidate3Votes > candidate1Votes && candidate3Votes > candidate2Votes) {
        printf("Candidate 3 has won the election!\n");
    } else {
        printf("The election is a tie.\n");
    }
}

int main() {
    while (1) {
        printf("Welcome to the Electronic Voting System!\n");
        printf("Press 1 to cast your vote for Candidate 1\n");
        printf("Press 2 to cast your vote for Candidate 2\n");
        printf("Press 3 to cast your vote for Candidate 3\n");
        printf("Press 4 to view the result\n");
        printf("Press 5 to exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                candidate1Votes++;
                totalVoters++;
                printf("Thank you for voting for Candidate 1!\n\n");
                break;
            case 2:
                candidate2Votes++;
                totalVoters++;
                printf("Thank you for voting for Candidate 2!\n\n");
                break;
            case 3:
                candidate3Votes++;
                totalVoters++;
                printf("Thank you for voting for Candidate 3!\n\n");
                break;
            case 4:
                printResult();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}