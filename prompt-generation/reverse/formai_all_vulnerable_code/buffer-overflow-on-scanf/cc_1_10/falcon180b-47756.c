//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 10

struct candidate {
    char name[50];
    int votes;
};

struct voter {
    char name[50];
    int age;
};

void read_candidates(struct candidate* candidates) {
    int i = 0;
    while (i < MAX_CANDIDATES && scanf("%s %d", candidates[i].name, &candidates[i].votes)!= EOF) {
        i++;
    }
}

void read_voters(struct voter* voters) {
    int i = 0;
    while (i < MAX_VOTERS && scanf("%s %d", voters[i].name, &voters[i].age)!= EOF) {
        i++;
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];

    read_candidates(candidates);
    read_voters(voters);

    int total_votes = 0;

    for (int i = 0; i < MAX_VOTERS; i++) {
        printf("Enter the votes for %s:\n", voters[i].name);
        int votes[MAX_CANDIDATES];
        int num_votes = 0;
        while (num_votes < MAX_VOTES && scanf("%d", &votes[num_votes])!= EOF) {
            num_votes++;
        }
        for (int j = 0; j < num_votes; j++) {
            int candidate_index = -1;
            for (int k = 0; k < MAX_CANDIDATES; k++) {
                if (strcmp(candidates[k].name, votes[j]) == 0) {
                    candidate_index = k;
                    break;
                }
            }
            if (candidate_index >= 0) {
                candidates[candidate_index].votes++;
                total_votes++;
            }
        }
    }

    printf("Total votes: %d\n", total_votes);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > 0) {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }

    return 0;
}