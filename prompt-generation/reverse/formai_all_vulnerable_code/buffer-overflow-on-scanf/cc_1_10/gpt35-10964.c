//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

// Struct for each element in the periodic table
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    double atomic_weight;
} Element;

// Creating the array of elements
Element elements[NUM_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.00794},
    {"Helium", "He", 2, 4.00260},
    {"Lithium", "Li", 3, 6.941},
    {"Beryllium", "Be", 4, 9.01218},
    {"Boron", "B", 5, 10.81},
    {"Carbon", "C", 6, 12.011},
    {"Nitrogen", "N", 7, 14.0067},
    {"Oxygen", "O", 8, 15.9994},
    {"Fluorine", "F", 9, 18.9984},
    {"Neon", "Ne", 10, 20.1797},
    {"Sodium", "Na", 11, 22.9898},
    {"Magnesium", "Mg", 12, 24.305},
    {"Aluminum", "Al", 13, 26.9815},
    {"Silicon", "Si", 14, 28.0855},
    {"Phosphorus", "P", 15, 30.9738},
    {"Sulfur", "S", 16, 32.06},
    {"Chlorine", "Cl", 17, 35.453},
    {"Argon", "Ar", 18, 39.948},
    {"Potassium", "K", 19, 39.098},
    {"Calcium", "Ca", 20, 40.078},
    {"Scandium", "Sc", 21, 44.956},
    {"Titanium", "Ti", 22, 47.867},
    {"Vanadium", "V", 23, 50.9415},
    {"Chromium", "Cr", 24, 51.996},
    {"Manganese", "Mn", 25, 54.938},
    {"Iron", "Fe", 26, 55.845},
    {"Cobalt", "Co", 27, 58.9332},
    {"Nickel", "Ni", 28, 58.6934},
    {"Copper", "Cu", 29, 63.546},
    {"Zinc", "Zn", 30, 65.38},
    {"Gallium", "Ga", 31, 69.723},
    {"Germanium", "Ge", 32, 72.63},
    {"Arsenic", "As", 33, 74.9216},
    {"Selenium", "Se", 34, 78.96},
    {"Bromine", "Br", 35, 79.904},
    {"Krypton", "Kr", 36, 83.798},
    {"Rubidium", "Rb", 37, 85.4678},
    {"Strontium", "Sr", 38, 87.62},
    {"Yttrium", "Y", 39, 88.9059},
    {"Zirconium", "Zr", 40, 91.224},
    {"Niobium", "Nb", 41, 92.9064},
    {"Molybdenum", "Mo", 42, 95.94},
    {"Technetium", "Tc", 43, 97.9072},
    {"Ruthenium", "Ru", 44, 101.07},
    {"Rhodium", "Rh", 45, 102.9055},
    {"Palladium", "Pd", 46, 106.42},
    {"Silver", "Ag", 47, 107.8682},
    {"Cadmium", "Cd", 48, 112.41},
    {"Indium", "In", 49, 114.82},
    {"Tin", "Sn", 50, 118.71},
    {"Antimony", "Sb", 51, 121.76},
    {"Tellurium", "Te", 52, 127.6},
    {"Iodine", "I", 53, 126.9045},
    {"Xenon", "Xe", 54, 131.29},
    {"Cesium", "Cs", 55, 132.9055},
    {"Barium", "Ba", 56, 137.33},
    {"Lanthanum", "La", 57, 138.9055},
    {"Cerium", "Ce", 58, 140.12},
    {"Praseodymium", "Pr", 59, 140.9077},
    {"Neodymium", "Nd", 60, 144.24},
    {"Promethium", "Pm", 61, 145},
    {"Samarium", "Sm", 62, 150.36},
    {"Europium", "Eu", 63, 151.964},
    {"Gadolinium", "Gd", 64, 157.25},
    {"Terbium", "Tb", 65, 158.9253},
    {"Dysprosium", "Dy", 66, 162.50},
    {"Holmium", "Ho", 67, 164.9303},
    {"Erbium", "Er", 68, 167.26},
    {"Thulium", "Tm", 69, 168.9342},
    {"Ytterbium", "Yb", 70, 173.04},
    {"Lutetium", "Lu", 71, 174.967},
    {"Hafnium", "Hf", 72, 178.49},
    {"Tantalum", "Ta", 73, 180.9479},
    {"Tungsten", "W", 74, 183.84},
    {"Rhenium", "Re", 75, 186.207},
    {"Osmium", "Os", 76, 190.23},
    {"Iridium", "Ir", 77, 192.217},
    {"Platinum", "Pt", 78, 195.084},
    {"Gold", "Au", 79, 196.9666},
    {"Mercury", "Hg", 80, 200.59},
    {"Thallium", "Tl", 81, 204.3833},
    {"Lead", "Pb", 82, 207.2},
    {"Bismuth", "Bi", 83, 208.9804},
    {"Polonium", "Po", 84, 209},
    {"Astatine", "At", 85, 210},
    {"Radon", "Rn", 86, 222},
    {"Francium", "Fr", 87, 223},
    {"Radium", "Ra", 88, 226.0254},
    {"Actinium", "Ac", 89, 227},
    {"Thorium", "Th", 90, 232.0381},
    {"Protactinium", "Pa", 91, 231.0359},
    {"Uranium", "U", 92, 238.0289},
    {"Neptunium", "Np", 93, 237},
    {"Plutonium", "Pu", 94, 244},
    {"Americium", "Am", 95, 243},
    {"Curium", "Cm", 96, 247},
    {"Berkelium", "Bk", 97, 247},
    {"Californium", "Cf", 98, 251},
    {"Einsteinium", "Es", 99, 252},
    {"Fermium", "Fm", 100, 257},
    {"Mendelevium", "Md", 101, 258},
    {"Nobelium", "No", 102, 259},
    {"Lawrencium", "Lr", 103, 262},
    {"Rutherfordium", "Rf", 104, 261},
    {"Dubnium", "Db", 105, 262},
    {"Seaborgium", "Sg", 106, 266},
    {"Bohrium", "Bh", 107, 264},
    {"Hassium", "Hs", 108, 267},
    {"Meitnerium", "Mt", 109, 268},
    {"Darmstadtium", "Ds", 110, 271},
    {"Roentgenium", "Rg", 111, 272},
    {"Copernicium", "Cn", 112, 277},
    {"Nihonium", "Nh", 113, 284},
    {"Flerovium", "Fl", 114, 289},
    {"Moscovium", "Mc", 115, 288},
    {"Livermorium", "Lv", 116, 293},
    {"Tennessine", "Ts", 117, 294},
    {"Oganesson", "Og", 118, 294}
};

int main() {
    int correct_answers = 0;
    int total_questions = 0;
    char user_choice;

    do {
        // Generating a random element to ask the user about
        int random_index = rand() % NUM_ELEMENTS;
        Element random_element = elements[random_index];

        // Getting the user's answer
        printf("What is the symbol for %s?\n", random_element.name);
        char user_answer[MAX_SYMBOL_LENGTH];
        scanf("%s", user_answer);

        // Converting the user answer to uppercase for comparison
        for (int i = 0; i < MAX_SYMBOL_LENGTH; i++) {
            user_answer[i] = toupper(user_answer[i]);
        }

        // Comparing the user's answer to the correct answer
        if (strcmp(user_answer, random_element.symbol) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", random_element.symbol);
        }

        // Asking if the user wants to continue
        total_questions++;
        printf("Do you want to continue? (Y/N)\n");
        scanf(" %c", &user_choice); // the space before %c is important

    } while (toupper(user_choice) == 'Y');

    // Displaying the user's score after the quiz ends
    printf("You answered %d out of %d questions correctly.\n", correct_answers, total_questions);

    return 0;
}