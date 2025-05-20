//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 118 // maximum number of elements in the periodic table

typedef struct element {
    char symbol[3];     // chemical symbol
    char name[20];      // element name
    int atomic_number;  // atomic number
    char category[20];  // element category
    float atomic_weight;// atomic weight
} element;

int main() {
    char choice;    // user's choice of action
    int score = 0;   // user's current score
    int num_quiz = 0;// number of questions attempted
    
    element periodic_table[MAX] = {
        {"H", "Hydrogen", 1, "Non-metal", 1.008},
        {"He", "Helium", 2, "Noble gas", 4.003},
        {"Li", "Lithium", 3, "Alkali metal", 6.941},
        {"Be", "Beryllium", 4, "Alkaline earth metal", 9.012},
        {"B", "Boron", 5, "Metalloid", 10.81},
        {"C", "Carbon", 6, "Non-metal", 12.01},
        {"N", "Nitrogen", 7, "Non-metal", 14.01},
        {"O", "Oxygen", 8, "Non-metal", 16.00},
        {"F", "Fluorine", 9, "Halogen", 19.00},
        {"Ne", "Neon", 10, "Noble gas", 20.18},
        {"Na", "Sodium", 11, "Alkali metal", 22.99},
        {"Mg", "Magnesium", 12, "Alkaline earth metal", 24.31},
        {"Al", "Aluminum", 13, "Metal", 26.98},
        {"Si", "Silicon", 14, "Metalloid", 28.09},
        {"P", "Phosphorus", 15, "Non-metal", 30.97},
        {"S", "Sulfur", 16, "Non-metal", 32.07},
        {"Cl", "Chlorine", 17, "Halogen", 35.45},
        {"Ar", "Argon", 18, "Noble gas", 39.95},
        {"K", "Potassium", 19, "Alkali metal", 39.10},
        {"Ca", "Calcium", 20, "Alkaline earth metal", 40.08},
        {"Sc", "Scandium", 21, "Transition metal", 44.96},
        {"Ti", "Titanium", 22, "Transition metal", 47.87},
        {"V", "Vanadium", 23, "Transition metal", 50.94},
        {"Cr", "Chromium", 24, "Transition metal", 52.00},
        {"Mn", "Manganese", 25, "Transition metal", 54.94},
        {"Fe", "Iron", 26, "Transition metal", 55.85},
        {"Co", "Cobalt", 27, "Transition metal", 58.93},
        {"Ni", "Nickel", 28, "Transition metal", 58.69},
        {"Cu", "Copper", 29, "Transition metal", 63.55},
        {"Zn", "Zinc", 30, "Transition metal", 65.38},
        {"Ga", "Gallium", 31, "Metal", 69.72},
        {"Ge", "Germanium", 32, "Metalloid", 72.63},
        {"As", "Arsenic", 33, "Metalloid", 74.92},
        {"Se", "Selenium", 34, "Non-metal", 78.96},
        {"Br", "Bromine", 35, "Halogen", 79.90},
        {"Kr", "Krypton", 36, "Noble gas", 83.80},
        {"Rb", "Rubidium", 37, "Alkali metal", 85.47},
        {"Sr", "Strontium", 38, "Alkaline earth metal", 87.62},
        {"Y", "Yttrium", 39, "Transition metal", 88.91},
        {"Zr", "Zirconium", 40, "Transition metal", 91.22},
        {"Nb", "Niobium", 41, "Transition metal", 92.91},
        {"Mo", "Molybdenum", 42, "Transition metal", 95.94},
        {"Tc", "Technetium", 43, "Transition metal", 98.00},
        {"Ru", "Ruthenium", 44, "Transition metal", 101.07},
        {"Rh", "Rhodium", 45, "Transition metal", 102.91},
        {"Pd", "Palladium", 46, "Transition metal", 106.42},
        {"Ag", "Silver", 47, "Transition metal", 107.87},
        {"Cd", "Cadmium", 48, "Transition metal", 112.41},
        {"In", "Indium", 49, "Metal", 114.82},
        {"Sn", "Tin", 50, "Metal", 118.71},
        {"Sb", "Antimony", 51, "Metalloid", 121.76},
        {"Te", "Tellurium", 52, "Metalloid", 127.60},
        {"I", "Iodine", 53, "Halogen", 126.90},
        {"Xe", "Xenon", 54, "Noble gas", 131.29},
        {"Cs", "Cesium", 55, "Alkali metal", 132.91},
        {"Ba", "Barium", 56, "Alkaline earth metal", 137.33},
        {"La", "Lanthanum", 57, "Lanthanide", 138.91},
        {"Ce", "Cerium", 58, "Lanthanide", 140.12},
        {"Pr", "Praseodymium", 59, "Lanthanide", 140.91},
        {"Nd", "Neodymium", 60, "Lanthanide", 144.24},
        {"Pm", "Promethium", 61, "Lanthanide", 145.00},
        {"Sm", "Samarium", 62, "Lanthanide", 150.36},
        {"Eu", "Europium", 63, "Lanthanide", 151.96},
        {"Gd", "Gadolinium", 64, "Lanthanide", 157.25},
        {"Tb", "Terbium", 65, "Lanthanide", 158.93},
        {"Dy", "Dysprosium", 66, "Lanthanide", 162.50},
        {"Ho", "Holmium", 67, "Lanthanide", 164.93},
        {"Er", "Erbium", 68, "Lanthanide", 167.26},
        {"Tm", "Thulium", 69, "Lanthanide", 168.93},
        {"Yb", "Ytterbium", 70, "Lanthanide", 173.05},
        {"Lu", "Lutetium", 71, "Lanthanide", 174.97},
        {"Hf", "Hafnium", 72, "Transition metal", 178.49},
        {"Ta", "Tantalum", 73, "Transition metal", 180.95},
        {"W", "Tungsten", 74, "Transition metal", 183.84},
        {"Re", "Rhenium", 75, "Transition metal", 186.21},
        {"Os", "Osmium", 76, "Transition metal", 190.23},
        {"Ir", "Iridium", 77, "Transition metal", 192.22},
        {"Pt", "Platinum", 78, "Transition metal", 195.08},
        {"Au", "Gold", 79, "Transition metal", 196.97},
        {"Hg", "Mercury", 80, "Transition metal", 200.59},
        {"Tl", "Thallium", 81, "Metal", 204.38},
        {"Pb", "Lead", 82, "Metal", 207.2},
        {"Bi", "Bismuth", 83, "Metal", 208.98},
        {"Po", "Polonium", 84, "Metal", 209.00},
        {"At", "Astatine", 85, "Metalloid", 210.00},
        {"Rn", "Radon", 86, "Noble gas", 222.00},
        {"Fr", "Francium", 87, "Alkali metal", 223.00},
        {"Ra", "Radium", 88, "Alkaline earth metal", 226.03},
        {"Ac", "Actinium", 89, "Actinide", 227.03},
        {"Th", "Thorium", 90, "Actinide", 232.04},
        {"Pa", "Protactinium", 91, "Actinide", 231.04},
        {"U", "Uranium", 92, "Actinide", 238.03},
        {"Np", "Neptunium", 93, "Actinide", 237.05},
        {"Pu", "Plutonium", 94, "Actinide", 244.06},
        {"Am", "Americium", 95, "Actinide", 243.06},
        {"Cm", "Curium", 96, "Actinide", 247.07},
        {"Bk", "Berkelium", 97, "Actinide", 247.07},
        {"Cf", "Californium", 98, "Actinide", 251.08},
        {"Es", "Einsteinium", 99, "Actinide", 252.08},
        {"Fm", "Fermium", 100, "Actinide", 257.10},
        {"Md", "Mendelevium", 101, "Actinide", 258.10},
        {"No", "Nobelium", 102, "Actinide", 259.10},
        {"Lr", "Lawrencium", 103, "Actinide", 262.11},
        {"Rf", "Rutherfordium", 104, "Transition metal", 267.12},
        {"Db", "Dubnium", 105, "Transition metal", 270.13},
        {"Sg", "Seaborgium", 106, "Transition metal", 271.14},
        {"Bh", "Bohrium", 107, "Transition metal", 270.13},
        {"Hs", "Hassium", 108, "Transition metal", 277.16},
        {"Mt", "Meitnerium", 109, "Unknown", 276.15},
        {"Ds", "Darmstadtium", 110, "Unknown", 281.17},
        {"Rg", "Roentgenium", 111, "Unknown", 282.18},
        {"Cn", "Copernicium", 112, "Unknown", 285.18},
        {"Nh", "Nihonium", 113, "Unknown", 284.18},
        {"Fl", "Flerovium", 114, "Unknown", 289.19},
        {"Mc", "Moscovium", 115, "Unknown", 288.19},
        {"Lv", "Livermorium", 116, "Unknown", 293.20},
        {"Ts", "Tennessine", 117, "Unknown", 294.21},
        {"Og", "Oganesson", 118, "Unknown", 294.21}
    };

    // Greet the user
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Do you want to play? (y/n): ");
    scanf("%c", &choice);

    while ((choice == 'y') || (choice == 'Y')) {
        // Select an element randomly
        int index = rand() % MAX;

        // Prompt the user to identify the element
        printf("\nWhat is the chemical symbol of %s? ", periodic_table[index].name);

        char answer[3];
        scanf("%s", answer);

        // Convert the answer to upper case
        for (int i = 0; i < strlen(answer); i++) {
            answer[i] = toupper(answer[i]);
        }

        // Check the answer
        if (strcmp(answer, periodic_table[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", periodic_table[index].symbol);
        }

        num_quiz++;

        // Ask the user if they want to continue
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        // Clear the input buffer
        while (getchar() != '\n') {}

    }

    // Calculate the score percentage
    float percentage = (float)score / num_quiz * 100;

    // Display the final score
    printf("\nYour score is %d out of %d (%.2f%%).\n", score, num_quiz, percentage);

    return 0;
}