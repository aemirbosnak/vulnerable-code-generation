//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {

   // Define the periodic table array
   char periodicTable[118][3] = {
       "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
       "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
       "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
       "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
       "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
       "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
       "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
       "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
       "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
       "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
       "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
       "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
   };

   // Define the element names array
   char elementNames[118][25] = {
       "Hydrogen",                   "Helium",                      "Lithium",                     
       "Beryllium",                  "Boron",                       "Carbon",                      
       "Nitrogen",                   "Oxygen",                      "Fluorine",                    
       "Neon",                       "Sodium",                      "Magnesium",                   
       "Aluminum",                   "Silicon",                     "Phosphorus",                  
       "Sulfur",                     "Chlorine",                    "Argon",                       
       "Potassium",                  "Calcium",                     "Scandium",                    
       "Titanium",                   "Vanadium",                    "Chromium",                    
       "Manganese",                  "Iron",                        "Cobalt",                      
       "Nickel",                     "Copper",                      "Zinc",                        
       "Gallium",                    "Germanium",                   "Arsenic",                     
       "Selenium",                   "Bromine",                     "Krypton",                     
       "Rubidium",                   "Strontium",                   "Yttrium",                     
       "Zirconium",                  "Niobium",                     "Molybdenum",                  
       "Technetium",                 "Ruthenium",                   "Rhodium",                     
       "Palladium",                  "Silver",                      "Cadmium",                     
       "Indium",                     "Tin",                         "Antimony",                    
       "Tellurium",                  "Iodine",                      "Xenon",                       
       "Cesium",                     "Barium",                      "Lanthanum",                   
       "Cerium",                     "Praseodymium",                "Neodymium",                    
       "Promethium",                 "Samarium",                    "Europium",                    
       "Gadolinium",                 "Terbium",                     "Dysprosium",                  
       "Holmium",                    "Erbium",                      "Thulium",                     
       "Ytterbium",                  "Lutetium",                    "Hafnium",                     
       "Tantalum",                   "Tungsten",                    "Rhenium",                     
       "Osmium",                     "Iridium",                     "Platinum",                    
       "Gold",                       "Mercury",                     "Thallium",                    
       "Lead",                       "Bismuth",                     "Polonium",                    
       "Astatine",                   "Radon",                       "Francium",                    
       "Radium",                     "Actinium",                    "Thorium",                     
       "Protactinium",               "Uranium",                     "Neptunium",                   
       "Plutonium",                  "Americium",                   "Curium",                      
       "Berkelium",                  "Californium",                 "Einsteinium",                 
       "Fermium",                    "Mendelevium",                 "Nobelium",                    
       "Lawrencium",                 "Rutherfordium",               "Dubnium",                     
       "Seaborgium",                 "Bohrium",                     "Hassium",                     
       "Meitnerium",                 "Darmstadtium",                "Roentgenium",                 
       "Copernicium",                "Nihonium",                    "Flerovium",                   
       "Moscovium",                  "Livermorium",                 "Tennessine",                  
       "Oganesson"
   };

   // Define the number of elements in the periodic table
   int numElements = 118;

   // Define the correct answers and initialize the score
   char correctAnswers[10][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};
   int score = 0;

   // Print welcome message and instructions
   printf("Welcome to the Periodic Table Quiz!\n");
   printf("You will be asked to identify the symbol for each of the first 10 elements.\n");
   printf("Enter your answer and press enter. Your score will be displayed at the end.\n");

   // Ask the user for the symbol of each element
   for (int i = 0; i < 10; i++) {
       printf("\nWhat is the symbol for %s?\n", elementNames[i]);
       char userAnswer[3];
       scanf("%s", userAnswer);
       if (strcmp(userAnswer, correctAnswers[i]) == 0) {
           printf("Correct!\n");
           score++;
       } else {
           printf("Incorrect. The correct answer is %s.\n", correctAnswers[i]);
       }
   }

   // Display the final score
   printf("\nYour final score is %d/10\n", score);

   return 0;
}