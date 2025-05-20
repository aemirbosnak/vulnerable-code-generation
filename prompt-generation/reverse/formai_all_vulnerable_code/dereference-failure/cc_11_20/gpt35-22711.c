//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Welcome to the Clustering Algorithm Implementation program!\n");
  printf("Please enter the number of clusters you wish to create:\n");
  int num_clusters;
  scanf("%d", &num_clusters);
  printf("Great! You want to create %d clusters. Let's get started!\n", num_clusters);
  printf("First, let's input some data. Enter the number of data points you have:\n");
  int num_data_points;
  scanf("%d", &num_data_points);
  printf("Awesome! You have %d data points. Please enter the data points separated by spaces:\n", num_data_points);
  int* data_points = (int*) malloc(sizeof(int) * num_data_points);
  for (int i = 0; i < num_data_points; i++) {
    scanf("%d", &data_points[i]);
  }
  printf("Fantastic! Your data points are: ");
  for (int i = 0; i < num_data_points; i++) {
    printf("%d ", data_points[i]);
  }
  printf("\nNow let's start clustering!\n");
  int* clusters = (int*) malloc(sizeof(int) * num_clusters);
  for (int i = 0; i < num_clusters; i++) {
    clusters[i] = data_points[i];
  }
  printf("Initial clusters are: ");
  for (int i = 0; i < num_clusters; i++) {
    printf("%d ", clusters[i]);
  }
  printf("\n");
  int num_iterations = 0; 
  int convergence = 0;
  while (!convergence) {
    num_iterations++;
    printf("Running iteration %d...\n", num_iterations);
    int* new_clusters = (int*) malloc(sizeof(int) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
      new_clusters[i] = 0;
    }
    
    //Assign data points to the nearest cluster
    for (int i = 0; i < num_data_points; i++) {
      int min_cluster = 0;
      for (int j = 0; j < num_clusters; j++) {
        if (abs(data_points[i] - clusters[j]) < abs(data_points[i] - clusters[min_cluster])) {
          min_cluster = j;
        }
      }
      new_clusters[min_cluster] += data_points[i];
    }
    
    //Calculate the average of each cluster and update the clusters
    for (int i = 0; i < num_clusters; i++) {
      if (new_clusters[i] != 0) {
        new_clusters[i] /= num_clusters;
        printf("New cluster %d: %d\n", i + 1, new_clusters[i]);
      }
    }
    if (memcmp(clusters, new_clusters, sizeof(int) * num_clusters) == 0) {
      printf("Convergence reached after %d iterations! Yay!\n", num_iterations);
      convergence = 1;
    } else {
      memcpy(clusters, new_clusters, sizeof(int) * num_clusters);
      free(new_clusters);
    }
  }
  
  free(data_points);
  free(clusters);
  
  printf("Thanks for using the Clustering Algorithm Implementation program! See you later!");
  
  return 0;
}