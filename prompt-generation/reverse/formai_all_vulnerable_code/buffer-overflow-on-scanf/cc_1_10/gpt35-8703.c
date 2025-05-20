//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for element data
typedef struct {
    char symbol[3];
    int atomic_number;
    char name[20];
    float atomic_mass;
} Element;

// Define prototype for function to display element data
void displayElementData(Element *);

int main() {
    // Initialize array with element data
    Element elements[118] = {
        {"H", 1, "Hydrogen", 1.008},
        {"He", 2, "Helium", 4.003},
        {"Li", 3, "Lithium", 6.941},
        {"Be", 4, "Beryllium", 9.012},
        {"B", 5, "Boron", 10.81},
        {"C", 6, "Carbon", 12.01},
        {"N", 7, "Nitrogen", 14.01},
        {"O", 8, "Oxygen", 16.00},
        {"F", 9, "Fluorine", 19.00},
        {"Ne", 10, "Neon", 20.18},
        {"Na", 11, "Sodium", 22.99},
        {"Mg", 12, "Magnesium", 24.31},
        {"Al", 13, "Aluminum", 26.98},
        {"Si", 14, "Silicon", 28.09},
        {"P", 15, "Phosphorus", 30.97},
        {"S", 16, "Sulfur", 32.07},
        {"Cl", 17, "Chlorine", 35.45},
        {"Ar", 18, "Argon", 39.95},
        {"K", 19, "Potassium", 39.10},
        {"Ca", 20, "Calcium", 40.08},
        {"Sc", 21, "Scandium", 44.96},
        {"Ti", 22, "Titanium", 47.87},
        {"V", 23, "Vanadium", 50.94},
        {"Cr", 24, "Chromium", 52.00},
        {"Mn", 25, "Manganese", 54.94},
        {"Fe", 26, "Iron", 55.85},
        {"Co", 27, "Cobalt", 58.93},
        {"Ni", 28, "Nickel", 58.69},
        {"Cu", 29, "Copper", 63.55},
        {"Zn", 30, "Zinc", 65.38},
        {"Ga", 31, "Gallium", 69.72},
        {"Ge", 32, "Germanium", 72.63},
        {"As", 33, "Arsenic", 74.92},
        {"Se", 34, "Selenium", 78.96},
        {"Br", 35, "Bromine", 79.90},
        {"Kr", 36, "Krypton", 83.80},
        {"Rb", 37, "Rubidium", 85.47},
        {"Sr", 38, "Strontium", 87.62},
        {"Y", 39, "Yttrium", 88.91},
        {"Zr", 40, "Zirconium", 91.22},
        {"Nb", 41, "Niobium", 92.91},
        {"Mo", 42, "Molybdenum", 95.94},
        {"Tc", 43, "Technetium", 98.00},
        {"Ru", 44, "Ruthenium", 101.07},
        {"Rh", 45, "Rhodium", 102.91},
        {"Pd", 46, "Palladium", 106.42},
        {"Ag", 47, "Silver", 107.87},
        {"Cd", 48, "Cadmium", 112.41},
        {"In", 49, "Indium", 114.82},
        {"Sn", 50, "Tin", 118.71},
        {"Sb", 51, "Antimony", 121.76},
        {"Te", 52, "Tellurium", 127.60},
        {"I", 53, "Iodine", 126.90},
        {"Xe", 54, "Xenon", 131.29},
        {"Cs", 55, "Cesium", 132.91},
        {"Ba", 56, "Barium", 137.33},
        {"La", 57, "Lanthanum", 138.91},
        {"Ce", 58, "Cerium", 140.12},
        {"Pr", 59, "Praseodymium", 140.91},
        {"Nd", 60, "Neodymium", 144.24},
        {"Pm", 61, "Promethium", 145.00},
        {"Sm", 62, "Samarium", 150.36},
        {"Eu", 63, "Europium", 151.96},
        {"Gd", 64, "Gadolinium", 157.25},
        {"Tb", 65, "Terbium", 158.93},
        {"Dy", 66, "Dysprosium", 162.50},
        {"Ho", 67, "Holmium", 164.93},
        {"Er", 68, "Erbium", 167.26},
        {"Tm", 69, "Thulium", 168.93},
        {"Yb", 70, "Ytterbium", 173.05},
        {"Lu", 71, "Lutetium", 174.97},
        {"Hf", 72, "Hafnium", 178.49},
        {"Ta", 73, "Tantalum", 180.95},
        {"W", 74, "Tungsten", 183.84},
        {"Re", 75, "Rhenium", 186.21},
        {"Os", 76, "Osmium", 190.23},
        {"Ir", 77, "Iridium", 192.22},
        {"Pt", 78, "Platinum", 195.08},
        {"Au", 79, "Gold", 196.97},
        {"Hg", 80, "Mercury", 200.59},
        {"Tl", 81, "Thallium", 204.38},
        {"Pb", 82, "Lead", 207.2},
        {"Bi", 83, "Bismuth", 208.98},
        {"Po", 84, "Polonium", 209.00},
        {"At", 85, "Astatine", 210.00},
        {"Rn", 86, "Radon", 222.00},
        {"Fr", 87, "Francium", 223.00},
        {"Ra", 88, "Radium", 226.03},
        {"Ac", 89, "Actinium", 227.03},
        {"Th", 90, "Thorium", 232.04},
        {"Pa", 91, "Protactinium", 231.04},
        {"U", 92, "Uranium", 238.03},
        {"Np", 93, "Neptunium", 237.05},
        {"Pu", 94, "Plutonium", 244.06},
        {"Am", 95, "Americium", 243.06},
        {"Cm", 96, "Curium", 247.07},
        {"Bk", 97, "Berkelium", 247.07},
        {"Cf", 98, "Californium", 251.08},
        {"Es", 99, "Einsteinium", 252.08},
        {"Fm", 100, "Fermium", 257.10},
        {"Md", 101, "Mendelevium", 258.10},
        {"No", 102, "Nobelium", 259.10},
        {"Lr", 103, "Lawrencium", 262.11},
        {"Rf", 104, "Rutherfordium", 267.12},
        {"Db", 105, "Dubnium", 270.13},
        {"Sg", 106, "Seaborgium", 271.14},
        {"Bh", 107, "Bohrium", 270.13},
        {"Hs", 108, "Hassium", 277.15},
        {"Mt", 109, "Meitnerium", 276.15},
        {"Ds", 110, "Darmstadtium", 281.16},
        {"Rg", 111, "Roentgenium", 280.16},
        {"Cn", 112, "Copernicium", 285.18},
        {"Nh", 113, "Nihonium", 284.18},
        {"Fl", 114, "Flerovium", 289.19},
        {"Mc", 115, "Moscovium", 288.19},
        {"Lv", 116, "Livermorium", 293.20},
        {"Ts", 117, "Tennessine", 294.21},
        {"Og", 118, "Oganesson", 294.21}
    };
    
    // Welcome message and instructions
    printf("*** Periodic Table Quiz ***\n");
    printf("Enter the atomic number of the element given the symbol:\n");
    
    // Randomly select 5 elements for quiz
    int i, rand_nums[5];
    printf("\n");
    for(i = 0; i < 5; i++) {
        rand_nums[i] = rand() % 118;
        printf("%d. %s\n", i+1, elements[rand_nums[i]].symbol);
    }
    
    // Prompt user for atomic number of each element and check answer
    int answer, correct = 0;
    for(i = 0; i < 5; i++) {
        printf("\n%s: ", elements[rand_nums[i]].symbol);
        scanf("%d", &answer);
        if(answer == elements[rand_nums[i]].atomic_number) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", elements[rand_nums[i]].atomic_number);
        }
    }
    
    // Display quiz results
    printf("\nYou got %d out of 5 correct.\n", correct);
    printf("Here are the element details:\n");
    for(i = 0; i < 5; i++) {
        displayElementData(&elements[rand_nums[i]]);
    }
    
    return 0;
}

void displayElementData(Element *element) {
    printf("\nSymbol: %s\n", element->symbol);
    printf("Atomic Number: %d\n", element->atomic_number);
    printf("Name: %s\n", element->name);
    printf("Atomic Mass: %.2f\n", element->atomic_mass);
}