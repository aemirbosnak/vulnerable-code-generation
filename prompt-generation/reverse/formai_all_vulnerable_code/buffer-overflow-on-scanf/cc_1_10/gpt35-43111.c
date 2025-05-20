//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int players = 0; //number of players
int scores[10] = {0}; //stores scores for each player
int turn = 0; //tracks current player's turn
int dice[6] = {1,2,3,4,5,6}; //dice faces
int currPos = 0; //tracks current position of player on the board
int win = 0; //tracks if any player has won

int main(){
    printf("Welcome to Ludo - The Hilarious Game of Luck and Strategy!\n");
    printf("How many players? ");
    scanf("%d", &players);
    
    //initialize random seed
    srand(time(NULL));
    
    while(!win){
        printf("\n\n");
        printf("It's Player %d's Turn.\n", turn+1);
        printf("Press 'r' to roll the dice.\n");
        char input;
        scanf("%c", &input); //flush input buffer
        scanf("%c", &input); //get input
        
        if(input == 'r'){
            int roll = dice[rand()%6]; //generate a random dice roll
            printf("You Rolled a %d.\n", roll);
            currPos += roll; //increment position based on roll
            
            if(currPos > 100){
                currPos = 100 - (currPos - 100); //bounce back if overshooting
            }
            
            printf("You are Now on Square %d.\n", currPos);
            
            switch(currPos){
                case 27:
                    printf("Oops! You Stepped on a Snake and went back to Square 7.\n");
                    currPos = 7;
                    break;
                case 92:
                    printf("Wow! You Found a Ladder and climbed up to Square 100!\n");
                    currPos = 100;
                    break;
                case 100:
                    scores[turn] = 100; //store final score
                    printf("Congratulations! You Won the Game.\n");
                    win = 1; //set win flag
                    break;
                default:
                    break;
            }
            
            turn++;
            if(turn >= players){
                turn = 0; //start over
            }
        }
    }
    
    //print out final scores
    printf("\nFinal Scores: \n");
    for(int i = 0; i < players; i++){
        printf("Player %d: %d\n", i+1, scores[i]);
    }
    
    return 0;
}