//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
    int players, max_turns, max_score, turn, score, winner = 0;
    printf("Welcome to the C Table Game!\n\n");
    printf("How many players will play? (2-4): ");
    scanf("%d", &players);
    
    while (players < 2 || players > 4){
        printf("The number of players must be 2 to 4. Please enter again: ");
        scanf("%d", &players);
    }
    
    printf("\nHow many turns will the game have? (5-20): ");
    scanf("%d", &max_turns);
    
    while (max_turns < 5 || max_turns > 20){
        printf("The number of turns must be 5 to 20. Please enter again: ");
        scanf("%d", &max_turns);
    }
    
    printf("\nWhat is the maximum score to win? (100-1000): ");
    scanf("%d", &max_score);
    
    while (max_score < 100 || max_score > 1000){
        printf("The maximum score must be 100 to 1000. Please enter again: ");
        scanf("%d", &max_score);
    }
    
    printf("\n");
    printf("*******************************************************************************************\n\n");
    printf("The game is ready to start!\n");
    printf("Players: %d \t Max Turns: %d \t Max Score: %d\n", players, max_turns, max_score);
    printf("\n");
    printf("*******************************************************************************************\n\n");
    
    srand(time(NULL)); // Setting the seed to use random numbers
    
    for(turn = 1; turn <= max_turns; turn++){
        printf("Turn %d: \n", turn);
        for(int i = 1; i <= players; i++){
            score = 0;
            printf("Player %d\n", i);
            int roll = rand() % 6 + 1; // random number between 1 and 6
            printf("Roll: %d\n", roll);
            score += roll;
            printf("Current Score: %d\n", score);
            char option = 'r';
            while(option == 'r'){
                printf("Roll Again? (r) or Hold? (h)\n");
                scanf(" %c", &option);
                if(option == 'r'){
                    roll = rand() % 6 + 1; // random number between 1 and 6
                    printf("Roll: %d\n", roll);
                    score += roll;
                    printf("Current Score: %d\n", score);
                }
            }
            printf("Turn Score: %d\n", score);
            printf("*******************************************************************************************\n\n");
            if(score >= max_score){
                winner = i;
                break;
            }    
        }
        if(winner != 0){ 
            break;
        }
    }
    
    printf("*******************************************************************************************\n\n");
    if(winner != 0){
        printf("Player %d won the game with a score of %d in %d turns!\n", winner, score, turn);
    }
    else{
        printf("Game over! There was no winner in %d turns.\n", max_turns);
    }
    printf("\n");
    printf("*******************************************************************************************\n\n");
    
    return 0;
}