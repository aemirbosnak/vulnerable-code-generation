//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for periodic table elements */
struct Element {
    char symbol[3];
    char name[20];
    int atomic_number;
    char category[20];
};

/* Declare an array of elements */
struct Element table[] = {
    {"H", "Hydrogen", 1, "Nonmetal"},
    {"He", "Helium", 2, "Noble Gas"},
    {"Li", "Lithium", 3, "Alkali Metal"},
    {"Be", "Beryllium", 4, "Alkaline Earth Metal"},
    {"B", "Boron", 5, "Metalloid"},
    {"C", "Carbon", 6, "Nonmetal"},
    {"N", "Nitrogen", 7, "Nonmetal"},
    {"O", "Oxygen", 8, "Nonmetal"},
    {"F", "Fluorine", 9, "Halogen"},
    {"Ne", "Neon", 10, "Noble Gas"},
    {"Na", "Sodium", 11, "Alkali Metal"},
    {"Mg", "Magnesium", 12, "Alkaline Earth Metal"},
    {"Al", "Aluminum", 13, "Metal"},
    {"Si", "Silicon", 14, "Metalloid"},
    {"P", "Phosphorus", 15, "Nonmetal"},
    {"S", "Sulfur", 16, "Nonmetal"},
    {"Cl", "Chlorine", 17, "Halogen"},
    {"Ar", "Argon", 18, "Noble Gas"},
    {"K", "Potassium", 19, "Alkali Metal"},
    {"Ca", "Calcium", 20, "Alkaline Earth Metal"},
    {"Sc", "Scandium", 21, "Transition Metal"},
    {"Ti", "Titanium", 22, "Transition Metal"},
    {"V", "Vanadium", 23, "Transition Metal"},
    {"Cr", "Chromium", 24, "Transition Metal"},
    {"Mn", "Manganese", 25, "Transition Metal"},
    {"Fe", "Iron", 26, "Transition Metal"},
    {"Co", "Cobalt", 27, "Transition Metal"},
    {"Ni", "Nickel", 28, "Transition Metal"},
    {"Cu", "Copper", 29, "Transition Metal"},
    {"Zn", "Zinc", 30, "Transition Metal"},
    {"Ga", "Gallium", 31, "Metal"},
    {"Ge", "Germanium", 32, "Metalloid"},
    {"As", "Arsenic", 33, "Metalloid"},
    {"Se", "Selenium", 34, "Nonmetal"},
    {"Br", "Bromine", 35, "Halogen"},
    {"Kr", "Krypton", 36, "Noble Gas"},
    {"Rb", "Rubidium", 37, "Alkali Metal"},
    {"Sr", "Strontium", 38, "Alkaline Earth Metal"},
    {"Y", "Yttrium", 39, "Transition Metal"},
    {"Zr", "Zirconium", 40, "Transition Metal"},
    {"Nb", "Niobium", 41, "Transition Metal"},
    {"Mo", "Molybdenum", 42, "Transition Metal"},
    {"Tc", "Technetium", 43, "Transition Metal"},
    {"Ru", "Ruthenium", 44, "Transition Metal"},
    {"Rh", "Rhodium", 45, "Transition Metal"},
    {"Pd", "Palladium", 46, "Transition Metal"},
    {"Ag", "Silver", 47, "Transition Metal"},
    {"Cd", "Cadmium", 48, "Transition Metal"},
    {"In", "Indium", 49, "Metal"},
    {"Sn", "Tin", 50, "Metal"},
    {"Sb", "Antimony", 51, "Metalloid"},
    {"Te", "Tellurium", 52, "Metalloid"},
    {"I", "Iodine", 53, "Halogen"},
    {"Xe", "Xenon", 54, "Noble Gas"},
    {"Cs", "Cesium", 55, "Alkali Metal"},
    {"Ba", "Barium", 56, "Alkaline Earth Metal"},
    {"La", "Lanthanum", 57, "Lanthanide"},
    {"Ce", "Cerium", 58, "Lanthanide"},
    {"Pr", "Praseodymium", 59, "Lanthanide"},
    {"Nd", "Neodymium", 60, "Lanthanide"},
    {"Pm", "Promethium", 61, "Lanthanide"},
    {"Sm", "Samarium", 62, "Lanthanide"},
    {"Eu", "Europium", 63, "Lanthanide"},
    {"Gd", "Gadolinium", 64, "Lanthanide"},
    {"Tb", "Terbium", 65, "Lanthanide"},
    {"Dy", "Dysprosium", 66, "Lanthanide"},
    {"Ho", "Holmium", 67, "Lanthanide"},
    {"Er", "Erbium", 68, "Lanthanide"},
    {"Tm", "Thulium", 69, "Lanthanide"},
    {"Yb", "Ytterbium", 70, "Lanthanide"},
    {"Lu", "Lutetium", 71, "Lanthanide"},
    {"Hf", "Hafnium", 72, "Transition Metal"},
    {"Ta", "Tantalum", 73, "Transition Metal"},
    {"W", "Tungsten", 74, "Transition Metal"},
    {"Re", "Rhenium", 75, "Transition Metal"},
    {"Os", "Osmium", 76, "Transition Metal"},
    {"Ir", "Iridium", 77, "Transition Metal"},
    {"Pt", "Platinum", 78, "Transition Metal"},
    {"Au", "Gold", 79, "Transition Metal"},
    {"Hg", "Mercury", 80, "Transition Metal"},
    {"Tl", "Thallium", 81, "Metal"},
    {"Pb", "Lead", 82, "Metal"},
    {"Bi", "Bismuth", 83, "Metal"},
    {"Po", "Polonium", 84, "Metal"},
    {"At", "Astatine", 85, "Halogen"},
    {"Rn", "Radon", 86, "Noble Gas"},
    {"Fr", "Francium", 87, "Alkali Metal"},
    {"Ra", "Radium", 88, "Alkaline Earth Metal"},
    {"Ac", "Actinium", 89, "Actinide"},
    {"Th", "Thorium", 90, "Actinide"},
    {"Pa", "Protactinium", 91, "Actinide"},
    {"U", "Uranium", 92, "Actinide"},
    {"Np", "Neptunium", 93, "Actinide"},
    {"Pu", "Plutonium", 94, "Actinide"},
    {"Am", "Americium", 95, "Actinide"},
    {"Cm", "Curium", 96, "Actinide"},
    {"Bk", "Berkelium", 97, "Actinide"},
    {"Cf", "Californium", 98, "Actinide"},
    {"Es", "Einsteinium", 99, "Actinide"},
    {"Fm", "Fermium", 100, "Actinide"},
    {"Md", "Mendelevium", 101, "Actinide"},
    {"No", "Nobelium", 102, "Actinide"},
    {"Lr", "Lawrencium", 103, "Actinide"}
};

/* Declare function for printing element information */
void print_element(struct Element e) {
    printf("%s:\n", e.symbol);
    printf("Name: %s\n", e.name);
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Category: %s\n", e.category);
}

int main() {
    /* Initialize variables for user input and validation */
    char symbol[3];
    int found = 0;

    /* Prompt user for symbol and validate 
    until a valid element is entered */
    do {
        printf("Enter an element symbol (case-sensitive): ");
        scanf("%s", symbol);
        for (int i = 0; i < sizeof(table) / sizeof(table[0]); i++) {
            if (strcmp(table[i].symbol, symbol) == 0) {
                print_element(table[i]);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Invalid symbol. Try again.\n");
        }
    } while (!found);

    return 0;
}