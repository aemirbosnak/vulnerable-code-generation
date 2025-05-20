//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Knights' Phone Book

struct knight {
  char name[50];
  char kingdom[50];
  int strength;
};

int main() {
  struct knight knights[5];
  int i;

  // Load the knights into the phone book
  for (i = 0; i < 5; i++) {
    printf("Enter the name of the next knight: ");
    fgets(knights[i].name, 50, stdin);
    printf("Enter the kingdom of the next knight: ");
    fgets(knights[i].kingdom, 50, stdin);
    printf("Enter the strength of the next knight: ");
    scanf("%d", &knights[i].strength);
  }

  // Search the phone book for a knight
  printf("Searching for a knight...\n");
  for (i = 0; i < 5; i++) {
    if (strcmp(knights[i].name, "Sir Cedric") == 0) {
      printf("Sir Cedric the Brave has a strength of %d\n", knights[i].strength);
      break;
    }
  }

  // Add a new knight to the phone book
  printf("Adding a new knight...\n");
  struct knight new_knight;
  printf("Enter the name of the new knight: ");
  fgets(new_knight.name, 50, stdin);
  printf("Enter the kingdom of the new knight: ");
  fgets(new_knight.kingdom, 50, stdin);
  printf("Enter the strength of the new knight: ");
  scanf("%d", &new_knight.strength);
  knights[5] = new_knight;

  // Remove a knight from the phone book
  printf("Removing a knight...\n");
  int remove_index;
  printf("Enter the index of the knight to remove: ");
  scanf("%d", &remove_index);
  if (remove_index < 5) {
    memmove(knights, knights + remove_index, (5 - remove_index) * sizeof(struct knight));
    --remove_index;
    knights[remove_index].name[0] = '\0';
    knights[remove_index].kingdom[0] = '\0';
    knights[remove_index].strength = 0;
  }

  // Print the phone book
  printf("Phone Book:\n");
  for (i = 0; i < 5; i++) {
    printf("  %s %s %d\n", knights[i].name, knights[i].kingdom, knights[i].strength);
  }

  return 0;
}