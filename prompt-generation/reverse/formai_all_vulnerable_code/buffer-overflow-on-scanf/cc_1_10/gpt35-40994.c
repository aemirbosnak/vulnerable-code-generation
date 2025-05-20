//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearScreen() {
  system("cls||clear");
}

// Function to display the periodic table
void displayTable() {
  clearScreen();
  printf("Here is the periodic table:\n\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|     H | He                                                             |\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|Li | Be                                   |  B |  C |  N |  O |  F | Ne |  \n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|Na | Mg                                   | Al | Si |  P |  S | Cl | Ar |\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|K  | Ca | Sc | Ti | V  |Cr  |Mn  |Fe  |Co  |Ni  |Cu  |Zn  |Ga  |Ge  |As  |Se | Br | Kr |\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|Rb |Sr | Y | Zr | Nb | Mo | Tc |Ru |Rh | Pd |Ag  |Cd  |In  |Sn  |Sb  |Te | I |Xe |\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|Cs |Ba                                    | Hf | Ta | W  | Re |Os  |Ir  |Pt  |Au |Hg  |Tl  |Pb  |Bi  |Po  |At | Rn |\n");
  printf("|----------------------------------------------------------------------|\n");
  printf("|Fr |Ra                                    | Rf | Db | Sg | Bh | Hs | Mt | Ds |Rg |Cn  |Nh  |Fl  |Mc  |Lv  |Ts | Og |\n");
  printf("|----------------------------------------------------------------------|\n");
}

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Welcome message
  printf("Welcome to the Periodic Table Quiz!\n\n");
  printf("You will be given a chemical symbol and you need to guess the corresponding element.\n\n");
  printf("Enter 'quit' to exit the game.\n\n");

  // Array of chemical symbols and their corresponding elements
  char *symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

  // Calculate number of symbols
  int numSymbols = sizeof(symbols) / sizeof(symbols[0]);

  // Main game loop
  while (1) {
    // Generate random symbol
    int index = rand() % numSymbols;
    char *symbol = symbols[index];

    // Display the periodic table
    displayTable();

    // Get user input
    printf("Enter the element corresponding to the symbol '%s': ", symbol);
    char guess[3];
    scanf("%s", guess);

    // Check if user wants to quit
    if (strcmp(guess, "quit") == 0) {
      break;
    }

    // Check if guess is correct
    if (strcmp(guess, symbols[index + 1]) == 0) {
      printf("Correct!\n\n");
    } else {
      printf("Incorrect. The correct answer is '%s'.\n\n", symbols[index + 1]);
    }
  }

  return 0;
}