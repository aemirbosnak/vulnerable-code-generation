//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 30
#define MAX_DESCRIPTION_LEN 100

typedef struct {
  char name[MAX_NAME_LEN];
  char description[MAX_DESCRIPTION_LEN];
  int quantity;
  float price;
} Item;

typedef struct {
  char name[MAX_NAME_LEN];
  float balance;
  Item items[MAX_ITEMS];
  int num_items;
} Player;

void create_player(Player *player) {
  printf("Enter your name, lone wanderer: ");
  scanf("%s", player->name);

  player->balance = 0.0f;
  player->num_items = 0;
}

void add_item(Player *player) {
  Item item;

  printf("Enter the name of the item: ");
  scanf("%s", item.name);

  printf("Enter a brief description of the item: ");
  scanf("%s", item.description);

  printf("Enter the quantity of the item: ");
  scanf("%d", &item.quantity);

  printf("Enter the price of the item: ");
  scanf("%f", &item.price);

  player->items[player->num_items++] = item;
}

void remove_item(Player *player) {
  char name[MAX_NAME_LEN];

  printf("Enter the name of the item to remove: ");
  scanf("%s", name);

  for (int i = 0; i < player->num_items; i++) {
    if (strcmp(player->items[i].name, name) == 0) {
      player->items[i] = player->items[player->num_items - 1];
      player->num_items--;
      break;
    }
  }
}

void print_inventory(Player *player) {
  printf("Your inventory, %s:\n", player->name);

  for (int i = 0; i < player->num_items; i++) {
    printf("%s x%d (%s) - $%.2f\n", player->items[i].name, player->items[i].quantity,
           player->items[i].description, player->items[i].price);
  }

  printf("Total value: $%.2f\n", player->balance);
}

int main() {
  Player player;

  create_player(&player);

  while (1) {
    int choice;

    printf("\nWhat would you like to do, %s?\n", player.name);
    printf("1. Add an item to your inventory\n");
    printf("2. Remove an item from your inventory\n");
    printf("3. Print your inventory\n");
    printf("4. Quit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_item(&player);
        break;
      case 2:
        remove_item(&player);
        break;
      case 3:
        print_inventory(&player);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}