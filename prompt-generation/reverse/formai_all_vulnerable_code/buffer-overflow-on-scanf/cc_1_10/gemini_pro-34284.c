//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
// Welcome to the Enchanted Cafe Billing System!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our magical array of potion ingredients
char *ingredients[] = {"Moonstone Dust", "Unicorn Tears", "Dragon's Breath", "Mermaid Scales", "Phoenix Feathers"};

// The mystical menu of potions
char *potions[] = {"Potion of Courage", "Potion of Wisdom", "Potion of Healing", "Potion of Invisibility", "Potion of Love"};

// Our esteemed list of customers
char *customers[] = {"Merlin the Wizard", "Morgana the Sorceress", "King Arthur", "Gandalf the Grey", "Frodo Baggins"};

// The magical function to calculate potion prices
double calculatePotionPrice(int ingredient1, int ingredient2, int ingredient3) {
  double price = 10.0;  // Base price for a potion
  price += 5.0 * ingredient1;
  price += 3.0 * ingredient2;
  price += 1.0 * ingredient3;
  return price;
}

// The enchanting function to generate a potion name
char *generatePotionName(int ingredient1, int ingredient2, int ingredient3) {
  char *name = malloc(50);
  strcpy(name, potions[ingredient1]);
  strcat(name, " of ");
  strcat(name, ingredients[ingredient2]);
  strcat(name, " and ");
  strcat(name, ingredients[ingredient3]);
  return name;
}

// The mystical main function
int main() {
  // Welcome the customer to the cafe
  printf("Welcome to the Enchanted Cafe, %s!\n", customers[rand() % 5]);

  // Allow the customer to choose their ingredients
  int ingredient1, ingredient2, ingredient3;
  printf("Choose your first ingredient (1-5): ");
  scanf("%d", &ingredient1);
  ingredient1--;  // Adjust for 0-based indexing
  printf("Choose your second ingredient (1-5): ");
  scanf("%d", &ingredient2);
  ingredient2--;
  printf("Choose your third ingredient (1-5): ");
  scanf("%d", &ingredient3);
  ingredient3--;

  // Calculate the price of the potion
  double price = calculatePotionPrice(ingredient1, ingredient2, ingredient3);

  // Generate the name of the potion
  char *name = generatePotionName(ingredient1, ingredient2, ingredient3);

  // Print the receipt
  printf("\nYour potion, the %s, is ready!\n", name);
  printf("Price: %.2f\n", price);

  // End the magical experience
  printf("Thank you for visiting the Enchanted Cafe! Come again soon!\n");

  return 0;
}