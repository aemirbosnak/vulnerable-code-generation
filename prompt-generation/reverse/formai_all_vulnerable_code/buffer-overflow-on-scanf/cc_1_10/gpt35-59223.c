//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: relaxed
#include<stdio.h>

int main()
{
    // welcome message
    printf("Welcome to the Periodic Table Quiz!\n\n");

    // an array containing all the elements and their symbols
    char elements[118][20] = {
        "Hydrogen", "H",
        "Helium", "He",
        "Lithium", "Li",
        "Beryllium", "Be",
        "Boron", "B",
        "Carbon", "C",
        "Nitrogen", "N",
        "Oxygen", "O",
        "Fluorine", "F",
        "Neon", "Ne",
        "Sodium", "Na",
        "Magnesium", "Mg",
        "Aluminum", "Al",
        "Silicon", "Si",
        "Phosphorus", "P",
        "Sulfur", "S",
        "Chlorine", "Cl",
        "Argon", "Ar",
        "Potassium", "K",
        "Calcium", "Ca",
        "Scandium", "Sc",
        "Titanium", "Ti",
        "Vanadium", "V",
        "Chromium", "Cr",
        "Manganese", "Mn",
        "Iron", "Fe",
        "Cobalt", "Co",
        "Nickel", "Ni",
        "Copper", "Cu",
        "Zinc", "Zn",
        "Gallium", "Ga",
        "Germanium", "Ge",
        "Arsenic", "As",
        "Selenium", "Se",
        "Bromine", "Br",
        "Krypton", "Kr",
        "Rubidium", "Rb",
        "Strontium", "Sr",
        "Yttrium", "Y",
        "Zirconium", "Zr",
        "Niobium", "Nb",
        "Molybdenum", "Mo",
        "Technetium", "Tc",
        "Ruthenium", "Ru",
        "Rhodium", "Rh",
        "Palladium", "Pd",
        "Silver", "Ag",
        "Cadmium", "Cd",
        "Indium", "In",
        "Tin", "Sn",
        "Antimony", "Sb",
        "Tellurium", "Te",
        "Iodine", "I",
        "Xenon", "Xe",
        "Cesium", "Cs",
        "Barium", "Ba",
        "Lanthanum", "La",
        "Cerium", "Ce",
        "Praseodymium", "Pr",
        "Neodymium", "Nd",
        "Promethium", "Pm",
        "Samarium", "Sm",
        "Europium", "Eu",
        "Gadolinium", "Gd",
        "Terbium", "Tb",
        "Dysprosium", "Dy",
        "Holmium", "Ho",
        "Erbium", "Er",
        "Thulium", "Tm",
        "Ytterbium", "Yb",
        "Lutetium", "Lu",
        "Hafnium", "Hf",
        "Tantalum", "Ta",
        "Tungsten", "W",
        "Rhenium", "Re",
        "Osmium", "Os",
        "Iridium", "Ir",
        "Platinum", "Pt",
        "Gold", "Au",
        "Mercury", "Hg",
        "Thallium", "Tl",
        "Lead", "Pb",
        "Bismuth", "Bi",
        "Polonium", "Po",
        "Astatine", "At",
        "Radon", "Rn",
        "Francium", "Fr",
        "Radium", "Ra",
        "Actinium", "Ac",
        "Thorium", "Th",
        "Protactinium", "Pa",
        "Uranium", "U",
        "Neptunium", "Np",
        "Plutonium", "Pu",
        "Americium", "Am",
        "Curium", "Cm",
        "Berkelium", "Bk",
        "Californium", "Cf",
        "Einsteinium", "Es",
        "Fermium", "Fm",
        "Mendelevium", "Md",
        "Nobelium", "No",
        "Lawrencium", "Lr",
        "Rutherfordium", "Rf",
        "Dubnium", "Db",
        "Seaborgium", "Sg",
        "Bohrium", "Bh",
        "Hassium", "Hs",
        "Meitnerium", "Mt",
        "Darmstadtium", "Ds",
        "Roentgenium", "Rg",
        "Copernicium", "Cn",
        "Nihonium", "Nh",
        "Flerovium", "Fl",
        "Moscovium", "Mc",
        "Livermorium", "Lv",
        "Tennessine", "Ts",
        "Oganesson", "Og"
    };

    int total_elements = 118;
    int score = 0;

    // loop to ask the user 5 random questions
    for (int i = 0; i < 5; i++) {
        // generate a random number between 0 and 117
        int random_element_index = rand() % total_elements;

        // get the name and symbol of the random element
        char *name = elements[random_element_index * 2];
        char *symbol = elements[random_element_index * 2 + 1];

        // show the question and prompt the user for an answer
        printf("Question %d: What is the symbol of %s?\n", i + 1, name);

        char answer[20];
        scanf("%s", answer);

        // check if the user's answer is correct
        if (strcmp(answer, symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", symbol);
        }

        printf("\n");
    }

    // show the user's final score
    printf("Quiz complete! You scored %d out of 5.\n", score);

    return 0;
}