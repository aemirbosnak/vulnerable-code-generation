//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

int votes[MAX_VOTERS][MAX_CANDIDATES];
char *candidates[MAX_CANDIDATES];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char *name){
    candidates[num_candidates] = name;
    num_candidates++;
}

void cast_vote(){
    int voter_id, candidate_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    printf("Select candidate (by ID):\n");
    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", i+1, candidates[i]);
    }
    scanf("%d", &candidate_id);
    votes[voter_id][candidate_id-1] = 1;
}

void count_votes(){
    int candidate_votes[MAX_CANDIDATES] = {0};
    for(int i=0; i<num_voters; i++){
        for(int j=0; j<num_candidates; j++){
            if(votes[i][j] == 1){
                candidate_votes[j]++;
            }
        }
    }
    printf("Results:\n");
    for(int i=0; i<num_candidates; i++){
        printf("%s: %d votes\n", candidates[i], candidate_votes[i]);
    }
}

int main(){
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    printf("Please enter the names of the candidates:\n");
    char name[50];
    for(int i=0; i<num_candidates; i++){
        scanf("%s", name);
        add_candidate(name);
    }
    printf("Please enter the number of voters: ");
    scanf("%d", &num_voters);
    for(int i=0; i<num_voters; i++){
        cast_vote();
    }
    printf("All votes have been cast.\n");
    count_votes();
    return 0;
}