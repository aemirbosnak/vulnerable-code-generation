//FormAI DATASET v1.0 Category: Smart home automation ; Style: real-life
#include <stdio.h>
int main()
{
  // Welcome message
  printf("Welcome to the Smart Home Automation System!\n\n");
  
  // Variables initialization
  int temperature = 0;
  int humidity = 0;
  int isLightOn = 0;
  int isFanOn = 0;
  
  // Taking temperature input
  printf("Please enter the room temperature (in degrees Celsius): ");
  scanf("%d", &temperature);
  
  // Taking humidity input
  printf("Please enter the room humidity (in percentage): ");
  scanf("%d", &humidity);
  
  // Checking room temperature
  if(temperature < 18) {
    printf("Room is too cold. Turning on the heater...\n");
  }
  else if(temperature > 25) {
    printf("Room is too hot. Turning on the air conditioner...\n");
  }
  else {
    printf("Room temperature is optimal.\n");
  }
  
  // Checking room humidity
  if(humidity > 70) {
    printf("Room is too humid. Turning on the dehumidifier...\n");
  }
  else if(humidity < 40) {
    printf("Room is too dry. Turning on the humidifier...\n");
  }
  else {
    printf("Room humidity is optimal.\n");
  }
  
  // Light control
  printf("Do you want to turn on the light? (1 for Yes / 0 for No): ");
  scanf("%d", &isLightOn);
  
  if(isLightOn == 1) {
    printf("Turning on the light...\n");
  }
  else {
    printf("Leaving the light off...\n");
  }
  
  // Fan control
  printf("Do you want to turn on the fan? (1 for Yes / 0 for No): ");
  scanf("%d", &isFanOn);
  
  if(isFanOn == 1) {
    printf("Turning on the fan...\n");
  }
  else {
    printf("Leaving the fan off...\n");
  }
  
  // Goodbye message
  printf("\nSmart Home Automation System is now turned off. Goodbye!\n");
  
  return 0;
}