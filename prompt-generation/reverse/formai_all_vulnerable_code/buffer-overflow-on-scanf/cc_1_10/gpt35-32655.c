//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Define elements struct
typedef struct {
  char symbol[3];
  char name[20];
  int atomic_number;
} element;

// Define periodic table as array of elements
const element periodic_table[] = {
  {"H", "Hydrogen", 1},
  {"He", "Helium", 2},
  {"Li", "Lithium", 3},
  {"Be", "Beryllium", 4},
  {"B", "Boron", 5},
  {"C", "Carbon", 6},
  {"N", "Nitrogen", 7},
  {"O", "Oxygen", 8},
  {"F", "Fluorine", 9},
  {"Ne", "Neon", 10},
  // Add more elements here
};

// Function to get element by symbol
element get_element(char* symbol) {
  // Loop through periodic table and search for element with matching symbol
  for (int i = 0; i < sizeof(periodic_table) / sizeof(element); i++) {
    if (strcmp(periodic_table[i].symbol, symbol) == 0) {
      return periodic_table[i];
    }
  }
  // If no element found, return error element
  return (element){"Xx", "Unknown Element", -1};
}

int main() {
  // Prompt user to enter element symbol
  printf("Enter an element symbol: ");
  char symbol[3];
  scanf("%s", symbol);

  // Get element by symbol
  element e = get_element(symbol);

  // Check if element found or not
  if (strcmp(e.symbol, "Xx") == 0) {
    printf("Error: Element not found!\n");
    return 1;
  }

  // Print element information
  printf("\nElement Name: %s\n", e.name);
  printf("Atomic Number: %d\n", e.atomic_number);

  return 0;
}