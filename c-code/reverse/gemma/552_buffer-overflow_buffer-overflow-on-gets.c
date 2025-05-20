#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[1024];
  gets(input);

  if (strstr(input, ":)") && strstr(input, ":(")) {
    printf("Neutral\n");
  } else if (strstr(input, ":)") || strstr(input, ":)")) {
    printf("Happy\n");
  } else if (strstr(input, ":(")) {
    printf("Sad\n");
  } else {
    printf("Invalid input\n");
  }

  return 0;
}
