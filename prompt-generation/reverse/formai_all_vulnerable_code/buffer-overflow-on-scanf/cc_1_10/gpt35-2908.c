//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function prototypes
void cast_vote(int); //Function to cast vote
void view_results(); //Function to view results

//Structure to store candidate details
struct candidate{
    char name[20];
    int votes;
};

//Global variables declaration
struct candidate c[5]; //Array of candidates
int total_votes = 0; //Total number of votes casted

int main(){
    int choice, i;
    
    //Setting initial candidate details
    strcpy(c[0].name, "John");
    c[0].votes = 0;
    strcpy(c[1].name, "Emily");
    c[1].votes = 0;
    strcpy(c[2].name, "William");
    c[2].votes = 0;
    strcpy(c[3].name, "Sophia");
    c[3].votes = 0;
    strcpy(c[4].name, "Michael");
    c[4].votes = 0;
    
    printf("Welcome to our Electronic Voting System!\n");
    
    while(1){
        printf("\nPlease choose an option:\n1. Cast Vote\n2. View Results\n3. Exit\n");
        scanf("%d", &choice);
        
        //Switch case to handle user choice
        switch(choice){
            case 1:
                cast_vote(total_votes+1);
                total_votes++;
                break;
            case 2:
                view_results();
                break;
            case 3:
                printf("Thank you for using our Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }
    return 0;
}

//Function to cast vote
void cast_vote(int vote_no){
    int i, candidate_choice;
    
    printf("Vote no: %d\n", vote_no);
    printf("Please choose a candidate:\n");
    
    //Displaying list of candidate names
    for(i=0;i<5;i++){
        printf("%d. %s\n", i+1, c[i].name);
    }
    
    scanf("%d", &candidate_choice);
    
    //Incrementing votes of the chosen candidate
    c[candidate_choice-1].votes++;
    printf("Vote successfully casted for %s\n", c[candidate_choice-1].name);
}

//Function to view results
void view_results(){
    int i, highest_votes = -1, winner_index;
    
    printf("\nVoting Results:\n");
    for(i=0;i<5;i++){
        printf("%s : %d votes\n", c[i].name, c[i].votes);
        
        //Finding candidate with highest votes
        if(c[i].votes > highest_votes){
            highest_votes = c[i].votes;
            winner_index = i;
        }
    }
    
    printf("\nWinner of the Election: %s\n", c[winner_index].name);
}