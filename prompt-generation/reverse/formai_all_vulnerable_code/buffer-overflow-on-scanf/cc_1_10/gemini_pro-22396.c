//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Introducing our trusty temperature monitor...
  printf("Behold, the mighty Temperature Monitor! Let's get this party started.\n");
  
  // Prepare for thermometer readings...
  float temperature;
  printf("Feed me temperature readings, one at a time. Hit enter after each reading.\n");
  printf("When you're done, just enter a negative value and I'll wrap things up.\n");
  
  // Let's gather some temperature data...
  int count = 0;
  float sum = 0.0;
  float max = -1000.0;
  float min = 1000.0;
  while (1) {
    printf("Temperature reading %d: ", count + 1);
    scanf("%f", &temperature);
    if (temperature < 0.0) {
      break;
    }
    
    // Update our stats...
    count++;
    sum += temperature;
    if (temperature > max) {
      max = temperature;
    }
    if (temperature < min) {
      min = temperature;
    }
  }
  
  // Time to summarize our findings...
  printf("\nSummary of %d temperature readings:\n", count);
  
  // Calculate the average temperature...
  float average = sum / count;
  printf("Average temperature: %.2f degrees Celsius\n", average);
  
  // Reveal the temperature extremes...
  printf("Maximum temperature: %.2f degrees Celsius\n", max);
  printf("Minimum temperature: %.2f degrees Celsius\n", min);
  
  // And that's a wrap!
  printf("Thanks for using the Temperature Monitor. Stay cool!\n");
  
  return 0;
}