//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
  char name[50];
  int quantity;
  float price;
} item_t;

typedef struct {
  item_t items[MAX_ITEMS];
  int num_items;
  float total;
} bill_t;

void add_item(bill_t *bill, item_t item) {
  if (bill->num_items == MAX_ITEMS) {
    printf("Error: cannot add item to bill, bill is already full\n");
    return;
  }
  bill->items[bill->num_items++] = item;
}

void print_bill(bill_t *bill) {
  printf("Bill:\n");
  for (int i = 0; i < bill->num_items; i++) {
    printf("  %s x %d = %.2f\n", bill->items[i].name, bill->items[i].quantity, bill->items[i].price * bill->items[i].quantity);
  }
  printf("Total: %.2f\n", bill->total);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Error: must provide a file name as the first argument\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error: could not open file %s\n", argv[1]);
    return 1;
  }
  bill_t bill;
  bill.num_items = 0;
  bill.total = 0.0;
  char line[100];
  while (fgets(line, sizeof(line), fp) != NULL) {
    item_t item;
    int n = sscanf(line, "%s %d %f", item.name, &item.quantity, &item.price);
    if (n != 3) {
      printf("Error: could not parse line %s\n", line);
      continue;
    }
    add_item(&bill, item);
    bill.total += item.quantity * item.price;
  }
  fclose(fp);
  print_bill(&bill);
  return 0;
}