//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  // Generate random coordinates for the player's starting position
  int player_x = rand() % 1000;
  int player_y = rand() % 1000;
  
  // Initialize variables to track the player's inventory and health
  int health = 100;
  int fuel = 100;
  int crystals = 0;

  printf("Welcome to Procedural Space Adventure!\n");
  printf("Your mission is to explore the galaxy, collect crystals, and survive.\n");
  printf("You start at coordinates (%d,%d)\n", player_x, player_y);
  printf("Your health is %d and your fuel is %d\n", health, fuel);
  
  // Loop until the player has collected 10 crystals or dies
  while (crystals < 10 && health > 0 && fuel > 0) {
    // Generate a random event
    int event = rand() % 3;
    
    if (event == 0) {
      // The player finds a crystal
      int crystal_x = rand() % 1000;
      int crystal_y = rand() % 1000;
      printf("You found a crystal at coordinates (%d,%d)!\n", crystal_x, crystal_y);
      crystals++;
    } else if (event == 1) {
      // The player encounters a hostile alien ship
      printf("You encountered a hostile alien ship!\n");
      printf("You have two choices: fight or flee\n");
      printf("Enter 1 to fight or 2 to flee\n");
      int choice;
      scanf("%d", &choice);
      if (choice == 1) {
        printf("You engage in battle!\n");
        int player_damage = rand() % 30 + 10;
        int alien_damage = rand() % 20 + 10;
        health -= alien_damage;
        printf("You inflict %d damage on the alien ship\n", player_damage);
        printf("The alien ship inflicts %d damage on you\n", alien_damage);
      } else {
        printf("You flee from the alien ship\n");
        fuel -= 10;
      }
    } else {
      // The player discovers a new planet
      printf("You discovered a new planet!\n");
      printf("You have two choices: land or fly by\n");
      printf("Enter 1 to land or 2 to fly by\n");
      int choice;
      scanf("%d", &choice);
      if (choice == 1) {
        printf("You land on the planet\n");
        fuel -= 20;
        printf("Your fuel is now %d\n", fuel);
      } else {
        printf("You fly by the planet\n");
      }
    }
    
    // Update player's health and fuel
    health--;
    fuel--;
    printf("Your health is now %d and your fuel is now %d\n", health, fuel);
  }
  
  // Check if the player won or lost
  if (crystals == 10) {
    printf("Congratulations! You collected all 10 crystals and won the game!\n");
  } else if (health <= 0) {
    printf("Game over! You lost all your health and died.\n");
  } else {
    printf("Game over! You ran out of fuel and are stranded in space.\n");
  }
  
  return 0;
}