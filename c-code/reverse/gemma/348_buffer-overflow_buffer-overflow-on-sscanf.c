#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int query_database(char *search_criteria) {
  // Replace "my_database" with the actual name of your database
  FILE *database = fopen("my_database", "r");
  if (database == NULL) {
    return -1;
  }

  char *record = NULL;
  int record_size = 0;
  while (getline(database, record, &record_size) != -1) {
    // Compare the record with the search criteria
    if (strstr(record, search_criteria) != NULL) {
      // Print the record
      printf("%s\n", record);
    }
  }

  fclose(database);
  return 0;
}

int main() {
  char *search_criteria = "John Doe";
  int result = query_database(search_criteria);
  if (result == -1) {
    printf("Error querying database.\n");
  } else {
    printf("Records matching search criteria:\n");
  }

  return 0;
}
