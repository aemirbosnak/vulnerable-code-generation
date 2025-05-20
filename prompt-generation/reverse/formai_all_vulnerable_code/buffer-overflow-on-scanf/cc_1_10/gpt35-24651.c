//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Welcome Message
  printf("Welcome to Procedural Space Adventure!\n");
  printf("You are about to embark on a journey through the vast reaches of space.\n");
  
  // Get Player Name
  char player_name[20];
  printf("But first, what should we call you, star traveler? ");
  scanf("%s", player_name);
  
  // Introduction
  printf("\nGreetings %s! Your mission is to explore the galaxy and seek out new worlds and civilizations.\n", player_name);

  // Variables for Game
  int distance_from_earth = 100;
  int fuel_level = 100;
  int planet_count = 0;

  // Game Loop
  while (distance_from_earth > 0) {
    // Display Status
    printf("\n%s, here is your current status:\n", player_name);
    printf("Distance from Earth: %d light years\n", distance_from_earth);
    printf("Fuel level: %d%%\n", fuel_level);
    printf("Planets discovered: %d\n", planet_count);

    // User Input
    char action;
    printf("\nWhat would you like to do? (F)ly to a new planet, (R)efuel your ship, or (Q)uit the game?\n");
    scanf(" %c", &action);

    // Fly to a New Planet
    if (action == 'F') {
      // Calculate Distance and Fuel Consumption
      int planet_distance = rand() % 101;
      int fuel_consumption = rand() % 21;
      distance_from_earth -= planet_distance;
      fuel_level -= fuel_consumption;

      // Check if Player has Enough Fuel
      if (fuel_level < 0) {
        printf("\nUh oh, it looks like you ran out of fuel! Your ship is stranded in space.\n");
        break;
      }

      // Discover New Planet
      else {
        planet_count++;
        printf("\nCongratulations, you discovered a new planet! It is %d light years away.\n", planet_distance);
      }
    }

    // Refuel Ship
    else if (action == 'R') {
      fuel_level = 100;
      printf("\nYour ship has been refueled to 100%%.\n");
    }

    // Quit the Game
    else if (action == 'Q') {
      printf("\nThank you for playing Procedural Space Adventure, %s!\n", player_name);
      break;
    }

    // Invalid Input
    else {
      printf("\nSorry, that is not a valid input. Please try again.\n");
    }
  }

  // Game Over Message
  printf("\nGAME OVER.\n");

  return 0;
}