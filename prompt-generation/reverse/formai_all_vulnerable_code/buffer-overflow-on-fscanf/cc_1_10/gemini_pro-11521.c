//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a data point
typedef struct {
  double x;
  double y;
} DataPoint;

// Define the function to read the data from a file
DataPoint *readData(char *filename, int *numDataPoints) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    exit(1);
  }

  // Read the number of data points from the file
  fscanf(file, "%d", numDataPoints);

  // Allocate memory for the data points
  DataPoint *dataPoints = malloc(*numDataPoints * sizeof(DataPoint));

  // Read the data points from the file
  for (int i = 0; i < *numDataPoints; i++) {
    fscanf(file, "%lf %lf", &dataPoints[i].x, &dataPoints[i].y);
  }

  // Close the file
  fclose(file);

  return dataPoints;
}

// Define the function to calculate the mean of a data set
double mean(DataPoint *dataPoints, int numDataPoints) {
  double sum = 0.0;
  for (int i = 0; i < numDataPoints; i++) {
    sum += dataPoints[i].x;
  }
  return sum / numDataPoints;
}

// Define the function to calculate the standard deviation of a data set
double standardDeviation(DataPoint *dataPoints, int numDataPoints) {
  double sum = 0.0;
  for (int i = 0; i < numDataPoints; i++) {
    sum += pow(dataPoints[i].x - mean(dataPoints, numDataPoints), 2);
  }
  return sqrt(sum / numDataPoints);
}

// Define the function to calculate the covariance of two data sets
double covariance(DataPoint *dataPoints1, DataPoint *dataPoints2, int numDataPoints) {
  double sum = 0.0;
  for (int i = 0; i < numDataPoints; i++) {
    sum += (dataPoints1[i].x - mean(dataPoints1, numDataPoints)) *
           (dataPoints2[i].x - mean(dataPoints2, numDataPoints));
  }
  return sum / numDataPoints;
}

// Define the function to calculate the correlation coefficient of two data sets
double correlationCoefficient(DataPoint *dataPoints1, DataPoint *dataPoints2, int numDataPoints) {
  return covariance(dataPoints1, dataPoints2, numDataPoints) /
         (standardDeviation(dataPoints1, numDataPoints) *
          standardDeviation(dataPoints2, numDataPoints));
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check the command line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  // Read the data from the file
  int numDataPoints;
  DataPoint *dataPoints = readData(argv[1], &numDataPoints);

  // Calculate the mean of the data set
  double meanX = mean(dataPoints, numDataPoints);

  // Calculate the standard deviation of the data set
  double standardDeviationX = standardDeviation(dataPoints, numDataPoints);

  // Print the mean and standard deviation of the data set
  printf("Mean: %lf\n", meanX);
  printf("Standard deviation: %lf\n", standardDeviationX);

  // Free the memory allocated for the data points
  free(dataPoints);

  return 0;
}