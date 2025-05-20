//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  double temperature;
  char choice;
  int count = 0;
  time_t start_time, end_time;
  double elapsed_time;

  printf("Welcome to the Temperature Monitor!\n\n");
  printf("Please enter your temperature in Celsius: ");
  scanf("%lf", &temperature);

  while (temperature < 35.0 || temperature > 42.0) {
    printf("Invalid temperature! Please enter your temperature in Celsius: ");
    scanf("%lf", &temperature);
  }

  while (1) {
    printf("\n");
    printf("Current temperature: %.2lf degrees Celsius\n", temperature);
    printf("Press 'c' to convert to Fahrenheit or 'q' to quit: ");
    scanf(" %c", &choice);

    if (choice == 'c') {
      temperature = (temperature * 9.0 / 5.0) + 32.0;
      printf("\n");
      printf("Current temperature: %.2lf degrees Fahrenheit\n", temperature);
    } else if (choice == 'q') {
      break;
    } else {
      printf("\n");
      printf("Invalid choice! Please try again.\n");
    }

    count++;
    if (count == 10) {
      start_time = time(NULL);
      do {
        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
      } while (elapsed_time < 1.0);
      printf("\n");
      printf("Elapsed time: %.2lf seconds\n", elapsed_time);
      count = 0;
    }
  }

  return 0;
}