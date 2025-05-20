//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

struct element {
  int atomic_number;
  char symbol[3];
  char name[20];
  int period;
  int group;
};

struct element elements[MAX_ELEMENTS] = {{1, "H", "Hydrogen", 1, 1}, {2, "He", "Helium", 1, 18},
                                          {3, "Li", "Lithium", 2, 1}, {4, "Be", "Beryllium", 2, 2},
                                          {5, "B", "Boron", 2, 13}, {6, "C", "Carbon", 2, 14},
                                          {7, "N", "Nitrogen", 2, 15}, {8, "O", "Oxygen", 2, 16},
                                          {9, "F", "Fluorine", 2, 17}, {10, "Ne", "Neon", 2, 18},
                                          {11, "Na", "Sodium", 3, 1}, {12, "Mg", "Magnesium", 3, 2},
                                          {13, "Al", "Aluminum", 3, 13}, {14, "Si", "Silicon", 3, 14},
                                          {15, "P", "Phosphorus", 3, 15}, {16, "S", "Sulfur", 3, 16},
                                          {17, "Cl", "Chlorine", 3, 17}, {18, "Ar", "Argon", 3, 18},
                                          {19, "K", "Potassium", 4, 1}, {20, "Ca", "Calcium", 4, 2},
                                          {21, "Sc", "Scandium", 4, 3}, {22, "Ti", "Titanium", 4, 4},
                                          {23, "V", "Vanadium", 4, 5}, {24, "Cr", "Chromium", 4, 6},
                                          {25, "Mn", "Manganese", 4, 7}, {26, "Fe", "Iron", 4, 8},
                                          {27, "Co", "Cobalt", 4, 9}, {28, "Ni", "Nickel", 4, 10},
                                          {29, "Cu", "Copper", 4, 11}, {30, "Zn", "Zinc", 4, 12},
                                          {31, "Ga", "Gallium", 4, 13}, {32, "Ge", "Germanium", 4, 14},
                                          {33, "As", "Arsenic", 4, 15}, {34, "Se", "Selenium", 4, 16},
                                          {35, "Br", "Bromine", 4, 17}, {36, "Kr", "Krypton", 4, 18},
                                          {37, "Rb", "Rubidium", 5, 1}, {38, "Sr", "Strontium", 5, 2},
                                          {39, "Y", "Yttrium", 5, 3}, {40, "Zr", "Zirconium", 5, 4},
                                          {41, "Nb", "Niobium", 5, 5}, {42, "Mo", "Molybdenum", 5, 6},
                                          {43, "Tc", "Technetium", 5, 7}, {44, "Ru", "Ruthenium", 5, 8},
                                          {45, "Rh", "Rhodium", 5, 9}, {46, "Pd", "Palladium", 5, 10},
                                          {47, "Ag", "Silver", 5, 11}, {48, "Cd", "Cadmium", 5, 12},
                                          {49, "In", "Indium", 5, 13}, {50, "Sn", "Tin", 5, 14},
                                          {51, "Sb", "Antimony", 5, 15}, {52, "Te", "Tellurium", 5, 16},
                                          {53, "I", "Iodine", 5, 17}, {54, "Xe", "Xenon", 5, 18},
                                          {55, "Cs", "Cesium", 6, 1}, {56, "Ba", "Barium", 6, 2},
                                          {57, "La", "Lanthanum", 6, 3}, {58, "Ce", "Cerium", 6, 4},
                                          {59, "Pr", "Praseodymium", 6, 5}, {60, "Nd", "Neodymium", 6, 6},
                                          {61, "Pm", "Promethium", 6, 7}, {62, "Sm", "Samarium", 6, 8},
                                          {63, "Eu", "Europium", 6, 9}, {64, "Gd", "Gadolinium", 6, 10},
                                          {65, "Tb", "Terbium", 6, 11}, {66, "Dy", "Dysprosium", 6, 12},
                                          {67, "Ho", "Holmium", 6, 13}, {68, "Er", "Erbium", 6, 14},
                                          {69, "Tm", "Thulium", 6, 15}, {70, "Yb", "Ytterbium", 6, 16},
                                          {71, "Lu", "Lutetium", 6, 17}, {72, "Hf", "Hafnium", 6, 4},
                                          {73, "Ta", "Tantalum", 6, 5}, {74, "W", "Tungsten", 6, 6},
                                          {75, "Re", "Rhenium", 6, 7}, {76, "Os", "Osmium", 6, 8},
                                          {77, "Ir", "Iridium", 6, 9}, {78, "Pt", "Platinum", 6, 10},
                                          {79, "Au", "Gold", 6, 11}, {80, "Hg", "Mercury", 6, 12},
                                          {81, "Tl", "Thallium", 6, 13}, {82, "Pb", "Lead", 6, 14},
                                          {83, "Bi", "Bismuth", 6, 15}, {84, "Po", "Polonium", 6, 16},
                                          {85, "At", "Astatine", 6, 17}, {86, "Rn", "Radon", 6, 18},
                                          {87, "Fr", "Francium", 7, 1}, {88, "Ra", "Radium", 7, 2},
                                          {89, "Ac", "Actinium", 7, 3}, {90, "Th", "Thorium", 7, 4},
                                          {91, "Pa", "Protactinium", 7, 5}, {92, "U", "Uranium", 7, 6},
                                          {93, "Np", "Neptunium", 7, 7}, {94, "Pu", "Plutonium", 7, 8},
                                          {95, "Am", "Americium", 7, 9}, {96, "Cm", "Curium", 7, 10},
                                          {97, "Bk", "Berkelium", 7, 11}, {98, "Cf", "Californium", 7, 12},
                                          {99, "Es", "Einsteinium", 7, 13}, {100, "Fm", "Fermium", 7, 14},
                                          {101, "Md", "Mendelevium", 7, 15}, {102, "No", "Nobelium", 7, 16},
                                          {103, "Lr", "Lawrencium", 7, 17}, {104, "Rf", "Rutherfordium", 7, 4},
                                          {105, "Db", "Dubnium", 7, 5}, {106, "Sg", "Seaborgium", 7, 6},
                                          {107, "Bh", "Bohrium", 7, 7}, {108, "Hs", "Hassium", 7, 8},
                                          {109, "Mt", "Meitnerium", 7, 9}, {110, "Ds", "Darmstadtium", 7, 10},
                                          {111, "Rg", "Roentgenium", 7, 11}, {112, "Cn", "Copernicium", 7, 12},
                                          {113, "Nh", "Nihonium", 7, 13}, {114, "Fl", "Flerovium", 7, 14},
                                          {115, "Mc", "Moscovium", 7, 15}, {116, "Lv", "Livermorium", 7, 16},
                                          {117, "Ts", "Tennessine", 7, 17}, {118, "Og", "Oganesson", 7, 18}};

int get_element_index(char *symbol) {
  for (int i = 0; i < MAX_ELEMENTS; i++) {
    if (strcmp(symbol, elements[i].symbol) == 0) {
      return i;
    }
  }

  return -1;
}

void print_element(char *symbol) {
  int index = get_element_index(symbol);

  if (index < 0) {
    printf("Element not found.\n");
    return;
  }

  struct element e = elements[index];

  printf("Atomic number: %d\n", e.atomic_number);
  printf("Symbol: %s\n", e.symbol);
  printf("Name: %s\n", e.name);
  printf("Period: %d\n", e.period);
  printf("Group: %d\n", e.group);
}

void quiz() {
  int score = 0;

  printf("Welcome to the Periodic Table Quiz!\n");
  printf("You will be given 10 questions about the elements of the periodic table.\n");
  printf("Answer each question by entering the corresponding element symbol.\n");
  printf("Good luck!\n\n");

  for (int i = 1; i <= 10; i++) {
    printf("Question %d: What is the symbol for the element with atomic number %d?\n", i, i);
    char answer[3];
    scanf("%s", answer);

    int index = get_element_index(answer);
    if (index < 0) {
      printf("Incorrect. The element does not exist.\n");
    } else if (elements[index].atomic_number == i) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect.\n");
    }

    printf("\n");
  }

  printf("Quiz complete!\n");
  printf("Score: %d/10\n", score);
}

int main() {
  quiz();

  return 0;
}