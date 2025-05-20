//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

  int temp, rain;
  int chance_of_rain;
  int num_of_days;

  //Get User Input
  printf("Enter number of days: ");
  scanf("%d", &num_of_days);

  printf("Enter temperature: ");
  scanf("%d", &temp);

  printf("Enter chance of rain (in percentage): ");
  scanf("%d", &chance_of_rain);

  //Initialize Random Seed
  srand(time(NULL));

  //Weather Simulation
  for(int i=1; i<=num_of_days; i++){

    //Generate Random Rain Chance
    rain = rand() % 101;

    //Print Weather For Day
    printf("\nWeather For Day %d:\n", i);
    printf("Temperature: %d degrees\n", temp);

    //Check if Raining
    if(rain <= chance_of_rain)
      printf("It is raining with a %d%% chance of precipitation.\n", chance_of_rain);
    else
      printf("It is not raining today.\n");

    //Random Temperature Change
    temp += (rand() % 5) - 2; //Randomly add or subtract up to 2 degrees

    //Prevent Negative Temperatures
    if(temp < 0)
      temp = 0;

  }

  return 0;
}