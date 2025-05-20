//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char symbol[3];
    char name[20];
    int atomic_number;
    double atomic_weight;
    char category[20];
} element_t;

void print_question(element_t *elements, int question_number)
{
    printf("What element has the symbol \"%s\"?\n", elements[question_number].symbol);
}

int check_answer(element_t *elements, int question_number, char *answer)
{
    if (strcmp(elements[question_number].name, answer) == 0)
    {
        printf("Correct!\n");
        return 1;
    }
    else
    {
        printf("Incorrect. The correct answer is %s.\n", elements[question_number].name);
        return 0;
    }
}

int main()
{
    element_t elements[118] = {
        {"H", "Hydrogen", 1, 1.008, "Nonmetal"},
        {"He", "Helium", 2, 4.003, "Noble Gas"},
        {"Li", "Lithium", 3, 6.941, "Alkali Metal"},
        {"Be", "Beryllium", 4, 9.012, "Alkaline Earth Metal"},
        {"B", "Boron", 5, 10.81, "Metalloid"},
        {"C", "Carbon", 6, 12.01, "Nonmetal"},
        {"N", "Nitrogen", 7, 14.01, "Nonmetal"},
        {"O", "Oxygen", 8, 16.00, "Nonmetal"},
        {"F", "Fluorine", 9, 19.00, "Halogen"},
        {"Ne", "Neon", 10, 20.18, "Noble Gas"},
        {"Na", "Sodium", 11, 22.99, "Alkali Metal"},
        {"Mg", "Magnesium", 12, 24.31, "Alkaline Earth Metal"},
        {"Al", "Aluminum", 13, 26.98, "Post-Transition Metal"},
        {"Si", "Silicon", 14, 28.09, "Metalloid"},
        {"P", "Phosphorus", 15, 30.97, "Nonmetal"},
        {"S", "Sulfur", 16, 32.06, "Nonmetal"},
        {"Cl", "Chlorine", 17, 35.45, "Halogen"},
        {"Ar", "Argon", 18, 39.95, "Noble Gas"},
        {"K", "Potassium", 19, 39.10, "Alkali Metal"},
        {"Ca", "Calcium", 20, 40.08, "Alkaline Earth Metal"},
        {"Sc", "Scandium", 21, 44.96, "Transition Metal"},
        {"Ti", "Titanium", 22, 47.87, "Transition Metal"},
        {"V", "Vanadium", 23, 50.94, "Transition Metal"},
        {"Cr", "Chromium", 24, 52.00, "Transition Metal"},
        {"Mn", "Manganese", 25, 54.94, "Transition Metal"},
        {"Fe", "Iron", 26, 55.85, "Transition Metal"},
        {"Co", "Cobalt", 27, 58.93, "Transition Metal"},
        {"Ni", "Nickel", 28, 58.69, "Transition Metal"},
        {"Cu", "Copper", 29, 63.55, "Transition Metal"},
        {"Zn", "Zinc", 30, 65.38, "Transition Metal"},
        {"Ga", "Gallium", 31, 69.72, "Post-Transition Metal"},
        {"Ge", "Germanium", 32, 72.63, "Metalloid"},
        {"As", "Arsenic", 33, 74.92, "Metalloid"},
        {"Se", "Selenium", 34, 78.96, "Nonmetal"},
        {"Br", "Bromine", 35, 79.90, "Halogen"},
        {"Kr", "Krypton", 36, 83.80, "Noble Gas"},
        {"Rb", "Rubidium", 37, 85.47, "Alkali Metal"},
        {"Sr", "Strontium", 38, 87.62, "Alkaline Earth Metal"},
        {"Y", "Yttrium", 39, 88.91, "Transition Metal"},
        {"Zr", "Zirconium", 40, 91.22, "Transition Metal"},
        {"Nb", "Niobium", 41, 92.91, "Transition Metal"},
        {"Mo", "Molybdenum", 42, 95.94, "Transition Metal"},
        {"Tc", "Technetium", 43, 98.00, "Transition Metal"},
        {"Ru", "Ruthenium", 44, 101.07, "Transition Metal"},
        {"Rh", "Rhodium", 45, 102.91, "Transition Metal"},
        {"Pd", "Palladium", 46, 106.42, "Transition Metal"},
        {"Ag", "Silver", 47, 107.87, "Transition Metal"},
        {"Cd", "Cadmium", 48, 112.41, "Transition Metal"},
        {"In", "Indium", 49, 114.82, "Post-Transition Metal"},
        {"Sn", "Tin", 50, 118.71, "Post-Transition Metal"},
        {"Sb", "Antimony", 51, 121.76, "Metalloid"},
        {"Te", "Tellurium", 52, 127.60, "Metalloid"},
        {"I", "Iodine", 53, 126.90, "Halogen"},
        {"Xe", "Xenon", 54, 131.29, "Noble Gas"},
        {"Cs", "Cesium", 55, 132.91, "Alkali Metal"},
        {"Ba", "Barium", 56, 137.33, "Alkaline Earth Metal"},
        {"La", "Lanthanum", 57, 138.91, "Lanthanide"},
        {"Ce", "Cerium", 58, 140.12, "Lanthanide"},
        {"Pr", "Praseodymium", 59, 140.91, "Lanthanide"},
        {"Nd", "Neodymium", 60, 144.24, "Lanthanide"},
        {"Pm", "Promethium", 61, 145.00, "Lanthanide"},
        {"Sm", "Samarium", 62, 150.36, "Lanthanide"},
        {"Eu", "Europium", 63, 151.96, "Lanthanide"},
        {"Gd", "Gadolinium", 64, 157.25, "Lanthanide"},
        {"Tb", "Terbium", 65, 158.93, "Lanthanide"},
        {"Dy", "Dysprosium", 66, 162.50, "Lanthanide"},
        {"Ho", "Holmium", 67, 164.93, "Lanthanide"},
        {"Er", "Erbium", 68, 167.26, "Lanthanide"},
        {"Tm", "Thulium", 69, 168.93, "Lanthanide"},
        {"Yb", "Ytterbium", 70, 173.05, "Lanthanide"},
        {"Lu", "Lutetium", 71, 174.97, "Lanthanide"},
        {"Hf", "Hafnium", 72, 178.49, "Transition Metal"},
        {"Ta", "Tantalum", 73, 180.95, "Transition Metal"},
        {"W", "Tungsten", 74, 183.84, "Transition Metal"},
        {"Re", "Rhenium", 75, 186.21, "Transition Metal"},
        {"Os", "Osmium", 76, 190.23, "Transition Metal"},
        {"Ir", "Iridium", 77, 192.22, "Transition Metal"},
        {"Pt", "Platinum", 78, 195.08, "Transition Metal"},
        {"Au", "Gold", 79, 196.97, "Transition Metal"},
        {"Hg", "Mercury", 80, 200.59, "Transition Metal"},
        {"Tl", "Thallium", 81, 204.38, "Post-Transition Metal"},
        {"Pb", "Lead", 82, 207.2, "Post-Transition Metal"},
        {"Bi", "Bismuth", 83, 208.98, "Post-Transition Metal"},
        {"Po", "Polonium", 84, 209.00, "Metalloid"},
        {"At", "Astatine", 85, 210.00, "Halogen"},
        {"Rn", "Radon", 86, 222.00, "Noble Gas"},
        {"Fr", "Francium", 87, 223.00, "Alkali Metal"},
        {"Ra", "Radium", 88, 226.03, "Alkaline Earth Metal"},
        {"Ac", "Actinium", 89, 227.03, "Actinide"},
        {"Th", "Thorium", 90, 232.04, "Actinide"},
        {"Pa", "Protactinium", 91, 231.04, "Actinide"},
        {"U", "Uranium", 92, 238.03, "Actinide"},
        {"Np", "Neptunium", 93, 237.05, "Actinide"},
        {"Pu", "Plutonium", 94, 244.06, "Actinide"},
        {"Am", "Americium", 95, 243.06, "Actinide"},
        {"Cm", "Curium", 96, 247.07, "Actinide"},
        {"Bk", "Berkelium", 97, 247.07, "Actinide"},
        {"Cf", "Californium", 98, 251.08, "Actinide"},
        {"Es", "Einsteinium", 99, 252.08, "Actinide"},
        {"Fm", "Fermium", 100, 257.10, "Actinide"},
        {"Md", "Mendelevium", 101, 258.10, "Actinide"},
        {"No", "Nobelium", 102, 259.10, "Actinide"},
        {"Lr", "Lawrencium", 103, 262.11, "Actinide"},
        {"Rf", "Rutherfordium", 104, 267.12, "Transition Metal"},
        {"Db", "Dubnium", 105, 270.13, "Transition Metal"},
        {"Sg", "Seaborgium", 106, 271.13, "Transition Metal"},
        {"Bh", "Bohrium", 107, 270.13, "Transition Metal"},
        {"Hs", "Hassium", 108, 277.15, "Transition Metal"},
        {"Mt", "Meitnerium", 109, 278.16, "Unknown"},
        {"Ds", "Darmstadtium", 110, 281.16, "Unknown"},
        {"Rg", "Roentgenium", 111, 284.18, "Unknown"},
        {"Cn", "Copernicium", 112, 285.18, "Transition Metal"},
        {"Nh", "Nihonium", 113, 286.19, "Unknown"},
        {"Fl", "Flerovium", 114, 289.19, "Post-Transition Metal"},
        {"Mc", "Moscovium", 115, 290.19, "Post-Transition Metal"},
        {"Lv", "Livermorium", 116, 293.20, "Post-Transition Metal"},
        {"Ts", "Tennessine", 117, 294.21, "Halogen"},
        {"Og", "Oganesson", 118, 294.21, "Noble Gas"}
    };

    printf("*** Welcome to the Periodic Table Quiz! ***\n");

    int num_questions = 10; // number of questions per quiz
    int num_correct = 0; // number of correct answers
    int question_bank[118]; // indices of the questions
    memset(question_bank, -1, sizeof(question_bank)); // fill with -1
    
    for (int i = 0; i < num_questions; i++)
    {
        int question_number;
        do
        {
            question_number = rand() % 118; // generate a random question number
        }
        while (question_bank[question_number] != -1); // make sure the question hasn't been asked before
        
        question_bank[question_number] = 1; // mark that the question has been asked
        print_question(elements, question_number); // print the question
        char answer[20];
        scanf("%s", answer); // get the answer from the user
        num_correct += check_answer(elements, question_number, answer); // check the answer, increment num_correct if correct
    }
    
    printf("You got %d out of %d correct!\n", num_correct, num_questions);
    
    return 0;
}