//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define CHEM_SIZ 118
#define SYM_SIZ 3

char* chem_syms[] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O",
    "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S",
    "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr",
    "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge",
    "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
    "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba",
    "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd",
    "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf",
    "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra",
    "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm",
    "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf",
    "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
    "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

float chem_mass[] = {
    1.008, 4.003, 6.94, 9.012, 10.81, 12.01, 14.01, 16.00,
    19.00, 20.18, 22.99, 24.31, 26.98, 28.09, 30.97, 32.07,
    35.45, 39.95, 39.10, 40.08, 44.96, 47.87, 50.94, 52.00,
    54.94, 55.85, 58.93, 58.69, 63.55, 65.39, 69.72, 72.63,
    74.92, 78.96, 79.90, 83.80, 85.47, 87.62, 88.91, 91.22,
    92.91, 95.94, 98.00, 101.1, 102.9, 106.4, 107.9, 112.4,
    114.8, 118.7, 121.8, 127.6, 126.9, 131.3, 132.9, 137.3,
    138.9, 140.1, 140.9, 144.2, 145.0, 150.4, 151.9, 157.3,
    158.9, 162.5, 164.9, 167.3, 168.9, 173.0, 175.0, 178.5,
    180.9, 183.8, 186.2, 190.2, 192.2, 195.1, 197.0, 200.6,
    204.4, 207.2, 208.9, 209.0, 210.0, 222.0, 223.0, 226.0,
    227.0, 232.0, 231.0, 238.0, 237.0, 244.1, 243.1, 247.1,
    247.1, 251.1, 252.1, 257.1, 258.1, 259.1, 266.1, 267.1,
    270.1, 269.1, 270.1, 281.1, 280.1, 285.1, 284.1, 289.2,
    288.2, 293.2, 294.2, 294.2
};

char* chem_names[] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon",
    "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium",
    "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon",
    "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium",
    "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium",
    "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium",
    "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum",
    "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium",
    "Indium", "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium",
    "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium",
    "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium",
    "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum",
    "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury",
    "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon",
    "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium",
    "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium",
    "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium",
    "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium",
    "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicum", "Nihonium",
    "Flerovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"
};

/* Function to convert uppercase letters to lowercase */
void to_lower(char* str) {
    for(int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

/* Function to check if symbol is valid */
int is_valid_sym(char* sym) {
    char first = sym[0];
    int val = atoi(sym+1);
    if(strlen(sym) == 1 && isupper(first)) {
        return 1;
    }
    else if(strlen(sym) == 2 && isupper(first) && val >= 1 && val <= 9) {
        return 1;
    }
    return 0;
}

/* Function to get element index from symbol */
int get_index(char* sym) {
    for(int i = 0; i < CHEM_SIZ; i++) {
        if(strcmp(sym, chem_syms[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int option, indx;
    char sym[SYM_SIZ], ans[SYM_SIZ];
    float mass, tolerance = 0.5; // Always +/- 0.5 for atomic mass

    printf("**** Welcome to the Periodic Table Quiz! ****\n\n");
    printf("Choose an option to continue:\n");
    do {
        printf("[1] Guess by symbol\n");
        printf("[2] Guess by name\n");
        printf("[0] Exit the program\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nGuess the element by symbol:\n");
                do {
                    printf("Symbol: ");
                    scanf("%s", sym);
                    to_lower(sym);
                } while(!is_valid_sym(sym));

                indx = get_index(sym);
                if(indx == -1) {
                    printf("Invalid symbol.\n");
                    continue;
                }

                printf("What is the atomic mass of %s?: ", chem_names[indx]);
                scanf("%f", &mass);

                if(mass >= chem_mass[indx]-tolerance && mass <= chem_mass[indx]+tolerance) {
                    printf("Correct answer!\n\n");
                }
                else {
                    printf("Incorrect answer. The correct answer was %.3f.\n\n", chem_mass[indx]);
                }
                break;

            case 2:
                printf("\nGuess the element by name:\n");
                do {
                    printf("Element name: ");
                    scanf("%s", ans);
                    to_lower(ans);
                } while(ans[0] == '\0');

                for(int i = 0; i < CHEM_SIZ; i++) {
                    if(strcmp(ans, chem_names[i]) == 0) {
                        printf("What is the symbol for %s?: ", ans);
                        scanf("%s", sym);
                        to_lower(sym);

                        if(strcmp(sym, chem_syms[i]) == 0) {
                            printf("Correct answer!\n\n");
                            break;
                        }
                        else {
                            printf("Incorrect answer. The correct answer was %s.\n\n", chem_syms[i]);
                            break;
                        }
                    }
                }

                printf("Element does not exist in the periodic table.\n\n");
                break;

            case 0:
                printf("\nThank you for playing the Periodic Table Quiz! Goodbye!\n");
                break;

            default:
                printf("\nInvalid option. Try again.\n\n");
                break;
        }
    } while(option != 0);

    return 0;
}