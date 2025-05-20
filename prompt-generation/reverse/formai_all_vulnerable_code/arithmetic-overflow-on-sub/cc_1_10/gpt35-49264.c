//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for spaceship
struct Spaceship {
  int fuel;
  int cargo;
  int health;
};

// Function to initialize spaceship
struct Spaceship initialize_spaceship() {
  struct Spaceship new_spaceship;
  new_spaceship.fuel = 100;
  new_spaceship.cargo = 0;
  new_spaceship.health = 100;
  return new_spaceship;
}

// Function to simulate traveling to a planet
void travel_to_planet(struct Spaceship* spaceship) {
  // Subtract fuel
  srand(time(NULL));
  int fuel_used = rand() % 20 + 10;
  spaceship->fuel -= fuel_used;

  // Random event
  int event = rand() % 3;
  if (event == 0) {
    // Nothing happens
    printf("Smooth sailing to the next planet!\n");
  }
  else if (event == 1) {
    // Pirates attack
    printf("Pirates are attacking! Prepare for battle!\n");
    int ship_health_loss = rand() % 20 + 10;
    int enemy_health_loss = rand() % 30 + 10;
    spaceship->health -= ship_health_loss;
    printf("You lost %d health from your spaceship during the battle.\n", ship_health_loss);
    printf("You dealt %d damage to the enemy ship.\n", enemy_health_loss);
  }
  else {
    // Synthetic life form encounter
    printf("You have encountered synthetic life forms! Do you want to engage with them?\n");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("You have chosen to engage with the synthetic life forms!\n");
        int ship_health_gain = rand() % 30 + 10;
        printf("You gained %d health from their advanced medical technology!\n", ship_health_gain);
        spaceship->health += ship_health_gain;
    }
    else {
      printf("You chose not to engage with the synthetic life forms. Moving on.\n");
    }
  }
}

int main() {
  // Initialize spaceship
  struct Spaceship spaceship = initialize_spaceship();

  // Introduction
  printf("Welcome to Procedural Space Adventure! You will be traveling to various planets and encountering different events on the way.\n");
  printf("Your spaceship has 100 fuel and 100 health points. Your cargo hold is currently empty.\n\n");

  // Game loop
  while (1) {
    // Check for game over
    if (spaceship.health <= 0) {
      printf("Your spaceship has been destroyed. Game over.\n");
      break;
    }
    if (spaceship.fuel <= 0) {
      printf("Your spaceship has run out of fuel. Game over.\n");
      break;
    }

    // Display current status
    printf("Fuel: %d Health: %d Cargo: %d\n", spaceship.fuel, spaceship.health, spaceship.cargo);

    // Ask for user input
    printf("What would you like to do? (T)ravel to a planet, (B)uy fuel, or (S)ell cargo.\n");
    char choice;
    scanf(" %c", &choice);

    // Handle user input
    if (choice == 't' || choice == 'T') {
      travel_to_planet(&spaceship);
    }
    else if (choice == 'b' || choice == 'B') {
      printf("Fuel costs 10 credits per unit. How many units would you like to purchase? ");
      int units;
      scanf("%d", &units);

      if (spaceship.cargo < units) {
        printf("You do not have enough cargo space to purchase that much fuel.\n");
      }
      else {
        spaceship.cargo -= units;
        spaceship.fuel += units * 10;
        printf("You have purchased %d units of fuel.\n", units);
      }
    }
    else if (choice == 's' || choice == 'S') {
      printf("Fuel sells for 5 credits per unit. How many units would you like to sell? ");
      int units;
      scanf("%d", &units);

      if (spaceship.fuel < units) {
        printf("You do not have enough fuel to sell that much.\n");
      }
      else {
        spaceship.cargo += units;
        spaceship.fuel -= units;
        printf("You have sold %d units of fuel.\n", units);
      }
    }
    else {
      printf("Invalid choice. Please choose T, B, or S.\n");
    }

    // Random event: asteroid belt
    int event = rand() % 10;
    if (event == 0) {
      printf("You have encountered an asteroid belt! You must navigate through it carefully.\n");
      int health_loss = rand() % 30 + 10;
      spaceship.health -= health_loss;
      printf("You lost %d health from your spaceship during the asteroid belt.\n", health_loss);
    }
  }

  return 0;
}