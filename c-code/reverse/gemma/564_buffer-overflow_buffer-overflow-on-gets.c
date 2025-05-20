#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1024];
  gets(str);

  if (strlen(str) > 1024) {
    return 1;
  }

  if (strcmp(str, "keyword1") == 0) {
    // Do something
  } else if (strcmp(str, "keyword2") == 0) {
    // Do something
  } else if (strcmp(str, "keyword3") == 0) {
    // Do something
  } else {
    return 1;
  }

  return 0;
}
