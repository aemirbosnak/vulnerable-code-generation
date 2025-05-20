//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <string.h>

struct element {
   char name[20];
   char symbol[3];
   int atomicNumber;
   float atomicWeight;
   char category[20];
   char state[15];
};

int main() {
   // array of 118 elements
   struct element elements[] = {
      {"Hydrogen", "H", 1, 1.008, "Nonmetal", "Gas"},
      {"Helium", "He", 2, 4.0026, "Noble gas", "Gas"},
      {"Lithium", "Li", 3, 6.94, "Alkali metal", "Solid"},
      {"Beryllium", "Be", 4, 9.0122, "Alkaline earth metal", "Solid"},
      {"Boron", "B", 5, 10.81, "Metalloid", "Solid"},
      {"Carbon", "C", 6, 12.011, "Nonmetal", "Solid"},
      {"Nitrogen", "N", 7, 14.007, "Nonmetal", "Gas"},
      {"Oxygen", "O", 8, 15.999, "Nonmetal", "Gas"},
      {"Fluorine", "F", 9, 18.998, "Halogen", "Gas"},
      {"Neon", "Ne", 10, 20.18, "Noble gas", "Gas"},
      {"Sodium", "Na", 11, 22.99, "Alkali metal", "Solid"},
      {"Magnesium", "Mg", 12, 24.305, "Alkaline earth metal", "Solid"},
      {"Aluminum", "Al", 13, 26.982, "Metal", "Solid"},
      {"Silicon", "Si", 14, 28.086, "Metalloid", "Solid"},
      {"Phosphorus", "P", 15, 30.974, "Nonmetal", "Solid"},
      {"Sulfur", "S", 16, 32.06, "Nonmetal", "Solid"},
      {"Chlorine", "Cl", 17, 35.45, "Halogen", "Gas"},
      {"Argon", "Ar", 18, 39.948, "Noble gas", "Gas"},
      {"Potassium", "K", 19, 39.098, "Alkali metal", "Solid"},
      {"Calcium", "Ca", 20, 40.078, "Alkaline earth metal", "Solid"},
      {"Scandium", "Sc", 21, 44.956, "Transition metal", "Solid"},
      {"Titanium", "Ti", 22, 47.867, "Transition metal", "Solid"},
      {"Vanadium", "V", 23, 50.942, "Transition metal", "Solid"},
      {"Chromium", "Cr", 24, 52.0, "Transition metal", "Solid"},
      {"Manganese", "Mn", 25, 54.938, "Transition metal", "Solid"},
      {"Iron", "Fe", 26, 55.845, "Transition metal", "Solid"},
      {"Cobalt", "Co", 27, 58.933, "Transition metal", "Solid"},
      {"Nickel", "Ni", 28, 58.693, "Transition metal", "Solid"},
      {"Copper", "Cu", 29, 63.546, "Transition metal", "Solid"},
      {"Zinc", "Zn", 30, 65.38, "Transition metal", "Solid"},
      {"Gallium", "Ga", 31, 69.723, "Metal", "Solid"},
      {"Germanium", "Ge", 32, 72.63, "Metalloid", "Solid"},
      {"Arsenic", "As", 33, 74.922, "Metalloid", "Solid"},
      {"Selenium", "Se", 34, 78.96, "Nonmetal", "Solid"},
      {"Bromine", "Br", 35, 79.904, "Halogen", "Liquid"},
      {"Krypton", "Kr", 36, 83.798, "Noble gas", "Gas"},
      {"Rubidium", "Rb", 37, 85.468, "Alkali metal", "Solid"},
      {"Strontium", "Sr", 38, 87.62, "Alkaline earth metal", "Solid"},
      {"Yttrium", "Y", 39, 88.906, "Transition metal", "Solid"},
      {"Zirconium", "Zr", 40, 91.224, "Transition metal", "Solid"},
      {"Niobium", "Nb", 41, 92.906, "Transition metal", "Solid"},
      {"Molybdenum", "Mo", 42, 95.94, "Transition metal", "Solid"},
      {"Technetium", "Tc", 43, 98.0, "Transition metal", "Solid"},
      {"Ruthenium", "Ru", 44, 101.07, "Transition metal", "Solid"},
      {"Rhodium", "Rh", 45, 102.91, "Transition metal", "Solid"},
      {"Palladium", "Pd", 46, 106.42, "Transition metal", "Solid"},
      {"Silver", "Ag", 47, 107.87, "Transition metal", "Solid"},
      {"Cadmium", "Cd", 48, 112.41, "Transition metal", "Solid"},
      {"Indium", "In", 49, 114.82, "Metal", "Solid"},
      {"Tin", "Sn", 50, 118.71, "Metal", "Solid"},
      {"Antimony", "Sb", 51, 121.76, "Metalloid", "Solid"},
      {"Tellurium", "Te", 52, 127.6, "Metalloid", "Solid"},
      {"Iodine", "I", 53, 126.9, "Halogen", "Solid"},
      {"Xenon", "Xe", 54, 131.29, "Noble gas", "Gas"},
      {"Cesium", "Cs", 55, 132.91, "Alkali metal", "Solid"},
      {"Barium", "Ba", 56, 137.33, "Alkaline earth metal", "Solid"},
      {"Lanthanum", "La", 57, 138.91, "Lanthanide", "Solid"},
      {"Cerium", "Ce", 58, 140.12, "Lanthanide", "Solid"},
      {"Praseodymium", "Pr", 59, 140.91, "Lanthanide", "Solid"},
      {"Neodymium", "Nd", 60, 144.24, "Lanthanide", "Solid"},
      {"Promethium", "Pm", 61, 145.0, "Lanthanide", "Solid"},
      {"Samarium", "Sm", 62, 150.36, "Lanthanide", "Solid"},
      {"Europium", "Eu", 63, 151.96, "Lanthanide", "Solid"},
      {"Gadolinium", "Gd", 64, 157.25, "Lanthanide", "Solid"},
      {"Terbium", "Tb", 65, 158.93, "Lanthanide", "Solid"},
      {"Dysprosium", "Dy", 66, 162.5, "Lanthanide", "Solid"},
      {"Holmium", "Ho", 67, 164.93, "Lanthanide", "Solid"},
      {"Erbium", "Er", 68, 167.26, "Lanthanide", "Solid"},
      {"Thulium", "Tm", 69, 168.93, "Lanthanide", "Solid"},
      {"Ytterbium", "Yb", 70, 173.05, "Lanthanide", "Solid"},
      {"Lutetium", "Lu", 71, 174.97, "Lanthanide", "Solid"},
      {"Hafnium", "Hf", 72, 178.49, "Transition metal", "Solid"},
      {"Tantalum", "Ta", 73, 180.95, "Transition metal", "Solid"},
      {"Tungsten", "W", 74, 183.84, "Transition metal", "Solid"},
      {"Rhenium", "Re", 75, 186.21, "Transition metal", "Solid"},
      {"Osmium", "Os", 76, 190.23, "Transition metal", "Solid"},
      {"Iridium", "Ir", 77, 192.22, "Transition metal", "Solid"},
      {"Platinum", "Pt", 78, 195.08, "Transition metal", "Solid"},
      {"Gold", "Au", 79, 196.97, "Transition metal", "Solid"},
      {"Mercury", "Hg", 80, 200.59, "Transition metal", "Liquid"},
      {"Thallium", "Tl", 81, 204.38, "Metal", "Solid"},
      {"Lead", "Pb", 82, 207.2, "Metal", "Solid"},
      {"Bismuth", "Bi", 83, 208.98, "Metal", "Solid"},
      {"Polonium", "Po", 84, 209.0, "Metalloid", "Solid"},
      {"Astatine", "At", 85, 210.0, "Halogen", "Solid"},
      {"Radon", "Rn", 86, 222.02, "Noble gas", "Gas"},
      {"Francium", "Fr", 87, 223.02, "Alkali metal", "Solid"},
      {"Radium", "Ra", 88, 226.03, "Alkaline earth metal", "Solid"},
      {"Actinium", "Ac", 89, 227.03, "Actinide", "Solid"},
      {"Thorium", "Th", 90, 232.04, "Actinide", "Solid"},
      {"Protactinium", "Pa", 91, 231.04, "Actinide", "Solid"},
      {"Uranium", "U", 92, 238.03, "Actinide", "Solid"},
      {"Neptunium", "Np", 93, 237.05, "Actinide", "Solid"},
      {"Plutonium", "Pu", 94, 244.06, "Actinide", "Solid"},
      {"Americium", "Am", 95, 243.06, "Actinide", "Solid"},
      {"Curium", "Cm", 96, 247.07, "Actinide", "Solid"},
      {"Berkelium", "Bk", 97, 247.07, "Actinide", "Solid"},
      {"Californium", "Cf", 98, 251.08, "Actinide", "Solid"},
      {"Einsteinium", "Es", 99, 252.08, "Actinide", "Solid"},
      {"Fermium", "Fm", 100, 257.1, "Actinide", "Solid"},
      {"Mendelevium", "Md", 101, 258.1, "Actinide", "Solid"},
      {"Nobelium", "No", 102, 259.1, "Actinide", "Solid"},
      {"Lawrencium", "Lr", 103, 262.11, "Actinide", "Solid"},
      {"Rutherfordium", "Rf", 104, 267.13, "Transition metal", "Unknown"},
      {"Dubnium", "Db", 105, 270.13, "Transition metal", "Unknown"},
      {"Seaborgium", "Sg", 106, 271.14, "Transition metal", "Unknown"},
      {"Bohrium", "Bh", 107, 270.13, "Transition metal", "Unknown"},
      {"Hassium", "Hs", 108, 277.15, "Transition metal", "Unknown"},
      {"Meitnerium", "Mt", 109, 276.15, "Unknown", "Unknown"},
      {"Darmstadtium", "Ds", 110, 281.16, "Unknown", "Unknown"},
      {"Roentgenium", "Rg", 111, 280.16, "Unknown", "Unknown"},
      {"Copernicium", "Cn", 112, 285.18, "Transition metal", "Unknown"},
      {"Nihonium", "Nh", 113, 284.18, "Unknown", "Unknown"},
      {"Flerovium", "Fl", 114, 289.19, "Post-transition metal", "Unknown"},
      {"Moscovium", "Mc", 115, 288.19, "Unknown", "Unknown"},
      {"Livermorium", "Lv", 116, 293.21, "Post-transition metal", "Unknown"},
      {"Tennessine", "Ts", 117, 294.21, "Unknown", "Unknown"},
      {"Oganesson", "Og", 118, 294.21, "Unknown", "Unknown"}
   };

   int numQuestions, numCorrect = 0;

   printf("Welcome to the Periodic Table Quiz!\n");
   printf("Enter number of elements to be quizzed (maximum is 118): ");
   scanf("%d", &numQuestions);

   if (numQuestions > 118) {
      printf("Error: Maximum number of elements is 118.\n");
      return 0;
   }

   // ask questions
   for (int i = 0; i < numQuestions; i++) {
      int index = rand() % 118; // select a random element
      char answer[20];

      // print question
      printf("\nWhat is the atomic number of %s (%s)? ", elements[index].name, elements[index].symbol);
      scanf("%s", answer);

      // check if answer is correct
      if (atoi(answer) == elements[index].atomicNumber) {
         printf("Correct!\n");
         numCorrect++;
      }
      else {
         printf("Incorrect. The correct answer is %d.\n", elements[index].atomicNumber);
      }
   }

   // display score
   float percentCorrect = (float)numCorrect / numQuestions * 100;
   printf("\nYou scored %d out of %d, or %.2f%%.\n", numCorrect, numQuestions, percentCorrect);

   return 0;
}