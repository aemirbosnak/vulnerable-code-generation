//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Structure for Voter Information
struct Voter{
    char name[20];
    int age;
    char gender[10];
    int voter_id;
    int has_voted;
};

//Function to Add New Voter
void AddVoter(struct Voter v[], int *v_count){
    printf("\n----Add New Voter----\n");
    printf("Enter Name: ");
    scanf("%s", v[*v_count].name);
    printf("Enter Age: ");
    scanf("%d", &v[*v_count].age);
    printf("Enter Gender: ");
    scanf("%s", v[*v_count].gender);
    v[*v_count].voter_id = *v_count + 1;
    v[*v_count].has_voted = 0;
    (*v_count)++;
    printf("New Voter Added Successfully!\n");
}

//Function to Display Voter List
void DisplayVoters(struct Voter v[], int v_count){
    printf("\n----Voter List----\n");
    printf("ID\tName\tAge\tGender\tVoted?\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < v_count; i++){
        printf("%d\t%s\t%d\t%s\t%d\n", v[i].voter_id, v[i].name, v[i].age, v[i].gender, v[i].has_voted);
    }
}

//Function to Vote by a Voter
void CastVote(struct Voter v[], int *v_count, int candidate_count){
    int id, choice;
    printf("\n----Cast Vote----\n");
    printf("Enter Voter ID: ");
    scanf("%d", &id);
    if(id > *v_count || id < 1){
        printf("Invalid Voter ID. Could not Cast Vote.\n");
        return;
    }
    if(v[id-1].has_voted){
        printf("This Voter has Already Casted their Vote!\n");
        return;
    }
    printf("\nCandidates: \n");
    for(int i = 1; i <= candidate_count; i++){
        printf("%d. Candidate %d\n", i, i);
    }
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    if(choice > candidate_count || choice < 1){
        printf("Invalid Candidate Choice. Could not Cast Vote.\n");
        return;
    }
    v[id-1].has_voted = 1;
    printf("Vote Casted Successfully!\n");
}

//Function to Display Vote Count for each Candidate
void DisplayVoteCount(int vote_count[], int candidate_count){
    printf("\n----Vote Count----\n");
    for(int i = 0; i < candidate_count; i++){
        printf("Candidate %d: %d Votes\n", i+1, vote_count[i]);
    }
}

int main(){
    //Voter Count
    int v_count = 0;
    //Candidate Count
    int candidate_count;
    printf("Enter Number of Candidates: ");
    scanf("%d", &candidate_count);
    //Vote Count for all Candidates
    int vote_count[candidate_count];
    for(int i = 0; i < candidate_count; i++){
        vote_count[i] = 0;
    }
    //Voter Information
    struct Voter v[100];
    //Menu
    printf("\n----Electronic Voting System----\n");
    int choice;
    while(1){
        printf("\n1. Add New Voter\n");
        printf("2. Display Voter List\n");
        printf("3. Cast Vote\n");
        printf("4. Display Vote Count\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: AddVoter(v, &v_count);
                break;
            case 2: DisplayVoters(v, v_count);
                break;
            case 3: CastVote(v, &v_count, candidate_count);
                break;
            case 4: DisplayVoteCount(vote_count, candidate_count);
                break;
            case 5: printf("\nThank You for Using Electronic Voting System!\n");
                exit(0);
            default: printf("\nInvalid Choice. Try Again!\n");
        }
    }
    return 0;
}