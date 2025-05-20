#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int searchRecords(int id, char* name) {
  // Assuming a database of records with fields id and name
  // Replace this with actual database access code
  if (id == 10 && strcmp(name, "John Doe") == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int id;
  char name[20];

  printf("Enter search criteria:");
  scanf("%d %s", &id, name);

  if (searchRecords(id, name) == 1) {
    printf("Record found!");
  } else {
    printf("No record found.");
  }

  return 0;
}
