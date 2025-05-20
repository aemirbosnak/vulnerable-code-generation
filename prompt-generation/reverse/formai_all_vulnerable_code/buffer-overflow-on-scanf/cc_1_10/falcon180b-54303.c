//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct candidate {
    char name[50];
    int votes;
};

int main() {
    int num_candidates, num_voters;
    struct candidate candidates[MAX_CANDIDATES];
    char input[100];

    // Get number of candidates
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    // Get candidate names and initialize vote count
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name #%d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    // Get number of voters
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    // Get votes from each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Enter vote for voter #%d: ", i+1);
        scanf("%s", input);
        int vote_index = -1;
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, input) == 0) {
                vote_index = j;
                break;
            }
        }
        if (vote_index!= -1) {
            candidates[vote_index].votes++;
        } else {
            printf("Invalid vote\n");
        }
    }

    // Print election results
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}