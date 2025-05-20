//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int vote;
} Voter;

void read_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter the vote of voter %s: ", voters[i].name);
        scanf("%d", &voters[i].vote);
    }
}

void count_votes(Candidate candidates[], Voter voters[], int num_candidates, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        int candidate_index = -1;
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, voters[i].name) == 0) {
                candidate_index = j;
                break;
            }
        }
        if (candidate_index!= -1) {
            candidates[candidate_index].votes++;
        }
    }
}

void print_results(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates, num_voters;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    read_candidates(candidates, num_candidates);
    read_voters(voters, num_voters);

    count_votes(candidates, voters, num_candidates, num_voters);

    print_results(candidates, num_candidates);

    return 0;
}