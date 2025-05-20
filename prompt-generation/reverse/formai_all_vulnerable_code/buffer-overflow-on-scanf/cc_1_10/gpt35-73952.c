//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include<stdio.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

int main() {
    int total_votes = 0;
    int voters_count = 0;
    int max_votes = 0;
    int winner_index = -1;
    int num_candidates = 3; // change to number of candidates

    struct candidate candidates[num_candidates];

    for(int i = 0; i < num_candidates; i++) {
        printf("Enter details for candidate %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &candidates[i].id);
        printf("Name: ");
        scanf("%s", candidates[i].name);
        
        candidates[i].votes = 0;
    }

    printf("\n");

    while(1) {
        int id;
        printf("Enter your voter ID or 0 to stop voting: ");
        scanf("%d", &id);

        if(id == 0)
            break;

        int candidate_index = -1;
        for(int i = 0; i < num_candidates; i++) {
            if(candidates[i].id == id) {
                candidate_index = i;
                break;
            }
        }

        if(candidate_index == -1) {
            printf("Invalid ID. Try again.\n");
            continue;
        }

        printf("You have voted for %s\n", candidates[candidate_index].name);
        total_votes++;
        candidates[candidate_index].votes++;
        voters_count++;
    }

    printf("\n");

    printf("Voting is closed.\n");
    printf("%d people have voted.\n\n", voters_count);

    printf("Results:\n\n");

    for(int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);

        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("\nThe winner is %s with %d votes.\n", candidates[winner_index].name, max_votes);

    return 0;
}