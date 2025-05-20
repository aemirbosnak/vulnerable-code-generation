//FormAI DATASET v1.0 Category: Game ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  int score1=0, score2=0, diceRoll, turnScore=0, choice=0, player=1;
  srand(time(NULL));

  printf("Welcome to the Dice Game!!\n\n");

  while(score1 < 100 && score2 < 100){
    printf("Player %d's Turn.\n", player);
    printf("Press 1 to Roll or 0 to Hold.\n");
    scanf("%d", &choice);

    if(choice==1){
      diceRoll = rand()%6 + 1;
      printf("You rolled a %d.\n", diceRoll);

      if(diceRoll==1){
        printf("You lose your turn and your turn's score.\n\n");
        turnScore=0;
        if(player==1)
          player=2;
        else player=1;
        continue;
      }
      else{
        turnScore+=diceRoll;
        printf("Your turn score is %d.\n\n", turnScore);
      }
    }
    else{
      if(player==1){
        score1+=turnScore;
        printf("Player 1's score is now %d.\n\n", score1);
        player=2;
        turnScore=0;
      }
      else{
        score2+=turnScore;
        printf("Player 2's score is now %d.\n\n", score2);
        player=1;
        turnScore=0;
      }
    }
  }

  printf("\nPlayer %d Wins!!\n", (score1>score2)?1:2);

  return 0;
}