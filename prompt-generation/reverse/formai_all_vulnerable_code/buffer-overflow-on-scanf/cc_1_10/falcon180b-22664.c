//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defining the variables
int num_of_aliens;
int num_of_humans;
int num_of_days;
int num_of_invasions;

int main()
{
   //Seeding the random number generator
   srand(time(NULL));

   //Prompting the user to enter the number of aliens
   printf("Enter the number of aliens: ");
   scanf("%d",&num_of_aliens);

   //Prompting the user to enter the number of humans
   printf("Enter the number of humans: ");
   scanf("%d",&num_of_humans);

   //Prompting the user to enter the number of days
   printf("Enter the number of days: ");
   scanf("%d",&num_of_days);

   //Initializing the number of invasions to zero
   num_of_invasions=0;

   //Looping through the number of days
   for(int i=0;i<num_of_days;i++)
   {
      //Generating a random number between 0 and 1
      float random_number=rand()%2;

      //If the random number is 1, then an invasion has occurred
      if(random_number==1)
      {
         //Incrementing the number of invasions
         num_of_invasions++;

         //Printing the message that an invasion has occurred
         printf("An alien invasion has occurred on day %d\n",i+1);
      }
   }

   //Calculating the probability of an alien invasion
   float probability=((float)num_of_invasions/(float)num_of_days)*100;

   //Printing the probability of an alien invasion
   printf("The probability of an alien invasion is %.2f%%\n",probability);

   return 0;
}