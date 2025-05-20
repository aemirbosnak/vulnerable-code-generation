//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_CANDIDATES 5

typedef struct candidate {
    char name[20];
    int votes;
} candidate;

candidate candidates[NUM_CANDIDATES] = {
    {"John Doe", 0},
    {"Jane Doe", 0},
    {"Bill Smith", 0},
    {"Mary Johnson", 0},
    {"Alex Perez", 0}
};

int main() {
    system("/bin/clear");
    printf("Welcome to the Electronic Voting System!\n");
    printf("------------------------\n");

    // Voting loop
    for (int i = 0; i < 10; i++) {
        printf("Enter the number of the candidate you want to vote for: ");
        int candidate_num;
        scanf("%d", &candidate_num);

        if (candidate_num < 1 || candidate_num > NUM_CANDIDATES) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        candidates[candidate_num - 1].votes++;
    }

    // Print results
    printf("------------------------\n");
    printf("The results of the election are:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("------------------------\n");
    printf("Thank you for voting!\n");

    return 0;
}