//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>

int main() {

  float temp = 0.0;
  int count = 0;
  float sum = 0.0;
  float avg = 0.0;
  float min = 100.0;
  float max = -100.0;

  printf("Welcome to the Temperature monitor program!\n\n");

  while(1) {
    printf("Enter current temperature or enter -99 to exit: ");
    scanf("%f", &temp);

    if(temp == -99) {
      break;
    }

    if(temp < -50.0 || temp > 50.0) {
      printf("Invalid temperature input. Try again.\n");
      continue;
    }

    sum += temp;
    count++;

    if(temp < min) {
      min = temp;
    }

    if(temp > max) {
      max = temp;
    }
  }

  if(count > 0) {
    avg = sum / count;
  }

  printf("\nTemperature Summary:\n");
  printf("====================\n");
  printf("Total Readings: %d\n", count);
  printf("Average Temperature: %.2f\n", avg);
  printf("Minimum Temperature: %.2f\n", min);
  printf("Maximum Temperature: %.2f\n", max);

  return 0;
}