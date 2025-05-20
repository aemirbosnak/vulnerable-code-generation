//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  srand(time(0));
  int fuel = 500;
  int inventory = 0;
  int damage = 0;
  int warp_speed = 0;
  int system_position = 1;
  int planet_position = 0;
  int planet_found = 0;
  int enemy_ship = 0;
  int enemy_strength = 0;
  int game_over = 0;

  printf("Welcome to the Procedural Space Adventure Game!\n\n");

  while(!game_over){
    printf("Your ship's current system position is %d.\n", system_position);
    printf("You have %d fuel and %d inventory space.\n", fuel, (500-inventory));
    printf("Enter distance to travel (1-10):");
    int distance;
    scanf("%d", &distance);

    if(distance<=0){
        printf("Invalid input.\n");
        continue;
    }

    if(distance > fuel){
      printf("You do not have enough fuel.\n");
      continue;
    }

    fuel -= distance;
    int random_event = rand()%3;
    if(random_event==0){
      printf("You encountered an enemy ship!\n");
      enemy_strength = rand()%101;
      printf("Their strength is %d.\n", enemy_strength);
      enemy_ship = 1;
    }
    else if(random_event==1){
      int item = rand()%4;
      if(item==0){
        printf("You found a shield upgrade!\n");
        damage -= 25;
      }
      else if(item==1){
        printf("You found a weapon upgrade!\n");
        enemy_strength -= 25;
      }
      else if(item==2){
        printf("You found a repair kit!\n");
        damage += 25;
        if(damage < 0)
          damage = 0;
      }
      else{
        printf("You found a cargo bay upgrade!\n");
        inventory += 100;
      }
    }
    else{
      printf("You encountered no events.\n");
    }

    system_position += distance;

    if(system_position%10==0){
      printf("You found a planet!\n");
      planet_found = 1;
    }

    if(planet_found){
      printf("Do you want to land on the planet?\n");
      char choice;
      scanf(" %c", &choice);
      if(choice=='y' || choice=='Y'){
        printf("Landing on the planet...\n");
        int resource = rand()%4;
        if(resource==0){
          printf("You found gold!\n");
          inventory += 50;
        }
        else if(resource==1){
          printf("You found silver!\n");
          inventory += 25;
        }
        else if(resource==2){
          printf("You found water!\n");
          inventory += 100;
        }
        else{
          printf("You found food!\n");
          inventory += 75;
        }
        planet_found = 0;
        planet_position = system_position;
      }
    }

    if(enemy_ship){
      printf("Do you want to fight (f) or run (r)?\n");
      char choice;
      scanf(" %c", &choice);
      if(choice=='r' || choice=='R'){
        if(warp_speed){
          printf("Warping out of battle!\n");
          enemy_ship = 0;
        }
        else{
          printf("You can't run without a warp drive.\n");
          printf("Fighting instead...\n");
        }
      }
      if(choice=='f' || choice=='F'){
        printf("Fighting...\n");
        int player_damage = rand()%51;
        int enemy_damage = rand()%51;
        if(player_damage > enemy_strength){
          printf("You won the battle!\n");
          enemy_ship = 0;
          int resource = rand()%3;
          if(resource==0){
            printf("You looted gold from the enemy ship!\n");
            inventory += 25;
          }
          else if(resource==1){
            printf("You looted silver from the enemy ship!\n");
            inventory += 15;
          }
          else{
            printf("You looted water from the enemy ship!\n");
            inventory += 50;
          }
        }
        else{
          printf("You lost the battle!\n");
          printf("Taking damage...\n");
          damage += enemy_damage;
        }
      }
    }

    if(damage >= 100){
      printf("Your ship is destroyed! Game over!\n");
      game_over = 1;
      continue;
    }

    if(system_position >= 500){
      printf("You made it to your destination!\n");
      printf("You earned %d credits!\n", inventory*10);
      game_over = 1;
    }

    if(system_position == 250){
      printf("Halfway there!\n");
    }

    if(system_position > planet_position+10 && planet_position>0){
      printf("You missed the planet!\n");
      planet_found = 0;
      planet_position = 0;
    }

    if(system_position%50==0){
      printf("You found a warp drive upgrade!\n");
      warp_speed = 1;
    }

    printf("Your ship's current damage is %d.\n", damage);
  }

  return 0;
}