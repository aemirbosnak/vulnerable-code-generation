//FormAI DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
  int temperature, humidity, rain;
  srand(time(0)); // seed for random number generation
  
  printf("Welcome to the Weather Simulation Program!\n");
  printf("-------------------------------------------\n\n");
  printf("Please enter the current temperature in Celsius: ");
  scanf("%d", &temperature);
  
  printf("Please enter the current humidity (percentage): ");
  scanf("%d", &humidity);
  
  printf("Please enter the chance of rain (percentage): ");
  scanf("%d", &rain);
  
  printf("\nHere is your weather report for today:\n");
  printf("--------------------------------------\n");
  
  // temperature conditionals
  if (temperature < 0)
  {
    printf("It's freezing cold out there!\n");
    printf("Make sure to bundle up before heading out.\n");
  }
  else if (temperature < 10)
  {
    printf("It's a bit chilly outside.\n");
    printf("A jacket or a sweater should keep you warm.\n");
  }
  else if (temperature < 20)
  {
    printf("It's a comfortable temperature today.\n");
    printf("Enjoy your day!\n");
  }
  else if (temperature < 30)
  {
    printf("It's getting a bit warm outside.\n");
    printf("Stay hydrated!\n");
  }
  else
  {
    printf("It's scorching hot outside!\n");
    printf("Make sure to avoid direct sunlight.\n");
  }
  
  // humidity conditionals
  if (humidity < 30)
  {
    printf("The air is dry today.\n");
    printf("Consider applying some moisturizer to your skin.\n");
  }
  else if (humidity < 60)
  {
    printf("The humidity is just right.\n");
    printf("Enjoy your day!\n");
  }
  else
  {
    printf("The air is very humid today.\n");
    printf("Make sure to stay cool and hydrated.\n");
  }
  
  // rain probability
  if (rain > 70)
  {
    printf("It's highly likely to rain today.\n");
    printf("Don't forget your umbrella and raincoat!\n");
  }
  else if (rain > 40)
  {
    printf("There's a fair chance of rain today.\n");
    printf("Keep your umbrella handy just in case.\n");
  }
  else
  {
    printf("It's unlikely to rain today.\n");
    printf("Enjoy your day!\n");
  }
  
  // random weather event
  if (temperature > 20 && humidity < 60 && rain < 30)
  {
    int event = rand() % 4; // generates a random number between 0 and 3
    
    switch (event)
    {
      case 0:
        printf("What a beautiful day!\n");
        break;
      case 1:
        printf("The sky is so blue today!\n");
        break;
      case 2:
        printf("The air smells so fresh!\n");
        break;
      case 3:
        printf("The birds are singing so sweetly!\n");
        break;
    }
  }
  
  return 0;
}