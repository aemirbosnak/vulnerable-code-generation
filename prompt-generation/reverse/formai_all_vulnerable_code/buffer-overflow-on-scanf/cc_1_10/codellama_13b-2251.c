//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
// Periodic Table Quiz Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure to represent an element
struct Element {
  char symbol[2];
  char name[20];
  int atomic_number;
  int atomic_mass;
};

// Array of elements
struct Element elements[118] = {
  {"H", "Hydrogen", 1, 1.00794},
  {"He", "Helium", 2, 4.002602},
  // ...
  {"U", "Uranium", 92, 238.02891},
  {"U", "Uranium", 93, 239.02891},
  {"U", "Uranium", 94, 239.02891},
  {"U", "Uranium", 95, 239.02891},
  {"U", "Uranium", 96, 239.02891},
  {"U", "Uranium", 97, 239.02891},
  {"U", "Uranium", 98, 239.02891},
  {"U", "Uranium", 99, 239.02891},
  {"U", "Uranium", 100, 239.02891},
  {"U", "Uranium", 101, 239.02891},
  {"U", "Uranium", 102, 239.02891},
  {"U", "Uranium", 103, 239.02891},
  {"U", "Uranium", 104, 239.02891},
  {"U", "Uranium", 105, 239.02891},
  {"U", "Uranium", 106, 239.02891},
  {"U", "Uranium", 107, 239.02891},
  {"U", "Uranium", 108, 239.02891},
  {"U", "Uranium", 109, 239.02891},
  {"U", "Uranium", 110, 239.02891},
  {"U", "Uranium", 111, 239.02891},
  {"U", "Uranium", 112, 239.02891},
  {"U", "Uranium", 113, 239.02891},
  {"U", "Uranium", 114, 239.02891},
  {"U", "Uranium", 115, 239.02891},
  {"U", "Uranium", 116, 239.02891},
  {"U", "Uranium", 117, 239.02891},
  {"U", "Uranium", 118, 239.02891}
};

// Function to get a random element
struct Element get_random_element() {
  // Get a random index between 0 and 117
  int index = rand() % 118;
  // Return the element at the random index
  return elements[index];
}

// Function to check if the user's guess is correct
int check_guess(struct Element element, char guess) {
  // Check if the guess is equal to the element's symbol
  if (element.symbol[0] == guess) {
    return 1;
  }
  // Check if the guess is equal to the element's name
  if (strcmp(element.name, guess) == 0) {
    return 1;
  }
  // If the guess is not equal to the element's symbol or name, return 0
  return 0;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Get a random element
  struct Element element = get_random_element();

  // Print the element's atomic number and mass
  printf("Atomic number: %d\nAtomic mass: %d\n", element.atomic_number, element.atomic_mass);

  // Get the user's guess
  char guess;
  printf("Enter the symbol or name of the element: ");
  scanf("%c", &guess);

  // Check if the user's guess is correct
  int result = check_guess(element, guess);

  // Print the result
  if (result == 1) {
    printf("Correct!\n");
  } else {
    printf("Incorrect.\n");
  }

  return 0;
}