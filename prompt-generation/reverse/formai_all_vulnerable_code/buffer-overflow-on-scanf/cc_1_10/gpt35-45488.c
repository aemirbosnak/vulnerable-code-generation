//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
  char name[30];
  int quantity;
  float price;
};

struct node {
  struct item data;
  struct node *next;
};

typedef struct node NODE;
NODE *head = NULL;

void add_item() {
  NODE *new_node = (NODE*) malloc(sizeof(NODE));
  printf("Enter name of item: ");
  scanf("%s", new_node->data.name);
  printf("Enter quantity: ");
  scanf("%d", &new_node->data.quantity);
  printf("Enter price: ");
  scanf("%f", &new_node->data.price);
  new_node->next = head;
  head = new_node;
}

void display_items() {
  NODE *current = head;
  printf("%-30s%-10s%-10s\n", "Item", "Quantity", "Price");
  while(current != NULL) {
    printf("%-30s%-10d%-10.2f\n", current->data.name, current->data.quantity, current->data.price);
    current = current->next;
  }
}

void menu() {
  printf("\n1. Add item\n");
  printf("2. Display items\n");
  printf("3. Exit\n");
  printf("Enter choice: ");
}

int main() {
  int choice;
  do {
    menu();
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        add_item();
        break;
      case 2:
        display_items();
        break;
      case 3:
        printf("\nThank you for using our surreal medical store management system!\n");
        break;
      default:
        printf("\nInvalid choice!\n");
    }
  } while(choice != 3);
  return 0;
}