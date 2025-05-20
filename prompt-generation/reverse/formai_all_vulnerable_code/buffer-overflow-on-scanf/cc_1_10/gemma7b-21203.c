//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
  char name[50];
  int quantity;
  float price;
  struct Item* next;
} Item;

Item* addItem(Item* head, char* name, int quantity, float price) {
  Item* newNode = (Item*)malloc(sizeof(Item));
  strcpy(newNode->name, name);
  newNode->quantity = quantity;
  newNode->price = price;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void displayItems(Item* head) {
  Item* current = head;
  while (current) {
    printf("%s - %d - %.2f\n", current->name, current->quantity, current->price);
    current = current->next;
  }
}

int main() {
  Item* head = NULL;

  // Multiplayer Interaction
  char action;
  int itemQuantity;
  float itemPrice;
  char itemName[50];

  // Loop until the user chooses to quit
  while (1) {
    printf("Enter action (add/list/quit): ");
    scanf("%c", &action);

    switch (action) {
      case 'a':
        printf("Enter item name: ");
        scanf("%s", itemName);
        printf("Enter item quantity: ");
        scanf("%d", &itemQuantity);
        printf("Enter item price: ");
        scanf("%f", &itemPrice);
        addItem(head, itemName, itemQuantity, itemPrice);
        break;
      case 'l':
        displayItems(head);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}