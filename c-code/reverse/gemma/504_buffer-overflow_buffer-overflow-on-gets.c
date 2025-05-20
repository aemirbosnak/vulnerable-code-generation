#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char name[100];
  gets(name);

  int length = strlen(name);
  int i = 0;
  int probability = 0;

  if (length > 20) {
    probability = 100;
  } else if (length > 10) {
    probability = 50;
  } else if (length > 5) {
    probability = 25;
  } else {
    probability = 0;
  }

  printf("Your alien invasion probability is: %d%%", probability);
  return 0;
}
