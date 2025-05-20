//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ELEMENTS 118
#define MAX_ATTEMPTS 3

typedef struct {
    char symbol[3];
    char name[20]; 
} Element;

Element table[ELEMENTS] = {
    {"H",  "Hydrogen"},
    {"He", "Helium"},
    {"Li", "Lithium"},
    {"Be", "Beryllium"},
    {"B",  "Boron"},
    {"C",  "Carbon"},
    {"N",  "Nitrogen"},
    {"O",  "Oxygen"},
    {"F",  "Fluorine"},
    {"Ne", "Neon"},
    {"Na", "Sodium"},
    {"Mg", "Magnesium"},
    {"Al", "Aluminium"},
    {"Si", "Silicon"},
    {"P",  "Phosphorus"},
    {"S",  "Sulfur"},
    {"Cl", "Chlorine"},
    {"Ar", "Argon"},
    {"K",  "Potassium"},
    {"Ca", "Calcium"},
    {"Sc", "Scandium"},
    {"Ti", "Titanium"},
    {"V",  "Vanadium"},
    {"Cr", "Chromium"},
    {"Mn", "Manganese"},
    {"Fe", "Iron"},
    {"Co", "Cobalt"},
    {"Ni", "Nickel"},
    {"Cu", "Copper"},
    {"Zn", "Zinc"},
    {"Ga", "Gallium"},
    {"Ge", "Germanium"},
    {"As", "Arsenic"},
    {"Se", "Selenium"},
    {"Br", "Bromine"},
    {"Kr", "Krypton"},
    {"Rb", "Rubidium"},
    {"Sr", "Strontium"},
    {"Y",  "Yttrium"},
    {"Zr", "Zirconium"},
    {"Nb", "Niobium"},
    {"Mo", "Molybdenum"},
    {"Tc", "Technetium"},
    {"Ru", "Ruthenium"},
    {"Rh", "Rhodium"},
    {"Pd", "Palladium"},
    {"Ag", "Silver"},
    {"Cd", "Cadmium"},
    {"In", "Indium"},
    {"Sn", "Tin"},
    {"Sb", "Antimony"},
    {"Te", "Tellurium"},
    {"I",  "Iodine"},
    {"Xe", "Xenon"},
    {"Cs", "Cesium"},
    {"Ba", "Barium"},
    {"La", "Lanthanum"},
    {"Ce", "Cerium"},
    {"Pr", "Praseodymium"},
    {"Nd", "Neodymium"},
    {"Pm", "Promethium"},
    {"Sm", "Samarium"},
    {"Eu", "Europium"},
    {"Gd", "Gadolinium"},
    {"Tb", "Terbium"},
    {"Dy", "Dysprosium"},
    {"Ho", "Holmium"},
    {"Er", "Erbium"},
    {"Tm", "Thulium"},
    {"Yb", "Ytterbium"},
    {"Lu", "Lutetium"},
    {"Hf", "Hafnium"},
    {"Ta", "Tantalum"},
    {"W",  "Tungsten"},
    {"Re", "Rhenium"},
    {"Os", "Osmium"},
    {"Ir", "Iridium"},
    {"Pt", "Platinum"},
    {"Au", "Gold"},
    {"Hg", "Mercury"},
    {"Ti", "Thallium"},
    {"Pb", "Lead"},
    {"Bi", "Bismuth"},
    {"Po", "Polonium"},
    {"At", "Astatine"},
    {"Rn", "Radon"},
    {"Fr", "Francium"},
    {"Ra", "Radium"},
    {"Ac", "Actinium"},
    {"Th", "Thorium"},
    {"Pa", "Protactinium"},
    {"U",  "Uranium"},
    {"Np", "Neptunium"},
    {"Pu", "Plutonium"},
    {"Am", "Americium"},
    {"Cm", "Curium"},
    {"Bk", "Berkelium"},
    {"Cf", "Californium"},
    {"Es", "Einsteinium"},
    {"Fm", "Fermium"},
    {"Md", "Mendelevium"},
    {"No", "Nobelium"},
    {"Lr", "Lawrencium"},
    {"Rf", "Rutherfordium"},
    {"Db", "Dubnium"},
    {"Sg", "Seaborgium"},
    {"Bh", "Bohrium"},
    {"Hs", "Hassium"},
    {"Mt", "Meitnerium"},
    {"Ds", "Darmstadtium"},
    {"Rg", "Roentgenium"},
    {"Cn", "Copernicium"},
    {"Nh", "Nihonium"},
    {"Fl", "Flerovium"},
    {"Mc", "Moscovium"},
    {"Lv", "Livermorium"},
    {"Ts", "Tennessine"},
    {"Og", "Oganesson"}
};

void clear_screen() {
    system("clear||cls");
}

void print_header() {
    printf("+----------------------+------------------------+\n"
           "| Guess the Element     | Number of Attempts: %d |\n"
           "+----------------------+------------------------+\n\n", MAX_ATTEMPTS);
}

void print_element(Element element) {
    printf("+----------------------------------+\n"
           "| Symbol: %-3s    Name: %-12s |\n"
           "+----------------------------------+\n\n", element.symbol, element.name);
}

Element get_random_element() {
    srand(time(NULL));
    int random_index = rand() % ELEMENTS;
    return table[random_index];
}

int get_guess(Element element) {
    char guess[3];
    int attempts = MAX_ATTEMPTS;
    while (attempts > 0) {
        printf("Enter the symbol of the element (Attempt %d): ", MAX_ATTEMPTS - (attempts - 1));
        scanf("%s", guess);
        if (strcmp(guess, element.symbol) == 0) {
            printf("Correct Answer!\n\n");
            return 1;
        }
        else {
            attempts--;
            printf("Incorrect Answer (%d attempts left)!\n\n", attempts);
        }
    }
    printf("Out of attempts! The correct answer is %s (%s).\n\n", element.symbol, element.name);
    return 0;
}

int main() {
    clear_screen();
    print_header();
    Element element = get_random_element();
    print_element(element);
    get_guess(element);
    return 0;
}