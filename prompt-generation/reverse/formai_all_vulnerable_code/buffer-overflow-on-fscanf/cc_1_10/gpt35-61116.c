//FormAI DATASET v1.0 Category: Data mining ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the struct for each data record
struct record {
  char name[50];
  int age;
  float height;
  int weight;
};

int main() {
  // create an array of records
  struct record data[100];

  // open the data file for reading
  FILE *fp = fopen("data.txt", "r");

  // check that the file was opened successfully
  if (fp == NULL) {
    printf("Error: could not open file for reading\n");
    return 1;
  }

  // read in each record from the file
  int i = 0;
  while (fscanf(fp, "%s %d %f %d\n", data[i].name, &data[i].age, &data[i].height, &data[i].weight) == 4) {
    i++;
  }

  // close the file
  fclose(fp);

  // calculate the average age, height, and weight
  int n = i;
  float age_sum = 0;
  float height_sum = 0;
  float weight_sum = 0;
  for (i = 0; i < n; i++) {
    age_sum += data[i].age;
    height_sum += data[i].height;
    weight_sum += data[i].weight;
  }
  float avg_age = age_sum / n;
  float avg_height = height_sum / n;
  float avg_weight = weight_sum / n;

  // output the results
  printf("Average Age: %.2f\n", avg_age);
  printf("Average Height: %.2f\n", avg_height);
  printf("Average Weight: %.2f\n", avg_weight);

  return 0;
}