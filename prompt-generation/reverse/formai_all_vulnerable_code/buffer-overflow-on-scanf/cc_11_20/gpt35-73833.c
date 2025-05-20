//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Initialize random seed
   srand(time(NULL));
   
   int health = 100;
   int fuel = 100;
   int maxHealth = 100;
   int maxFuel = 100;
   
   char action;
   
   printf("Welcome to Procedural Space Adventure!\n");
   printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
   printf("Your ship is equipped with a scanner, a laser gun, and a warp drive.\n");
   printf("Your goal is to find new planets and discover new life forms.\n");
   
   while(health > 0 && fuel > 0) {
      printf("\n\n\nCURRENT STATUS:\n");
      printf("Health: %d/%d\n", health, maxHealth);
      printf("Fuel: %d/%d\n", fuel, maxFuel);
      printf("Choose your next action:\n");
      printf("1. Scan for planets\n");
      printf("2. Shoot laser gun\n");
      printf("3. Warp to new location\n");
      scanf(" %c", &action);
      
      if(action == '1') {
         int scanChance = rand() % 10;
         if(scanChance <= 3) { // 40% chance to find a planet
            printf("You have discovered a new planet!\n");
            printf("Do you want to land and explore? (y/n)\n");
            char explore;
            scanf(" %c", &explore);
            if(explore == 'y') {
               printf("You land on the planet and encounter a new life form.\n");
               printf("The life form speaks in an alien language but seems friendly.\n");
               printf("You exchange information and learn new things.\n");
               printf("Your health and fuel are fully replenished.\n");
               health = maxHealth;
               fuel = maxFuel;
            }
         } else {
            printf("You scan the area but find nothing of interest...\n");
         }
         fuel -= 10;
      } else if(action == '2') {
         int hitChance = rand() % 10;
         if(hitChance <= 5) { // 50% chance to hit
            printf("Your laser gun hits an asteroid, preventing a collision!\n");
         } else {
            printf("Your laser gun misses...\n");
         }
         fuel -= 5;
      } else if(action == '3') {
         int warpChance = rand() % 10;
         if(warpChance <= 2) { // 30% chance to have a random encounter
            printf("You activate the warp drive and end up in a strange location.\n");
            printf("You encounter a hostile alien race!\n");
            printf("You have no choice but to fight...\n");
            int alienHealth = 50;
            while(alienHealth > 0 && health > 0) {
               int alienHit = rand() % 10 + 1;
               health -= alienHit;
               printf("The alien attacks and deals %d damage! You have %d health left.\n", alienHit, health);
               if(health <= 0) break;
               int playerHit = rand() % 10 + 1;
               alienHealth -= playerHit;
               printf("You attack the alien and deal %d damage! The alien has %d health left.\n", playerHit, alienHealth);
            }
            if(health <= 0) {
               printf("You have been defeated...\n");
               exit(0);
            } else {
               printf("You have won the battle!\n");
            }
         } else {
            printf("You activate the warp drive and end up in a new location.\n");
         }
         fuel -= 20;
      } else {
         printf("Invalid input...\n");
      }
      
      if(fuel <= 0) {
         printf("You have run out of fuel...\n");
         printf("GAME OVER\n");
         return 0;
      } else if(health <= 0) {
         printf("Your ship has been destroyed...\n");
         printf("GAME OVER\n");
         return 0;
      }
   }

   printf("CONGRATULATIONS! You have completed your mission and discovered new things.\n");
   printf("GAME OVER\n");
   
   return 0;
}