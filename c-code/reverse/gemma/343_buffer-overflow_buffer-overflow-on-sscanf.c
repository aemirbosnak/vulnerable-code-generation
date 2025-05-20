#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  // Define an array of records
  struct record {
    int id;
    char name[20];
    int age;
    char profession[20];
  } records[] = {
    {1, "John Doe", 25, "Software Engineer"},
    {2, "Jane Doe", 30, "Teacher"},
    {3, "Peter Pan", 12, "Student"},
    {4, "Mary Poppins", 40, "Nurse"}
  };

  // Get the query string from the user
  char query[100];
  printf("Enter a query: ");
  scanf("%s", query);

  // Parse the query string using sscanf
  char field[20];
  int value;
  sscanf(query, "query %s = %d", field, &value);

  // Find all matching records
  for (int i = 0; i < 4; i++) {
    if (strcmp(records[i].name, field) == 0 && records[i].age == value) {
      // Print the matching record
      printf("ID: %d, Name: %s, Age: %d, Profession: %s\n", records[i].id, records[i].name, records[i].age, records[i].profession);
    }
  }

  return 0;
}
