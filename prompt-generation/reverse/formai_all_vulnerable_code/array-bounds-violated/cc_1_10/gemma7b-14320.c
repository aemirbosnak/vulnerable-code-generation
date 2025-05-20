//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HEART_RATE 220
#define MAX_STEPS 10000

typedef struct HeartRate {
  int current_heart_rate;
  int target_heart_rate;
  int heart_rate_history[100];
  int heart_rate_index;
} HeartRate;

typedef struct StepCounter {
  int current_steps;
  int target_steps;
  int steps_history[100];
  int steps_index;
} StepCounter;

int main() {
  HeartRate heart_rate;
  StepCounter step_counter;

  // Initialize the heart rate and step counter structures
  heart_rate.current_heart_rate = 60;
  heart_rate.target_heart_rate = 120;
  step_counter.current_steps = 0;
  step_counter.target_steps = 5000;

  // Simulate heart rate and step counter data
  for (int i = 0; i < 10; i++) {
    heart_rate.heart_rate_history[heart_rate.heart_rate_index++] = heart_rate.current_heart_rate++;
    step_counter.steps_history[step_counter.steps_index++] = step_counter.current_steps++;
  }

  // Display the heart rate and step counter data
  printf("Heart Rate History:\n");
  for (int i = 0; i < heart_rate.heart_rate_index; i++) {
    printf("%d ", heart_rate.heart_rate_history[i]);
  }

  printf("\nStep Counter History:\n");
  for (int i = 0; i < step_counter.steps_index; i++) {
    printf("%d ", step_counter.steps_history[i]);
  }

  return 0;
}