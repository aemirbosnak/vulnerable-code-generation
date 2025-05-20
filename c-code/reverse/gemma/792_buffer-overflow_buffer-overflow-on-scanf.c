#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  char input[10];
  switch (scanf("%s", input)) {
    case 1:
      // Accelerate
      break;
    case 2:
      // Brake
      break;
    case 3:
      // Turn left
      break;
    case 4:
      // Turn right
      break;
    case 5:
      // Stop
      break;
    case 6:
      // Change gear
      break;
    case 7:
      // Open hood
      break;
    case 8:
      // Open trunk
      break;
    case 9:
      // Honk horn
      break;
    default:
      // Invalid input
      break;
  }
  return 0;
}
