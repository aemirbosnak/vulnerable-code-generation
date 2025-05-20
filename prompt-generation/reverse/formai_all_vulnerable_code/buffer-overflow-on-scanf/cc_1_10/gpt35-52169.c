//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

struct Candidate{
    int id;
    char name[50];
    int vote_count;
};

struct Voter{
    int id;
    int voted;
};

void cast_vote(struct Voter voters[], struct Candidate candidates[], int num_voters, int num_candidates){
    int voter_id, candidate_id;
    printf("Enter Voter ID: ");
    scanf("%d", &voter_id);
    for(int i=0; i<num_voters; i++){
        if(voters[i].id == voter_id){
            if(voters[i].voted == 1){
                printf("You have already voted\n");
                return;
            }
            else{
                printf("List of Candidates:\n");
                for(int j=0; j<num_candidates; j++){
                    printf("%d. %s\n", candidates[j].id, candidates[j].name);
                }
                printf("Enter Candidate ID: ");
                scanf("%d", &candidate_id);
                for(int k=0; k<num_candidates; k++){
                    if(candidates[k].id == candidate_id){
                        candidates[k].vote_count++;
                        voters[i].voted = 1;
                        printf("%s received 1 vote from %d\n", candidates[k].name, voter_id);
                        return;
                    }
                }
                printf("Invalid Candidate ID\n");
                return;
            }
        }
    }
    printf("Invalid Voter ID\n");
}

void display_results(struct Candidate candidates[], int num_candidates){
    printf("Election Results\n");
    for(int i=0; i<num_candidates; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main(){
    int num_candidates, num_voters;
    printf("Enter Number of Candidates: ");
    scanf("%d", &num_candidates);
    printf("Enter Number of Voters: ");
    scanf("%d", &num_voters);

    //initialize candidates
    struct Candidate candidates[num_candidates];
    for(int i=0; i<num_candidates; i++){
        printf("Enter Candidate ID:\n");
        scanf("%d", &candidates[i].id);
        printf("Enter Candidate Name:\n");
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }

    //initialize voters
    struct Voter voters[num_voters];
    for(int i=0; i<num_voters; i++){
        printf("Enter Voter ID:\n");
        scanf("%d", &voters[i].id);
        voters[i].voted = 0;
    }

    //voting process
    int choice = 0;
    while(choice != 3){
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Enter Choice:\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: cast_vote(voters, candidates, num_voters, num_candidates);
                    break;
            case 2: display_results(candidates, num_candidates);
                    break;
            case 3: exit(0);
                    break;
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}