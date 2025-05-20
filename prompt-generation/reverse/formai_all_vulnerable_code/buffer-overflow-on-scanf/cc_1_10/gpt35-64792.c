//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int play_game(char c, int score){
    if(score > 10) return score; // Base case: if the player's score is more than 10, the game ends

    int num = (rand() % 2) + 1; // Random number generator for computer's choice

    printf("\n\nChoose one: \n1. Rock\n2. Paper\n3. Scissors\n"); // Displaying options
    int choice = 0; 
    scanf("%d", &choice); // Taking input from user
    if(choice<1 || choice>3){ // If input is not valid, start over
        printf("Invalid Input!\n");
        play_game(c, score);
    }

    // Display Computer's Move
    if(num == 1) printf("Computer chose: Rock\n");
    else if(num == 2) printf("Computer chose: Paper\n");
    else printf("Computer chose: Scissors\n");

    // Game Logic
    if(num == choice) {
        printf("Draw!\n");
        play_game(c, score);
    }
    else if((num == 1 && choice == 2) || (num == 2 && choice == 3) || (num == 3 && choice == 1)){
        printf("You Win!\n");
        score++;
        play_game(c, score);
    }
    else {
        printf("Computer Wins!\n");
        score--;
        play_game(c, score);
    }
    return 0;
}

int main(){
    srand(time(NULL)); // Initialization of random number generator

    printf("Welcome to the game\n\n");
    printf("Do you want to play? Press 'y' for YES and 'n' for NO: ");
    char c; 
    scanf(" %c", &c); // Taking input from user

    if(c=='n'){
        printf("Goodbye");
        return 0;
    }

    int score = 0;
    play_game(c, score); // Starting game

    return 0;
}