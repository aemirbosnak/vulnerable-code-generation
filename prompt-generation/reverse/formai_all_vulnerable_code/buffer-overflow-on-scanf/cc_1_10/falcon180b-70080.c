//Falcon-180B DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice;

  printf("In a post-apocalyptic world, you are a scavenger trying to survive.\n");
  printf("You find a mysterious device that can grant you one wish.\n");
  printf("What do you wish for?\n");
  printf("1. Food\n");
  printf("2. Water\n");
  printf("3. Shelter\n");
  printf("4. Companionship\n");
  printf("5. Protection\n");
  printf("6. Knowledge\n");
  printf("7. Power\n");
  printf("8. Freedom\n");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      printf("You wish for food.\n");
      break;
    case 2:
      printf("You wish for water.\n");
      break;
    case 3:
      printf("You wish for shelter.\n");
      break;
    case 4:
      printf("You wish for companionship.\n");
      break;
    case 5:
      printf("You wish for protection.\n");
      break;
    case 6:
      printf("You wish for knowledge.\n");
      break;
    case 7:
      printf("You wish for power.\n");
      break;
    case 8:
      printf("You wish for freedom.\n");
      break;
    default:
      printf("Invalid choice.\n");
      exit(1);
  }

  return 0;
}