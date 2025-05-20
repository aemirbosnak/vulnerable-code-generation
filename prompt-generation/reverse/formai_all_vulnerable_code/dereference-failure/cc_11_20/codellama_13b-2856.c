//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STR_LEN 100
#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[]) {
  FILE *fp;
  char *str;
  char *delim = " ";
  int i, j, k, n;
  char *arr[MAX_FILE_SIZE];

  if (argc != 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Error: unable to open file %s\n", argv[1]);
    return 1;
  }

  // Read file into array
  i = 0;
  while (fgets(arr[i], MAX_STR_LEN, fp)) {
    i++;
  }
  n = i;

  // Sort array
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - 1 - i; j++) {
      if (strcmp(arr[j], arr[j + 1]) > 0) {
        str = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = str;
      }
    }
  }

  // Print sorted array
  for (i = 0; i < n; i++) {
    printf("%s", arr[i]);
    if (i < n - 1) {
      printf("%s", delim);
    }
  }
  printf("\n");

  // Calculate statistical data
  double mean = 0.0, std_dev = 0.0, variance = 0.0;
  for (i = 0; i < n; i++) {
    mean += atof(arr[i]);
  }
  mean /= n;
  for (i = 0; i < n; i++) {
    variance += pow(atof(arr[i]) - mean, 2);
  }
  variance /= n;
  std_dev = sqrt(variance);

  // Print statistical data
  printf("Mean: %f\n", mean);
  printf("Standard Deviation: %f\n", std_dev);

  // Free memory
  for (i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}