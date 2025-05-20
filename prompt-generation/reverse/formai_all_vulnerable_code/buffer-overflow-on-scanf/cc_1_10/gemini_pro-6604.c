//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the number of temperature readings
#define NUM_READINGS 100

// Define the minimum and maximum temperatures
#define MIN_TEMP 0
#define MAX_TEMP 100

// Define the number of bins for the histogram
#define NUM_BINS 10

// Create an array to store the temperature readings
float temperatures[NUM_READINGS];

// Create an array to store the number of readings in each bin
int histogram[NUM_BINS];

// Get the temperature readings from the user
void get_temperatures() {
  for (int i = 0; i < NUM_READINGS; i++) {
    printf("Enter temperature %d: ", i + 1);
    scanf("%f", &temperatures[i]);

    // Check if the temperature is valid
    if (temperatures[i] < MIN_TEMP || temperatures[i] > MAX_TEMP) {
      printf("Invalid temperature: %f\n", temperatures[i]);
      exit(1);
    }
  }
}

// Calculate the mean temperature
float calculate_mean() {
  float sum = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    sum += temperatures[i];
  }
  return sum / NUM_READINGS;
}

// Calculate the standard deviation of the temperature
float calculate_standard_deviation() {
  float mean = calculate_mean();
  float sum_of_squares = 0;
  for (int i = 0; i < NUM_READINGS; i++) {
    sum_of_squares += pow(temperatures[i] - mean, 2);
  }
  return sqrt(sum_of_squares / (NUM_READINGS - 1));
}

// Create a histogram of the temperature readings
void create_histogram() {
  for (int i = 0; i < NUM_READINGS; i++) {
    int bin = (int)floor((temperatures[i] - MIN_TEMP) / (MAX_TEMP - MIN_TEMP) * NUM_BINS);
    histogram[bin]++;
  }
}

// Print the results
void print_results() {
  printf("Mean temperature: %f\n", calculate_mean());
  printf("Standard deviation: %f\n", calculate_standard_deviation());

  printf("Histogram:\n");
  for (int i = 0; i < NUM_BINS; i++) {
    printf("%d-%d: %d\n", i * (MAX_TEMP - MIN_TEMP) / NUM_BINS, (i + 1) * (MAX_TEMP - MIN_TEMP) / NUM_BINS, histogram[i]);
  }
}

// Main function
int main() {
  // Get the temperature readings from the user
  get_temperatures();

  // Calculate the mean and standard deviation of the temperature
  float mean = calculate_mean();
  float standard_deviation = calculate_standard_deviation();

  // Create a histogram of the temperature readings
  create_histogram();

  // Print the results
  print_results();

  return 0;
}