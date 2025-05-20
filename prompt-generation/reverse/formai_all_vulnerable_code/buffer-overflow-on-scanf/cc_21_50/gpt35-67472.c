//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int player_count, position1, position2, position3, position4, current_player, roll, winner = 0;
  printf("Welcome to Snakes and Ladders!\n");
  printf("How many players will be playing? (2-4): ");
  scanf("%d", &player_count);

  // Initialize player positions
  position1 = position2 = position3 = position4 = 1;

  // Game Loop
  while(winner == 0) {

    // Roll the dice
    printf("\nPlayer %d, it's your turn!\n", current_player+1);
    printf("Press enter to roll the dice...\n");
    getchar();
    srand(time(NULL));
    roll = rand() % 6 + 1;
    printf("You rolled a %d!\n", roll);

    // Update player position
    switch(current_player) {
      case 0:
        position1 += roll;
        break;
      case 1:
        position2 += roll;
        break;
      case 2:
        position3 += roll;
        break;
      case 3:
        position4 += roll;
        break;
    }

    // Check for snaked and ladders
    if(position1 == 8) {
      position1 = 15;
      printf("Player 1 landed on a ladder!\n");
    }
    else if(position1 == 19) {
      position1 = 2;
      printf("Player 1 landed on a snake!\n");
    }
    else if(position2 == 4) {
      position2 = 14;
      printf("Player 2 landed on a ladder!\n");
    }
    else if(position2 == 17) {
      position2 = 5;
      printf("Player 2 landed on a snake!\n");
    }
    else if(position3 == 6) {
      position3 = 27;
      printf("Player 3 landed on a ladder!\n");
    }
    else if(position3 == 24) {
      position3 = 16;
      printf("Player 3 landed on a snake!\n");
    }
    else if(position4 == 2) {
      position4 = 9;
      printf("Player 4 landed on a ladder!\n");
    }
    else if(position4 == 11) {
      position4 = 3;
      printf("Player 4 landed on a snake!\n");
    }

    // Check if player wins
    if(position1 >= 30) {
      printf("Player 1 wins!\n");
      winner = 1;
    }
    else if(position2 >= 30) {
      printf("Player 2 wins!\n");
      winner = 1;
    }
    else if(position3 >= 30 && player_count >= 3) {
      printf("Player 3 wins!\n");
      winner = 1;
    }
    else if(position4 >= 30 && player_count >= 4) {
      printf("Player 4 wins!\n");
      winner = 1;
    }

    // Move to next player
    current_player++;
    if(current_player >= player_count) {
      current_player = 0;
    }
  }

  return 0;
}