//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>

// Define the resources available
#define GOLD 100
#define SILVER 50
#define COPPER 25

// Define the items that can be purchased
#define SWORD 10
#define ARMOR 15
#define HEALING_POTION 5

// Define the player's inventory
int gold = 0;
int silver = 0;
int copper = 0;
int sword = 0;
int armor = 0;
int healing_potions = 0;

// Function to purchase an item
void purchase(int item) {
  switch (item) {
    case SWORD:
      if (gold >= SWORD) {
        gold -= SWORD;
        sword++;
      }
      break;
    case ARMOR:
      if (gold >= ARMOR) {
        gold -= ARMOR;
        armor++;
      }
      break;
    case HEALING_POTION:
      if (gold >= HEALING_POTION) {
        gold -= HEALING_POTION;
        healing_potions++;
      }
      break;
  }
}

// Function to sell an item
void sell(int item) {
  switch (item) {
    case SWORD:
      if (sword > 0) {
        gold += SWORD;
        sword--;
      }
      break;
    case ARMOR:
      if (armor > 0) {
        gold += ARMOR;
        armor--;
      }
      break;
    case HEALING_POTION:
      if (healing_potions > 0) {
        gold += HEALING_POTION;
        healing_potions--;
      }
      break;
  }
}

// Function to display the player's inventory
void display_inventory() {
  printf("Your inventory:\n");
  printf("Gold: %d\n", gold);
  printf("Silver: %d\n", silver);
  printf("Copper: %d\n", copper);
  printf("Sword: %d\n", sword);
  printf("Armor: %d\n", armor);
  printf("Healing potions: %d\n", healing_potions);
}

// Main function
int main() {
  // Initialize the player's inventory
  gold = GOLD;
  silver = SILVER;
  copper = COPPER;

  // Display the player's inventory
  display_inventory();

  // Prompt the player to purchase an item
  printf("What item would you like to purchase? (sword, armor, healing potion)\n");
  char item[20];
  scanf("%s", item);

  // Purchase the item
  if (strcmp(item, "sword") == 0) {
    purchase(SWORD);
  } else if (strcmp(item, "armor") == 0) {
    purchase(ARMOR);
  } else if (strcmp(item, "healing potion") == 0) {
    purchase(HEALING_POTION);
  }

  // Display the player's inventory
  display_inventory();

  return 0;
}