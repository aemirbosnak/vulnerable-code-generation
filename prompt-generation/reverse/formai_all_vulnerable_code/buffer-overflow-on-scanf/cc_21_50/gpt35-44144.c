//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate {
    int candidate_id;
    char candidate_name[20];
    char party_name[20];
    int votes;
};

struct voter {
    int voter_id;
    char voter_name[20];
    int voted_for;
};

struct candidate candidates[5];
struct voter voters[10];

int main()
{
    int i, j, vote=0;
    int count1=0, count2=0, count3=0, count4=0, count5=0;
    int voted[10] = {0};
    char input[10];
    
    candidates[0].candidate_id = 1;
    strcpy(candidates[0].candidate_name, "John");
    strcpy(candidates[0].party_name, "Red Party");
    candidates[0].votes = 0;
    
    candidates[1].candidate_id = 2;
    strcpy(candidates[1].candidate_name, "Jane");
    strcpy(candidates[1].party_name, "Blue Party");
    candidates[1].votes = 0;
    
    candidates[2].candidate_id = 3;
    strcpy(candidates[2].candidate_name, "Tom");
    strcpy(candidates[2].party_name, "Green Party");
    candidates[2].votes = 0;
    
    candidates[3].candidate_id = 4;
    strcpy(candidates[3].candidate_name, "Mary");
    strcpy(candidates[3].party_name, "Yellow Party");
    candidates[3].votes = 0;
    
    candidates[4].candidate_id = 5;
    strcpy(candidates[4].candidate_name, "Kevin");
    strcpy(candidates[4].party_name, "Purple Party");
    candidates[4].votes = 0;
    
    printf("Welcome to the Electronic Voting System\n\n");
    
    for(i=0;i<10;i++){
        
        printf("Voter %d please enter your name: ", i+1);
        scanf("%s", input);
        strcpy(voters[i].voter_name, input);
        
        printf("Select the candidate you want to vote for:\n");
        printf("Candidate 1 - %s\n", candidates[0].candidate_name);
        printf("Candidate 2 - %s\n", candidates[1].candidate_name);
        printf("Candidate 3 - %s\n", candidates[2].candidate_name);
        printf("Candidate 4 - %s\n", candidates[3].candidate_name);
        printf("Candidate 5 - %s\n", candidates[4].candidate_name);
        printf("Enter your chosen candidate ID: ");
        scanf("%d", &vote);
        
        while(vote<1 || vote>5){
            printf("Invalid entry! Please choose again: ");
            scanf("%d", &vote);
        }
        
        while(voted[i]!=0){
            printf("You have already voted.\n");
            printf("Please enter the ID of another candidate: ");
            scanf("%d", &vote);
            while(vote<1 || vote>5){
                printf("Invalid entry! Please choose again: ");
                scanf("%d", &vote);
            }
        }
        
        voted[i] = 1;
        voters[i].voted_for = vote;
        
        switch(vote){
            case 1:
                candidates[0].votes++;
                break;
            case 2:
                candidates[1].votes++;
                break;
            case 3:
                candidates[2].votes++;
                break;
            case 4:
                candidates[3].votes++;
                break;
            case 5:
                candidates[4].votes++;
                break;
        }
        
        printf("Thank you for your vote %s!\n\n", voters[i].voter_name);
    }
    
    
    printf("Number of votes received by each candidate:\n");
    printf("Candidate %d - %s: %d votes\n", candidates[0].candidate_id, candidates[0].candidate_name, candidates[0].votes);
    printf("Candidate %d - %s: %d votes\n", candidates[1].candidate_id, candidates[1].candidate_name, candidates[1].votes);
    printf("Candidate %d - %s: %d votes\n", candidates[2].candidate_id, candidates[2].candidate_name, candidates[2].votes);
    printf("Candidate %d - %s: %d votes\n", candidates[3].candidate_id, candidates[3].candidate_name, candidates[3].votes);
    printf("Candidate %d - %s: %d votes\n", candidates[4].candidate_id, candidates[4].candidate_name, candidates[4].votes);
    
    if(candidates[0].votes > candidates[1].votes && candidates[0].votes > candidates[2].votes && candidates[0].votes > candidates[3].votes && candidates[0].votes > candidates[4].votes){
        printf("\n%s of the %s wins the election with a total of %d votes.\n", candidates[0].candidate_name, candidates[0].party_name, candidates[0].votes);
    }
    else if(candidates[1].votes > candidates[0].votes && candidates[1].votes > candidates[2].votes && candidates[1].votes > candidates[3].votes && candidates[1].votes > candidates[4].votes){
        printf("\n%s of the %s wins the election with a total of %d votes.\n", candidates[1].candidate_name, candidates[1].party_name, candidates[1].votes);
    }
    else if(candidates[2].votes > candidates[0].votes && candidates[2].votes > candidates[1].votes && candidates[2].votes > candidates[3].votes && candidates[2].votes > candidates[4].votes){
        printf("\n%s of the %s wins the election with a total of %d votes.\n", candidates[2].candidate_name, candidates[2].party_name, candidates[2].votes);
    }
    else if(candidates[3].votes > candidates[0].votes && candidates[3].votes > candidates[1].votes && candidates[3].votes > candidates[2].votes && candidates[3].votes > candidates[4].votes){
        printf("\n%s of the %s wins the election with a total of %d votes.\n", candidates[3].candidate_name, candidates[3].party_name, candidates[3].votes);
    }
    else{
        printf("\n%s of the %s wins the election with a total of %d votes.\n", candidates[4].candidate_name, candidates[4].party_name, candidates[4].votes);
    }
    
    return 0;
}