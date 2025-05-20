//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer {
  char name[100];
  int table;
  int order[10];
  int total_items;
  float total_cost;
};

int main() {
  struct customer c;

  printf("\n\t\t***Welcome to Our Cafe Billing System***\n\n");
  printf("Please provide us with your name: ");
  fgets(c.name, 100, stdin);

  printf("What table would you like to sit at? ");
  scanf("%d", &c.table);

  printf("\nPlease enter each item you would like to order followed by the quantity (ex. 'Coffee 2', 'Croissant 1', etc.)\nEnter 'Done' when you are finished:\n");
  int i = 0;
  char input[100];
  float total_cost = 0.0;
  while (1) {
    printf("> ");
    fgets(input, 100, stdin);
    if (strcmp(input, "Done\n") == 0) {
      break;
    }
    char *ptr;
    char *item;
    int quantity;
    item = strtok(input, " ");
    quantity = atoi(strtok(NULL, " "));

    if (strcmp(item, "Coffee") == 0) {
      total_cost += 2.5 * quantity;
    } else if (strcmp(item, "Latte") == 0) {
      total_cost += 3.5 * quantity;
    } else if (strcmp(item, "Croissant") == 0) {
      total_cost += 2.0 * quantity;
    } else if (strcmp(item, "Sandwich") == 0) {
      total_cost += 4.5 * quantity;
    }

    c.order[i] = quantity;
    i++;
  }

  c.total_items = i; 
  c.total_cost = total_cost;

  printf("\nThank you %s, your bill for Table %d is:\n", c.name, c.table);
  for (int j = 0; j < c.total_items; j++) {
    if (c.order[j] != 0) {
      printf("%d x Item %d\n", c.order[j], j + 1);
    }
  }
  printf("Total cost: $%.2f", c.total_cost);

  return 0;
}