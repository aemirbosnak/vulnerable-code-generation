//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(NULL));

  //initialize variables
  int health = 100;
  int fuel = 100;
  int oxygen = 100;
  int gold = 0;
  int engine_lvl = 1;
  int shield_lvl = 1;
  int attack_lvl = 1;

  //introduction
  printf("Welcome to the Procedural Space Adventure!\n");
  printf("You are the captain of your own spaceship, traveling through the galaxy.\n");
  printf("Your mission is to explore new planets, mine for resources, and defend your ship against alien attacks.\n");

  //start game loop
  int game_over = 0;
  while(!game_over){
    //display status
    printf("\nYour current status:\n");
    printf("Health: %d\n", health);
    printf("Fuel: %d\n", fuel);
    printf("Oxygen: %d\n", oxygen);
    printf("Gold: %d\n", gold);
    printf("Engine Level: %d\n", engine_lvl);
    printf("Shield Level: %d\n", shield_lvl);
    printf("Attack Level: %d\n", attack_lvl);

    //random event generator
    int event_num = rand() % 3; //0 - nothing happens, 1 - asteroid field, 2 - alien encounter
    switch(event_num){
      case 0:
        printf("You continue on your journey.\n");
        break;
      case 1:
        printf("You enter an asteroid field!\n");
        printf("Do you want to mine for resources or avoid the asteroids? (1 - mine, 2 - avoid)\n");
        int choice;
        scanf("%d", &choice);
        if(choice == 1){
          //chance to find gold
          int gold_found = rand() % 2; //50% chance to find gold
          if(gold_found){
            printf("You found some gold!\n");
            gold++;
          }
          else{
            printf("You didn't find any gold, but you were able to mine some fuel.\n");
            fuel += 10;
          }
        }
        else{
          //chance to take damage
          int damage = rand() % 20 + 1; //1-20 damage
          printf("You avoided the asteroids, but took %d damage to your shield.\n", damage);
          shield_lvl -= damage;
          if(shield_lvl < 0){
            printf("Your ship exploded in the asteroid field. Game over.\n");
            game_over = 1;
          }
        }
        break;
      case 2:
        printf("You encounter an alien ship!\n");
        printf("Do you want to fight or flee? (1 - fight, 2 - flee)\n");
        int fight_choice;
        scanf("%d", &fight_choice);
        if(fight_choice == 1){
          //chance to win battle
          int win_chance = rand() % 2; //50% chance to win
          if(win_chance){
            printf("You defeated the alien ship and looted some gold!\n");
            gold += 2;
          }
          else{
            printf("You were defeated by the alien ship. Game over.\n");
            game_over = 1;
          }
        }
        else{
          //chance to take damage
          int damage = rand() % 30 + 1; //1-30 damage
          printf("You fled the alien ship, but took %d damage to your engine.\n", damage);
          engine_lvl -= damage;
          if(engine_lvl < 0){
            printf("Your ship's engine failed and you drifted off into space. Game over.\n");
            game_over = 1;
          }
        }
        break;
    }

    //decrease resources
    health -= 10;
    fuel -= 10;
    oxygen -= 10;

    //check if resources are empty
    if(health <= 0){
      printf("Your health reached 0. Game over.\n");
      game_over = 1;
    }
    if(fuel <= 0){
      printf("Your fuel reached 0. Game over.\n");
      game_over = 1;
    }
    if(oxygen <= 0){
      printf("Your oxygen reached 0. Game over.\n");
      game_over = 1;
    }
  }

  printf("\nThanks for playing the Procedural Space Adventure!\n");

  return 0;
}