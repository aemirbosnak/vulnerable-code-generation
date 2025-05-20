//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate random number
int generateRandomNumber(int n)
{
    time_t t;
    srand((unsigned) time(&t));
    return rand() % n;
}

struct Element
{
    char symbol[3];
    char name[20];
} elements[118] = {{"H", "Hydrogen"}, {"He", "Helium"}, {"Li", "Lithium"}, {"Be", "Beryllium"}, {"B", "Boron"}, {"C", "Carbon"}, {"N", "Nitrogen"}, {"O", "Oxygen"}, {"F", "Fluorine"}, {"Ne", "Neon"}, {"Na", "Sodium"}, {"Mg", "Magnesium"}, {"Al", "Aluminium"}, {"Si", "Silicon"}, {"P", "Phosphorus"}, {"S", "Sulfur"}, {"Cl", "Chlorine"}, {"Ar", "Argon"}, {"K", "Potassium"}, {"Ca", "Calcium"}, {"Sc", "Scandium"}, {"Ti", "Titanium"}, {"V", "Vanadium"}, {"Cr", "Chromium"}, {"Mn", "Manganese"}, {"Fe", "Iron"}, {"Co", "Cobalt"}, {"Ni", "Nickel"}, {"Cu", "Copper"}, {"Zn", "Zinc"}, {"Ga", "Gallium"}, {"Ge", "Germanium"}, {"As", "Arsenic"}, {"Se", "Selenium"}, {"Br", "Bromine"}, {"Kr", "Krypton"}, {"Rb", "Rubidium"}, {"Sr", "Strontium"}, {"Y", "Yttrium"}, {"Zr", "Zirconium"}, {"Nb", "Niobium"}, {"Mo", "Molybdenum"}, {"Tc", "Technetium"}, {"Ru", "Ruthenium"}, {"Rh", "Rhodium"}, {"Pd", "Palladium"}, {"Ag", "Silver"}, {"Cd", "Cadmium"}, {"In", "Indium"}, {"Sn", "Tin"}, {"Sb", "Antimony"}, {"Te", "Tellurium"}, {"I", "Iodine"}, {"Xe", "Xenon"}, {"Cs", "Caesium"}, {"Ba", "Barium"}, {"La", "Lanthanum"}, {"Ce", "Cerium"}, {"Pr", "Praseodymium"}, {"Nd", "Neodymium"}, {"Pm", "Promethium"}, {"Sm", "Samarium"}, {"Eu", "Europium"}, {"Gd", "Gadolinium"}, {"Tb", "Terbium"}, {"Dy", "Dysprosium"}, {"Ho", "Holmium"}, {"Er", "Erbium"}, {"Tm", "Thulium"}, {"Yb", "Ytterbium"}, {"Lu", "Lutetium"}, {"Hf", "Hafnium"}, {"Ta", "Tantalum"}, {"W", "Tungsten"}, {"Re", "Rhenium"}, {"Os", "Osmium"}, {"Ir", "Iridium"}, {"Pt", "Platinum"}, {"Au", "Gold"}, {"Hg", "Mercury"}, {"Tl", "Thallium"}, {"Pb", "Lead"}, {"Bi", "Bismuth"}, {"Po", "Polonium"}, {"At", "Astatine"}, {"Rn", "Radon"}, {"Fr", "Francium"}, {"Ra", "Radium"}, {"Ac", "Actinium"}, {"Th", "Thorium"}, {"Pa", "Protactinium"}, {"U", "Uranium"}, {"Np", "Neptunium"}, {"Pu", "Plutonium"}, {"Am", "Americium"}, {"Cm", "Curium"}, {"Bk", "Berkelium"}, {"Cf", "Californium"}, {"Es", "Einsteinium"}, {"Fm", "Fermium"}, {"Md", "Mendelevium"}, {"No", "Nobelium"}, {"Lr", "Lawrencium"}, {"Rf", "Rutherfordium"}, {"Db", "Dubnium"}, {"Sg", "Seaborgium"}, {"Bh", "Bohrium"}, {"Hs", "Hassium"}, {"Mt", "Meitnerium"}, {"Ds", "Darmstadtium"}, {"Rg", "Roentgenium"}, {"Cn", "Copernicium"}, {"Nh", "Nihonium"}, {"Fl", "Flerovium"}, {"Mc", "Moscovium"}, {"Lv", "Livermorium"}, {"Ts", "Tennessine"}, {"Og", "Oganesson"}};

int main() 
{
    printf("Welcome to the Medieval Periodic Table Quiz!\n");
    printf("Test your knowledge of chemical elements.\n\n");

    int score = 0;
    char playerName[20];

    printf("What's your name? ");
    scanf("%s", playerName);

    printf("Hail, %s.\n", playerName);

    int numOfQuestions = 10;
    char answer[20];
    int questionNum;
    for (int i=0; i<numOfQuestions; i++)
    {
        questionNum = generateRandomNumber(118);
        printf("\nQuestion %d: What is the symbol of %s?\n", i+1, elements[questionNum].name);
        scanf("%s", answer);

        // Convert answer to uppercase
        for (int j=0; j<strlen(answer); j++)
        {
            answer[j] = toupper(answer[j]);
        }

        if (strcmp(answer, elements[questionNum].symbol) == 0)
        {
            printf("You are correct! The symbol of %s is %s.\n", elements[questionNum].name, elements[questionNum].symbol);
            score++;
        }
        else
        {
            printf("I'm sorry, %s is not the symbol of %s. The symbol of %s is %s.\n", answer, elements[questionNum].name, elements[questionNum].name, elements[questionNum].symbol);
        }
    }

    printf("\nHuzzah! You have completed the quiz. Your final score is %d out of %d questions.\n", score, numOfQuestions);

    return 0;
}