//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>
#include <string.h>
#define MAX_RETRIES 3

int main()
{
    char element[3], answer[10];
    int retries = 0;

    // Define the periodic table with element symbols and corresponding names
    char periodic_table[118][3] = {
        "H" , "Hydrogen",
        "He", "Helium",
        "Li", "Lithium",
        "Be", "Beryllium",
        "B" , "Boron",
        "C" , "Carbon",
        "N" , "Nitrogen",
        "O" , "Oxygen",
        "F" , "Fluorine",
        "Ne", "Neon",
        "Na", "Sodium",
        "Mg", "Magnesium",
        "Al", "Aluminum",
        "Si", "Silicon",
        "P" , "Phosphorus",
        "S" , "Sulfur",
        "Cl", "Chlorine",
        "Ar", "Argon",
        "K" , "Potassium",
        "Ca", "Calcium",
        "Sc", "Scandium",
        "Ti", "Titanium",
        "V" , "Vanadium",
        "Cr", "Chromium",
        "Mn", "Manganese",
        "Fe", "Iron",
        "Co", "Cobalt",
        "Ni", "Nickel",
        "Cu", "Copper",
        "Zn", "Zinc",
        "Ga", "Gallium",
        "Ge", "Germanium",
        "As", "Arsenic",
        "Se", "Selenium",
        "Br", "Bromine",
        "Kr", "Krypton",
        "Rb", "Rubidium",
        "Sr", "Strontium",
        "Y" , "Yttrium",
        "Zr", "Zirconium",
        "Nb", "Niobium",
        "Mo", "Molybdenum",
        "Tc", "Technetium",
        "Ru", "Ruthenium",
        "Rh", "Rhodium",
        "Pd", "Palladium",
        "Ag", "Silver",
        "Cd", "Cadmium",
        "In", "Indium",
        "Sn", "Tin",
        "Sb", "Antimony",
        "Te", "Tellurium",
        "I" , "Iodine",
        "Xe", "Xenon",
        "Cs", "Cesium",
        "Ba", "Barium",
        "La", "Lanthanum",
        "Ce", "Cerium",
        "Pr", "Praseodymium",
        "Nd", "Neodymium",
        "Pm", "Promethium",
        "Sm", "Samarium",
        "Eu", "Europium",
        "Gd", "Gadolinium",
        "Tb", "Terbium",
        "Dy", "Dysprosium",
        "Ho", "Holmium",
        "Er", "Erbium",
        "Tm", "Thulium",
        "Yb", "Ytterbium",
        "Lu", "Lutetium",
        "Hf", "Hafnium",
        "Ta", "Tantalum",
        "W" , "Tungsten",
        "Re", "Rhenium",
        "Os", "Osmium",
        "Ir", "Iridium",
        "Pt", "Platinum",
        "Au", "Gold",
        "Hg", "Mercury",
        "Tl", "Thallium",
        "Pb", "Lead",
        "Bi", "Bismuth",
        "Po", "Polonium",
        "At", "Astatine",
        "Rn", "Radon",
        "Fr", "Francium",
        "Ra", "Radium",
        "Ac", "Actinium",
        "Th", "Thorium",
        "Pa", "Protactinium",
        "U" , "Uranium",
        "Np", "Neptunium",
        "Pu", "Plutonium",
        "Am", "Americium",
        "Cm", "Curium",
        "Bk", "Berkelium",
        "Cf", "Californium",
        "Es", "Einsteinium",
        "Fm", "Fermium",
        "Md", "Mendelevium",
        "No", "Nobelium",
        "Lr", "Lawrencium",
        "Rf", "Rutherfordium",
        "Db", "Dubnium",
        "Sg", "Seaborgium",
        "Bh", "Bohrium",
        "Hs", "Hassium",
        "Mt", "Meitnerium",
        "Ds", "Darmstadtium",
        "Rg", "Roentgenium",
        "Cn", "Copernicium",
        "Nh", "Nihonium",
        "Fl", "Flerovium",
        "Mc", "Moscovium",
        "Lv", "Livermorium",
        "Ts", "Tennessine",
        "Og", "Oganesson",
    };

    // Welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be given a chemical symbol and must enter the corresponding element name.\n");
    printf("You have %d chances to get each question correctly.\n\n", MAX_RETRIES);

    // Loop through periodic table and quiz the user on each element
    for (int i = 0; i < 118; i++) {
        memset(answer, 0, sizeof answer);
        retries = 0;

        // Ask the user to enter the element name for the given symbol
        printf("What is the element with the chemical symbol '%s'? ", periodic_table[i][0]);
        scanf("%s", answer);

        // Compare the user's answer to the correct element name
        while (strncmp(answer, periodic_table[i][1], strlen(answer)) != 0) {
            if (++retries >= MAX_RETRIES) {
                printf("Sorry, you have exceeded the maximum number of retries.\n");
                break;
            }

            printf("Incorrect. Please try again (%d of %d chances left): ", MAX_RETRIES - retries, MAX_RETRIES);
            scanf("%s", answer);
        }

        // If the user gets the answer right
        if (strncmp(answer, periodic_table[i][1], strlen(answer)) == 0) {
            printf("Correct! The element with the chemical symbol '%s' is '%s'.\n", periodic_table[i][0], periodic_table[i][1]);
        }
    }

    // End of program message
    printf("\nCongratulations, you have completed the Periodic Table Quiz!\n");
    printf("Thank you for playing.\n");

    return 0;
}