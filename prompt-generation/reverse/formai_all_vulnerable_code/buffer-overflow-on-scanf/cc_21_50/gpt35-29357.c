//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int fuel = 100, hp = 100;
  int distance = 0, planet = 0, credits = 0;
  srand(time(NULL));
  
  printf("Welcome to Procedural Space Adventure!\n");
  
  while(hp > 0) {
    int random_encounter = rand() % 4 + 1;
    
    if(random_encounter == 1) {
      printf("You found a friendly planet! Would you like to dock? (y/n): ");
      char decision;
      scanf(" %c", &decision);
      if(decision == 'y') {
        printf("Docking successful. Refueling...\n");
        fuel = 100;
        printf("Fuel level: %d\n", fuel);
        printf("Do you want to buy some goods? (y/n): ");
        char buy_goods;
        scanf(" %c", &buy_goods);
        if(buy_goods == 'y') {
          int random_goods = rand() % 4 + 1;
          if(random_goods == 1) {
            credits += 50;
            printf("You bought a crate of gold for 50 credits!\n");
            printf("Current credits: %d\n", credits);
          }
          else if(random_goods == 2) {
            credits += 20;
            printf("You bought some food for 20 credits!\n");
            printf("Current credits: %d\n", credits);
          }
          else if(random_goods == 3) {
            credits += 30;
            printf("You bought some fuel for 30 credits!\n");
            printf("Current credits: %d\n", credits);
          }
          else if(random_goods == 4) {
            printf("Nothing you want? Okay then.\n");
          }
        }
        printf("Would you like to leave this planet? (y/n): ");
        char leave_planet;
        scanf(" %c", &leave_planet);
        if(leave_planet == 'y') {
          planet++;
          printf("Leaving planet...\n");
        }
      }
      else {
        printf("You continued your journey.\n");
      }
    }
    else if(random_encounter == 2) {
      printf("You found a hostile planet! Evade or attack? (e/a): ");
      char evasive_action;
      scanf(" %c", &evasive_action);
      if(evasive_action == 'e') {
        printf("You successfully evaded the planet and continued your journey.\n");
      }
      else if(evasive_action == 'a') {
        printf("You engaged in combat!\n");
        int enemy_hp = 100;
        while(enemy_hp > 0 && hp > 0) {
          int random_damage = rand() % 11 + 10;
          printf("You dealt %d damage!\n", random_damage);
          enemy_hp -= random_damage;
          if(enemy_hp <= 0) {
            printf("Enemy destroyed!\n");
            credits += 50;
            printf("You found some credits on their ship. Current credits: %d\n", credits);
            break;
          }
          random_damage = rand() % 11 + 5;
          printf("Enemy dealt %d damage!\n", random_damage);
          hp -= random_damage;
          if(hp <= 0) {
            printf("You were destroyed! Game over.\n");
            break;
          }
        }
      }
    }
    else if(random_encounter == 3) {
      printf("You found an asteroid field! Try to navigate through it? (y/n): ");
      char navigate;
      scanf(" %c", &navigate);
      if(navigate == 'y') {
        int random_movement = rand() % 11 + 5;
        printf("You successfully navigated through the asteroid field! You moved %d kilometers.\n", random_movement);
        distance += random_movement;
      }
      else {
        printf("You decided not to risk it and continued your journey.\n");
      }
    }
    else {
      printf("You continued your journey.\n");
    }
    
    if(hp <= 0) {
      break;
    }
    
    if(distance >= 500) {
      printf("Congratulations! You finished the game!\n");
      break;
    }
    
    printf("Distance traveled: %d kilometers.\n", distance);
    printf("Current fuel level: %d\n", fuel);
    printf("Current health: %d\n", hp);
    printf("Current planet count: %d\n", planet);
    printf("Current credits: %d\n", credits);
    
    int random_fuel_loss = rand() % 11 + 20;
    printf("You lost %d fuel.\n", random_fuel_loss);
    fuel -= random_fuel_loss;
    if(fuel <= 0) {
      printf("You ran out of fuel and were stranded in space! Game over.\n");
      break;
    }
    
    int random_hp_loss = rand() % 11 + 5;
    printf("You took %d damage.\n", random_hp_loss);
    hp -= random_hp_loss;
    if(hp <= 0) {
      printf("You were destroyed! Game over.\n");
      break;
    }
  }
  
  return 0;
}