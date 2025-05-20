//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int fuel = 100;
  int shields = 100;
  int ammo = 100;
  int credits = 0;
  
  printf("Welcome to the Procedural Space Adventure!\n");

  printf("You are the captain of the spaceship Star Blaster.\n");
  printf("Your mission is to explore the galaxy and collect as many credits as possible.\n");
  printf("Be careful, the space is full of danger!\n");

  while (1) {
    printf("\n\n");
    printf("Please select an action:\n");
    printf("1. Explore the galaxy\n");
    printf("2. Check your ship\n");
    printf("3. Visit the space station\n");
    printf("4. Exit the program\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        printf("You have set course for a nearby planet...\n");
        int random_event = rand() % 4;
        switch (random_event) {
          case 0:
            printf("You discover a new species of alien!\n");
            printf("You make contact and they offer to trade with you.\n");
            printf("What would you like to trade?\n");
            printf("1. Fuel\n");
            printf("2. Shields\n");
            printf("3. Ammo\n");
            int trade_choice;
            scanf("%d", &trade_choice);
            if (credits > 0) {
              switch (trade_choice) {
                case 1:
                  fuel += 20;
                  credits -= 10;
                  printf("You gain 20 fuel and lose 10 credits.\n");
                  break;
                case 2:
                  shields += 20;
                  credits -= 10;
                  printf("You gain 20 shields and lose 10 credits.\n");
                  break;
                case 3:
                  ammo += 20;
                  credits -= 10;
                  printf("You gain 20 ammo and lose 10 credits.\n");
                  break;
                default:
                  printf("Invalid choice.\n");
              }
            }
            else {
              printf("You don't have enough credits.\n");
            }
            break;
          case 1:
            printf("A group of space pirates attack you!\n");
            printf("What do you want to do?\n");
            printf("1. Fight\n");
            printf("2. Run\n");
            int combat_choice;
            scanf("%d", &combat_choice);
            if (combat_choice == 1) {
              shields -= 50;
              ammo -= 50;
              if (shields < 0) shields = 0;
              if (ammo < 0) ammo = 0;
              printf("You fought bravely, but it wasn't easy.\n");
              printf("You lost 50 shields and 50 ammo.\n");
            }
            else {
              printf("You managed to escape.\n");
            }
            break;
          case 2:
            credits += 50;
            printf("You have found a hidden treasure!\n");
            printf("You gain 50 credits.\n");
            break;
          default:
            printf("You didn't find anything interesting...\n");
        }
        break;
      case 2:
        printf("Your current status:\n");
        printf("Fuel: %d\n", fuel);
        printf("Shields: %d\n", shields);
        printf("Ammo: %d\n", ammo);
        printf("Credits: %d\n", credits);
        break;
      case 3:
        printf("Welcome to the space station!\n");
        printf("What would you like to purchase?\n");
        printf("1. Fuel (10 credits)\n");
        printf("2. Shields (20 credits)\n");
        printf("3. Ammo (5 credits)\n");
        int station_choice;
        scanf("%d", &station_choice);
        switch (station_choice) {
          case 1:
            if (credits >= 10) {
              fuel += 50;
              credits -= 10;
              printf("You gain 50 fuel and lose 10 credits.\n");
            }
            else {
              printf("You don't have enough credits.\n");
            }
            break;
          case 2:
            if (credits >= 20) {
              shields += 50;
              credits -= 20;
              printf("You gain 50 shields and lose 20 credits.\n");
            }
            else {
              printf("You don't have enough credits.\n");
            }
            break;
          case 3:
            if (credits >= 5) {
              ammo += 50;
              credits -= 5;
              printf("You gain 50 ammo and lose 5 credits.\n");
            }
            else {
              printf("You don't have enough credits.\n");
            }
            break;
          default:
            printf("Invalid choice.\n");
        }
        break;
      case 4:
        printf("Thanks for playing the Procedural Space Adventure!\n");
        return 0;
      default:
        printf("Invalid choice.\n");
    }
    
    if (fuel <= 0) {
      printf("You have run out of fuel...\n");
      printf("Game over.\n");
      return 0;
    }
    
    fuel -= 10;
    if (ammo <= 0) ammo = 0;
    if (shields <= 0) shields = 0;
  }
  
  return 0;
}