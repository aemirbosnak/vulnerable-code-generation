//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>

//initialize global variables
int candidate1=0, candidate2=0, candidate3=0;

//function to display the menu
void displayMenu(){
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select your candidate:\n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");
    printf("4. Exit the voting system\n");
}

//function to cast a vote
void castVote(int candidate){
    switch(candidate){
        case 1:
            candidate1+=1;
            break;
        case 2:
            candidate2+=1;
            break;
        case 3:
            candidate3+=1;
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

int main(){
    int vote;
    displayMenu();
    
    do{
        printf("Enter your choice: ");
        scanf("%d", &vote);
        castVote(vote);
    }while(vote!=4);
    
    //display the final results
    printf("Voting has ended. Here are the final results:\n");
    printf("Candidate 1: %d votes\n", candidate1);
    printf("Candidate 2: %d votes\n", candidate2);
    printf("Candidate 3: %d votes\n", candidate3);
    
    //determine the winner
    if(candidate1>candidate2 && candidate1>candidate3){
        printf("The winner is Candidate 1!\n");
    }
    else if(candidate2>candidate1 && candidate2>candidate3){
        printf("The winner is Candidate 2!\n");
    }
    else if(candidate3>candidate1 && candidate3>candidate2){
        printf("The winner is Candidate 3!\n");
    }
    else{
        printf("There is a tie!\n");
    }
    
    return 0;
}