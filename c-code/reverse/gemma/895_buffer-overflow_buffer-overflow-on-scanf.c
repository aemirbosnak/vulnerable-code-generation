#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char name[100];
  scanf("Enter your name: ", name);

  if (strlen(name) > 20) {
    printf("Error: Name too long. Please try again.\n");
    return 1;
  }

  printf("Welcome, %s, to the haunted house.\n", name);

  // Branching narrative based on user input
  printf("You hear a noise in the hallway. What do you do? (Press 1 for investigation, 2 for escape): ");
  int choice = 0;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You investigate and find a ghostly figure. The figure offers you a choice: you can either fight or flee. What do you do? (Press 1 for fight, 2 for flee): ");
      int subchoice = 0;
      scanf("%d", &subchoice);

      if (subchoice == 1) {
        printf("You fight the ghostly figure and win. You escape the haunted house.\n");
      } else if (subchoice == 2) {
        printf("You flee and escape the haunted house.\n");
      } else {
        printf("Invalid input. Please try again.\n");
      }
      break;
    case 2:
      printf("You escape the haunted house. You are safe.\n");
      break;
    default:
      printf("Invalid input. Please try again.\n");
  }

  return 0;
}
