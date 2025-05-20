//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
// C Periodic Table Quiz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the elements
#define NUM_ELEMENTS 118
char elements[NUM_ELEMENTS][20] = {
  "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
  "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon",
  "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
  "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron",
  "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic",
  "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium",
  "Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium",
  "Iridium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium",
  "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium",
  "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium", "Plutonium",
  "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
  "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
  "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
  "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium",
  "Tennessine", "Oganesson"
};

// Define the answers
#define NUM_QUESTIONS 10
char answers[NUM_QUESTIONS][20] = {
  "Hydrogen", "Carbon", "Oxygen", "Nitrogen", "Sodium", "Magnesium",
  "Aluminum", "Silicon", "Phosphorus", "Sulfur"
};

// Generate random questions
int main() {
  int i, j;
  char input[20];

  srand(time(NULL));

  for (i = 0; i < NUM_QUESTIONS; i++) {
    j = rand() % NUM_ELEMENTS;
    printf("What is the name of the %dth element?\n", j + 1);
    scanf("%s", input);
    if (strcmp(input, answers[i]) == 0) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The answer is %s.\n", elements[j]);
    }
  }

  return 0;
}