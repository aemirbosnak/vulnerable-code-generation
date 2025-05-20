//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char symbol[3]; // Maximum length of an element symbol is 2
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter the correct symbol for each given element.\n");

    // Possible quiz questions
    char *quizQuestions[][2] = {{"Hydrogen", "H"}, {"Helium", "He"}, {"Lithium", "Li"}, {"Beryllium", "Be"},
                                  {"Boron", "B"}, {"Carbon", "C"}, {"Nitrogen", "N"}, {"Oxygen", "O"},
                                  {"Fluorine", "F"}, {"Neon", "Ne"}, {"Sodium", "Na"}, {"Magnesium", "Mg"},
                                  {"Aluminum", "Al"}, {"Silicon", "Si"}, {"Phosphorus", "P"}, {"Sulfur", "S"}, {"Chlorine", "Cl"},
                                  {"Argon", "Ar"}, {"Potassium", "K"}, {"Calcium", "Ca"}, {"Scandium", "Sc"}, {"Titanium", "Ti"},
                                  {"Vanadium", "V"}, {"Chromium", "Cr"}, {"Manganese", "Mn"}, {"Iron", "Fe"}, {"Cobalt", "Co"},
                                  {"Nickel", "Ni"}, {"Copper", "Cu"}, {"Zinc", "Zn"}, {"Gallium", "Ga"}, {"Germanium", "Ge"},
                                  {"Arsenic", "As"}, {"Selenium", "Se"}, {"Bromine", "Br"}, {"Krypton", "Kr"}, {"Rubidium", "Rb"},
                                  {"Strontium", "Sr"}, {"Yttrium", "Y"}, {"Zirconium", "Zr"}, {"Niobium", "Nb"}, {"Molybdenum", "Mo"},
                                  {"Technetium", "Tc"}, {"Ruthenium", "Ru"}, {"Rhodium", "Rh"}, {"Palladium", "Pd"}, {"Silver", "Ag"},
                                  {"Cadmium", "Cd"}, {"Indium", "In"}, {"Tin", "Sn"}, {"Antimony", "Sb"}, {"Tellurium", "Te"},
                                  {"Iodine", "I"}, {"Xenon", "Xe"}, {"Cesium", "Cs"}, {"Barium", "Ba"}, {"Lanthanum", "La"}};

    int indexUsed[71]; // Stores the index of the already used elements
    int score = 0;

    for (int i = 0; i < 10; ++i) { // Generate 10 random questions
        int questionIndex = rand() % 71; // Generate random index
        while (indexUsed[questionIndex]) { // Check if the index has not been used before
            questionIndex = rand() % 71;
        }
        indexUsed[questionIndex] = 1; // Mark the index as used

        printf("Question %d: What is the symbol for %s?\n", i + 1, quizQuestions[questionIndex][0]);
        scanf("%s", symbol);

        if (strcmp(symbol, quizQuestions[questionIndex][1]) == 0) { // Correct answer
            printf("Correct!\n");
            score++;
        } else { // Incorrect answer
            printf("Wrong. The correct symbol is %s.\n", quizQuestions[questionIndex][1]);
        }
    }

    printf("Quiz finished!\n");
    printf("Your score is %d out of 10.\n", score);

    return 0;
}