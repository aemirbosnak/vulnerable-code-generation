//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to get user choice
int getUserChoice(){
    int choice;
    printf("Choose Rock(1), Paper(2), Scissors(3): ");
    scanf("%d", &choice);
    return choice;
}

//Function to get computer choice
int getComputerChoice(){
    srand(time(NULL));
    int choice = rand() % 3 + 1;
    return choice;
}

//Function to display result
void displayResult(int userChoice, int computerChoice){
    if(userChoice == computerChoice){
        printf("It's a tie!\n");
    }
    else if(userChoice == 1 && computerChoice == 3){
        printf("You Win!\n");
    }
    else if(userChoice == 2 && computerChoice == 1){
        printf("You Win!\n");
    }
    else if(userChoice == 3 && computerChoice == 2){
        printf("You Win!\n");
    }
    else{
        printf("Computer Wins!\n");
    }
}

int main(){
    int userChoice, computerChoice;
    char playAgain = 'y';
    printf("Welcome to Rock-Paper-Scissors Game!\n");

    while(playAgain == 'y'){
        userChoice = getUserChoice();
        computerChoice = getComputerChoice();
        displayResult(userChoice, computerChoice);

        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
    }

    printf("\nThank you for playing! Goodbye!\n");

    return 0;
}