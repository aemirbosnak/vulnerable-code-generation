//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <string.h>

// Function to display the periodic table
void display_table()
{
    printf("\n========================PERIODIC TABLE========================\n");
    printf("  *-----------------*-----------------*-----------------*\n");
    printf("  |    ELEMENTS     |    SYMBOLS      |   ATOMIC NUMBERS |\n");
    printf("  *-----------------*-----------------*-----------------*\n");
    printf("  |    Hydrogen     |        H        |        1        |\n");
    printf("  |    Helium       |        He       |        2        |\n");
    printf("  |    Lithium      |        Li       |        3        |\n");
    printf("  |    Beryllium    |        Be       |        4        |\n");
    printf("  |    Boron        |        B        |        5        |\n");
    printf("  |    Carbon       |        C        |        6        |\n");
    printf("  |    Nitrogen     |        N        |        7        |\n");
    printf("  |    Oxygen       |        O        |        8        |\n");
    printf("  |    Fluorine     |        F        |        9        |\n");
    printf("  |    Neon         |        Ne       |        10       |\n");
    printf("  |    Sodium       |        Na       |        11       |\n");
    printf("  |    Magnesium    |        Mg       |        12       |\n");
    printf("  |    Aluminum     |        Al       |        13       |\n");
    printf("  |    Silicon      |        Si       |        14       |\n");
    printf("  |    Phosphorus   |        P        |        15       |\n");
    printf("  |    Sulfur       |        S        |        16       |\n");
    printf("  |    Chlorine     |        Cl       |        17       |\n");
    printf("  |    Argon        |        Ar       |        18       |\n");
    printf("  |    Potassium    |        K        |        19       |\n");
    printf("  |    Calcium      |        Ca       |        20       |\n");
    printf("  |    Scandium     |        Sc       |        21       |\n");
    printf("  |    Titanium     |        Ti       |        22       |\n");
    printf("  |    Vanadium     |        V        |        23       |\n");
    printf("  |    Chromium     |        Cr       |        24       |\n");
    printf("  |    Manganese    |        Mn       |        25       |\n");
    printf("  |    Iron         |        Fe       |        26       |\n");
    printf("  |    Cobalt       |        Co       |        27       |\n");
    printf("  |    Nickel       |        Ni       |        28       |\n");
    printf("  |    Copper       |        Cu       |        29       |\n");
    printf("  |    Zinc         |        Zn       |        30       |\n");
    printf("  *-----------------*-----------------*-----------------*\n");
}

// Function to validate user input
int validate_input(int input)
{
    if (input < 1 || input > 30)
    {
        printf("\nInvalid input. Please enter a number between 1 and 30.\n");
        return 0;
    }
    
    return 1;
}

// Function to process user's answer
int process_answer(int input, char symbol[])
{
    char correct_symbol[] = {"C"};
    
    if (strcmp(symbol, correct_symbol) == 0)
    {
        printf("\nCongratulations, you got it right! C is the symbol for Carbon.\n");
        return 1;
    }
    else
    {
        printf("\nSorry, your answer is incorrect. Carbon's symbol is C.\n");
        return 0;
    }
}

// Function to start the quiz
void start_quiz()
{
    int input, score = 0;
    char symbol[3];
    
    printf("\n\nWelcome to the Periodic Table Quiz!\n");
    printf("=====================================\n");
    printf("   This quiz tests your knowledge of  \n");
    printf(" the atomic symbol for different elements\n");
    printf("=====================================\n");

    while (score < 3)
    {
        printf("\nWhat is the atomic symbol for Carbon? ");
        scanf("%d %s", &input, symbol);
        
        if (validate_input(input))
        {
            score += process_answer(input, symbol);
            printf("Current score: %d/3\n", score);
        }
    }
    
    printf("\nCongratulations, you have completed the quiz!\n");
}

// Main function to call other modules
int main()
{
    display_table();
    start_quiz();
    
    return 0;
}