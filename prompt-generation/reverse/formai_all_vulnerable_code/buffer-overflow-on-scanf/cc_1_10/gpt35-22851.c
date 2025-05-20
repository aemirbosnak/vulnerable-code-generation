//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main() {

   // Initialize the periodic table with element symbols and their corresponding name and atomic number.
   char symbol[118][3] = {
      "H" , "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
      "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
      "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
      "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
      "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
      "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
      "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
      "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
      "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
      "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
      "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
      "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
   };
   
   char name[118][100] = {
      "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
      "Sodium", "Magnesium", "Aluminium", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
      "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
      "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
      "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
      "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
      "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
      "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
      "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
      "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
      "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
      "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
   };

   int atomicNumber[118] = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
      11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
      21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
      31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
      41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
      51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
      61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
      71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
      81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
      91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
      101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
      111, 112, 113, 114, 115, 116, 117, 118
   };

   // Print the instructions of the quiz
   printf("Welcome to the Periodic Table Quiz!\n");
   printf("In this quiz, you will be given the name or the symbol of an element, and you need to enter the corresponding symbol or name respectively.\n");
   printf("You will be given a total of 10 questions, and your score will be calculated at the end.\n");
   printf("Are you ready to start the quiz? (Y/N): ");

   // Read the input of the user
   char response;
   scanf("%c", &response);

   if(response == 'Y' || response == 'y') {

      // Initialize variables for score and question counter
      int score = 0;
      int counter = 0;

      // Loop through 10 questions
      while(counter < 10) {

         // Randomly select an element from the periodic table
         int randomIndex = rand() % 118;

         // Prompt the user with the name or symbol of the element
         if(rand() % 2 == 0) {
            // Print the name of the element
            printf("%d. What is the symbol of %s? ", counter+1, name[randomIndex]);
            // Read the input of the user
            char input[3];
            scanf("%s", input);
            // Check if the input is correct
            if(strcmp(input, symbol[randomIndex]) == 0) {
               printf("Correct!\n");
               score++;
            } else {
               printf("Incorrect! The correct symbol is %s.\n", symbol[randomIndex]);
            }
         } else {
            // Print the symbol of the element
            printf("%d. What is the name of %s? ", counter+1, symbol[randomIndex]);
            // Read the input of the user
            char input[100];
            scanf("%s", input);
            // Check if the input is correct
            if(strcmp(input, name[randomIndex]) == 0) {
               printf("Correct!\n");
               score++;
            } else {
               printf("Incorrect! The correct name is %s.\n", name[randomIndex]);
            }
         }

         // Increment the question counter
         counter++;
      }

      // Print the score of the user
      printf("Congratulations, you have completed the quiz. Your score is %d/10.\n", score);

   } else {

      // Print a message indicating that the quiz has been cancelled.
      printf("Quiz cancelled.\n");

   }

   return 0;
}