#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char query[1024];
  scanf("%s", query);

  // Handle different field names
  if (strstr(query, "id=") != NULL) {
    // Search by ID
  } else if (strstr(query, "name=") != NULL) {
    // Search by name
  } else if (strstr(query, "age=") != NULL) {
    // Search by age
  } else if (strstr(query, "profession=") != NULL) {
    // Search by profession
  } else {
    // Invalid query
  }

  return 0;
}
