//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
    char state[15];
} Element;

const int NUMBER_OF_ELEMENTS = 118;

Element periodic_table[118] = {
    {"H", "Hydrogen", 1, 1.008, "Gas"},
    {"He", "Helium", 2, 4.0026, "Gas"},
    {"Li", "Lithium", 3, 6.94, "Solid"},
    {"Be", "Beryllium", 4, 9.0122, "Solid"},
    {"B", "Boron", 5, 10.81, "Solid"},
    {"C", "Carbon", 6, 12.011, "Solid"},
    {"N", "Nitrogen", 7, 14.007, "Gas"},
    {"O", "Oxygen", 8, 15.999, "Gas"},
    {"F", "Fluorine", 9, 18.998, "Gas"},
    {"Ne", "Neon", 10, 20.180, "Gas"},
    {"Na", "Sodium", 11, 22.990, "Solid"},
    {"Mg", "Magnesium", 12, 24.305, "Solid"},
    {"Al", "Aluminum", 13, 26.982, "Solid"},
    {"Si", "Silicon", 14, 28.086, "Solid"},
    {"P", "Phosphorus", 15, 30.974, "Solid"},
    {"S", "Sulfur", 16, 32.066, "Solid"},
    {"Cl", "Chlorine", 17, 35.453, "Gas"},
    {"Ar", "Argon", 18, 39.948, "Gas"},
    {"K", "Potassium", 19, 39.098, "Solid"},
    {"Ca", "Calcium", 20, 40.078, "Solid"},
    {"Sc", "Scandium", 21, 44.956, "Solid"},
    {"Ti", "Titanium", 22, 47.867, "Solid"},
    {"V", "Vanadium", 23, 50.942, "Solid"},
    {"Cr", "Chromium", 24, 51.996, "Solid"},
    {"Mn", "Manganese", 25, 54.938, "Solid"},
    {"Fe", "Iron", 26, 55.845, "Solid"},
    {"Co", "Cobalt", 27, 58.933, "Solid"},
    {"Ni", "Nickel", 28, 58.693, "Solid"},
    {"Cu", "Copper", 29, 63.546, "Solid"},
    {"Zn", "Zinc", 30, 65.38, "Solid"},
    {"Ga", "Gallium", 31, 69.723, "Solid"},
    {"Ge", "Germanium", 32, 72.63, "Solid"},
    {"As", "Arsenic", 33, 74.922, "Solid"},
    {"Se", "Selenium", 34, 78.96, "Solid"},
    {"Br", "Bromine", 35, 79.904, "Liquid"},
    {"Kr", "Krypton", 36, 83.798, "Gas"},
    {"Rb", "Rubidium", 37, 85.468, "Solid"},
    {"Sr", "Strontium", 38, 87.62, "Solid"},
    {"Y", "Yttrium", 39, 88.906, "Solid"},
    {"Zr", "Zirconium", 40, 91.224, "Solid"},
    {"Nb", "Niobium", 41, 92.906, "Solid"},
    {"Mo", "Molybdenum", 42, 95.94, "Solid"},
    {"Tc", "Technetium", 43, 98, "Unknown"},
    {"Ru", "Ruthenium", 44, 101.07, "Solid"},
    {"Rh", "Rhodium", 45, 102.91, "Solid"},
    {"Pd", "Palladium", 46, 106.42, "Solid"},
    {"Ag", "Silver", 47, 107.87, "Solid"},
    {"Cd", "Cadmium", 48, 112.41, "Solid"},
    {"In", "Indium", 49, 114.82, "Solid"},
    {"Sn", "Tin", 50, 118.71, "Solid"},
    {"Sb", "Antimony", 51, 121.76, "Solid"},
    {"Te", "Tellurium", 52, 127.6, "Solid"},
    {"I", "Iodine", 53, 126.90, "Solid"},
    {"Xe", "Xenon", 54, 131.29, "Gas"},
    {"Cs", "Cesium", 55, 132.91, "Solid"},
    {"Ba", "Barium", 56, 137.33, "Solid"},
    {"La", "Lanthanum", 57, 138.91, "Solid"},
    {"Ce", "Cerium", 58, 140.12, "Solid"},
    {"Pr", "Praseodymium", 59, 140.91, "Solid"},
    {"Nd", "Neodymium", 60, 144.24, "Solid"},
    {"Pm", "Promethium", 61, 145, "Unknown"},
    {"Sm", "Samarium", 62, 150.36, "Solid"},
    {"Eu", "Europium", 63, 151.96, "Solid"},
    {"Gd", "Gadolinium", 64, 157.25, "Solid"},
    {"Tb", "Terbium", 65, 158.93, "Solid"},
    {"Dy", "Dysprosium", 66, 162.50, "Solid"},
    {"Ho", "Holmium", 67, 164.93, "Solid"},
    {"Er", "Erbium", 68, 167.26, "Solid"},
    {"Tm", "Thulium", 69, 168.93, "Solid"},
    {"Yb", "Ytterbium", 70, 173.05, "Solid"},
    {"Lu", "Lutetium", 71, 174.97, "Solid"},
    {"Hf", "Hafnium", 72, 178.49, "Solid"},
    {"Ta", "Tantalum", 73, 180.95, "Solid"},
    {"W", "Tungsten", 74, 183.84, "Solid"},
    {"Re", "Rhenium", 75, 186.21, "Solid"},
    {"Os", "Osmium", 76, 190.23, "Solid"},
    {"Ir", "Iridium", 77, 192.22, "Solid"},
    {"Pt", "Platinum", 78, 195.08, "Solid"},
    {"Au", "Gold", 79, 196.97, "Solid"},
    {"Hg", "Mercury", 80, 200.59, "Liquid"},
    {"Tl", "Thallium", 81, 204.38, "Solid"},
    {"Pb", "Lead", 82, 207.2, "Solid"},
    {"Bi", "Bismuth", 83, 208.98, "Solid"},
    {"Th", "Thorium", 90, 232.04, "Solid"},
    {"Pa", "Protactinium", 91, 231.04, "Solid"},
    {"U", "Uranium", 92, 238.03, "Solid"},
    {"Np", "Neptunium", 93, 237.05, "Unknown"},
    {"Pu", "Plutonium", 94, 244, "Unknown"},
    {"Am", "Americium", 95, 243, "Unknown"},
    {"Cm", "Curium", 96, 247, "Unknown"},
    {"Bk", "Berkelium", 97, 247, "Unknown"},
    {"Cf", "Californium", 98, 251, "Unknown"},
    {"Es", "Einsteinium", 99, 252, "Unknown"},
    {"Fm", "Fermium", 100, 257, "Unknown"},
    {"Md", "Mendelevium", 101, 258, "Unknown"},
    {"No", "Nobelium", 102, 259, "Unknown"},
    {"Lr", "Lawrencium", 103, 262, "Unknown"},
    {"Rf", "Rutherfordium", 104, 267, "Unknown"},
    {"Db", "Dubnium", 105, 270, "Unknown"},
    {"Sg", "Seaborgium", 106, 271, "Unknown"},
    {"Bh", "Bohrium", 107, 270, "Unknown"},
    {"Hs", "Hassium", 108, 277, "Unknown"},
    {"Mt", "Meitnerium", 109, 276, "Unknown"},
    {"Ds", "Darmstadtium", 110, 281, "Unknown"},
    {"Rg", "Roentgenium", 111, 280, "Unknown"},
    {"Cn", "Copernicium", 112, 285, "Unknown"},
    {"Nh", "Nihonium", 113, 284, "Unknown"},
    {"Fl", "Flerovium", 114, 289, "Unknown"},
    {"Mc", "Moscovium", 115, 288, "Unknown"},
    {"Lv", "Livermorium", 116, 293, "Unknown"},
    {"Ts", "Tennessine", 117, 294, "Unknown"},
    {"Og", "Oganesson", 118, 294, "Unknown"}
};

void capitalize(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

char get_grade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else if (score >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void print_element_info(Element element) {
    printf("\nSymbol: %s\n", element.symbol);
    printf("Name: %s\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Atomic Weight: %f\n", element.atomic_weight);
    printf("State: %s\n", element.state);
}

int main() {
    char symbol[3];
    int score = 0;
    int i;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be presented with the symbol of an element and you must enter the name of that element.\n");
    printf("Let's get started!\n");

    for (i = 1; i <= NUMBER_OF_ELEMENTS; i++) {
        Element current_element = periodic_table[i-1];
        printf("\n%d. What is the name of the element with the symbol %s?\n", i, current_element.symbol);
        printf("Enter your answer: ");
        scanf("%s", symbol);
        capitalize(symbol);

        if (strcmp(symbol, current_element.name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", current_element.name);
        }
    }

    float percentage = ((float)score / NUMBER_OF_ELEMENTS) * 100;
    char grade = get_grade(percentage);

    printf("\nCongratulations! You scored %d out of %d (%.2f%%).\n", score, NUMBER_OF_ELEMENTS, percentage);
    printf("Your final grade is %c.\n", grade);

    printf("\nWould you like to see the information of a specific element? Enter Y for Yes or N for No: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        printf("\nEnter the symbol of the element you would like to see the information of: ");
        scanf("%s", symbol);
        capitalize(symbol);

        for (i = 0; i < NUMBER_OF_ELEMENTS; i++) {
            if (strcmp(symbol, periodic_table[i].symbol) == 0) {
                print_element_info(periodic_table[i]);
                break;
            }
        }
    }

    printf("\nThank you for playing the C Periodic Table Quiz!\n");

    return 0;
}