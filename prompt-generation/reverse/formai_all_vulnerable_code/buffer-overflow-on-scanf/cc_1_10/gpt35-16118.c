//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
    char name[50];
    int vote_count;
};

void display_candidates(struct candidate *candidates, int num_candidates){
    printf("## Candidate List ##\n");
    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("\n");
}

int vote(struct candidate *candidates, int num_candidates, char *selected_candidate){
    for(int i=0; i<num_candidates; i++){
        if(strcmp(candidates[i].name, selected_candidate) == 0){
            candidates[i].vote_count++;
            printf("\nThank you, your vote has been recorded!\n");
            return 1;
        }
    }
    printf("\nError: Candidate not found!\n");
    return 0;
}

int main(){
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    struct candidate *candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));

    for(int i=0; i<num_candidates; i++){
        printf("\nEnter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }

    int choice;
    char selected_candidate[50];

    do{
        printf("\n## Welcome to E-Voting System ##\n");
        display_candidates(candidates, num_candidates);
        printf("%d. Exit\n", num_candidates+1);

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice <= num_candidates){
            printf("\nEnter the name of candidate %d: ", choice);
            scanf("%s", selected_candidate);
            vote(candidates, num_candidates, selected_candidate);
        }

    }while(choice != num_candidates+1);

    printf("\n## Result ##\n");
    display_candidates(candidates, num_candidates);
    
    free(candidates);

    return 0;
}