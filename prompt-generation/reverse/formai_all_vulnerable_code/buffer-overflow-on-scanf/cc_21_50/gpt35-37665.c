//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   srand(time(NULL));
   // initializing variables
   int distance = 0, oxygen = 100, fuel = 100, battery = 100;
   int landed = 0, explosion = 0, alien = 0;
   // welcoming user
   printf("*** Welcome to Procedural Space Adventure ***\n\n");
   printf("Your mission is to land on planet X and collect samples.\n");
   printf("Are you ready to launch?\n\n");
   
   // checking user input
   char ans;
   printf("Enter 'y' to launch: ");
   scanf("%c", &ans);
   if(ans == 'y' || ans == 'Y')
   {
        printf("\nBlast off! You are on your way to planet X.\n\n");
        // starting the journey
        while(distance < 100)
        {
            // generating random events
            int event = rand() % 3;
            if(event == 0 && oxygen > 10)
            {
                // decreasing oxygen level
                oxygen -= 10;
                printf("Oxygen level decreased by 10. Current oxygen level: %d%%\n", oxygen);
            }
            else if(event == 1 && fuel > 10)
            {
                // decreasing fuel level
                fuel -= 10;
                printf("Fuel level decreased by 10. Current fuel level: %d%%\n", fuel);
            }
            else if(event == 2 && battery > 10)
            {
                // decreasing battery level
                battery -= 10;
                printf("Battery level decreased by 10. Current battery level: %d%%\n", battery);
            }
            else
            {
                // increasing distance
                distance += 10;
                printf("You traveled 10 light years. Current distance: %d light years\n", distance);
            }
            // checking status
            if(fuel == 0)
            {
                printf("You ran out of fuel. Game over!\n");
                break;
            }
            else if(battery == 0)
            {
                printf("You ran out of battery. Game over!\n");
                break;
            }
            else if(oxygen == 0)
            {
                printf("You ran out of oxygen. Game over!\n");
                break;
            }   
        }
        // landing on the planet
        if(distance >= 100 && (fuel > 0 && oxygen > 0))
        {
            printf("\nCongratulations! You landed on planet X.\n\n");
            landed = 1;
            // searching for samples
            printf("You begin collecting samples and suddenly...\n");
            int search = rand() % 2;
            if(search == 0)
            {
                printf("The ground shakes and you lose balance. You realize there is an active volcano nearby!\n\n");
                // calculating escape time
                int escape_time = rand() % 3 + 1;
                printf("You need to escape in %d minutes. Hurry!\n\n", escape_time);
                // starting countdown
                for(int i=escape_time; i>0; i--)
                {
                    printf("%d...\n", i);
                    sleep(1);
                }
                // checking if escaped or not
                int escape = rand() % 2;
                if(escape == 0)
                {
                    printf("\nThe volcano erupted and you died. Game over!\n");
                    explosion = 1;
                }
                else
                {
                    printf("\nYou escaped just in time. Great job!\n");
                }
            }
            else
            {
                printf("You find strange alien artifacts and record your findings.\n");
                alien = 1;
            }
        }
   }
   else
   {
        printf("Blast off aborted. Goodbye!\n");
   }
   
   // displaying final message
   printf("\n--- FINAL MESSAGE ---\n");
   if(landed == 1 && explosion == 0)
   {
        printf("Congratulations! You successfully collected samples from planet X.\n");
        if(alien == 1)
        {
            printf("Your discovery of alien artifacts will forever change the history of space exploration.\n");
        }
   }
   else
   {
        printf("Unfortunately, your journey did not end well. Try again!\n");
   }
   
   return 0;
}