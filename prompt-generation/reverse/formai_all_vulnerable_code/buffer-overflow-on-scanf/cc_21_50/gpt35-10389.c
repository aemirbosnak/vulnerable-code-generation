//FormAI DATASET v1.0 Category: Game ; Style: funny
#include<stdio.h> //Header File

int main() {
  int player_score=0, computer_score=0; //Initializing values for scores
  char player_choice, computer_choice; //Declaring values for player choice and computer choice
  printf("Welcome to the hilarious game of Rock, Paper and Scissors!!\n");

  while(1) { //Infinite loop to continue game
    printf("Enter your choice: [R]ock, [P]aper or [S]cissors? ");
    scanf(" %c", &player_choice);

    switch(player_choice) {
        case 'R': printf("You chose Rock\n"); break;
        case 'P': printf("You chose Paper\n"); break;
        case 'S': printf("Your chose Scissors\n"); break;
        default: printf("OMG you can't even choose right...DEAL WITH IT!!\n"); continue; //If user inputs wrong option
    }

    computer_choice = rand()%3; //Computer chooses randomly from Rock, paper and scissors (R, P, S)

    switch(computer_choice) {
        case 0: printf("Computer chooses Rock\n"); break;
        case 1: printf("Computer chooses Paper\n"); break;
        case 2: printf("Computer chooses Scissors\n"); break;
    }

    //Determining Result of match
    if(player_choice == 'R' && computer_choice == 2)
        printf("YAY! You won!.\n");
    else if (player_choice == 'P' && computer_choice == 0)
        printf("YAY! You won!\n");
    else if (player_choice == 'S' && computer_choice == 1)
        printf("YAY! You won!\n");
    else if (player_choice == 'R' && computer_choice == 1)
        printf("HAHA! Computer won!.\n");
    else if (player_choice == 'P' && computer_choice == 2)
        printf("HAHA! Computer won!\n");
    else if (player_choice == 'S' && computer_choice == 0)
        printf("HAHA! Computer won!\n");
    else
        printf("Draw\n");

    //Determining Score
    if(player_choice == 'R' && computer_choice == 2)
        player_score++;
    else if (player_choice == 'P' && computer_choice == 0)
        player_score++;
    else if (player_choice == 'S' && computer_choice == 1)
        player_score++;
    else if (player_choice == 'R' && computer_choice == 1)
        computer_score++;
    else if (player_choice == 'P' && computer_choice == 2)
        computer_score++;
    else if (player_choice == 'S' && computer_choice == 0)
        computer_score++;

    //Final Score
    printf("Your score: %d | Computer score: %d\n\n", player_score, computer_score);

    //Ending 
    if(player_score==5 || computer_score==5) {
        printf("Game Over\n");
        if(player_score>computer_score)
            printf("YAY! You Won!\n");
        else
            printf("HAHA! Computer Won\n");
        break;
    }
  }
  return 0;
}