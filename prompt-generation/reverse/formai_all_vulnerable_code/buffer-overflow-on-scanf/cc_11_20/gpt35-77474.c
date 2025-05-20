//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

struct voter {
    int id;
    int voted;
};

int main() {
    int num_candidates = 3;
    struct candidate candidates[num_candidates];
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John Doe");
    candidates[0].votes = 0;
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane Smith");
    candidates[1].votes = 0;
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Bob Johnson");
    candidates[2].votes = 0;

    int num_voters = 5;
    struct voter voters[num_voters];
    for (int i = 0; i < num_voters; i++) {
        voters[i].id = i + 1;
        voters[i].voted = 0;
    }

    int votes_cast = 0;
    while (votes_cast < num_voters) {
        printf("Enter your voter ID: ");
        int voter_id;
        scanf("%d", &voter_id);

        int voter_index = -1;
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].id == voter_id) {
                voter_index = i;
                break;
            }
        }

        if (voter_index == -1) {
            printf("Invalid voter ID\n");
            continue;
        }

        if (voters[voter_index].voted) {
            printf("You have already cast your vote\n");
            continue;
        }

        printf("Enter the candidate ID you want to vote for: ");
        int candidate_id;
        scanf("%d", &candidate_id);

        int candidate_index = -1;
        for (int i = 0; i < num_candidates; i++) {
            if (candidates[i].id == candidate_id) {
                candidate_index = i;
                break;
            }
        }

        if (candidate_index == -1) {
            printf("Invalid candidate ID\n");
            continue;
        }

        candidates[candidate_index].votes++;
        voters[voter_index].voted = 1;
        votes_cast++;
    }

    printf("Vote count:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }

    return 0;
}