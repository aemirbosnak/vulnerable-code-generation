//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 20
#define MAX_COLUMN_NAME_LENGTH 50

int main() {
  char csv_filename[100];
  printf("Enter the CSV filename: ");
  scanf("%s", csv_filename);

  // Open the CSV file
  FILE* csv_file = fopen(csv_filename, "r");
  if (csv_file == NULL) {
    printf("Error opening file: %s\n", csv_filename);
    return 1;
  }

  char line[1000];
  char* field;
  char* headers[MAX_COLUMNS];

  // Read the first line of the CSV file to get the headers
  if (fgets(line, 1000, csv_file)) {
    int i = 0;
    field = strtok(line, ",");
    while (field != NULL && i < MAX_COLUMNS) {
      headers[i++] = strdup(field);
      field = strtok(NULL, ",");
    }
  }

  // Print headers
  printf("CSV Headers:\n");
  for (int i = 0; i < MAX_COLUMNS; i++) {
    if (headers[i] != NULL) {
      printf("%s\n", headers[i]);
    }
  }

  // Read remaining lines of the CSV file
  int row_number = 1;
  while (fgets(line, 1000, csv_file)) {
    printf("\nRow %d:\n", row_number++);
    int i = 0;
    field = strtok(line, ",");
    while (field != NULL && i < MAX_COLUMNS) {
      if (headers[i] != NULL) {
        printf("%s: %s\n", headers[i], field);
      }
      field = strtok(NULL, ",");
      i++;
    }
  }

  // Close the CSV file
  fclose(csv_file);

  return 0;
}