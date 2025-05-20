//FormAI DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Player struct to store player information
struct Player{
    char name[20];
    int score;
};

void printLeaderboard(struct Player *players, int numPlayers){
    printf("Leaderboard:\n");
    printf("Name\t\tScore\n");
    for(int i=0; i<numPlayers; i++){
        printf("%s\t\t%d\n", players[i].name, players[i].score);
    }
}

int main(){
    int numPlayers;
    printf("How many players will be playing?\n");
    scanf("%d", &numPlayers);
    
    struct Player players[numPlayers];
    for(int i=0; i<numPlayers; i++){
        printf("Enter player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    char input[20];
    int currPlayer = 0;
    int numMoves = 0;
    
    printf("Game started!\n");
    while(1){
        printf("%s's turn. Enter your move: ", players[currPlayer].name);
        scanf("%s", input);
        
        if(strcmp(input, "end") == 0){
            printf("Game over!\n");
            printLeaderboard(players, numPlayers);
            return 0;
        }
        else{
            // Parse C syntax
            if(strstr(input, "{") && strstr(input, "}")){
                players[currPlayer].score += 2;
            }
            else if(strstr(input, "(") && strstr(input, ")")){
                players[currPlayer].score += 1;
            }
            else{
                players[currPlayer].score -= 1;
            }
            
            numMoves++;
            
            if(numMoves % numPlayers == 0){
                // Print leaderboard after each round
                printLeaderboard(players, numPlayers);
            }
            
            currPlayer = (currPlayer + 1) % numPlayers;
        }
    }
}