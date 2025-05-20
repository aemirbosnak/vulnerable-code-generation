//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
struct voter{
    char name[MAX];
    int id;
    int voted;
};
struct candidate{
    char name[MAX];
    int id;
    int votes;
};
struct voter v[MAX];
struct candidate c[MAX];
int n_voters = 0;
int n_candidates = 0;
void add_voter(){
    if(n_voters >= MAX){
        printf("Maximum limit of voters reached. No more voters can be added.\n");
        return;
    }
    printf("Enter name of voter: ");
    scanf("%s",v[n_voters].name);
    printf("Enter ID of voter: ");
    scanf("%d",&v[n_voters].id);
    v[n_voters].voted = 0;
    n_voters++;
    printf("Successfully added voter.\n");
}
void add_candidate(){
    if(n_candidates >= MAX){
        printf("Maximum limit of candidates reached. No more candidates can be added.\n");
        return;
    }
    printf("Enter name of candidate: ");
    scanf("%s",c[n_candidates].name);
    printf("Enter ID of candidate: ");
    scanf("%d",&c[n_candidates].id);
    c[n_candidates].votes = 0;
    n_candidates++;
    printf("Successfully added candidate.\n");
}
void cast_vote(){
    int id_voter, id_candidate;
    printf("Enter voter ID: ");
    scanf("%d",&id_voter);
    for(int i=0;i<n_voters;i++){
        if(v[i].id == id_voter){
            if(v[i].voted == 1){
                printf("This voter has already cast his/her vote.\n");
                return;
            }
            printf("Enter candidate ID: ");
            scanf("%d",&id_candidate);
            for(int j=0;j<n_candidates;j++){
                if(c[j].id == id_candidate){
                    c[j].votes++;
                    v[i].voted = 1;
                    printf("Vote casted successfully.\n");
                    return;
                }
            }
            printf("Candidate with specified ID not found.\n");
            return;
        }
    }
    printf("Voter with specified ID not found.\n");
}
void view_results(){
    if(n_candidates == 0){
        printf("No candidates available for voting.\n");
        return;
    }
    printf("Results:\n");
    printf("ID\tName\t\tVotes Received\n");
    for(int i=0;i<n_candidates;i++){
        printf("%d\t%s\t\t%d\n",c[i].id,c[i].name,c[i].votes);
    }
}
int main(){
    int choice;
    while(1){
        printf("Choose one of the following options:\n");
        printf("1. Add voter\n");
        printf("2. Add candidate\n");
        printf("3. Cast vote\n");
        printf("4. View results\n");
        printf("5. Quit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: add_voter();
                    break;
            case 2: add_candidate();
                    break;
            case 3: cast_vote();
                    break;
            case 4: view_results();
                    break;
            case 5: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}