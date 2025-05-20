#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char query[1024];
  scanf("%s", query);

  char key[1024];
  char value[1024];
  sscanf(query, "key=%s&value=%s", key, value);

  // Database query logic
  // ...

  printf("Record: key=%s, value=%s", key, value);

  return 0;
}
