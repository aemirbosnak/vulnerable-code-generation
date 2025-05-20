//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENTS 118

// Function prototypes
void display_menu();
void display_table();
void start_quiz();
void display_score();
int get_random_element();
void check_answer(int answer, int correct_answer);
void end_game();

// Array of element names
char *elements[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", 
"Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium", "Titanium", "Vanadium", "Chromium", "Manganese", 
"Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", 
"Zirconium", "Niobium", "Molybdenum", "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium", 
"Iodine", "Xenon", "Cesium", "Barium", "Lanthanum", "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium", 
"Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium", "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", 
"Platinum", "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine", "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", 
"Uranium", "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium", "Fermium", "Mendelevium", "Nobelium", "Lawrencium", 
"Rutherfordium", "Dubnium", "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium", "Copernicium", "Nihonium", "Flerovium", 
"Moscovium", "Livermorium", "Tennessine", "Oganesson"};

// Array of element symbols
char *symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", 
"Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", 
"Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", 
"Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", 
"Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

// Array of element colors
char *colors[] = {"#ffffff", "#d9ffff", "#cc80ff", "#c2ff00", "#ffb5b5", "#909090", "#3050f8", "#ff0d0d", "#90e050", "#b3e3f5", "#ab5cf2", "#8aff00", 
"#bfa6a6", "#f0c8a0", "#ff8000", "#ffff30", "#1ff01f", "#80d1e3", "#8f40d4", "#3dff00", "#e6e6e6", "#bfc2c7", "#8a99c7", "#8c7f70", "#7f8c8d", 
"#c78d8d", "#a6544d", "#668f8f", "#9e63b5", "#d47a00", "#940094", "#429eb0", "#57178f", "#00c900", "#70d4ff", "#ffc400", "#00ff00", "#50d050", "#ff8d00", 
"#c8c8c8", "#7d80b0", "#c7c7c7", "#a6a6ab", "#8f8f8f", "#bd80e3", "#c0c0c0", "#ffd98f", "#a67573", "#668080", "#9e4fb5", "#d9bfff", "#ff77ff", "#f0a3ff", 
"#00ffff", "#94ffff", "#94e0e0", "#73c2c9", "#54b5b5", "#3b9e9e", "#248f8f", "#0a7d8c", "#006985", "#c0ff00", "#ffbfff", "#ff7f00", "#ffffc7", "#d9ffc7", 
"#a3ffc7", "#8cff9f", "#00ff9c", "#4dff4d", "#4dffc7", "#ffc27f", "#c45a00", "#00ffc7", "#6f4fff", "#c7c77f", "#00ff00", "#8f8f00", "#e6e600", "#50c878", 
"#e6e8fa", "#fff9d9", "#d9ffff", "#ffd9b5", "#fffff0", "#f0fff0", "#ffe4e1", "#d9d9d9", "#ffbf00", "#a67573", "#668080", "#9e63b5", "#d9bfff", "#ff77ff", 
"#f0a3ff", "#00ffff", "#e6e6e6", "#bfc2c7", "#a4a4a4", "#8a99c7", "#9c7ac7", "#e06633", "#f090a0", "#50d050", "#c88033", "#7d80b0", "#c0c0c0", "#007d00", 
"#70d4ff", "#ffc0cb", "#ffffc0", "#00ff7f", "#d9d9d9", "#ffa07a", "#8fffc7", "#c0ffa0", "#ffd9a0", "#a0d9ff", "#ffa07a", "#ffc7b5", "#ffc0c0", "#c0c0d9", 
"#ffffff", "#ffffff", "#ffffff", "#ffffff"};

// Variable to store user's score
int score = 0;

int main()
{
    int choice;

    srand(time(NULL)); // seed random number generator

    do
    {
        display_menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                display_table();
                break;
            case 2:
                start_quiz();
                break;
            case 3:
                display_score();
                break;
            case 4:
                end_game();
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    }while(choice != 4);

    return 0;
}

// Function to display the main menu
void display_menu()
{
    printf("\n---Periodic Table Quiz---\n");
    printf("\n1. Display Periodic Table");
    printf("\n2. Start Quiz");
    printf("\n3. Display Score");
    printf("\n4. End Game");
    printf("\n\nEnter your choice: ");
}

// Function to display the periodic table
void display_table()
{
    int count = 0;

    printf("\n---Periodic Table---\n");

    for(int i = 1; i <= 7; i++)
    {
        for(int j = 1; j <= 18; j++)
        {
            if(j == 1 && i == 1)
            {
                printf("%2s", ""); // top left corner
            }
            else if(j == 1 || j == 18)
            {
                printf("%2s", "|"); // vertical border
            }
            else if(i == 1)
            {
                printf("%-2s ", symbols[count]); // element symbol
                count++;
            }
            else if(i == 2)
            {
                if(j == 3 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8 || j == 9)
                {
                    printf("%2s", "---"); // top row of filling
                }
                else
                {
                    printf("%2s", " "); // top row of empty spaces
                }
            }
            else if(j == 3 || j == 4 || j == 13 || j == 14 || j == 15 || j == 16 || j == 17)
            {
                printf("%2s", "---"); // middle rows of filling
            }
            else
            {
                printf("%2s", " "); // middle rows of empty spaces
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Function to start the quiz
void start_quiz()
{
    int num_questions, answer;

    printf("\n---Start Quiz---\n");

    printf("\nHow many questions do you want to answer? ");
    scanf("%d", &num_questions);

    printf("\n---Quiz Begins---\n");

    for(int i = 1; i <= num_questions; i++)
    {
        int element_num = get_random_element(); // get random element number
        char *element_name = elements[element_num]; // get element name
        char *element_symbol = symbols[element_num]; // get element symbol
        
        printf("\nQuestion %d: What is the atomic symbol for %s? ", i, element_name);
        scanf("%s", &answer);

        check_answer(answer, element_symbol);
    }

    printf("\nQuiz complete!\n");
}

// Function to display the user's score
void display_score()
{
    printf("\n---Score: %d---\n", score);
}

// Function to get a random element number
int get_random_element()
{
    return rand() % MAX_ELEMENTS;
}

// Function to check the user's answer
void check_answer(int answer, int correct_answer)
{
    if(answer == correct_answer)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect. The correct answer was %s\n", correct_answer);
    }
}

// Function to end the game
void end_game()
{
    printf("\nThanks for playing the periodic table quiz!\n");
}