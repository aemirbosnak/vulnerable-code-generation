//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure of Candidate
typedef struct Candidate{
    int id;
    char name[20];
    int count;
}Candidate;

// Voting function for individual voter
void vote(Candidate candidates[], int num_candidates){
    int voter_choice;
    printf("Please enter the ID of the candidate you want to vote for: ");
    scanf("%d", &voter_choice);
    if(voter_choice < 1 || voter_choice > num_candidates){
        printf("Invalid choice! Please enter a valid ID.\n");
    }
    else{
        candidates[voter_choice-1].count++;
        printf("Thank you for voting!\n");
    }
}

// Display function to show current vote count
void display(Candidate candidates[], int num_candidates){
    printf("ID\tName\tVotes\n");
    for(int i=0; i<num_candidates; i++){
        printf("%d\t%s\t%d\n", candidates[i].id, candidates[i].name, candidates[i].count);
    }
    printf("\n");
}

int main(){
    srand(time(NULL)); // Seed for random number generator
    
    int num_candidates = 4; // Number of initial candidates
    Candidate candidates[num_candidates]; // Array of candidates
    
    // Initializing candidates
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John Doe");
    candidates[0].count = 0;
    
    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane Smith");
    candidates[1].count = 0;
    
    candidates[2].id = 3;
    strcpy(candidates[2].name, "Bob Johnson");
    candidates[2].count = 0;
    
    candidates[3].id = 4;
    strcpy(candidates[3].name, "Alice Lee");
    candidates[3].count = 0;
    
    // Displaying initial candidates
    printf("Initial Candidates:\n");
    display(candidates, num_candidates);
    
    int option;
    while(1){
        printf("Press 1 to vote\n");
        printf("Press 2 to display current vote count\n");
        printf("Press 3 to exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                vote(candidates, num_candidates);
                break;
            case 2:
                display(candidates, num_candidates);
                break;
            case 3:
                printf("Thank you for using the electronic voting system!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid choice.\n");
                break;
        }
    }
    
    return 0;
}