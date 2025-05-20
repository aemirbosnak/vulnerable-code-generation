//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>

int main()
{
   int temperature = 25; // current temperature
   int lightIntensity = 100; // current light intensity

   // Display current status
   printf("Current temperature: %d\n", temperature);
   printf("Current light intensity: %d\n", lightIntensity);

   // Change temperature according to user input
   int newTemperature;
   printf("Enter new temperature: ");
   scanf("%d", &newTemperature);

   if(newTemperature > temperature)
   {
      printf("Increasing temperature by %d degrees\n", newTemperature - temperature);
   }
   else if(newTemperature < temperature)
   {
      printf("Decreasing temperature by %d degrees\n", temperature - newTemperature);
   }
   else
   {
      printf("Temperature remains the same\n");
   }

   temperature = newTemperature; // update current temperature

   // Change light intensity according to user input
   int newLightIntensity;
   printf("Enter new light intensity: ");
   scanf("%d", &newLightIntensity);

   if(newLightIntensity > lightIntensity)
   {
      printf("Increasing light intensity by %d percent\n", newLightIntensity - lightIntensity);
   }
   else if(newLightIntensity < lightIntensity)
   {
      printf("Decreasing light intensity by %d percent\n", lightIntensity - newLightIntensity);
   }
   else
   {
      printf("Light intensity remains the same\n");
   }

   lightIntensity = newLightIntensity; // update current light intensity

   // Display final status
   printf("Final temperature: %d\n", temperature);
   printf("Final light intensity: %d\n", lightIntensity);

   return 0;
}