//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    /* Define an array of element symbols */
    char symbols[118][3] = {
        "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne", "Na",
        "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca", "Sc", "Ti",
        "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As",
        "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru",
        "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs",
        "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy",
        "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir",
        "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Th", "Pa", "U",  "Np", "Pu",
        "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"
    };
    
    /* Define an array of element names */
    char names[118][30] = {
        "Hydrogen",       "Helium",         "Lithium",         "Beryllium",
        "Boron",          "Carbon",         "Nitrogen",        "Oxygen",
        "Fluorine",       "Neon",           "Sodium",          "Magnesium",
        "Aluminum",       "Silicon",        "Phosphorus",      "Sulfur",
        "Chlorine",       "Argon",          "Potassium",       "Calcium",
        "Scandium",       "Titanium",       "Vanadium",        "Chromium",
        "Manganese",      "Iron",           "Cobalt",          "Nickel",
        "Copper",         "Zinc",           "Gallium",         "Germanium",
        "Arsenic",        "Selenium",       "Bromine",         "Krypton",
        "Rubidium",       "Strontium",      "Yttrium",         "Zirconium",
        "Niobium",        "Molybdenum",     "Technetium",      "Ruthenium",
        "Rhodium",        "Palladium",      "Silver",          "Cadmium",
        "Indium",         "Tin",            "Antimony",        "Tellurium",
        "Iodine",         "Xenon",          "Cesium",          "Barium",
        "Lanthanum",      "Cerium",         "Praseodymium",    "Neodymium",
        "Promethium",     "Samarium",       "Europium",        "Gadolinium",
        "Terbium",        "Dysprosium",     "Holmium",         "Erbium",
        "Thulium",        "Ytterbium",      "Lutetium",        "Hafnium",
        "Tantalum",       "Tungsten",       "Rhenium",         "Osmium",
        "Iridium",        "Platinum",       "Gold",            "Mercury",
        "Thallium",       "Lead",           "Bismuth",         "Thorium",
        "Protactinium",   "Uranium",        "Neptunium",       "Plutonium",
        "Americium",      "Curium",         "Berkelium",       "Californium",
        "Einsteinium",    "Fermium",        "Mendelevium",     "Nobelium",
        "Lawrencium"
    };

    /* Define an array of element atomic numbers */
    int atomic_numbers[118] = {
        1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
        12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,
        23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,
        34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
        45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,
        56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,
        67,  68,  69,  70,  71,  72,  73,  74,  75,  76,  77,
        78,  79,  80,  81,  82,  83,  90,  91,  92,  93,  94,
        95,  96,  97,  98,  99, 100, 101, 102, 103, 104, 105,
        106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116,
        117, 118
    };
    
    /* Define the quiz questions and answers */
    char questions[10][50] = {
        "What is the symbol for oxygen?", 
        "What is the atomic number for iron?", 
        "What is the name of the element with symbol F?", 
        "What is the symbol for potassium?", 
        "What is the atomic number for nitrogen?", 
        "What is the name of the element with symbol Cu?", 
        "What is the symbol for nickel?", 
        "What is the atomic number for helium?", 
        "What is the name of the element with symbol Ag?", 
        "What is the symbol for neon?"
    };
    
    char answers[10][30] = {
        "O", "26", "Fluorine", "K", "7", "Copper", "Ni", "2", "Silver", "Ne"
    };
    
    int score = 0;
    char user_answer[30];
    
    /* Welcome message */
    printf("Welcome to a Periodic Table Quiz!\n\n");
    
    /* Iterate through each question and get user input */
    for (int i = 0; i < 10; i++) {
        printf("%s\n", questions[i]);
        printf("Your Answer: ");
        scanf("%s", user_answer);
        printf("\n");
        
        /* Check if answer is correct */
        if (strcmp(user_answer, answers[i]) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", answers[i]);
        }
    }
    
    /* Print final score */
    printf("Quiz Complete! You scored %d out of 10.\n", score);
    
    return 0;
}