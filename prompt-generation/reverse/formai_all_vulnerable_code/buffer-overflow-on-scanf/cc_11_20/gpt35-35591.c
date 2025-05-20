//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct candidate{
    int id;
    char name[50];
    int votes;
};

int main(){
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate candidates[num_candidates];
    int voter_id = 0;
    int has_voted[num_candidates];
    for(int i = 0; i < num_candidates; i++){
        has_voted[i] = 0;
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].id = i+1;
        candidates[i].votes = 0;
    }
    while(voter_id != -1){
        printf("\nEnter voter ID (-1 to exit): ");
        scanf("%d", &voter_id);
        if(voter_id == -1){
            break;
        }
        if(voter_id > 1000 || voter_id < 1){
            printf("Invalid voter ID\n");
            continue;
        }
        int has_voted_before = 0;
        for(int i = 0; i < num_candidates; i++){
            if(has_voted[i] == voter_id){
                printf("This voter has already voted\n");
                has_voted_before = 1;
                break;
            }
        }
        if(has_voted_before){
            continue;
        }
        int vote_cast = 0;
        while(!vote_cast){
            printf("\nEnter candidate ID to vote for: ");
            int vote_id;
            scanf("%d", &vote_id);
            if(vote_id > num_candidates || vote_id < 1){
                printf("Invalid candidate ID\n");
                continue;
            }
            candidates[vote_id-1].votes++;
            has_voted[vote_id-1] = voter_id;
            printf("Vote successfully cast for %s\n", candidates[vote_id-1].name);
            vote_cast = 1;
        }
    }
    printf("\n** ELECTION RESULTS **\n");
    for(int i = 0; i < num_candidates; i++){
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    return 0;
}