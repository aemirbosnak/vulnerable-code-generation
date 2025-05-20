//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>

int main(){
  // Initializations
  int fuel_tank = 1000;
  int ship_health = 100;
  int cargo = 0;
  int planet_distance = 500;

  // Welcome message
  printf("Welcome to Procedural Space Adventure!\n");

  // Gameplay loop
  while(ship_health > 0){
    // Display current status
    printf("\n-----\nStatus:\nFuel: %d\nHealth: %d\nCargo: %d\nDistance to Planet: %d\n-----\n", fuel_tank, ship_health, cargo, planet_distance);

    // Prompt user for action
    printf("\nWhat would you like to do?\n 1. Travel to Planet\n 2. Mine Asteroids\n 3. Repair Ship\n 4. Buy Fuel\n 5. Sell Cargo\n 6. Quit Game\n");
    int choice;
    scanf("%d", &choice);

    // Perform chosen action
    switch (choice){
      case 1:
        if(fuel_tank >= planet_distance){
          printf("You have reached the planet!\n");
          cargo += 100; // Add 100 cargo for successful mission
          planet_distance = 500; // Reset planet distance
          fuel_tank -= planet_distance; // Deduct fuel
        } else {
          printf("You do not have enough fuel to reach the planet.\n");
        }
        break;

      case 2:
        printf("Mining asteroids...\n");
        int ore = 50; // Random amount of ore collected between 10 and 100
        cargo += ore;
        printf("You collected %d units of ore.\n", ore);
        break;

      case 3:
        printf("Repairing ship...\n");
        int repair_cost = 500; // Cost to repair ship
        if(cargo >= repair_cost){
          ship_health += 50; // Increase ship health by 50
          cargo -= repair_cost; // Deduct repair cost from cargo
          printf("Ship has been repaired.\n");
        } else {
          printf("You do not have enough cargo to repair the ship.\n");
        }
        break;

      case 4:
        printf("Buying fuel...\n");
        int fuel_cost = 10; // Cost per unit of fuel
        int max_fuel = 500; // Maximum fuel that can be bought
        printf("How much fuel would you like to buy (max %d)?\n", max_fuel);
        int fuel_amount;
        scanf("%d", &fuel_amount);
        if((fuel_amount * fuel_cost) <= cargo && fuel_amount <= max_fuel){
          fuel_tank += fuel_amount; // Add fuel to tank
          cargo -= (fuel_amount * fuel_cost); // Deduct fuel cost from cargo
          printf("You have bought %d units of fuel.\n", fuel_amount);
        } else {
          printf("You do not have enough cargo or the amount requested exceeds the maximum fuel.\n");
        }
        break;

      case 5:
        printf("Selling cargo...\n");
        int sell_price = 5; // Cost per unit of cargo
        printf("How much cargo would you like to sell?\n");
        int sell_amount;
        scanf("%d", &sell_amount);
        if(sell_amount <= cargo){
          int sell_profit = sell_amount * sell_price; // Calculate sell profit
          cargo -= sell_amount; // Deduct sold cargo
          printf("You have sold %d units of cargo for %d credits.\n", sell_amount, sell_profit);
        } else {
          printf("You do not have enough cargo to sell.\n");
        }
        break;

      case 6:
        printf("Thank you for playing Procedural Space Adventure!\n");
        return 0;

      default:
        printf("Invalid choice. Try again.\n");
        break;
    }

    // Random events
    int event_chance = 5; // Chance of event occuring (in percentage)
    int event = rand() % 100 + 1; // Generate random number between 1 and 100
    if(event <= event_chance){
      int random_event = rand() % 3 + 1; // Generate random type of event (1, 2, or 3)
      switch (random_event){
        case 1:
          printf("\nAlien attack!\n");
          int attack_damage = rand() % 30 + 10; // Random amount of damage between 10 and 40
          ship_health -= attack_damage; // Deduct damage from ship's health
          printf("Your ship suffered %d damage.\n", attack_damage);
          break;

        case 2:
          printf("\nLost in space!\n");
          planet_distance = rand() % 1000 + 500; // Generate new random distance to planet between 500 and 1500
          printf("You are %d units away from a nearby planet.\n", planet_distance);
          break;

        case 3:
          printf("\nSpace debris!\n");
          int debris_damage = rand() % 20 + 5; // Random amount of damage between 5 and 25
          ship_health -= debris_damage; // Deduct damage from ship's health
          printf("Your ship suffered %d damage from colliding with space debris.\n", debris_damage);
          break;
      }
    }
  }

  // Game over message
  printf("\nGame over! Your ship has been destroyed.\n");

  return 0;
}