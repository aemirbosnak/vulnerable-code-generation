//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mathematical
#include <stdio.h>

int main()
{
   float temp[7], sum = 0, avg;
   int i;

   printf("Enter the temperature for the last 7 days: \n");

   for(i=0; i<7; i++)
   {
      printf("Day %d: ", i+1);
      scanf("%f", &temp[i]);
      sum += temp[i];
   }

   //Calculate average temperature
   avg = sum/7;

   //Calculate standard deviation of temperature
   float sd = 0;

   for(i=0; i<7; i++)
   {
      sd += pow(temp[i]-avg, 2);
   }

   sd = sqrt(sd/7);

   //Display results
   printf("\nAverage temperature for the last 7 days: %.2f°C\n", avg);
   printf("Standard deviation of temperature for the last 7 days: %.2f°C\n", sd);

   //Analyze the data
   if(avg >= 20 && sd <= 5)
   {
      printf("\nThe temperature is consistent and comfortable for the past 7 days.\n");
   }
   else if(avg < 20)
   {
      printf("\nThe temperature is cooler than usual for the past 7 days.\n");
   }
   else if(avg > 25 || sd > 10)
   {
      printf("\nThe temperature is higher than usual for the past 7 days and there is a significant variation in the temperature.\n");
   }
   else
   {
      printf("\nThe temperature is within the acceptable range but there is some variation.\n");
   }

   return 0;
}