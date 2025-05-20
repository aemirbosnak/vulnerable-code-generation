//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed random generator with current time
   int user_choice, computer_choice;
   int wins = 0, losses = 0, draws = 0;
   
   printf("***Welcome to the Statistical Adventure Game***\n\n");
   
   while (1) { // loop forever (until user quits)
      printf("Enter your choice (1 = rock, 2 = paper, 3 = scissors, 4 = quit): ");
      scanf("%d", &user_choice);
      
      if (user_choice == 4) { // user quits
         printf("Thanks for playing!\n");
         break;
      }
      
      // computer chooses randomly
      computer_choice = rand() % 3 + 1;
      
      printf("You chose ");
      if (user_choice == 1) printf("rock");
      else if (user_choice == 2) printf("paper");
      else if (user_choice == 3) printf("scissors");
      printf(". Computer chose ");
      if (computer_choice == 1) printf("rock");
      else if (computer_choice == 2) printf("paper");
      else if (computer_choice == 3) printf("scissors");
      
      if (computer_choice == user_choice) {
         printf(". It's a draw!\n");
         draws++;
      }
      else if ((user_choice == 1 && computer_choice == 3) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2)) {
         printf(". You win!\n");
         wins++;
      }
      else {
         printf(". You lose!\n");
         losses++;
      }
      
      printf("\n---STATISTICS---\n");
      printf("Wins: %d (%.1f%%)\n", wins, (float)wins / (wins + losses + draws) * 100);
      printf("Losses: %d (%.1f%%)\n", losses, (float)losses / (wins + losses + draws) * 100);
      printf("Draws: %d (%.1f%%)\n", draws, (float)draws / (wins + losses + draws) * 100);
      printf("----------------\n\n");
   }
   
   return 0;
}