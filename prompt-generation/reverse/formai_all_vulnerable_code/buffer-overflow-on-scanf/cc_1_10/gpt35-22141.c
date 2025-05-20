//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

struct Candidate{
    char name[50];
    int votes;
};

int main(){
    struct Candidate candidates[MAX_CANDIDATES];
    char name[50];
    int num_candidates, i, j, num_voters, k, valid_vote;
    int votes[MAX_VOTERS];
    char vote_file[20];
    FILE *fptr;

    printf("\nEnter the number of candidates: ");
    scanf("%d", &num_candidates);

    for(i=0; i<num_candidates; i++){
        printf("\nEnter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    for(i=0; i<num_voters; i++){
        valid_vote = 0;
        printf("\nEnter the name of the candidate for voter %d: ", i+1);
        scanf("%s", name);

        for(j=0; j<num_candidates; j++){
            if(strcmp(name, candidates[j].name) == 0){
                votes[i] = j;
                candidates[j].votes++;
                valid_vote = 1;
                break;
            }
        }

        if(!valid_vote){
            printf("\nInvalid candidate name entered. Please try again.");
            i--;
        }
    }

    printf("\nResults after vote counting\n");

    for(i=0; i<num_candidates; i++){
        printf("\n%s: %d", candidates[i].name, candidates[i].votes);
    }

    printf("\nEnter a filename to save the vote count: ");
    scanf("%s", vote_file);
    fptr = fopen(vote_file, "w");

    if(fptr == NULL){
        printf("\nError opening file.");
        exit(1);
    }

    fprintf(fptr, "Results after vote counting\n");

    for(i=0; i<num_candidates; i++){
        fprintf(fptr, "\n%s: %d", candidates[i].name, candidates[i].votes);
    }

    fclose(fptr);

    return 0;
}