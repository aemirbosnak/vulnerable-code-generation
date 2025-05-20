//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCK_NUM 10
#define MAX_TRANS_NUM 100

typedef struct Stock {
  char name[20];
  int current_price;
  int previous_price;
  int change;
  struct Stock* next;
} Stock;

typedef struct Transaction {
  char date[20];
  char stock_name[20];
  int quantity;
  int price;
  struct Transaction* next;
} Transaction;

Stock* insert_stock(Stock* head) {
  Stock* new_stock = (Stock*)malloc(sizeof(Stock));
  printf("Enter stock name: ");
  scanf("%s", new_stock->name);
  printf("Enter current price: ");
  scanf("%d", &new_stock->current_price);
  new_stock->previous_price = new_stock->current_price;
  new_stock->change = 0;
  new_stock->next = head;
  return new_stock;
}

Transaction* insert_transaction(Transaction* head) {
  Transaction* new_transaction = (Transaction*)malloc(sizeof(Transaction));
  printf("Enter date: ");
  scanf("%s", new_transaction->date);
  printf("Enter stock name: ");
  scanf("%s", new_transaction->stock_name);
  printf("Enter quantity: ");
  scanf("%d", &new_transaction->quantity);
  printf("Enter price: ");
  scanf("%d", &new_transaction->price);
  new_transaction->next = head;
  return new_transaction;
}

void calculate_stock_changes(Stock* head) {
  while (head) {
    head->change = head->current_price - head->previous_price;
    head = head->next;
  }
}

void print_stock_changes(Stock* head) {
  while (head) {
    printf("%s: %d\n", head->name, head->change);
    head = head->next;
  }
}

int main() {
  Stock* head = NULL;
  Transaction* head_trans = NULL;

  // Insert stocks
  head = insert_stock(head);
  insert_stock(head);

  // Insert transactions
  head_trans = insert_transaction(head_trans);
  insert_transaction(head_trans);

  // Calculate stock changes
  calculate_stock_changes(head);

  // Print stock changes
  print_stock_changes(head);

  return 0;
}