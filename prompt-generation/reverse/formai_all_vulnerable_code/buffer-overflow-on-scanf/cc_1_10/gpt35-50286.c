//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ELEMENTS 118
#define NUM_THREADS 4

typedef struct
{
    int id;
    char symbol[3];
    char name[20];
    float atomic_mass;
} Element;

Element elements[MAX_ELEMENTS] = {
    {1, "H", "Hydrogen", 1.008},
    {2, "He", "Helium", 4.003},
    {3, "Li", "Lithium", 6.941},
    {4, "Be", "Beryllium", 9.012},
    {5, "B", "Boron", 10.811},
    {6, "C", "Carbon", 12.011},
    {7, "N", "Nitrogen", 14.007},
    {8, "O", "Oxygen", 15.999},
    {9, "F", "Fluorine", 18.998},
    {10, "Ne", "Neon", 20.180},
    {11, "Na", "Sodium", 22.990},
    {12, "Mg", "Magnesium", 24.305},
    {13, "Al", "Aluminium", 26.982},
    {14, "Si", "Silicon", 28.086},
    {15, "P", "Phosphorus", 30.974},
    {16, "S", "Sulfur", 32.066},
    {17, "Cl", "Chlorine", 35.453},
    {18, "Ar", "Argon", 39.948},
    {19, "K", "Potassium", 39.098},
    {20, "Ca", "Calcium", 40.078},
    {21, "Sc", "Scandium", 44.956},
    {22, "Ti", "Titanium", 47.867},
    {23, "V", "Vanadium", 50.942},
    {24, "Cr", "Chromium", 52.000},
    {25, "Mn", "Manganese", 54.938},
    {26, "Fe", "Iron", 55.845},
    {27, "Co", "Cobalt", 58.933},
    {28, "Ni", "Nickel", 58.693},
    {29, "Cu", "Copper", 63.546},
    {30, "Zn", "Zinc", 65.390},
    {31, "Ga", "Gallium", 69.723},
    {32, "Ge", "Germanium", 72.631},
    {33, "As", "Arsenic", 74.922},
    {34, "Se", "Selenium", 78.960},
    {35, "Br", "Bromine", 79.904},
    {36, "Kr", "Krypton", 83.798},
    {37, "Rb", "Rubidium", 85.468},
    {38, "Sr", "Strontium", 87.620},
    {39, "Y", "Yttrium", 88.906},
    {40, "Zr", "Zirconium", 91.224},
    {41, "Nb", "Niobium", 92.906},
    {42, "Mo", "Molybdenum", 95.940},
    {43, "Tc", "Technetium", 98.000},
    {44, "Ru", "Ruthenium", 101.070},
    {45, "Rh", "Rhodium", 102.905},
    {46, "Pd", "Palladium", 106.420},
    {47, "Ag", "Silver", 107.868},
    {48, "Cd", "Cadmium", 112.411},
    {49, "In", "Indium", 114.818},
    {50, "Sn", "Tin", 118.710},
    {51, "Sb", "Antimony", 121.760},
    {52, "Te", "Tellurium", 127.600},
    {53, "I", "Iodine", 126.904},
    {54, "Xe", "Xenon", 131.293},
    {55, "Cs", "Cesium", 132.905},
    {56, "Ba", "Barium", 137.327},
    {57, "La", "Lanthanum", 138.905},
    {58, "Ce", "Cerium", 140.116},
    {59, "Pr", "Praseodymium", 140.908},
    {60, "Nd", "Neodymium", 144.242},
    {61, "Pm", "Promethium", 145.000},
    {62, "Sm", "Samarium", 150.360},
    {63, "Eu", "Europium", 151.964},
    {64, "Gd", "Gadolinium", 157.250},
    {65, "Tb", "Terbium", 158.925},
    {66, "Dy", "Dysprosium", 162.500},
    {67, "Ho", "Holmium", 164.930},
    {68, "Er", "Erbium", 167.259},
    {69, "Tm", "Thulium", 168.934},
    {70, "Yb", "Ytterbium", 173.054},
    {71, "Lu", "Lutetium", 174.967},
    {72, "Hf", "Hafnium", 178.490},
    {73, "Ta", "Tantalum", 180.948},
    {74, "W", "Tungsten", 183.840},
    {75, "Re", "Rhenium", 186.207},
    {76, "Os", "Osmium", 190.230},
    {77, "Ir", "Iridium", 192.217},
    {78, "Pt", "Platinum", 195.084},
    {79, "Au", "Gold", 196.967},
    {80, "Hg", "Mercury", 200.592},
    {81, "Tl", "Thallium", 204.383},
    {82, "Pb", "Lead", 207.210},
    {83, "Bi", "Bismuth", 208.980},
    {84, "Po", "Polonium", 209.000},
    {85, "At", "Astatine", 210.000},
    {86, "Rn", "Radon", 222.000},
    {87, "Fr", "Francium", 223.000},
    {88, "Ra", "Radium", 226.025},
    {89, "Ac", "Actinium", 227.028},
    {90, "Th", "Thorium", 232.038},
    {91, "Pa", "Protactinium", 231.036},
    {92, "U", "Uranium", 238.029},
    {93, "Np", "Neptunium", 237.048},
    {94, "Pu", "Plutonium", 244.064},
    {95, "Am", "Americium", 243.061},
    {96, "Cm", "Curium", 247.070},
    {97, "Bk", "Berkelium", 247.070},
    {98, "Cf", "Californium", 251.080},
    {99, "Es", "Einsteinium", 252.083},
    {100, "Fm", "Fermium", 257.100},
    {101, "Md", "Mendelevium", 258.100},
    {102, "No", "Nobelium", 259.101},
    {103, "Lr", "Lawrencium", 262.110},
    {104, "Rf", "Rutherfordium", 267.122},
    {105, "Db", "Dubnium", 270.128},
    {106, "Sg", "Seaborgium", 271.133},
    {107, "Bh", "Bohrium", 270.133},
    {108, "Hs", "Hassium", 277.152},
    {109, "Mt", "Meitnerium", 276.151},
    {110, "Ds", "Darmstadtium", 281.164},
    {111, "Rg", "Roentgenium", 280.165},
    {112, "Cn", "Copernicium", 285.177},
    {113, "Nh", "Nihonium", 284.178},
    {114, "Fl", "Flerovium", 289.191},
    {115, "Mc", "Moscovium", 288.192},
    {116, "Lv", "Livermorium", 293.204},
    {117, "Ts", "Tennessine", 294.210},
    {118, "Og", "Oganesson", 294.214}};

// function to generate a random number between min and max
int random_number(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

void *quiz(void *thread_id)
{
    int id = *(int *)thread_id;
    int max_questions = MAX_ELEMENTS / NUM_THREADS;

    // generate random range of elements for this thread
    int start = max_questions * id;
    int end = id == NUM_THREADS - 1 ? MAX_ELEMENTS : start + max_questions;

    // ask questions for the specified range of elements
    for (int i = start; i < end; i++)
    {
        printf("\n(%d) What is the symbol for %s? ", i + 1, elements[i].name);

        char user_answer[3];
        scanf("%s", user_answer);

        if (!strcmp(user_answer, elements[i].symbol))
        {
            printf("Correct!");
        }
        else
        {
            printf("Incorrect. The correct symbol is %s.", elements[i].symbol);
        }
    }

    pthread_exit(NULL);
}

int main()
{
    srand(time(NULL));

    printf("*** PERIODIC TABLE QUIZ ***\n");

    // initialize threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // create threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, quiz, &thread_ids[i]);
    }

    // wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("\nQuiz complete.\n");

    return 0;
}