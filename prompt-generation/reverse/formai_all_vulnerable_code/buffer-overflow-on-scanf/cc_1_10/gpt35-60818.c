//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomic_number;
    double atomic_weight;
} Element;

void print_menu(void);
void print_element(Element e);

void main()
{
    // Define the elements
    Element elements[MAX_ELEMENTS] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.003},
        {"Lithium", "Li", 3, 6.941},
        {"Beryllium", "Be", 4, 9.012},
        {"Boron", "B", 5, 10.811},
        {"Carbon", "C", 6, 12.011},
        {"Nitrogen", "N", 7, 14.007},
        {"Oxygen", "O", 8, 15.999},
        {"Fluorine", "F", 9, 18.998},
        {"Neon", "Ne", 10, 20.180},
        {"Sodium", "Na", 11, 22.990},
        {"Magnesium", "Mg", 12, 24.305},
        {"Aluminum", "Al", 13, 26.982},
        {"Silicon", "Si", 14, 28.086},
        {"Phosphorus", "P", 15, 30.974},
        {"Sulfur", "S", 16, 32.065},
        {"Chlorine", "Cl", 17, 35.453},
        {"Argon", "Ar", 18, 39.948},
        {"Potassium", "K", 19, 39.098},
        {"Calcium", "Ca", 20, 40.078},
        {"Scandium", "Sc", 21, 44.956},
        {"Titanium", "Ti", 22, 47.867},
        {"Vanadium", "V", 23, 50.942},
        {"Chromium", "Cr", 24, 52.000},
        {"Manganese", "Mn", 25, 54.938},
        {"Iron", "Fe", 26, 55.845},
        {"Cobalt", "Co", 27, 58.933},
        {"Nickel", "Ni", 28, 58.693},
        {"Copper", "Cu", 29, 63.546},
        {"Zinc", "Zn", 30, 65.390},
        {"Gallium", "Ga", 31, 69.723},
        {"Germanium", "Ge", 32, 72.610},
        {"Arsenic", "As", 33, 74.922},
        {"Selenium", "Se", 34, 78.960},
        {"Bromine", "Br", 35, 79.904},
        {"Krypton", "Kr", 36, 83.798},
        {"Rubidium", "Rb", 37, 85.468},
        {"Strontium", "Sr", 38, 87.620},
        {"Yttrium", "Y", 39, 88.906},
        {"Zirconium", "Zr", 40, 91.224},
        {"Niobium", "Nb", 41, 92.906},
        {"Molybdenum", "Mo", 42, 95.940},
        {"Technetium", "Tc", 43, 98.000}, // Only synthetic element in period 5
        {"Ruthenium", "Ru", 44, 101.070},
        {"Rhodium", "Rh", 45, 102.905},
        {"Palladium", "Pd", 46, 106.420},
        {"Silver", "Ag", 47, 107.868},
        {"Cadmium", "Cd", 48, 112.411},
        {"Indium", "In", 49, 114.818},
        {"Tin", "Sn", 50, 118.710},
        {"Antimony", "Sb", 51, 121.760},
        {"Tellurium", "Te", 52, 127.600},
        {"Iodine", "I", 53, 126.904},
        {"Xenon", "Xe", 54, 131.293},
        {"Cesium", "Cs", 55, 132.905},
        {"Barium", "Ba", 56, 137.327},
        {"Lanthanum", "La", 57, 138.905},
        {"Cerium", "Ce", 58, 140.116},
        {"Praseodymium", "Pr", 59, 140.908},
        {"Neodymium", "Nd", 60, 144.242},
        {"Promethium", "Pm", 61, 145.000}, // Only synthetic element in period 6
        {"Samarium", "Sm", 62, 150.360},
        {"Europium", "Eu", 63, 151.964},
        {"Gadolinium", "Gd", 64, 157.250},
        {"Terbium", "Tb", 65, 158.925},
        {"Dysprosium", "Dy", 66, 162.500},
        {"Holmium", "Ho", 67, 164.930},
        {"Erbium", "Er", 68, 167.259},
        {"Thulium", "Tm", 69, 168.934},
        {"Ytterbium", "Yb", 70, 173.054},
        {"Lutetium", "Lu", 71, 174.967},
        {"Hafnium", "Hf", 72, 178.490},
        {"Tantalum", "Ta", 73, 180.948},
        {"Tungsten", "W", 74, 183.840},
        {"Rhenium", "Re", 75, 186.207},
        {"Osmium", "Os", 76, 190.230},
        {"Iridium", "Ir", 77, 192.217},
        {"Platinum", "Pt", 78, 195.084},
        {"Gold", "Au", 79, 196.967},
        {"Mercury", "Hg", 80, 200.592},
        {"Thallium", "Tl", 81, 204.383},
        {"Lead", "Pb", 82, 207.200},
        {"Bismuth", "Bi", 83, 208.980},
        {"Polonium", "Po", 84, 209.000}, // Only synthetic element in period 6
        {"Astatine", "At", 85, 210.000}, // Only synthetic element in period 6
        {"Radon", "Rn", 86, 222.000}, // Only synthetic element in period 6
        {"Francium", "Fr", 87, 223.000}, // Only synthetic element in period 7
        {"Radium", "Ra", 88, 226.000},
        {"Actinium", "Ac", 89, 227.028},
        {"Thorium", "Th", 90, 232.038},
        {"Protactinium", "Pa", 91, 231.036},
        {"Uranium", "U", 92, 238.029},
        {"Neptunium", "Np", 93, 237.000}, // Only synthetic element in period 7
        {"Plutonium", "Pu", 94, 244.000}, // Only synthetic element in period 7
        {"Americium", "Am", 95, 243.000}, // Only synthetic element in period 7
        {"Curium", "Cm", 96, 247.000}, // Only synthetic element in period 7
        {"Berkelium", "Bk", 97, 247.000}, // Only synthetic element in period 7
        {"Californium", "Cf", 98, 251.000}, // Only synthetic element in period 7
        {"Einsteinium", "Es", 99, 252.000}, // Only synthetic element in period 7
        {"Fermium", "Fm", 100, 257.000}, // Only synthetic element in period 7
        {"Mendelevium", "Md", 101, 258.000}, // Only synthetic element in period 7
        {"Nobelium", "No", 102, 259.000}, // Only synthetic element in period 7
        {"Lawrencium", "Lr", 103, 262.000}, // Only synthetic element in period 7
        {"Rutherfordium", "Rf", 104, 267.000}, // Only synthetic element in period 7
        {"Dubnium", "Db", 105, 270.000}, // Only synthetic element in period 7
        {"Seaborgium", "Sg", 106, 271.000}, // Only synthetic element in period 7
        {"Bohrium", "Bh", 107, 270.000}, // Only synthetic element in period 7
        {"Hassium", "Hs", 108, 277.000}, // Only synthetic element in period 7
        {"Meitnerium", "Mt", 109, 276.000}, // Only synthetic element in period 7
        {"Darmstadtium", "Ds", 110, 281.000}, // Only synthetic element in period 7
        {"Roentgenium", "Rg", 111, 280.000}, // Only synthetic element in period 7
        {"Copernicium", "Cn", 112, 285.000}, // Only synthetic element in period 7
        {"Nihonium", "Nh", 113, 284.000}, // Only synthetic element in period 7
        {"Flerovium", "Fl", 114, 289.000}, // Only synthetic element in period 7
        {"Moscovium", "Mc", 115, 288.000}, // Only synthetic element in period 7
        {"Livermorium", "Lv", 116, 293.000}, // Only synthetic element in period 7
        {"Tennessine", "Ts", 117, 294.000}, // Only synthetic element in period 7
        {"Oganesson", "Og", 118, 294.000} // Only synthetic element in period 7
    };

    // Keep track of how many elements have been correctly identified
    int correct = 0;

    // Loop through 10 random elements
    for (int i = 0; i < 10; i++) {

        // Generate a random element
        int random_index = rand() % MAX_ELEMENTS;
        Element random_element = elements[random_index];

        // Print the element information
        print_element(random_element);

        // Prompt the user to enter the element symbol
        printf("Enter the symbol of the element: ");
        char input[3];
        scanf("%s", input);

        // Check if the user entered the correct symbol
        if (strcmp(input, random_element.symbol) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", random_element.symbol);
        }

        // Add a line break for clarity
        printf("\n");

    }

    // Print the user's score
    printf("You correctly identified %d out of 10 elements.\n", correct);

}

void print_menu(void)
{
    printf("=== Periodic Table Quiz ===\n");
    printf("Enter the symbol for each element shown.\n\n");
}

void print_element(Element e)
{
    printf("%s (%s)\n", e.name, e.symbol);
}