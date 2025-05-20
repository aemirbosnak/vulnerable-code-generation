//FormAI DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Define a struct for each data point
typedef struct {
  int id;
  char name[20];
  int age;
  float height;
  float weight;
} Data;

int main() {
  // Declare variables
  Data data[MAX_SIZE];
  int num_data = 0;
  FILE* fp;

  // Open file for reading
  fp = fopen("data.txt", "r");

  // Read data from file
  while (!feof(fp)) {
    fscanf(fp, "%d %s %d %f %f",
      &data[num_data].id,
      data[num_data].name,
      &data[num_data].age,
      &data[num_data].height,
      &data[num_data].weight);
    num_data++;
  }

  // Close file
  fclose(fp);

  // Perform data mining on data array
  int num_30_and_above = 0;
  float avg_height = 0;
  float avg_weight = 0;
  for (int i = 0; i < num_data; i++) {
    if (data[i].age >= 30) {
      num_30_and_above++;
    }
    avg_height += data[i].height;
    avg_weight += data[i].weight;
  }
  avg_height /= num_data;
  avg_weight /= num_data;

  // Print number of data points with age of 30 or above
  printf("Number of data points with age of 30 or above: %d\n",
    num_30_and_above);

  // Print average height and weight of data points
  printf("Average height of data points: %f\nAverage weight of data points: %f\n",
    avg_height, avg_weight);

  return 0;
}