//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_CLASSES 5
#define NUM_FEATURES 10

int main() {
  float weights[NUM_CLASSES][NUM_FEATURES];
  float input[NUM_FEATURES];
  float scores[NUM_CLASSES];
  int predicted_class;
  
  // Initialize weights randomly
  for (int i=0; i<NUM_CLASSES; i++) {
    for (int j=0; j<NUM_FEATURES; j++) {
      weights[i][j] = (float) rand() / (float) RAND_MAX;
    }
  }
  
  // Get user input for feature vector
  printf("Enter input feature vector (length %d):\n", NUM_FEATURES);
  for (int i=0; i<NUM_FEATURES; i++) {
    scanf("%f", &input[i]);
  }
  
  // Compute scores for each class
  for (int i=0; i<NUM_CLASSES; i++) {
    scores[i] = 0;
    for (int j=0; j<NUM_FEATURES; j++) {
      scores[i] += weights[i][j] * input[j];
    }
  }
  
  // Choose class with highest score as prediction
  predicted_class = 0;
  for (int i=1; i<NUM_CLASSES; i++) {
    if (scores[i] > scores[predicted_class]) {
      predicted_class = i;
    }
  }
  
  // Print results
  printf("Input feature vector:\n");
  for (int i=0; i<NUM_FEATURES; i++) {
    printf("%f ", input[i]);
  }
  printf("\n");
  printf("Scores for each class:\n");
  for (int i=0; i<NUM_CLASSES; i++) {
    printf("%f ", scores[i]);
  }
  printf("\n");
  printf("Predicted class: %d\n", predicted_class);
  
  return 0;
}