//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int player_choice, comp_choice, player_score = 0, comp_score = 0, play_again = 1;
  printf("\nWelcome to the game of Rock, Paper, Scissors!\n");
  
  while(play_again)
  {
    printf("\nChoose: 1 for Rock, 2 for Paper, 3 for Scissors\n");
    scanf("%d", &player_choice);
    
    srand(time(NULL));
    comp_choice = rand() % 3 + 1;
    
    switch(player_choice)
    {
      case 1: printf("\nPlayer chose Rock");
              switch(comp_choice)
              {
                case 1: printf("\nComputer chose Rock");
                        printf("\nIt's a tie!");
                        break;
                case 2: printf("\nComputer chose Paper");
                        printf("\nComputer wins!");
                        comp_score++;
                        break;
                case 3: printf("\nComputer chose Scissors");
                        printf("\nPlayer wins!");
                        player_score++;
                        break;
              }
              break;
      
      case 2: printf("\nPlayer chose Paper");
              switch(comp_choice)
              {
                case 1: printf("\nComputer chose Rock");
                        printf("\nPlayer wins!");
                        player_score++;
                        break;
                case 2: printf("\nComputer chose Paper");
                        printf("\nIt's a tie!");
                        break;
                case 3: printf("\nComputer chose Scissors");
                        printf("\nComputer wins!");
                        comp_score++;
                        break;
              }
              break;
      
      case 3: printf("\nPlayer chose Scissors");
              switch(comp_choice)
              {
                case 1: printf("\nComputer chose Rock");
                        printf("\nComputer wins!");
                        comp_score++;
                        break;
                case 2: printf("\nComputer chose Paper");
                        printf("\nPlayer wins!");
                        player_score++;
                        break;
                case 3: printf("\nComputer chose Scissors");
                        printf("\nIt's a tie!");
                        break;
              }
              break;
      
      default: printf("\nInvalid choice.");
               break;
    }
    
    printf("\nPlayer: %d, Computer: %d", player_score, comp_score);
    
    if(player_score == 3 || comp_score == 3)
    {
      if(player_score == 3)
        printf("\nCongratulations, you win!");
      else
        printf("\nSorry, the computer wins!");
      
      printf("\nDo you want to play again? 1 for Yes, 0 for No\n");
      scanf("%d", &play_again);
      player_score = 0;
      comp_score = 0;
    }
  }

  return 0;
}