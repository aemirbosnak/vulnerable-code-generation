//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 10
#define BAG_SIZE 20

typedef struct Bag {
  char **items;
  int num_items;
} Bag;

Bag **bags = NULL;

void handle_baggage() {
  int i, j, num_bags = 0;
  char item[20];

  // Calculate the number of bags
  for (i = 0; bags[i] != NULL; i++) {
    num_bags++;
  }

  // Create a new bag if needed
  if (num_bags == MAX_BAGS) {
    printf("No more bags can be added.\n");
  } else {
    bags[num_bags] = malloc(sizeof(Bag));
    bags[num_bags]->items = malloc(sizeof(char *) * BAG_SIZE);
    bags[num_bags]->num_items = 0;

    printf("Enter item name: ");
    scanf("%s", item);

    // Add the item to the bag
    bags[num_bags]->items[bags[num_bags]->num_items++] = item;

    printf("Item added successfully.\n");
  }
}

int main() {
  int choice;

  // Menu loop
  while (1) {
    printf("Please select an option:\n");
    printf("1. Add item to baggage\n");
    printf("2. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        handle_baggage();
        break;
      case 2:
        exit(0);
    }
  }

  return 0;
}