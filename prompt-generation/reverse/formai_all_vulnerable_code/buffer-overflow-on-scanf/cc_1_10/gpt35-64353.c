//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 118

int score = 0;
char answer[100];
char element[MAX][4] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S",
                        "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As",
                        "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In",
                        "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb",
                        "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl",
                        "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk",
                        "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn",
                        "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

char symbol[MAX][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon",
                        "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium",
                        "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium",
                        "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium",
                        "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony",
                        "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium",
                        "Samarium", "Europium", "Gadolinium", "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
                        "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum", "Gold", "Mercury", "Thallium", "Lead",
                        "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium", "Neptunium",
                        "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium",
                        "Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium",
                        "Florovium", "Moscovium", "Livermorium", "Tennessine", "Oganesson"};

int atomicNumber[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                         11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                         21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                         31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                         41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                         51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
                         61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
                         71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
                         81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
                         91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
                         101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
                         111, 112, 113, 114, 115, 116, 117, 118};

int randomNumber(int n){
    int num = rand() % n;
    return num;
}

void displayMenu(){
    printf("\n");
    printf("-------------------------------------\n");
    printf("---------- PERIODIC TABLE -----------\n");
    printf("-------------------------------------\n");
    printf("\n");
    printf("Choose from the following options:\n");
    printf("1. Guess the Element's Symbol\n");
    printf("2. Guess the Element's Atomic Number\n");
    printf("3. Quit\n");
    printf("\n");
}

void guessSymbol(){
    int num = randomNumber(MAX);
    printf("What element has the symbol '%s'?\n", element[num]);
    scanf("%s", answer);
    if(strcmp(answer, symbol[num]) == 0){
        printf("Correct! +1 point\n");
        score++;
    }else{
        printf("Incorrect! The answer was: %s\n", symbol[num]);
    }
}

void guessAtomicNumber(){
    int num = randomNumber(MAX);
    printf("What is the atomic number for %s?\n", symbol[num]);
    scanf("%s", answer);
    int ans = atoi(answer);
    if(ans == atomicNumber[num]){
        printf("Correct! +1 point\n");
        score++;
    }else{
        printf("Incorrect! The answer was: %d\n", atomicNumber[num]);
    }
}

int main(){
    int choice;
    srand(time(NULL));
    do{
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                guessSymbol();
                break;
            case 2:
                guessAtomicNumber();
                break;
            case 3:
                printf("Thank you for playing! Your final score was: %d\n", score);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 3);
    return 0;
}