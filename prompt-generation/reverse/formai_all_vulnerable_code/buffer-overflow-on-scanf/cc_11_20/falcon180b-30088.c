//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50

typedef struct{
    char name[MAX_NAME_LENGTH];
    int votes;
}candidate;

typedef struct{
    char name[MAX_NAME_LENGTH];
    int voter_id;
    int voted_candidate;
}voter;

int main(){

    candidate candidates[MAX_CANDIDATES];
    voter voters[MAX_VOTERS];
    int num_candidates, num_voters;
    char choice;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for(int i=0; i<num_candidates; i++){
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);

    for(int i=0; i<num_voters; i++){
        printf("Enter name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voter_id = i+1;
        voters[i].voted_candidate = -1;
    }

    printf("Voting has started.\n");

    while(1){
        int voted = 0;
        for(int i=0; i<num_voters; i++){
            if(voters[i].voted_candidate == -1){
                printf("Voter %d, please vote.\n", voters[i].voter_id);
                scanf(" %c", &choice);
                int chosen_candidate = -1;
                for(int j=0; j<num_candidates; j++){
                    if(strcmp(candidates[j].name, choice) == 0){
                        chosen_candidate = j;
                        break;
                    }
                }
                if(chosen_candidate == -1){
                    printf("Invalid vote.\n");
                }
                else{
                    voters[i].voted_candidate = chosen_candidate;
                    candidates[chosen_candidate].votes++;
                    printf("Vote recorded.\n");
                }
            }
        }
        if(voted == 0){
            break;
        }
    }

    printf("Voting has ended.\n");

    for(int i=0; i<num_candidates; i++){
        printf("Candidate %s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}