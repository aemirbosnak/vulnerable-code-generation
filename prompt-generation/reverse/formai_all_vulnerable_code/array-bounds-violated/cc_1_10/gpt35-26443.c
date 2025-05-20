//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct exercise {
  char name[50];
  int sets;
  int reps;
  int weight;
};

int main() {

  int numExercises;
  printf("How many exercises are you doing today? ");
  scanf("%d", &numExercises);

  struct exercise exercises[numExercises];

  for(int i = 0; i < numExercises; i++) {
    printf("Enter the name of exercise %d: ", i+1);
    scanf("%s", exercises[i].name);

    printf("Enter the number of sets: ");
    scanf("%d", &exercises[i].sets);

    printf("Enter the number of reps: ");
    scanf("%d", &exercises[i].reps);

    printf("Enter the weight: ");
    scanf("%d", &exercises[i].weight);
  }

  int totalReps = 0;
  for(int i = 0; i < numExercises; i++) {
    totalReps += exercises[i].reps;
  }

  printf("You are doing a total of %d reps today\n", totalReps);

  int maxWeightIndex = 0;
  for(int i = 0; i < numExercises; i++) {
    if(exercises[i].weight > exercises[maxWeightIndex].weight) {
      maxWeightIndex = i;
    }
  }

  printf("Your heaviest lift today is %s at %d lbs\n", exercises[maxWeightIndex].name, exercises[maxWeightIndex].weight);

  return 0;
}