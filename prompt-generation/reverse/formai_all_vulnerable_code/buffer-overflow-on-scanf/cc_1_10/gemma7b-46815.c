//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
  char name[MAX_BUFFER_SIZE];
  int age;
  double weight;
  double height;
  double heart_rate;
  time_t timestamp;
} fitness_tracker_data_t;

void save_fitness_tracker_data(fitness_tracker_data_t *data)
{
  FILE *fp = fopen("fitness_tracker_data.txt", "a");
  fprintf(fp, "%s, %d, %.2lf, %.2lf, %.2lf, %ld\n", data->name, data->age, data->weight, data->height, data->heart_rate, data->timestamp);
  fclose(fp);
}

int main()
{
  fitness_tracker_data_t data;

  // Get the current time
  time_t timestamp = time(NULL);

  // Get the user's name, age, weight, and height
  printf("Enter your name: ");
  scanf("%s", data.name);

  printf("Enter your age: ");
  scanf("%d", &data.age);

  printf("Enter your weight (in kilograms): ");
  scanf("%lf", &data.weight);

  printf("Enter your height (in meters): ");
  scanf("%lf", &data.height);

  // Calculate the user's heart rate
  data.heart_rate = 220 - (6.83 * data.age) - (0.83 * data.weight) - (1.09 * data.height);

  // Save the data to a file
  save_fitness_tracker_data(&data);

  // Print the saved data
  printf("Your name: %s\n", data.name);
  printf("Your age: %d\n", data.age);
  printf("Your weight: %.2lf kg\n", data.weight);
  printf("Your height: %.2lf m\n", data.height);
  printf("Your heart rate: %.2lf bpm\n", data.heart_rate);
  printf("Timestamp: %ld\n", data.timestamp);

  return 0;
}