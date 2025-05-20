//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL)); // initializing the random number generator
   
   int spaceship_health = 100; // initial health of spaceship

   printf("Welcome to Procedural Space Adventure!\n\n");
   printf("You are the captain of a spaceship traveling through the vast expanse of space.\n");
   printf("Your mission is to reach the other side of the galaxy without your spaceship getting destroyed.\n\n");
   
   while (spaceship_health > 0) // while the spaceship is still operational
   {
      int event = rand() % 3; // randomly generating an event
      
      switch (event) // handling different events
      {
         case 0: // asteroid collision
            {
               printf("Oh no! Your spaceship collided with an asteroid!\n");
               printf("Your spaceship health decreased by 20.\n");
               spaceship_health -= 20;
               break;
            }
         case 1: // hostile alien encounter
            {
               printf("Danger! Hostile aliens are approaching your spaceship!\n");
               printf("You must engage them in a space battle or try to evade them.\n");
               
               int choice;
               printf("Enter 1 to engage in space battle, 2 to evade them: ");
               scanf("%d", &choice);
               
               if (choice == 1)
               {
                  printf("You engaged the aliens in a space battle!\n");
                  printf("After a fierce battle, your spaceship emerged victorious.\n");
               }
               else if (choice == 2)
               {
                  printf("You tried to evade the aliens, but they managed to hit your spaceship.\n");
                  printf("Your spaceship health decreased by 30.\n");
                  spaceship_health -= 30;
               }
               else
               {
                  printf("Invalid choice. Try again.\n");
                  continue; // start the loop again
               }
               break;
            }
         case 2: // peaceful planet encounter
            {
               printf("You discovered a peaceful planet!\n");
               printf("You can explore the planet or mine its resources.\n");
               
               int choice;
               printf("Enter 1 to explore the planet, 2 to mine its resources: ");
               scanf("%d", &choice);
               
               if (choice == 1)
               {
                  printf("You explored the planet and discovered many interesting things!\n");
               }
               else if (choice == 2)
               {
                  printf("You mined the planet's resources and collected a valuable haul!\n");
               }
               else
               {
                  printf("Invalid choice. Try again.\n");
                  continue; // start the loop again
               }
               break;
            }
      }
      
      printf("Your spaceship health: %d\n\n", spaceship_health);
   }
   
   printf("Game over! Your spaceship was destroyed.\n");
   
   return 0;
}