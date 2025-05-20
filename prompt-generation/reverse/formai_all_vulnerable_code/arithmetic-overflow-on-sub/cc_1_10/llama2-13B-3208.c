//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define PI 3.14159

// Define variables for daily activities and emotions
int dailyActivities[7] = {0, 0, 0, 0, 0, 0, 0};
int emotions[5] = {0, 0, 0, 0, 0};
int happinessScore = 0;

// Function to calculate happiness score
void calculateHappinessScore() {
  // Add points for each daily activity
  for (int i = 0; i < 7; i++) {
    if (dailyActivities[i] == 1) {
      happinessScore += 10;
    }
  }

  // Subtract points for each negative emotion
  for (int i = 0; i < 5; i++) {
    if (emotions[i] == 1) {
      happinessScore -= 5;
    }
  }

  // Add bonus points for each positive emotion
  for (int i = 0; i < 5; i++) {
    if (emotions[i] == 2) {
      happinessScore += 5;
    }
  }

  // Calculate and display happiness score
  printf("Your happiness score is %d\n", happinessScore);
}

// Function to update daily activities and emotions
void updateDailyActivitiesAndEmotions() {
  // Get user input for daily activities and emotions
  int activity = getchar();
  int emotion = getchar();

  // Update daily activities and emotions
  dailyActivities[activity - '0'] = 1;
  emotions[emotion - '0'] = 1;
}

int main() {
  // Initialize daily activities and emotions
  for (int i = 0; i < 7; i++) {
    dailyActivities[i] = 0;
  }
  for (int i = 0; i < 5; i++) {
    emotions[i] = 0;
  }

  // Calculate and display happiness score
  calculateHappinessScore();

  // Main loop to update daily activities and emotions
  while (1) {
    updateDailyActivitiesAndEmotions();
    calculateHappinessScore();
    printf("\nDo you want to continue? (y/n): ");
    char cont = getchar();
    if (cont == 'n') {
      break;
    }
  }

  return 0;
}