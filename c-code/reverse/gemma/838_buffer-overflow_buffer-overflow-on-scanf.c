#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void addComponent(char *type, int value);

int main() {
  int choice;

  printf("Menu:\n");
  printf("1. Add Component\n");
  printf("2. Exit\n");

  scanf(" %d ", &choice);

  switch (choice) {
    case 1:
      char type[20];
      int value;

      printf("Enter component type: ");
      scanf(" %s ", type);

      printf("Enter component value: ");
      scanf(" %d ", &value);

      addComponent(type, value);
      break;
    case 2:
      exit(0);
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}

void addComponent(char *type, int value) {
  // Vulnerable code: does not validate the length of 'type'
  strcpy(type, "Component");
  // ...
}
