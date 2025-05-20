#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int choice;

  printf("Welcome to the Smart Home System!\n");
  printf("Please select an option:\n");
  printf("1. Lights\n");
  printf("2. Fan\n");
  printf("3. AC Unit\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("Lights are turned on.\n");
      break;
    case 2:
      printf("Fan is turned on.\n");
      break;
    case 3:
      printf("AC unit is turned on.\n");
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}
