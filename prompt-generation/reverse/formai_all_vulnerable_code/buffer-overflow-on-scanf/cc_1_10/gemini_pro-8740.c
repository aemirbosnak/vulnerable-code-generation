//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  int id;
  char *name;
  int quantity;
  float price;
};

struct node {
  struct product *data;
  struct node *next;
};

struct linkedlist {
  struct node *head;
};

struct linkedlist *create_linkedlist() {
  struct linkedlist *list = (struct linkedlist *)malloc(sizeof(struct linkedlist));
  list->head = NULL;
  return list;
}

void insert_product(struct linkedlist *list, struct product *product) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = product;
  new_node->next = list->head;
  list->head = new_node;
}

struct product *get_product_by_id(struct linkedlist *list, int id) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    if (current_node->data->id == id) {
      return current_node->data;
    }
    current_node = current_node->next;
  }
  return NULL;
}

void print_product(struct product *product) {
  printf("Id: %d\n", product->id);
  printf("Name: %s\n", product->name);
  printf("Quantity: %d\n", product->quantity);
  printf("Price: %.2f\n\n", product->price);
}

void print_linkedlist(struct linkedlist *list) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    print_product(current_node->data);
    current_node = current_node->next;
  }
}

int main() {
  struct linkedlist *inventory = create_linkedlist();

  struct product *product1 = (struct product *)malloc(sizeof(struct product));
  product1->id = 1;
  product1->name = "Rose";
  product1->quantity = 100;
  product1->price = 1.99;
  insert_product(inventory, product1);

  struct product *product2 = (struct product *)malloc(sizeof(struct product));
  product2->id = 2;
  product2->name = "Chocolate";
  product2->quantity = 50;
  product2->price = 2.99;
  insert_product(inventory, product2);

  struct product *product3 = (struct product *)malloc(sizeof(struct product));
  product3->id = 3;
  product3->name = "Teddy Bear";
  product3->quantity = 25;
  product3->price = 9.99;
  insert_product(inventory, product3);

  printf("My Dearest Love,\n\n");
  printf("Let us embark on a romantic journey through our love inventory.\n\n");
  print_linkedlist(inventory);

  printf("My heart yearns for the exquisite beauty of roses. How many would you like, my love?\n");
  int rose_quantity;
  scanf("%d", &rose_quantity);

  struct product *roses = get_product_by_id(inventory, 1);
  if (roses->quantity >= rose_quantity) {
    printf("Your wish is my command, my love. I shall eagerly pick %d roses for you.\n", rose_quantity);
    roses->quantity -= rose_quantity;
  } else {
    printf("Alas, my love, we only have %d roses left. May I suggest another token of my affection?\n", roses->quantity);
  }

  printf("In your absence, I long for the sweet taste of chocolate. How many chocolates would make your heart flutter?\n");
  int chocolate_quantity;
  scanf("%d", &chocolate_quantity);

  struct product *chocolates = get_product_by_id(inventory, 2);
  if (chocolates->quantity >= chocolate_quantity) {
    printf("Your wish is my desire, my love. I shall indulge in %d chocolates with you.\n", chocolate_quantity);
    chocolates->quantity -= chocolate_quantity;
  } else {
    printf("My love, we only have %d chocolates left. May I offer you a different treat?\n", chocolates->quantity);
  }

  printf("May I envelop you in the warmth of a teddy bear hug? How many would you like, my darling?\n");
  int teddy_bear_quantity;
  scanf("%d", &teddy_bear_quantity);

  struct product *teddy_bears = get_product_by_id(inventory, 3);
  if (teddy_bears->quantity >= teddy_bear_quantity) {
    printf("Your wish is my embrace. I shall cuddle you with %d teddy bears.\n", teddy_bear_quantity);
    teddy_bears->quantity -= teddy_bear_quantity;
  } else {
    printf("My love, we only have %d teddy bears left. May I suggest another way to show my affection?\n", teddy_bears->quantity);
  }

  printf("My love for you is as boundless as the stars in the night sky. May this inventory of our love tokens bring us endless joy and cherish our memories forever.\n\n");
  printf("With love and adoration,\n\n");
  printf("Your Valentine\n");

  return 0;
}