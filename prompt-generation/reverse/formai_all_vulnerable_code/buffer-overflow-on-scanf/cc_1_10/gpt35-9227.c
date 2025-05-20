//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118 // total no. of elements
#define MAX_ANS_LEN 5 // maximum length of answer
#define MAX_QUESTIONS 10 // number of questions in one round

char* elements[MAX_ELEMENTS][2] = { // list of elements and their symbols
    {"Hydrogen", "H"}, {"Helium", "He"}, {"Lithium", "Li"}, {"Beryllium", "Be"}, {"Boron", "B"}, {"Carbon", "C"},
    {"Nitrogen", "N"}, {"Oxygen", "O"}, {"Fluorine", "F"}, {"Neon", "Ne"}, {"Sodium", "Na"}, {"Magnesium", "Mg"}, 
    {"Aluminum", "Al"}, {"Silicon", "Si"}, {"Phosphorus", "P"}, {"Sulfur", "S"}, {"Chlorine", "Cl"}, {"Argon", "Ar"}, 
    {"Potassium", "K"}, {"Calcium", "Ca"}, {"Scandium", "Sc"}, {"Titanium", "Ti"}, {"Vanadium", "V"}, {"Chromium", "Cr"}, 
    {"Manganese", "Mn"}, {"Iron", "Fe"}, {"Cobalt", "Co"}, {"Nickel", "Ni"}, {"Copper", "Cu"}, {"Zinc", "Zn"}, 
    {"Gallium", "Ga"}, {"Germanium", "Ge"}, {"Arsenic", "As"}, {"Selenium", "Se"}, {"Bromine", "Br"}, {"Krypton", "Kr"}, 
    {"Rubidium", "Rb"}, {"Strontium", "Sr"}, {"Yttrium", "Y"}, {"Zirconium", "Zr"}, {"Niobium", "Nb"}, 
    {"Molybdenum", "Mo"}, {"Technetium", "Tc"}, {"Ruthenium", "Ru"}, {"Rhodium", "Rh"}, {"Palladium", "Pd"}, 
    {"Silver", "Ag"}, {"Cadmium", "Cd"}, {"Indium", "In"}, {"Tin", "Sn"}, {"Antimony", "Sb"}, 
    {"Tellurium", "Te"}, {"Iodine", "I"}, {"Xenon", "Xe"}, {"Cesium", "Cs"}, {"Barium", "Ba"}, 
    {"Lanthanum", "La"}, {"Cerium", "Ce"}, {"Praseodymium", "Pr"}, {"Neodymium", "Nd"}, {"Promethium", "Pm"}, 
    {"Samarium", "Sm"}, {"Europium", "Eu"}, {"Gadolinium", "Gd"}, {"Terbium", "Tb"}, {"Dysprosium", "Dy"}, 
    {"Holmium", "Ho"}, {"Erbium", "Er"}, {"Thulium", "Tm"}, {"Ytterbium", "Yb"}, {"Lutetium", "Lu"}, 
    {"Hafnium", "Hf"}, {"Tantalum", "Ta"}, {"Tungsten", "W"}, {"Rhenium", "Re"}, {"Osmium", "Os"}, 
    {"Iridium", "Ir"}, {"Platinum", "Pt"}, {"Gold", "Au"}, {"Mercury", "Hg"}, {"Thallium", "Tl"}, 
    {"Lead", "Pb"}, {"Bismuth", "Bi"}, {"Polonium", "Po"}, {"Astatine", "At"}, {"Radon", "Rn"}, 
    {"Francium", "Fr"}, {"Radium", "Ra"}, {"Actinium", "Ac"}, {"Thorium", "Th"}, {"Protactinium", "Pa"}, 
    {"Uranium", "U"}, {"Neptunium", "Np"}, {"Plutonium", "Pu"}, {"Americium", "Am"}, {"Curium", "Cm"}, 
    {"Berkelium", "Bk"}, {"Californium", "Cf"}, {"Einsteinium", "Es"}, {"Fermium", "Fm"}, {"Mendelevium", "Md"}, 
    {"Nobelium", "No"}, {"Lawrencium", "Lr"}, {"Rutherfordium", "Rf"}, {"Dubnium", "Db"}, {"Seaborgium", "Sg"}, 
    {"Bohrium", "Bh"}, {"Hassium", "Hs"}, {"Meitnerium", "Mt"}, {"Darmstadtium", "Ds"}, {"Roentgenium", "Rg"}, 
    {"Copernicium", "Cn"}, {"Nihonium", "Nh"}, {"Flerovium", "Fl"}, {"Moscovium", "Mc"}, {"Livermorium", "Lv"}, 
    {"Tennessine", "Ts"}, {"Oganesson", "Og"}};

int generate_random() { // returns a randomly generated element index
    return rand() % MAX_ELEMENTS;
}

int check_answer(char* symbol, char* answer) { // checks if the answer is correct
    if(strcasecmp(symbol, answer) == 0) { // case-insensitive comparison
        printf("Correct Answer!\n");
        return 1;
    }
    printf("Wrong Answer. The correct answer is %s.\n", symbol);
    return 0;
}

void play_round() { // runs a single round
    printf("New Round Starting:\n\n");
    int score = 0;
    for(int i=0; i<MAX_QUESTIONS; i++) {
        int index = generate_random();
        char* element = elements[index][0];
        char symbol[MAX_ANS_LEN];
        printf("What is the symbol for %s?\n", element);
        scanf("%s", symbol);
        score += check_answer(elements[index][1], symbol);
        printf("\n");
    }
    printf("Round over. Final Score: %d/%d\n", score, MAX_QUESTIONS);
}

int main() {
    srand(time(NULL)); // seeding the random number generator with current time
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the names of %d elements and asked to type in their symbols.\n", MAX_QUESTIONS);
    printf("The quiz will consist of %d questions in one round.\n", MAX_QUESTIONS);
    char choice;
    do {
        play_round();
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");
    } while(choice != 'n' && choice != 'N');
    printf("Thanks for playing the quiz!\n");
    return 0;
}