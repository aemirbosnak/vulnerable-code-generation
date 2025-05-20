//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: curious
// Welcome to the whimsical world of warehouse management!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our warehouse is a magical place filled with curious items.
typedef struct {
  char name[32];
  int quantity;
  float price;
  char description[128];
} Item;

// Every item has its own unique story.
Item items[] = {
  {"Rusty Sword", 5, 10.99, "Once belonged to a legendary warrior."},
  {"Crystal Ball", 1, 19.99, "Whispers secrets of the future."},
  {"Potion of Healing", 10, 5.99, "Restores health and vigor."},
  {"Tome of Spells", 3, 14.99, "Contains ancient and forbidden knowledge."},
  {"Golden Amulet", 1, 29.99, "Grants the power of persuasion."},
  {"Bag of Holding", 10, 9.99, "Can hold an infinite amount of items."},
  {"Staff of Wisdom", 1, 49.99, "Imparts wisdom and knowledge upon its wielder."},
  {"Horn of Summoning", 3, 24.99, "Summons allies or creatures from distant lands."},
  {"Cloak of Invisibility", 1, 39.99, "Renders its wearer invisible to the naked eye."},
  {"Ring of Power", 1, 99.99, "Controls the minds and hearts of mortals."},
};

// Our warehouse is a vibrant and ever-changing place.
int main() {
  printf("Welcome to the Enchanted Warehouse! Where the curious and unusual come together.\n");

  // Let's explore the items in our warehouse.
  printf("Behold, our collection of magical marvels:\n");
  for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
    printf(" - %s: %d in stock, %.2f gold each.\n", items[i].name, items[i].quantity, items[i].price);
  }

  // A wizard approaches the counter, seeking a mystical artifact.
  int wizardChoice;
  printf("\nGreetings, wise wizard! What item do you seek today?\n");
  printf("Enter the corresponding number to add it to your cart:\n");
  for (int i = 0; i < sizeof(items) / sizeof(Item); i++) {
    printf("  %d. %s\n", i + 1, items[i].name);
  }
  scanf("%d", &wizardChoice);

  // The wizard examines the mystical artifact, marveling at its powers.
  printf("\nBehold, the %s! Its %s will surely aid you in your adventures.\n",
         items[wizardChoice - 1].name, items[wizardChoice - 1].description);

  // The wizard pays for the artifact, his eyes gleaming with anticipation.
  float payment;
  printf("That will be %.2f gold. How would you like to pay?\n", items[wizardChoice - 1].price);
  scanf("%f", &payment);

  // The wizard bids farewell, the mystical artifact in hand.
  printf("\nMay the %s serve you well! Farewell, wizard, and may your adventures be filled with wonder.\n",
         items[wizardChoice - 1].name);

  return 0;
}