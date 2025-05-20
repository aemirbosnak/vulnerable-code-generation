//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct candidate {
    int id;
    char name[50];
} candidate;

typedef struct voter {
    int id;
    int vote;
} voter;

int main() {
    candidate candidates[5];
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John");
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane");
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Bob");
    candidates[3].id = 4;
    strcpy(candidates[3].name, "Karen");
    candidates[4].id = 5;
    strcpy(candidates[4].name, "Tom");
    printf("Available candidates:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    voter voters[10];
    for (int i = 0; i < 10; i++) {
        voters[i].id = i + 1;
        printf("Voter %d, please enter the candidate id you want to vote for: ", i + 1);
        scanf("%d", &voters[i].vote);
        while (voters[i].vote < 1 || voters[i].vote > 5) {
            printf("Invalid candidate id. Please enter a valid candidate id: ");
            scanf("%d", &voters[i].vote);
        }
        printf("Thank you for voting.\n");
    }
    int candidate_votes[5] = {0};
    for (int i = 0; i < 10; i++) {
        candidate_votes[voters[i].vote - 1]++;
    }
    printf("Vote counts:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", candidates[i].name, candidate_votes[i]);
    }
    int max_votes = 0, winner_id = 0;
    for (int i = 0; i < 5; i++) {
        if (candidate_votes[i] > max_votes) {
            max_votes = candidate_votes[i];
            winner_id = i + 1;
        }
    }
    printf("Winner: %s\n", candidates[winner_id - 1].name);
    return 0;
}