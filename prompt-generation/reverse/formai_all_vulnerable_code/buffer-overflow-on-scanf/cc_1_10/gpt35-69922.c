//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int lovers = 0;
  int clusters = 0;
  int *love = NULL;
  int *cluster = NULL;
  
  printf("Welcome to the Clustering of Love algorithm implementation!\n");
  printf("Please enter the number of lovers: ");
  scanf("%d", &lovers);
  
  love = (int*) malloc(lovers * sizeof(int));
  
  printf("Great! Now, please enter the amount of love each lover can give (values between 0 and 100):\n");
  
  for (int i = 0; i < lovers; i++) {
    printf("Lover %d: ", i+1);
    scanf("%d", &love[i]);
  }
  
  printf("All the love has been given. Let's group the lovers into clusters...\n");
  
  cluster = (int*) calloc(lovers, sizeof(int));
  
  for (int i = 0; i < lovers; i++) {
    if (cluster[i] == 0) { // Check if lover hasn't been assigned to a cluster yet
      clusters++; // Create a new cluster
      cluster[i] = clusters; // Assign the lover to the new cluster
      
      // Check all remaining lovers and add them to the cluster if their love value is similar
      for (int j = i+1; j < lovers; j++) {
        if (abs(love[i] - love[j]) <= 10) {
          cluster[j] = clusters; // Assign the lover to the cluster
        }
      }
    }
  }
  
  printf("The lovers have been successfully grouped into %d clusters! Here are the details:\n", clusters);
  
  for (int i = 1; i <= clusters; i++) {
    printf("Cluster %d: ", i);
    for (int j = 0; j < lovers; j++) {
      if (cluster[j] == i) {
        printf("%d ", j+1); // Print the lover number (starting from 1) in the current cluster
      }
    }
    printf("\n");
  }
  
  free(love);
  free(cluster);
  
  printf("Thank you for using the Clustering of Love algorithm implementation!\n");
  
  return 0;
}