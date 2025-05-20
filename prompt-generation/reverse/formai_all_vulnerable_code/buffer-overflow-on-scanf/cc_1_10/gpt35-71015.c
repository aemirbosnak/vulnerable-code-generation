//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  
  printf("Welcome to THE INTERNET SPEED TEST!\n");
  printf("This program will measure your connection speed and give you a rating based on your results.\n\n");

  printf("Please enter the download speed you'd like to test (in MB/s) [1-10]: ");
  int download_speed;
  scanf("%d", &download_speed);

  if (download_speed < 1 || download_speed > 10) {
    printf("Invalid download speed entered. Exiting program.\n");
    return 1;
  }

  printf("\nBeginning download speed test...\n\n");

  // simulate download speed test by randomly generating numbers between 1 and download_speed
  int test_size = 50;
  int test_results[test_size];

  for (int i = 0; i < test_size; i++) {
    test_results[i] = rand() % download_speed + 1;
    printf("Test result %d: %d MB/s\n", i+1, test_results[i]);
  }

  // calculate average
  int total_speed = 0;
  for (int i = 0; i < test_size; i++) {
    total_speed += test_results[i];
  }

  int avg_speed = total_speed / test_size;
  printf("\nAverage speed: %d MB/s\n", avg_speed);

  printf("\nCalculating rating based on average speed...\n");

  // determine rating based on average speed
  if (avg_speed >= 8) {
    printf("\nCongratulations! You have excellent internet speed.\n");
    printf("Rating: A++\n");
  } else if (avg_speed >= 6) {
    printf("\nYour internet speed is above average.\n");
    printf("Rating: A\n");
  } else if (avg_speed >= 4) {
    printf("\nYour internet speed is average.\n");
    printf("Rating: B\n");
  } else if (avg_speed >= 2) {
    printf("\nYour internet speed is below average.\n");
    printf("Rating: C\n");
  } else {
    printf("\nYour internet speed is terrible.\n");
    printf("Rating: F\n");
  }
  
  return 0;
}