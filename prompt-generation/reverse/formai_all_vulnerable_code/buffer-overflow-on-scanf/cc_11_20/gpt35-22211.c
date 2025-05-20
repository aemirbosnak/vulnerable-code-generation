//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int player_choice, computer_choice, player_score = 0, computer_score = 0, total_rounds;
   char play_again = 'y';
   
   printf("Welcome to the Ultimate Rock-Paper-Scissors Game\n");
   printf("------------------------------------------------\n");

   while(play_again == 'y') {
      printf("\nEnter the number of rounds you want to play: ");
      scanf("%d", &total_rounds);

      for(int i = 1; i <= total_rounds; i++) {
         printf("\nRound %d - What's your choice?\n", i);
         printf("1 : Rock 🥊\n");
         printf("2 : Paper 📃\n");
         printf("3 : Scissors ✂️\n");
         printf("Your choice: ");
         scanf("%d", &player_choice);

         srand(time(NULL));
         computer_choice = rand() % 3 + 1;

         switch(player_choice){
            case 1: 
               printf("You chose Rock 🥊\n");
               if(computer_choice == 1) {
                  printf("Computer chose Rock 🥊\n");
                  printf("It's a tie!\n");
               }
               else if(computer_choice == 2) {
                  printf("Computer chose Paper 📃\n");
                  printf("Computer wins this round!\n");
                  computer_score++;
               }
               else {
                  printf("Computer chose Scissors ✂️\n");
                  printf("You win this round!\n");
                  player_score++;
               }
               break;
            
            case 2: 
               printf("You chose Paper 📃\n");
               if(computer_choice == 1) {
                  printf("Computer chose Rock 🥊\n");
                  printf("You win this round!\n");
                  player_score++;
               }
               else if(computer_choice == 2) {
                  printf("Computer chose Paper 📃\n");
                  printf("It's a tie!\n");
               }
               else {
                  printf("Computer chose Scissors ✂️\n");
                  printf("Computer wins this round!\n");
                  computer_score++;
               }
               break;

            case 3: 
               printf("You chose Scissors ✂️\n");
               if(computer_choice == 1) {
                  printf("Computer chose Rock 🥊\n");
                  printf("Computer wins this round!\n");
                  computer_score++;
               }
               else if(computer_choice == 2) {
                  printf("Computer chose Paper 📃\n");
                  printf("You win this round!\n");
                  player_score++;
               }
               else {
                  printf("Computer chose Scissors ✂️\n");
                  printf("It's a tie!\n");
               }
               break;

            default: 
               printf("Oops! Invalid choice. Please try again.");
               i--;
         }
      }

      printf("\n-----------RESULTS-----------\n");
      printf("You won %d rounds.\n", player_score);
      printf("Computer won %d rounds.\n", computer_score);

      if(player_score > computer_score) {
         printf("\n💥💥 HURRAY! You have WON the game! 💥💥\n");
      }
      else if(player_score < computer_score){
         printf("\n😢😢 Alas! You LOST the game! 😢😢\n");
      }
      else {
         printf("\nWell well! It's a TIE game! 😎😎\n");
      }

      printf("\nDo you want to play again? (y/n): ");
      scanf(" %c", &play_again);

      if(play_again == 'y') {
         player_score = 0;
         computer_score = 0;
      }
   }
   
   return 0;
}