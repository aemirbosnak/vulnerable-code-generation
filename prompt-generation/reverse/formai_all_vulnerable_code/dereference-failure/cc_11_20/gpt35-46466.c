//FormAI DATASET v1.0 Category: Data mining ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000
#define MAX_ATTRIBUTES 20

typedef struct record {
  int ID;
  float attributes[MAX_ATTRIBUTES];
} Record;

int main() {
  Record data[MAX_RECORDS];
  int numRecords = 0;

  // read records from file
  FILE *file = fopen("data.txt", "r");
  if (file == NULL) {
    printf("Error: Could not open file.");
    return -1;
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    if (numRecords >= MAX_RECORDS) {
      printf("Error: Maximum number of records exceeded.");
      return -1;
    }

    Record record;
    record.ID = atoi(strtok(line, ","));
    for (int i = 0; i < MAX_ATTRIBUTES; i++) {
      char *attr = strtok(NULL, ",");
      if (attr == NULL) break;
      record.attributes[i] = atof(attr);
    }

    data[numRecords++] = record;
  }
  fclose(file);

  // calculate mean and standard deviation of attributes
  float means[MAX_ATTRIBUTES] = {0};
  float stddevs[MAX_ATTRIBUTES] = {0};
  for (int i = 0; i < numRecords; i++) {
    for (int j = 0; j < MAX_ATTRIBUTES; j++) {
      means[j] += data[i].attributes[j];
    }
  }
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    means[j] /= numRecords;
  }
  for (int i = 0; i < numRecords; i++) {
    for (int j = 0; j < MAX_ATTRIBUTES; j++) {
      float diff = data[i].attributes[j] - means[j];
      stddevs[j] += diff * diff;
    }
  }
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    stddevs[j] = sqrt(stddevs[j] / numRecords);
  }

  // output results
  printf("Data mining results:\n");
  printf("%10s", "ID");
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    printf("%15s%d", "attribute", j+1);
  }
  printf("\n");
  for (int i = 0; i < numRecords; i++) {
    printf("%10d", data[i].ID);
    for (int j = 0; j < MAX_ATTRIBUTES; j++) {
      printf("%15.2f", data[i].attributes[j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("%15s", "");
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    printf("%15s%d", "mean_", j+1);
  }
  printf("\n");
  printf("%15s", "");
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    printf("%15.2f", means[j]);
  }
  printf("\n");
  printf("%15s", "");
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    printf("%15s%d", "stddev_", j+1);
  }
  printf("\n");
  printf("%15s", "");
  for (int j = 0; j < MAX_ATTRIBUTES; j++) {
    printf("%15.2f", stddevs[j]);
  }
  printf("\n");

  return 0;
}