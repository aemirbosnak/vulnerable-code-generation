//FormAI DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int temperature = 20;
  int humidity = 50;
  int air_pressure = 101325;
 
  printf("Welcome to the Weather Simulator!\n");
  printf("\n");
  printf("Out the window, the temperature is %dC, the humidity is %d%%, and the air pressure is %dPa.\n", temperature, humidity, air_pressure);
  printf("\n");
  printf("But what if we change things up a bit?\n");
  printf("\n");
  printf("Enter a temperature change in Celsius (positive or negative): ");
  
  // user input for temperature change
  int temp_change;
  scanf("%d", &temp_change);
  temperature += temp_change;
  
  // random humidity change
  srand(time(NULL));
  int humid_change = rand() % 10 - 4; // random number between -4 and 5
  humidity += humid_change;
  
  // random air pressure change
  int air_change = rand() % 10000 - 5000; // random number between -5000 and 4999
  air_pressure += air_change;
  
  printf("\n");
  printf("After our changes, the temperature is now %dC, the humidity is now %d%%, and the air pressure is now %dPa.\n", temperature, humidity, air_pressure);
  printf("\n");
  printf("But wait, there's more! Let's add a little mystery to the mix.\n");
  printf("\n");
  
  // random mystery event
  int mystery = rand() % 10;
  
  switch(mystery) {
    case 0:
      printf("Oh no! A thunderstorm has rolled in! The temperature drops 5C and the air pressure plummets to 95000Pa.\n");
      temperature -= 5;
      air_pressure = 95000;
      break;
    case 1:
      printf("Wow, what a beautiful rainbow! The humidity jumps to 90%% and the air pressure rises to 105000Pa.\n");
      humidity = 90;
      air_pressure = 105000;
      break;
    case 2:
      printf("Yikes, it's a sandstorm! The air pressure drops to 80000Pa and the humidity drops to 10%%.\n");
      humidity = 10;
      air_pressure = 80000;
      break;
    case 3:
      printf("Look out, it's a blizzard! The temperature falls to -10C and the humidity skyrockets to 95%%.\n");
      temperature = -10;
      humidity = 95;
      break;
    case 4:
      printf("Ahhh, what a lovely spring day. The temperature rises to 25C and the air pressure remains steady at 101325Pa.\n");
      temperature = 25;
      break;
    case 5:
      printf("Interesting, a hailstorm! The temperature drops to 2C and the air pressure drops to 90000Pa.\n");
      temperature = 2;
      air_pressure = 90000;
      break;
    case 6:
      printf("Fascinating, a heat wave! The temperature soars to 35C and the humidity drops to 20%%.\n");
      temperature = 35;
      humidity = 20;
      break;
    case 7:
      printf("How bizarre, a hurricane! The temperature drops to 10C, the humidity rises to 90%%, and the air pressure drops to 85000Pa.\n");
      temperature = 10;
      humidity = 90;
      air_pressure = 85000;
      break;
    case 8:
      printf("Huh, it's snowing in the summer! The temperature drops to 8C and the humidity rises to 85%%.\n");
      temperature = 8;
      humidity = 85;
      break;
    case 9:
      printf("My oh my, it's a tornado! The temperature drops to 15C, the humidity rises to 80%%, and the air pressure drops to 80000Pa.\n");
      temperature = 15;
      humidity = 80;
      air_pressure = 80000;
      break;
  }
  
  printf("\n");
  printf("And there you have it folks, a completely random and totally puzzling weather simulation!\n");
  
  return 0;
}