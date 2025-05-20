//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random integers
int generateRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    // Seed random number generator with current time
    srand(time(NULL));
    
    // Define array of elements and respective symbols
    char elements[118][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluoride", "Neon",
                              "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chloride", "Argon", "Potassium", "Calcium",
                              "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc",
                              "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium",
                              "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin",
                              "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium",
                              "Promethium", "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium",
                              "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
                              "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium",
                              "Protactinium", "Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium",
                              "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium",
                              "Roentgenium", "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};
                  
    char symbols[118][5] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe",
                            "Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn",
                            "Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W",
                            "Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk",
                            "Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};
                  
    // Define variables to keep track of score
    int correctAnswers = 0;
    int totalQuestions = 0;
    
    // Loop through 10 questions
    for(int i=0; i<10; i++){
        // Generate random element index
        int elementIndex = generateRandomInt(0,117);
        // Print question
        printf("What is the symbol of %s?\n", elements[elementIndex]);
        // Get user answer
        char userAnswer[10];
        scanf("%s", userAnswer);
        // Convert user answer to uppercase
        char uppercaseAnswer[10];
        for(int i=0; i<10; i++){
            uppercaseAnswer[i] = toupper(userAnswer[i]);
        }
        // Compare user answer to correct answer
        if(strcmp(uppercaseAnswer, symbols[elementIndex]) == 0){
            printf("Correct!\n");
            correctAnswers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", symbols[elementIndex]);
        }
        // Increment total number of questions
        totalQuestions++;
    }
    // Print final score
    printf("You scored %d out of %d.\n", correctAnswers, totalQuestions);
    return 0;
}