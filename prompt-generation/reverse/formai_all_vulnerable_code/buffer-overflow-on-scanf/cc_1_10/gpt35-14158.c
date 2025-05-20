//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//function to roll the dice
int rollDice(){
  return (rand() % 6) + 1;
}

//function to play the game
void playGame(int boardSize, int playersCount){

  //board
  int board[boardSize];
  for(int i = 0; i < boardSize; i++) board[i] = 0;

  //players
  struct player{
    int position;
    bool winner;
  };

  struct player players[playersCount];
  for(int i = 0; i < playersCount; i++){
    players[i].position = 0;
    players[i].winner = false;
  }

  //initialize random seed
  srand(time(0));

  int turn = 1;

  printf("Welcome to C Table Game!\n");

  while(true){

    //check if all players have won
    int winnersCount = 0;
    for(int i = 0; i < playersCount; i++){
      if(players[i].winner) winnersCount++;
    }
    if(winnersCount == playersCount){
      printf("All players have won!\n");
      break;
    }

    //print turn information
    printf("\nTurn %d\n", turn);

    //roll the dice for each player
    for(int i = 0; i < playersCount; i++){
      if(!players[i].winner){
        printf("Player %d: press enter to roll the dice.\n", i+1);
        fflush(stdin);
        getchar();
        int diceValue = rollDice();
        players[i].position += diceValue;
        printf("Player %d rolled the dice and got a %d!\n", i+1, diceValue);
        if(players[i].position >= boardSize){
          players[i].winner = true;
          printf("Player %d has won the game!\n", i+1);
        }
        else{
          printf("Player %d is now at position %d.\n", i+1, players[i].position);
        }
      }
    }

    turn++;

  }

}

//main function
int main(){

  printf("Choose the size of the board (minimum 20): ");
  int boardSize;
  scanf("%d", &boardSize);
  if(boardSize < 20){
    printf("Invalid board size. Exiting program.\n");
    return 1;
  }

  printf("Choose the number of players (maximum 4): ");
  int playersCount;
  scanf("%d", &playersCount);
  if(playersCount < 1 || playersCount > 4){
    printf("Invalid number of players. Exiting program.\n");
    return 1;
  }

  playGame(boardSize, playersCount);

  return 0;
}