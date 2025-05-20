#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int choice;

  printf("Smart Home System Menu:\n");
  printf("1. Toggle Lights\n");
  printf("2. Control Fan\n");
  printf("3. Adjust AC Unit\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      // Logic to toggle lights
      break;
    case 2:
      // Logic to control fan
      break;
    case 3:
      // Logic to adjust AC unit
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
