//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each element in the periodic table
struct Element {
    int atomicNumber;
    char symbol[3];
    char name[20];
    char category[20];
    float atomicMass;
};

int main() {

    // Initialize the periodic table with 118 elements
    struct Element periodicTable[118] = {
        {1, "H", "Hydrogen", "Nonmetal", 1.008},
        {2, "He", "Helium", "Noble gas", 4.003},
        {3, "Li", "Lithium", "Alkali metal", 6.941},
        {4, "Be", "Beryllium", "Alkaline earth metal", 9.012},
        {5, "B", "Boron", "Metalloid", 10.81},
        //... and so on
        {116, "Lv", "Livermorium", "Post-​transition metal", 293},
        {117, "Ts", "Tennessine", "Metalloid", 294},
        {118, "Og", "Oganesson", "Noble gas", 294},
    };

    // Create an array of all the categories of elements
    char categories[10][20] = {"Nonmetal", "Noble gas", "Alkali metal", "Alkaline earth metal", "Metalloid", 
                               "Transition metal", "Post-​transition metal", "Poor metal", "Rare earth metal", "Unknown"};

    // Generate a random number for the element to quiz on
    srand(time(NULL));
    int randElement = rand() % 118;

    // Prompt the user to enter the atomic number of the randomly selected element
    printf("What is the atomic number of %s? \n", periodicTable[randElement].name);
    int userAnswer;
    scanf("%d", &userAnswer);

    // Check if the user's answer is correct, incorrect, or not in range
    if (userAnswer == periodicTable[randElement].atomicNumber) {
        printf("Correct! %d is the atomic number of %s. \n", userAnswer, periodicTable[randElement].name);
    } else if (userAnswer < 1 || userAnswer > 118) {
        printf("Invalid input. Please enter a number between 1 and 118. \n");
    } else {
        printf("Incorrect. %d is not the atomic number of %s. \n", userAnswer, periodicTable[randElement].name);
    }

    // Prompt the user to enter the symbol of the randomly selected element
    printf("What is the symbol of %s? \n", periodicTable[randElement].name);
    char userSymbol[3];
    scanf("%s", userSymbol);
    // Force user input to uppercase for comparison
    for (int i = 0; i < 3; i++) {
        userSymbol[i] = toupper(userSymbol[i]);
    }
    // Check if the user's answer is correct or incorrect
    if (strcmp(userSymbol, periodicTable[randElement].symbol) == 0) {
        printf("Correct! %s is the symbol of %s. \n", userSymbol, periodicTable[randElement].name);
    } else {
        printf("Incorrect. %s is not the symbol of %s. \n", userSymbol, periodicTable[randElement].name);
    }

    // Prompt the user to enter the category of the randomly selected element
    printf("What is the category of %s? \n", periodicTable[randElement].name);
    char userCategory[20];
    scanf("%s", userCategory);
    // Force user input to uppercase for comparison
    for (int i = 0; i < strlen(userCategory); i++) {
        userCategory[i] = toupper(userCategory[i]);
    }
    // Check if the user's answer is correct or incorrect
    if (strstr(userCategory, periodicTable[randElement].category) != NULL) {
        printf("Correct! %s is a %s element. \n", periodicTable[randElement].name, periodicTable[randElement].category);
    } else {
        // Print all of the possible categories for reference
        printf("Incorrect. %s is not a %s. Possible categories include: \n", userCategory, periodicTable[randElement].category);
        for (int i = 0; i < 10; i++) {
            printf("%s \n", categories[i]);
        }
    }

    // Prompt the user to enter the atomic mass of the randomly selected element
    printf("What is the atomic mass of %s? \n", periodicTable[randElement].name);
    float userMass;
    scanf("%f", &userMass);
    // Round user input to three decimal places for comparison
    userMass = roundf(userMass * 1000) / 1000;
    // Check if the user's answer is correct or incorrect
    if (userMass == periodicTable[randElement].atomicMass) {
        printf("Correct! %f is the atomic mass of %s. \n", userMass, periodicTable[randElement].name);
    } else {
        printf("Incorrect. %f is not the atomic mass of %s. \n", userMass, periodicTable[randElement].name);
    }

    return 0;
}