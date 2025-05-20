//FormAI DATASET v1.0 Category: Weather simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 15.0
#define MAX_TEMP 35.0
#define MIN_PRECIP 0.0
#define MAX_PRECIP 100.0

int main() {
  
  int month;
  double temperature, precipitation;
  srand(time(NULL)); // Seed random number generator
  
  printf("Welcome to the Weather Simulator!\n\n");
  
  printf("Please enter the month (1-12): ");
  scanf("%d", &month);
  
  switch(month) {
    case 1:
      printf("\nGenerating weather for January...\n\n");
      break;
    case 2:
      printf("\nGenerating weather for February...\n\n");
      break;
    case 3:
      printf("\nGenerating weather for March...\n\n");
      break;
    case 4:
      printf("\nGenerating weather for April...\n\n");
      break;
    case 5:
      printf("\nGenerating weather for May...\n\n");
      break;
    case 6:
      printf("\nGenerating weather for June...\n\n");
      break;
    case 7:
      printf("\nGenerating weather for July...\n\n");
      break;
    case 8:
      printf("\nGenerating weather for August...\n\n");
      break;
    case 9:
      printf("\nGenerating weather for September...\n\n");
      break;
    case 10:
      printf("\nGenerating weather for October...\n\n");
      break;
    case 11:
      printf("\nGenerating weather for November...\n\n");
      break;
    case 12:
      printf("\nGenerating weather for December...\n\n");
      break;
    default:
      printf("\nInvalid month entered. Please enter a value between 1 and 12.\n");
      return 0;
  }
  
  // Generate random temperature and precipitation values
  temperature = (double) rand() / RAND_MAX * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
  precipitation = (double) rand() / RAND_MAX * (MAX_PRECIP - MIN_PRECIP) + MIN_PRECIP;
  
  printf("The current temperature is: %.1f degrees Celsius.\n", temperature);
  printf("The chance of precipitation is: %.1f percent.\n", precipitation);
  
  return 0;
}