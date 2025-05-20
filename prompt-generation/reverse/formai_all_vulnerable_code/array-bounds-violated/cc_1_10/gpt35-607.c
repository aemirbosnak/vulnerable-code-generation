//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to shuffle the choices for each question
void shuffleChoices(char **choices) {
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        char *temp = choices[i];
        choices[i] = choices[j];
        choices[j] = temp;
    }
}

int main() {
    char *elements[118] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                          "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
                          "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                          "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
                          "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                          "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                          "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                          "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                          "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                          "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                          "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                          "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    char *symbols[118] = {"Hydrogen","Helium","Lithium","Beryllium","Boron","Carbon",
                          "Nitrogen","Oxygen","Fluorine","Neon","Sodium","Magnesium",
                          "Aluminum","Silicon","Phosphorus","Sulfur","Chlorine","Argon",
                          "Potassium","Calcium","Scandium","Titanium","Vanadium","Chromium",
                          "Manganese","Iron","Cobalt","Nickel","Copper","Zinc","Gallium",
                          "Germanium","Arsenic","Selenium","Bromine","Krypton","Rubidium",
                          "Strontium","Yttrium","Zirconium","Niobium","Molybdenum","Technetium",
                          "Ruthenium","Rhodium","Palladium","Silver","Cadmium","Indium",
                          "Tin","Antimony","Tellurium","Iodine","Xenon","Cesium","Barium",
                          "Lanthanum","Cerium","Praseodymium","Neodymium","Promethium",
                          "Samarium","Europium","Gadolinium","Terbium","Dysprosium",
                          "Holmium","Erbium","Thulium","Ytterbium","Lutetium","Hafnium",
                          "Tantalum","Tungsten","Rhenium","Osmium","Iridium","Platinum",
                          "Gold","Mercury","Thallium","Lead","Bismuth","Polonium",
                          "Astatine","Radon","Francium","Radium","Actinium","Thorium",
                          "Protactinium","Uranium","Neptunium","Plutonium","Americium",
                          "Curium","Berkelium","Californium","Einsteinium","Fermium",
                          "Mendelevium","Nobelium","Lawrencium","Rutherfordium","Dubnium",
                          "Seaborgium","Bohrium","Hassium","Meitnerium","Darmstadtium",
                          "Roentgenium","Copernicium","Nihonium","Flerovium","Moscovium",
                          "Livermorium","Tennessine","Oganesson"};

    char *categories[9] = {"Alkali Metal", "Alkaline Earth Metal", "Transition Metal",
                           "Post-Transition Metal", "Metalloid", "Nonmetal", "Halogen",
                           "Noble Gas", "Lanthanide/Actinide"};

    int category[118] = {0, 8, 1, 1, 9, 5, 5, 5, 6, 7, 2, 2, 1, 5, 5, 5, 6, 7, 2, 2,
                         3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 2, 3, 3, 3,
                         3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 2, 3, 3, 3, 4, 4, 4,
                         4, 4, 4, 4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 3, 4, 4, 4,
                         4, 4, 4, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7,
                         2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4};

    int correct = 0;

    // Seed the random number generator
    srand(time(NULL));

    printf("----- Welcome to the Periodic Table Quiz! -----\n\n");

    // Loop through 10 questions
    for (int i = 0; i < 10; i++) {
        int randIndex = rand() % 118;
        char *element = elements[randIndex];
        char *symbol = symbols[randIndex];
        int catIndex = category[randIndex];
        char *cat = categories[catIndex];

        char *choices[4] = {symbols[rand() % 118], symbols[rand() % 118], symbols[rand() % 118], symbols[rand() % 118]};
        choices[rand() % 4] = symbol;
        shuffleChoices(choices);

        printf("Question %d: What is the symbol for %s?\n", i+1, element);
        printf("a) %s\tb) %s\nc) %s\td) %s\n", choices[0], choices[1], choices[2], choices[3]);

        // Get the user's answer
        char userChoice;
        printf("Enter your choice (a, b, c, or d): ");
        scanf(" %c", &userChoice);

        // Check if the answer is correct and give feedback
        if (userChoice == 'a' && choices[0] == symbol) {
            printf("Correct! (%s is a %s)\n", symbol, cat);
            correct++;
        } else if (userChoice == 'b' && choices[1] == symbol) {
            printf("Correct! (%s is a %s)\n", symbol, cat);
            correct++;
        } else if (userChoice == 'c' && choices[2] == symbol) {
            printf("Correct! (%s is a %s)\n", symbol, cat);
            correct++;
        } else if (userChoice == 'd' && choices[3] == symbol) {
            printf("Correct! (%s is a %s)\n", symbol, cat);
            correct++;
        } else {
            printf("Sorry, that is incorrect. (%s is a %s)\n", symbol, cat);
        }

        printf("\n");
    }

    // Give the user their score
    printf("----- Quiz complete! -----\n\n");
    printf("You got %d out of 10 correct.\n", correct);

    return 0;
}