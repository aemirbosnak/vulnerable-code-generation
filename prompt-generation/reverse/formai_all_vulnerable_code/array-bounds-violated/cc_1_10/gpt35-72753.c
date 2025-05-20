//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to check if an element is in the array of answered questions
int inArray(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0)); // seed random number generator with current time

    // array of element symbols
    char *elements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", 
                        "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
                        "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"};

    // array of element names
    char *names[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium",
                     "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium",
                     "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel", "Copper", "Zinc", "Gallium", "Germanium",
                     "Arsenic", "Selenium", "Bromine", "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum",
                     "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium", "Tin", "Antimony", "Tellurium",
                     "Iodine", "Xenon"};

    // array of medieval-style questions
    char *questions[] = {"What be the symbol for the element that turnseth sand into glass?",
                         "Which element be named after a radiant light that shineth from within?",
                         "What powerful element be used in the construction of castles and fortresses?",
                         "Which element maketh ye sword sharp and strong?",
                         "What element doth fuel the roaring flames of ye furnace?",
                         "Which element doth giveth life to ye potion?",
                         "What be the element that twinkles like a star in ye nighttime sky?",
                         "Which element doth make ye poison deadly and deadly poison?",
                         "What be the element that doth preserve ye food for many a moon?",
                         "Which element hath ye power to heal wounds and mend bones?",
                         "What be the element that doth cause thunder and lightning on ye stormy eve?"};

    // array of answers to the questions
    int answers[] = {5, 2, 13, 4, 6, 7, 18, 9, 30, 20, 17};

    // initialize variables
    int score = 0;
    int answered[11];
    memset(answered, 0, sizeof(int) * 11);

    // print introduction
    printf("Welcome to the Medieval Periodic Table Quiz!\n");
    printf("Answer 10 questions about the elements and earn ye rightful place among the noble scientists of the realm.\n\n");

    // loop through 10 questions
    for (int i = 0; i < 10; i++) {
        int questionNum;
        do {
            questionNum = rand() % 11;
        } while (inArray(answered, i, questionNum));

        // print question
        printf("%d. %s\n", i+1, questions[questionNum]);

        // print answer options
        int answerOptions[4];
        for (int j = 0; j < 4; j++) {
            do {
                answerOptions[j] = rand() % 60;
            } while (answerOptions[j] == answers[questionNum] || inArray(answerOptions, j, answerOptions[j]));
            printf("%d. %s\t\t", j+1, elements[answerOptions[j]]);
        }
        printf("\n");

        // read and validate answer
        int choice;
        printf("Enter your answer: ");
        scanf("%d", &choice);
        while (choice < 1 || choice > 4) {
            printf("Invalid input. Please enter a number between 1 and 4: ");
            scanf("%d", &choice);
        }

        if (answerOptions[choice-1] == answers[questionNum]) {
            printf("Well done! Ye have answered correctly!\n\n");
            score++;
        } else {
            printf("Alas, ye have answered incorrectly. The correct answer wast: %s.\n\n", elements[answers[questionNum]]);
        }

        answered[i] = questionNum;
    }

    // print final score
    printf("Ye have completed the quiz! Ye score be %d out of 10.\n", score);

    return 0;
}