#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int light = 0, fan = 0, ac = 0;

  printf("Enter 'l' to toggle light, 'f' for fan, 'a' for AC: ");
  char input = getchar();

  switch (input) {
    case 'l':
      light = !light;
      break;
    case 'f':
      fan = !fan;
      break;
    case 'a':
      ac = !ac;
      break;
  }

  printf("Light: %d, Fan: %d, AC: %d\n", light, fan, ac);

  return 0;
}
