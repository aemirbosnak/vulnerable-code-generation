//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Structure to store candidate details*/
struct candidate{
    int id;
    char name[20];
    int votes;
}c[3];

/*Function to display candidate information*/
void display_candidates(){
    printf("\nCandidate Information:\n\n");
    for(int i=0;i<3;i++){
        printf("ID: %d\nName: %s\nVotes: %d\n\n",c[i].id,c[i].name,c[i].votes);
    }
}

/*Function to vote for a candidate*/
void vote(){
    int id;
    printf("\nEnter the ID of the candidate you wish to vote for: ");
    scanf("%d",&id);
    switch(id){
        case 1:
            c[0].votes++;
            printf("\nSuccessfully voted for candidate %d - %s\n",c[0].id,c[0].name);
            break;
        case 2:
            c[1].votes++;
            printf("\nSuccessfully voted for candidate %d - %s\n",c[1].id,c[1].name);
            break;
        case 3:
            c[2].votes++;
            printf("\nSuccessfully voted for candidate %d - %s\n",c[2].id,c[2].name);
            break;
        default:
            printf("\nInvalid candidate ID\n");
    }
}

/*Function to find the winner*/
void winner(){
    int max_votes = -1;
    int winner_id = -1;
    for(int i=0;i<3;i++){
        if(c[i].votes > max_votes){
            max_votes = c[i].votes;
            winner_id = c[i].id;
        }
    }
    for(int i=0;i<3;i++){
        if(c[i].id == winner_id){
            printf("\nWinner: Candidate %d - %s with %d votes\n",winner_id,c[i].name,max_votes);
            break;
        }
    }
}

/*Main function*/
int main(){
    printf("Welcome to the Electronic Voting System!\n\n");

    /*Initialize candidate information*/
    c[0].id = 1;
    strcpy(c[0].name,"John Doe");
    c[0].votes = 0;

    c[1].id = 2;
    strcpy(c[1].name,"Jane Smith");
    c[1].votes = 0;

    c[2].id = 3;
    strcpy(c[2].name,"Bob Johnson");
    c[2].votes = 0;

    /*Display candidate information*/
    display_candidates();

    /*Loop to allow multiple votes*/
    int flag = 1;
    while(flag){
        int choice;
        printf("\nMenu:\n1. Vote\n2. Display Candidate Information\n3. Find Winner\n4. Exit\n\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                vote();
                break;
            case 2:
                display_candidates();
                break;
            case 3:
                winner();
                break;
            case 4:
                flag = 0;
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }
    printf("\nThanks for using the Electronic Voting System!\n");
    return 0;
}