#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[100];
  gets(input);

  if (strchr(input, ':-)') || strchr(input, ':-(')) {
    printf("Happy\n");
  } else if (strchr(input, '(Neutral)')) {
    printf("Neutral\n");
  } else {
    printf("Sad\n");
  }

  return 0;
}
