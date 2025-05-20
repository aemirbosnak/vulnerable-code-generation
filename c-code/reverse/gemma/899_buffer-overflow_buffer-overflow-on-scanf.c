#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int choice;

  printf("You are in a forest. You see two paths, one to the left and one to the right.\n");
  printf("Enter 1 to go left or 2 to go right: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You go left and encounter a dragon.\n");
      break;
    case 2:
      printf("You go right and find a hidden treasure.\n");
      break;
    default:
      printf("Invalid input.\n");
  }

  return 0;
}
