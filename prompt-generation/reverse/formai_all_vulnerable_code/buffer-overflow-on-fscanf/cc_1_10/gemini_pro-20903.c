//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  char name[50];
  int age;
  char gender;
  char occupation[50];
} record;

record records[MAX_RECORDS];

int main() {
  int num_records = 0;

  // Read records from a file
  FILE *fp = fopen("database.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%s %d %c %s\n", records[num_records].name, &records[num_records].age, &records[num_records].gender, records[num_records].occupation) != EOF) {
    num_records++;
  }

  fclose(fp);

  // Display the records
  printf("Records:\n");
  for (int i = 0; i < num_records; i++) {
    printf("%s, age %d, gender %c, occupation %s\n", records[i].name, records[i].age, records[i].gender, records[i].occupation);
  }

  // Search for a record by name
  char search_name[50];
  printf("Enter the name of the record you wish to search for: ");
  scanf("%s", search_name);

  int found = 0;
  for (int i = 0; i < num_records; i++) {
    if (strcmp(records[i].name, search_name) == 0) {
      printf("Record found:\n");
      printf("%s, age %d, gender %c, occupation %s\n", records[i].name, records[i].age, records[i].gender, records[i].occupation);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Record not found.\n");
  }

  return EXIT_SUCCESS;
}