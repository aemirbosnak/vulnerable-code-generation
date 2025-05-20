//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int red = 1, yellow = 0, green = 0;
  int time = 0, duration = 0;
  
  printf("Welcome to the Traffic Light Controller.\n");
  printf("The light is currently RED.\n\n");

  while(1) {
    printf("How long should RED be on for? ");
    scanf("%d", &duration);
    time += duration;
    printf("RED is on for %d seconds.\n", duration);
    printf("Yellow will be on for 3 seconds.\n");
    printf("Green will be on for 10 seconds.\n");

    red = 0;
    yellow = 1;
    green = 0;

    printf("\nYELLOW\n");
    printf("Remaining time: %d seconds.\n", 3 - time);
    while(time < 3) {
      time++;
      sleep(1);
      printf("Remaining time: %d seconds.\n", 3 - time);
    }

    red = 0;
    yellow = 0;
    green = 1;
    time = 0;

    printf("\nGREEN\n");
    printf("Remaining time: %d seconds.\n", 10 - time);
    while(time < 10) {
      time++;
      sleep(1);
      printf("Remaining time: %d seconds.\n", 10 - time);
    }

    red = 1;
    yellow = 0;
    green = 0;
    time = 0;

    printf("\nRED\n");
    printf("Remaining time: %d seconds.\n", duration - time);
    while(time < duration) {
      time++;
      sleep(1);
      printf("Remaining time: %d seconds.\n", duration - time);
    }
  }

  return 0;
}