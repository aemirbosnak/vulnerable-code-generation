#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char statement[100];
  gets(statement);

  if (strstr(statement, ":)") || strstr(statement, ":)") || strstr(statement, ";)")) {
    printf("Happy\n");
  } else if (strstr(statement, ":(") || strstr(statement, ":(") || strstr(statement, ";(")) {
    printf("Sad\n");
  } else {
    printf("Neutral\n");
  }

  return 0;
}
