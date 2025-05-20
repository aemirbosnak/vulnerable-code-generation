//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the periodic table
#define ROWS 7
#define COLS 18

// Define the maximum score a player can get
#define MAX_SCORE 100

// Define the post-apocalyptic elements of the periodic table
const char ELEMENTS[ROWS][COLS][3] = {
    {"UN", "GR", "CN", "DC", "LC", "LT", "KA", "ES", "BL", "KR", "RA", "EB", "TR", "AI", "NZ", "OW", "PS", "ZM"},
    {"NA", "ZZ", "OS", "CA", "FD", "MT", "FR", "GL", "BL", "SP", "ST", "PH", "WI", "VA", "NC", "VI", "TH", "MI"},
    {"ME", "FN", "UD", "GW", "HH", "TM", "PI", "SW", "MU", "AM", "FI", "CR", "NV", "AP", "WI", "XM", "GG", "CF"},
    {"MU", "DS", "MW", "SS", "MU", "WU", "WI", "SE", "JP", "BT", "HM", "KS", "FB", "LG", "CD", "SA", "AS", "AN"},
    {"VE", "VO", "FE", "RG", "LA", "BA", "SI", "MM", "IO", "TA", "NO", "VE", "NA", "NE", "DR", "AC", "OR", "EE"},
    {"AK", "KR", "HH", "VE", "RM", "OG", "MA", "SO", "UL", "TH", "TN", "PA", "TT", "EO", "KU", "NI", "ES", "SP"},
    {"XI", "GG", "VV", "RU", "TT", "BA", "CA", "UG", "NA", "ME", "SI", "PL", "KI", "BO", "SS", "BZ", "BI", "DU"}
};

// Function to generate a random element from the periodic table
char* get_random_element()
{
    int row = rand() % ROWS;
    int col = rand() % COLS;
    return ELEMENTS[row][col];
}

// Main function
int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    
    // Initialize the variables
    int score = 0;
    char* element = get_random_element();
    char guess[3];
    
    printf("Welcome to the Cyberpunk Periodic Table Quiz!\n");
    printf("You have to guess the symbol of the randomly selected element.\n");
    printf("Each correct answer gives you 10 points. You need 100 points to win.\n");
    
    while (score < MAX_SCORE)
    {
        printf("\nCurrent score: %d\n", score);
        printf("Guess the symbol of the following element: %s\n", element);
        printf("Enter your guess (2 letters): ");
        scanf("%s", guess);
        
        if (strcmp(guess, element) == 0)
        {
            printf("Correct! You got 10 points.\n");
            score += 10;
            element = get_random_element();
        }
        else
        {
            printf("Incorrect! The symbol is %s. Try again.\n", element);
        }
    }
    
    printf("\nCongratulations! You have won the Cyberpunk Periodic Table Quiz!\n");
    printf("Your final score is %d.\n", score);
    
    return 0;
}