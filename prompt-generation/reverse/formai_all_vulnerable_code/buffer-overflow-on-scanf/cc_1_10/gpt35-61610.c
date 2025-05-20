//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int likelihood = 0;
   srand(time(NULL));

   printf("Welcome to the Alien Invasion Probability Calculator!\n");
   printf("Please answer the following questions:\n");

   // check for proximity to Area 51
   printf("Are you located near Area 51? (y/n)\n");
   char area51;
   scanf("%c", &area51);
   if(area51 == 'y')
   {
      likelihood += 50;
   }

   // check for previous UFO sightings
   printf("Have you ever witnessed a UFO or extraterrestrial activity? (y/n)\n");
   char ufoSighting;
   scanf(" %c", &ufoSighting);
   if(ufoSighting == 'y')
   {
      likelihood += 25;
   }

   // check for government conspiracy theories
   printf("Do you believe in government conspiracy theories regarding extraterrestrial life? (y/n)\n");
   char conspiracy;
   scanf(" %c", &conspiracy);
   if(conspiracy == 'y')
   {
      likelihood += 15;
   }

   // check for adherence to science fiction media
   printf("Do you often watch or read science fiction media? (y/n)\n");
   char scifi;
   scanf(" %c", &scifi);
   if(scifi == 'y')
   {
      likelihood += 10;
   }

   // check for fascination with astronomy
   printf("Are you fascinated with astronomy or space exploration? (y/n)\n");
   char astronomy;
   scanf(" %c", &astronomy);
   if(astronomy == 'y')
   {
      likelihood += 5;
   }

   // generate random number between 0 and 100
   int randomNumber = rand() % 101;

   // calculate the final likelihood of alien invasion
   likelihood += randomNumber;

   printf("Calculating possibility of alien invasion...\n");

   // simulate thinking time
   for(int i = 0; i < 5; i++)
   {
      printf(".");
      fflush(stdout);
      sleep(1);
   }
   printf("\n");

   if(likelihood < 33)
   {
      printf("Based on your responses and our calculations, it seems unlikely that an alien invasion will occur.\n");
   }
   else if(likelihood < 66)
   {
      printf("Based on your responses and our calculations, an alien invasion is possible but not probable.\n");
   }
   else
   {
      printf("Based on your responses and our calculations, an alien invasion is highly probable!\n");
   }

   return 0;
}