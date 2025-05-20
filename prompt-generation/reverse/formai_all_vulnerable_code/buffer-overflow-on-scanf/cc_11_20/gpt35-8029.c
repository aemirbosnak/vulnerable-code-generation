//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>

int main() {
    int n, option, vote;
    int candidate_1 = 0, candidate_2 = 0, candidate_3 = 0, candidate_4 = 0;

    printf("Welcome to the Electronic Voting System!\n");

    printf("Enter the number of voters: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Voter %d, please select your option:\n", i);
        printf("1. Candidate 1\n2. Candidate 2\n3. Candidate 3\n4. Candidate 4\n");
        scanf("%d", &option);

        if(option == 1) {
            candidate_1++;
        } else if(option == 2) {
            candidate_2++;
        } else if(option == 3) {
            candidate_3++;
        } else if(option == 4) {
            candidate_4++;
        } else {
            printf("Invalid option selected. Please try again.\n");
            i--;
        }
    }

    printf("Voting statistics:\n");
    printf("Candidate 1: %d votes\n", candidate_1);
    printf("Candidate 2: %d votes\n", candidate_2);
    printf("Candidate 3: %d votes\n", candidate_3);
    printf("Candidate 4: %d votes\n", candidate_4);

    printf("The winner is: ");

    if(candidate_1 > candidate_2 && candidate_1 > candidate_3 && candidate_1 > candidate_4) {
        printf("Candidate 1");
    } else if(candidate_2 > candidate_1 && candidate_2 > candidate_3 && candidate_2 > candidate_4) {
        printf("Candidate 2");
    } else if(candidate_3 > candidate_1 && candidate_3 > candidate_2 && candidate_3 > candidate_4) {
        printf("Candidate 3");
    } else if(candidate_4 > candidate_1 && candidate_4 > candidate_2 && candidate_4 > candidate_3) {
        printf("Candidate 4");
    } else {
        printf("No winner (tie)");
    }

    return 0;
}