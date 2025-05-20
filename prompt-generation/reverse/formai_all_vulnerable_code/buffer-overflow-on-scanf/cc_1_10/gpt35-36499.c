//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_ELEMENTS 118

int main() {
  // Create an array containing all the element symbols
  char symbols[NUM_ELEMENTS][3] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
    "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga",
    "Ge", "As", "Se", "Br", "Kr",
    "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In",
    "Sn", "Sb", "Te", "I", "Xe",
    "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho",
    "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn",
    "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es",
    "Fm", "Md", "No", "Lr", "Rf",
    "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts",
    "Og"
  };

  // Create an array containing the full names of each element
  char names[NUM_ELEMENTS][30] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
    "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon",
    "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium",
    "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel",
    "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine",
    "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
    "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver",
    "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon",
    "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
    "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium",
    "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium",
    "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold",
    "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",
    "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium",
    "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium",
    "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium",
    "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium",
    "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium",
    "Moscovium", "Livermorium", "Tennessine", "Oganesson"
  };

  // Create an array containing the atomic numbers of each element
  int numbers[NUM_ELEMENTS] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36,
    37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
    50, 51, 52, 53, 54,
    55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67,
    68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86,
    87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 112, 113, 114, 115, 116, 117, 118
  };

  // Create an array containing the atomic weights of each element
  float weights[NUM_ELEMENTS] = {
    1.008, 4.0026, 6.94, 9.0122, 10.81, 12.011, 14.007, 15.999, 18.998, 20.180,
    22.990, 24.305, 26.982, 28.086, 30.974, 32.066, 35.453, 39.948,
    39.098, 40.078, 44.956, 47.867, 50.942, 52.000, 54.938, 55.845,
    58.933, 58.693, 63.546, 65.390, 69.723, 72.630, 74.922, 78.960, 79.904,
    83.798, 85.468, 87.620, 88.906, 91.224, 92.906, 95.940, 98.000, 101.070,
    102.905, 106.420, 107.868, 112.411, 114.818, 118.710, 121.760, 127.600,
    126.905, 131.293, 132.905, 137.327, 138.905, 140.116, 140.908, 144.242,
    145.000, 150.360, 151.964, 157.250, 158.925, 162.500, 164.930, 167.259,
    168.934, 173.054, 174.967, 178.490, 180.948, 183.840, 186.207, 190.230,
    192.217, 195.084, 196.967, 200.592, 204.383, 207.200, 208.980, 209.000,
    210.000, 222.000, 223.000, 226.025, 227.028, 232.038, 231.036, 238.029,
    237.048, 244.064, 243.061, 247.070, 247.070, 251.080, 252.083, 257.095,
    258.098, 259.101, 262.114, 261.121, 262.129, 266.141, 264.141, 277.163,
    268.143, 271.133, 270.133, 277.000
  };

  // Initialize random number generator
  srand(time(NULL));

  // Keep track of score
  int score = 0;

  // Loop through the questions
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    // Randomly select an element
    int index = rand() % NUM_ELEMENTS;

    // Print the question
    printf("What is the symbol for %s (atomic number %d)?\n", names[index], numbers[index]);

    // Read the answer from user
    char answer[3];
    scanf("%s", answer);

    // Check the answer
    if (strcmp(answer, symbols[index]) == 0) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %s.\n", symbols[index]);
    }
  }

  // Print the final score
  printf("You scored %d out of %d.\n", score, NUM_QUESTIONS);

  return 0;
}