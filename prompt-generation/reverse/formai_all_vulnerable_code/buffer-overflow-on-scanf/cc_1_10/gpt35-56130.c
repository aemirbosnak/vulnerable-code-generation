//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 20
#define NUM_ELEMENTS 118

// Define element struct
typedef struct element {
    int atomic_number;
    char symbol[3];
    char name[MAX_STRING_LENGTH];
    float atomic_mass;
} element_t;

// Define periodic table array
element_t periodic_table[NUM_ELEMENTS] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.0026},
    {3, "Li", "Lithium", 6.94},
    {4, "Be", "Beryllium", 9.0122},
    {5, "B", "Boron", 10.81},
    {6, "C", "Carbon", 12.011},
    {7, "N", "Nitrogen", 14.007},
    {8, "O", "Oxygen", 15.999},
    {9, "F", "Fluorine", 18.998},
    {10, "Ne", "Neon", 20.180},
    {11, "Na", "Sodium", 22.990},
    {12, "Mg", "Magnesium", 24.305},
    {13, "Al", "Aluminum", 26.982},
    {14, "Si", "Silicon", 28.086},
    {15, "P", "Phosphorus", 30.974},
    {16, "S", "Sulfur", 32.066},
    {17, "Cl", "Chlorine", 35.45},
    {18, "Ar", "Argon", 39.948},
    {19, "K", "Potassium", 39.098},
    {20, "Ca", "Calcium", 40.078},
    {21, "Sc", "Scandium", 44.956},
    {22, "Ti", "Titanium", 47.867},
    {23, "V", "Vanadium", 50.942},
    {24, "Cr", "Chromium", 51.996},
    {25, "Mn", "Manganese", 54.938},
    {26, "Fe", "Iron", 55.845},
    {27, "Co", "Cobalt", 58.933},
    {28, "Ni", "Nickel", 58.693},
    {29, "Cu", "Copper", 63.546},
    {30, "Zn", "Zinc", 65.38},
    {31, "Ga", "Gallium", 69.723},
    {32, "Ge", "Germanium", 72.630},
    {33, "As", "Arsenic", 74.922},
    {34, "Se", "Selenium", 78.960},
    {35, "Br", "Bromine", 79.904},
    {36, "Kr", "Krypton", 83.798},
    {37, "Rb", "Rubidium", 85.468},
    {38, "Sr", "Strontium", 87.62},
    {39, "Y", "Yttrium", 88.906},
    {40, "Zr", "Zirconium", 91.224},
    {41, "Nb", "Niobium", 92.906},
    {42, "Mo", "Molybdenum", 95.94},
    {43, "Tc", "Technetium", 98},
    {44, "Ru", "Ruthenium", 101.07},
    {45, "Rh", "Rhodium", 102.91},
    {46, "Pd", "Palladium", 106.42},
    {47, "Ag", "Silver", 107.87},
    {48, "Cd", "Cadmium", 112.41},
    {49, "In", "Indium", 114.82},
    {50, "Sn", "Tin", 118.71},
    {51, "Sb", "Antimony", 121.76},
    {52, "Te", "Tellurium", 127.60},
    {53, "I", "Iodine", 126.90},
    {54, "Xe", "Xenon", 131.29},
    {55, "Cs", "Cesium", 132.91},
    {56, "Ba", "Barium", 137.33},
    {57, "La", "Lanthanum", 138.91},
    {58, "Ce", "Cerium", 140.12},
    {59, "Pr", "Praseodymium", 140.91},
    {60, "Nd", "Neodymium", 144.24},
    {61, "Pm", "Promethium", 145},
    {62, "Sm", "Samarium", 150.36},
    {63, "Eu", "Europium", 151.96},
    {64, "Gd", "Gadolinium", 157.25},
    {65, "Tb", "Terbium", 158.93},
    {66, "Dy", "Dysprosium", 162.50},
    {67, "Ho", "Holmium", 164.93},
    {68, "Er", "Erbium", 167.26},
    {69, "Tm", "Thulium", 168.93},
    {70, "Yb", "Ytterbium", 173.05},
    {71, "Lu", "Lutetium", 174.97},
    {72, "Hf", "Hafnium", 178.49},
    {73, "Ta", "Tantalum", 180.95},
    {74, "W", "Tungsten", 183.84},
    {75, "Re", "Rhenium", 186.21},
    {76, "Os", "Osmium", 190.23},
    {77, "Ir", "Iridium", 192.22},
    {78, "Pt", "Platinum", 195.08},
    {79, "Au", "Gold", 196.97},
    {80, "Hg", "Mercury", 200.59},
    {81, "Tl", "Thallium", 204.38},
    {82, "Pb", "Lead", 207.2},
    {83, "Bi", "Bismuth", 208.98},
    {84, "Po", "Polonium", 209},
    {85, "At", "Astatine", 210},
    {86, "Rn", "Radon", 222},
    {87, "Fr", "Francium", 223},
    {88, "Ra", "Radium", 226},
    {89, "Ac", "Actinium", 227},
    {90, "Th", "Thorium", 232.04},
    {91, "Pa", "Protactinium", 231.04},
    {92, "U", "Uranium", 238.03},
    {93, "Np", "Neptunium", 237},
    {94, "Pu", "Plutonium", 244},
    {95, "Am", "Americium", 243},
    {96, "Cm", "Curium", 247},
    {97, "Bk", "Berkelium", 247},
    {98, "Cf", "Californium", 251},
    {99, "Es", "Einsteinium", 252},
    {100, "Fm", "Fermium", 257},
    {101, "Md", "Mendelevium", 258},
    {102, "No", "Nobelium", 259},
    {103, "Lr", "Lawrencium", 262},
    {104, "Rf", "Rutherfordium", 267},
    {105, "Db", "Dubnium", 270},
    {106, "Sg", "Seaborgium", 271},
    {107, "Bh", "Bohrium", 270},
    {108, "Hs", "Hassium", 277},
    {109, "Mt", "Meitnerium", 276},
    {110, "Ds", "Darmstadtium", 281},
    {111, "Rg", "Roentgenium", 280},
    {112, "Cn", "Copernicium", 285},
    {113, "Nh", "Nihonium", 284},
    {114, "Fl", "Flerovium", 289},
    {115, "Mc", "Moscovium", 288},
    {116, "Lv", "Livermorium", 293},
    {117, "Ts", "Tennessine", 294},
    {118, "Og", "Oganesson", 294}
};

// Prompt for atomic number and return index in periodic table array
int get_element_index() {
    int atomic_num;
    printf("Enter atomic number: ");
    scanf("%d", &atomic_num);
    
    // Ensure number is within periodic table range
    if (atomic_num < 1 || atomic_num > NUM_ELEMENTS) {
        printf("Invalid atomic number.\n");
        return -1;
    }
    
    return atomic_num - 1;
}

// Print element information
void print_element_info(element_t element) {
    printf("\n%s (%s)\n", element.name, element.symbol);
    printf("Atomic number: %d\n", element.atomic_number);
    printf("Atomic mass: %.4f amu\n", element.atomic_mass);
}

int main() {
    int index;
    char continue_prompt;
    
    do {
        // Get element index and print information
        index = get_element_index();
        if (index >= 0) {
            print_element_info(periodic_table[index]);    
        }
        
        // Prompt to continue
        printf("\nContinue? (Y/N): ");
        scanf(" %c", &continue_prompt);
    } while (continue_prompt == 'Y' || continue_prompt == 'y');
    
    return 0;
}