//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int userVal, compVal;
    int userScore = 0, compScore = 0;
    
    srand(time(0));   //to generate random computer value
    
    printf("Welcome to the game of Rock, Paper, Scissors\n\n");
    printf("Rules:\nRock beats Scissors\nScissors beats Paper\nPaper beats Rock\n\n");
    
    for(int i=1; i<=5; i++){
        printf("Round %d\n", i);
        printf("Enter your choice\n1.Rock\n2.Paper\n3.Scissors\n");
        scanf("%d", &userVal);
        
        if(userVal<1 || userVal>3){
            printf("Invalid input\n");
            i--;
            continue;
        }
        
        compVal = rand()%3 + 1;
        
        if(userVal == compVal){
            printf("Tie!\n");
        }
        else if((userVal==1 && compVal==3) || (userVal==2 && compVal==1) || (userVal==3 && compVal==2)){
            printf("You win!\n");
            userScore++;
        }
        else{
            printf("Computer wins!\n");
            compScore++;
        }
        
        printf("Your score: %d\nComputer score: %d\n\n", userScore, compScore);
    }
    
    printf("\nFinal Scores:\nYour Score: %d\nComputer score: %d\n", userScore, compScore);
    
    if(userScore > compScore){
        printf("You are the winner!\n");
    }
    else if(userScore < compScore){
        printf("Computer wins the game!\n");
    }
    else{
        printf("Game is a tie!\n");
    }
    
    return 0; 
}