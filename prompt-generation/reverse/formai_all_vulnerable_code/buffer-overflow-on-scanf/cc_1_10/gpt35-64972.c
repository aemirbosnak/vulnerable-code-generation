//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the element
typedef struct Element {
    char symbol[3];
    int atomicNumber;
    char name[20];
} Element;

// Initialize the array of elements
Element elements[118] = { 
    {"H", 1, "Hydrogen"}, 
    {"He", 2, "Helium"}, 
    {"Li", 3, "Lithium"}, 
    {"Be", 4, "Beryllium"}, 
    {"B", 5, "Boron"}, 
    {"C", 6, "Carbon"}, 
    {"N", 7, "Nitrogen"}, 
    {"O", 8, "Oxygen"}, 
    {"F", 9, "Fluorine"}, 
    {"Ne", 10, "Neon"}, 
    {"Na", 11, "Sodium"}, 
    {"Mg", 12, "Magnesium"}, 
    {"Al", 13, "Aluminum"}, 
    {"Si", 14, "Silicon"}, 
    {"P", 15, "Phosphorus"}, 
    {"S", 16, "Sulfur"}, 
    {"Cl", 17, "Chlorine"}, 
    {"Ar", 18, "Argon"}, 
    {"K", 19, "Potassium"}, 
    {"Ca", 20, "Calcium"}, 
    {"Sc", 21, "Scandium"}, 
    {"Ti", 22, "Titanium"}, 
    {"V", 23, "Vanadium"}, 
    {"Cr", 24, "Chromium"}, 
    {"Mn", 25, "Manganese"}, 
    {"Fe", 26, "Iron"}, 
    {"Co", 27, "Cobalt"}, 
    {"Ni", 28, "Nickel"}, 
    {"Cu", 29, "Copper"}, 
    {"Zn", 30, "Zinc"}, 
    {"Ga", 31, "Gallium"}, 
    {"Ge", 32, "Germanium"}, 
    {"As", 33, "Arsenic"}, 
    {"Se", 34, "Selenium"}, 
    {"Br", 35, "Bromine"}, 
    {"Kr", 36, "Krypton"}, 
    {"Rb", 37, "Rubidium"}, 
    {"Sr", 38, "Strontium"}, 
    {"Y", 39, "Yttrium"}, 
    {"Zr", 40, "Zirconium"}, 
    {"Nb", 41, "Niobium"}, 
    {"Mo", 42, "Molybdenum"}, 
    {"Tc", 43, "Technetium"}, 
    {"Ru", 44, "Ruthenium"}, 
    {"Rh", 45, "Rhodium"}, 
    {"Pd", 46, "Palladium"}, 
    {"Ag", 47, "Silver"}, 
    {"Cd", 48, "Cadmium"}, 
    {"In", 49, "Indium"}, 
    {"Sn", 50, "Tin"}, 
    {"Sb", 51, "Antimony"}, 
    {"Te", 52, "Tellurium"}, 
    {"I", 53, "Iodine"}, 
    {"Xe", 54, "Xenon"}, 
    {"Cs", 55, "Cesium"}, 
    {"Ba", 56, "Barium"}, 
    {"La", 57, "Lanthanum"}, 
    {"Ce", 58, "Cerium"}, 
    {"Pr", 59, "Praseodymium"}, 
    {"Nd", 60, "Neodymium"}, 
    {"Pm", 61, "Promethium"}, 
    {"Sm", 62, "Samarium"}, 
    {"Eu", 63, "Europium"}, 
    {"Gd", 64, "Gadolinium"}, 
    {"Tb", 65, "Terbium"}, 
    {"Dy", 66, "Dysprosium"}, 
    {"Ho", 67, "Holmium"}, 
    {"Er", 68, "Erbium"}, 
    {"Tm", 69, "Thulium"}, 
    {"Yb", 70, "Ytterbium"}, 
    {"Lu", 71, "Lutetium"}, 
    {"Hf", 72, "Hafnium"}, 
    {"Ta", 73, "Tantalum"}, 
    {"W", 74, "Tungsten"}, 
    {"Re", 75, "Rhenium"}, 
    {"Os", 76, "Osmium"}, 
    {"Ir", 77, "Iridium"}, 
    {"Pt", 78, "Platinum"}, 
    {"Au", 79, "Gold"}, 
    {"Hg", 80, "Mercury"}, 
    {"Tl", 81, "Thallium"}, 
    {"Pb", 82, "Lead"}, 
    {"Bi", 83, "Bismuth"}, 
    {"Po", 84, "Polonium"}, 
    {"At", 85, "Astatine"}, 
    {"Rn", 86, "Radon"}, 
    {"Fr", 87, "Francium"}, 
    {"Ra", 88, "Radium"}, 
    {"Ac", 89, "Actinium"}, 
    {"Th", 90, "Thorium"}, 
    {"Pa", 91, "Protactinium"}, 
    {"U", 92, "Uranium"}, 
    {"Np", 93, "Neptunium"}, 
    {"Pu", 94, "Plutonium"}, 
    {"Am", 95, "Americium"}, 
    {"Cm", 96, "Curium"}, 
    {"Bk", 97, "Berkelium"}, 
    {"Cf", 98, "Californium"}, 
    {"Es", 99, "Einsteinium"}, 
    {"Fm", 100, "Fermium"}, 
    {"Md", 101, "Mendelevium"}, 
    {"No", 102, "Nobelium"}, 
    {"Lr", 103, "Lawrencium"}, 
    {"Rf", 104, "Rutherfordium"}, 
    {"Db", 105, "Dubnium"}, 
    {"Sg", 106, "Seaborgium"}, 
    {"Bh", 107, "Bohrium"}, 
    {"Hs", 108, "Hassium"}, 
    {"Mt", 109, "Meitnerium"}, 
    {"Ds", 110, "Darmstadtium"}, 
    {"Rg", 111, "Roentgenium"}, 
    {"Cn", 112, "Copernicium"}, 
    {"Nh", 113, "Nihonium"}, 
    {"Fl", 114, "Flerovium"}, 
    {"Mc", 115, "Moscovium"}, 
    {"Lv", 116, "Livermorium"}, 
    {"Ts", 117, "Tennessine"}, 
    {"Og", 118, "Oganesson"}, 
};

// Initialize the score variable
int score = 0;

// Define the function to check the answer
void checkAnswer(int atomicNumber) {
    int guess;
    printf("Enter the atomic number of the element: ");
    scanf("%d", &guess);
    if (guess == atomicNumber) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %d.\n", atomicNumber);
    }
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n\n");

    // Initialize the variable to store the user's input
    char input[20];

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Start the quiz\n");
        printf("2. View the periodic table\n");
        printf("3. Exit\n");

        scanf("%s", input);

        if (strcmp(input, "1") == 0) {
            printf("Starting the quiz...\n\n");

            // Initialize the random seed
            srand(time(NULL));

            // Ask 5 random questions
            for (int i = 0; i < 5; i++) {
                int randomIndex = rand() % 118; // Generate a random index
                Element randomElement = elements[randomIndex]; // Get the random element
                printf("What is the atomic number of %s? ", randomElement.name);
                checkAnswer(randomElement.atomicNumber);
            }

            printf("Quiz complete! You got %d out of 5.\n\n", score);

            // Reset the score
            score = 0;

        } else if (strcmp(input, "2") == 0) {
            printf("Here is the periodic table:\n\n");
            printf("H    1     He   2\n");
            printf("Li   3     Be   4     B    5     C    6     N    7     O    8     F    9     Ne  10\n");
            printf("Na  11     Mg  12    Al  13    Si  14     P   15    S   16    Cl  17    Ar  18\n");
            printf("K   19     Ca  20    Sc  21    Ti  22    V   23   Cr   24   Mn   25   Fe   26   Co   27   Ni   28   Cu   29   Zn   30\n");
            printf("Ga  31     Ge  32    As  33    Se  34    Br  35    Kr  36\n");
            printf("Rb  37     Sr  38    Y   39    Zr  40    Nb  41   Mo   42   Tc   43   Ru   44   Rh   45   Pd   46   Ag   47   Cd   48   In   49   Sn   50   Sb   51   Te   52   I   53    Xe  54\n");
            printf("Cs  55     Ba  56   La  57   Ce  58   Pr  59   Nd  60   Pm  61   Sm  62   Eu  63   Gd  64   Tb  65   Dy  66   Ho  67   Er  68   Tm  69   Yb  70   Lu  71\n");
            printf("Hf  72    Ta   73    W   74   Re  75    Os  76    Ir  77    Pt  78    Au  79   Hg  80   Tl   81   Pb   82   Bi   83   Po   84   At   85    Rn  86\n");
            printf("Fr  87    Ra   88   Ac  89   Th  90   Pa  91   U   92   Np  93   Pu  94    Am  95   Cm   96   Bk   97   Cf   98   Es  99   Fm   100  Md  101  No  102  Lr  103\n");
            printf("Rf  104   Db  105   Sg  106   Bh  107   Hs  108  Mt  109  Ds  110  Rg  111  Cn  112  Nh  113  Fl  114  Mc  115  Lv  116  Ts  117  Og  118\n\n");

        } else if (strcmp(input, "3") == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}