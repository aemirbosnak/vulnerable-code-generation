//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {
    // initialize random seed
    srand(time(NULL));

    // declare variables
    int num_questions = 0, correct_answers = 0;
    char answer;

    // print welcome message and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown a series of symbols and asked to name the corresponding elements.\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);
    printf("\n");

    // create array of symbol-element pairs
    char *elements[] = {"H-Hydrogen", "He-Helium", "Li-Lithium", "Be-Beryllium", "B-Boron", "C-Carbon", "N-Nitrogen", "O-Oxygen", "F-Fluorine", "Ne-Neon",
                        "Na-Sodium", "Mg-Magnesium", "Al-Aluminum", "Si-Silicon", "P-Phosphorus", "S-Sulfur", "Cl-Chlorine", "Ar-Argon", "K-Potassium", "Ca-Calcium",
                        "Sc-Scandium", "Ti-Titanium", "V-Vanadium", "Cr-Chromium", "Mn-Manganese", "Fe-Iron", "Co-Cobalt", "Ni-Nickel", "Cu-Copper", "Zn-Zinc",
                        "Ga-Gallium", "Ge-Germanium", "As-Arsenic", "Se-Selenium", "Br-Bromine", "Kr-Krypton", "Rb-Rubidium", "Sr-Strontium", "Y-Yttrium", "Zr-Zirconium",
                        "Nb-Niobium", "Mo-Molybdenum", "Tc-Technetium", "Ru-Ruthenium", "Rh-Rhodium", "Pd-Palladium", "Ag-Silver", "Cd-Cadmium", "In-Indium", "Sn-Tin",
                        "Sb-Antimony", "Te-Tellurium", "I-Iodine", "Xe-Xenon", "Cs-Cesium", "Ba-Barium", "La-Lanthanum", "Ce-Cerium", "Pr-Praseodymium", "Nd-Neodymium",
                        "Pm-Promethium", "Sm-Samarium", "Eu-Europium", "Gd-Gadolinium", "Tb-Terbium", "Dy-Dysprosium", "Ho-Holmium", "Er-Erbium", "Tm-Thulium", "Yb-Ytterbium",
                        "Lu-Lutetium", "Hf-Hafnium", "Ta-Tantalum", "W-Tungsten", "Re-Rhenium", "Os-Osmium", "Ir-Iridium", "Pt-Platinum", "Au-Gold", "Hg-Mercury",
                        "Tl-Thallium", "Pb-Lead", "Bi-Bismuth", "Po-Polonium", "At-Astatine", "Rn-Radon", "Fr-Francium", "Ra-Radium", "Ac-Actinium", "Th-Thorium",
                        "Pa-Protactinium", "U-Uranium", "Np-Neptunium", "Pu-Plutonium", "Am-Americium", "Cm-Curium", "Bk-Berkelium", "Cf-Californium", "Es-Einsteinium", "Fm-Fermium"};
    int num_elements = sizeof(elements) / sizeof(char *);

    // shuffle the array using Fisher-Yates shuffle algorithm
    for (int i = num_elements - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char *temp = elements[j];
        elements[j] = elements[i];
        elements[i] = temp;
    }

    // loop through questions
    for (int i = 0; i < num_questions; i++) {
        // get random symbol-element pair
        char *symbol_element_pair = elements[i];

        // get symbol and element from pair
        char symbol[3];
        char element[20];
        sscanf(symbol_element_pair, "%[^-]-%[^\n]", symbol, element);

        // print question
        printf("Question %d: What is the element represented by the symbol %s? ", i + 1, symbol);

        // get user's answer and convert to uppercase
        scanf(" %c", &answer);
        answer = toupper(answer);

        // check if answer is correct
        if (answer == symbol[0]) {
            printf("Correct!\n");
            correct_answers++;
        }
        else {
            printf("Incorrect. The correct answer is %s.\n", element);
        }
    }

    // calculate and print score
    double score = (double) correct_answers / num_questions * 100;
    printf("\nYou got %d out of %d questions correct. Your score is %.2f%%.\n", correct_answers, num_questions, score);

    return 0;
}