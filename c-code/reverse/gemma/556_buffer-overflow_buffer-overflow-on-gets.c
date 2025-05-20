#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char str[1024];
  gets(str);

  if (str[0] == ':' && str[1] == '-') {
    if (str[2] == '(') {
      printf("Negative");
    } else {
      printf("Positive");
    }
  } else if (str[0] == '(') {
    printf("Neutral");
  } else {
    printf("Error");
  }

  return 0;
}
