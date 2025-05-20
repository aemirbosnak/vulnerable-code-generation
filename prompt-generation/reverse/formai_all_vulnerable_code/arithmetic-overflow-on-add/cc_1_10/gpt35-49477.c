//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: lively
#include <stdio.h>

int main() {
  int red_light_timer, yellow_light_timer, green_light_timer;
  int total_time;
  
  printf("Welcome to the Traffic Light Controller program!\n");
  
  printf("Please enter the desired time for RED light (in seconds): ");
  scanf("%d", &red_light_timer);
  
  printf("Please enter the desired time for YELLOW light (in seconds): ");
  scanf("%d", &yellow_light_timer);
  
  printf("Please enter the desired time for GREEN light (in seconds): ");
  scanf("%d", &green_light_timer);
  
  printf("Please enter the desired total time for the traffic light cycle (in seconds): ");
  scanf("%d", &total_time);
  
  int red_count, yellow_count, green_count;
  int current_time = 0;
  
  while (current_time < total_time) {
    // Start with RED
    red_count = 0;
    printf("RED light ON\n");
    while (red_count < red_light_timer) {
      printf("Time remaining: %d seconds\n", red_light_timer - red_count);
      red_count++;
    }
    
    // Switch to YELLOW
    yellow_count = 0;
    printf("YELLOW light ON\n");
    while (yellow_count < yellow_light_timer) {
      printf("Time remaining: %d seconds\n", yellow_light_timer - yellow_count);
      yellow_count++;
    }
    
    // Switch to GREEN
    green_count = 0;
    printf("GREEN light ON\n");
    while (green_count < green_light_timer) {
      printf("Time remaining: %d seconds\n", green_light_timer - green_count);
      green_count++;
    }
    
    // Update current time
    current_time += (red_light_timer + yellow_light_timer + green_light_timer);
  }
  
  printf("Traffic Light Controller program completed successfully!\n");
  
  return 0;
}