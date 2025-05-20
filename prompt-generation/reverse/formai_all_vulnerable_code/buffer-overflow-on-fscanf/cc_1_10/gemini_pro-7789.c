//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of data points
#define MAX_DATA_POINTS 1000

// Define the maximum number of features
#define MAX_FEATURES 100

// Define the data type for a data point
typedef struct data_point {
  float features[MAX_FEATURES];
  int label;
} data_point;

// Define the data type for a data set
typedef struct data_set {
  data_point data_points[MAX_DATA_POINTS];
  int num_data_points;
  int num_features;
} data_set;

// Load a data set from a file
data_set *load_data_set(const char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  // Read the number of data points and features
  int num_data_points, num_features;
  fscanf(file, "%d %d\n", &num_data_points, &num_features);

  // Allocate memory for the data set
  data_set *data_set = malloc(sizeof(data_set));
  if (data_set == NULL) {
    fprintf(stderr, "Error allocating memory for data set\n");
    return NULL;
  }

  // Read the data points
  for (int i = 0; i < num_data_points; i++) {
    // Read the features
    for (int j = 0; j < num_features; j++) {
      fscanf(file, "%f ", &data_set->data_points[i].features[j]);
    }

    // Read the label
    fscanf(file, "%d\n", &data_set->data_points[i].label);
  }

  // Close the file
  fclose(file);

  // Set the number of data points and features
  data_set->num_data_points = num_data_points;
  data_set->num_features = num_features;

  // Return the data set
  return data_set;
}

// Free the memory allocated for a data set
void free_data_set(data_set *data_set) {
  // Free the memory allocated for the data points
  free(data_set->data_points);

  // Free the memory allocated for the data set
  free(data_set);
}

// Print a data set
void print_data_set(data_set *data_set) {
  // Print the number of data points and features
  printf("Number of data points: %d\n", data_set->num_data_points);
  printf("Number of features: %d\n", data_set->num_features);

  // Print the data points
  for (int i = 0; i < data_set->num_data_points; i++) {
    // Print the features
    for (int j = 0; j < data_set->num_features; j++) {
      printf("%f ", data_set->data_points[i].features[j]);
    }

    // Print the label
    printf("%d\n", data_set->data_points[i].label);
  }
}

// Main function
int main() {
  // Load the data set
  data_set *data_set = load_data_set("data.txt");
  if (data_set == NULL) {
    return 1;
  }

  // Print the data set
  print_data_set(data_set);

  // Free the memory allocated for the data set
  free_data_set(data_set);

  return 0;
}