//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant for the maximum length of an element name
#define MAX_NAME_LENGTH 20

// Define a struct for an element
struct element {
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    double atomic_mass;
};

// Define a function to populate an array of elements
void populate_elements(struct element elements[]) {
    // Element data retrieved from the International Union of Pure and Applied Chemistry at https://www.iupac.org
    elements[0] = (struct element) {1, "H", "Hydrogen", 1.008};
    elements[1] = (struct element) {2, "He", "Helium", 4.003};
    elements[2] = (struct element) {3, "Li", "Lithium", 6.941};
    elements[3] = (struct element) {4, "Be", "Beryllium", 9.012};
    elements[4] = (struct element) {5, "B", "Boron", 10.81};
    elements[5] = (struct element) {6, "C", "Carbon", 12.01};
    elements[6] = (struct element) {7, "N", "Nitrogen", 14.01};
    elements[7] = (struct element) {8, "O", "Oxygen", 16.00};
    elements[8] = (struct element) {9, "F", "Fluorine", 19.00};
    elements[9] = (struct element) {10, "Ne", "Neon", 20.18};
    elements[10] = (struct element) {11, "Na", "Sodium", 22.99};
    elements[11] = (struct element) {12, "Mg", "Magnesium", 24.31};
    elements[12] = (struct element) {13, "Al", "Aluminium", 26.98};
    elements[13] = (struct element) {14, "Si", "Silicon", 28.09};
    elements[14] = (struct element) {15, "P", "Phosphorus", 30.97};
    elements[15] = (struct element) {16, "S", "Sulfur", 32.06};
    elements[16] = (struct element) {17, "Cl", "Chlorine", 35.45};
    elements[17] = (struct element) {18, "Ar", "Argon", 39.95};
    elements[18] = (struct element) {19, "K", "Potassium", 39.10};
    elements[19] = (struct element) {20, "Ca", "Calcium", 40.08};
    elements[20] = (struct element) {21, "Sc", "Scandium", 44.96};
    elements[21] = (struct element) {22, "Ti", "Titanium", 47.87};
    elements[22] = (struct element) {23, "V", "Vanadium", 50.94};
    elements[23] = (struct element) {24, "Cr", "Chromium", 52.00};
    elements[24] = (struct element) {25, "Mn", "Manganese", 54.94};
    elements[25] = (struct element) {26, "Fe", "Iron", 55.85};
    elements[26] = (struct element) {27, "Co", "Cobalt", 58.93};
    elements[27] = (struct element) {28, "Ni", "Nickel", 58.69};
    elements[28] = (struct element) {29, "Cu", "Copper", 63.55};
    elements[29] = (struct element) {30, "Zn", "Zinc", 65.38};
    elements[30] = (struct element) {31, "Ga", "Gallium", 69.72};
    elements[31] = (struct element) {32, "Ge", "Germanium", 72.63};
    elements[32] = (struct element) {33, "As", "Arsenic", 74.92};
    elements[33] = (struct element) {34, "Se", "Selenium", 78.96};
    elements[34] = (struct element) {35, "Br", "Bromine", 79.90};
    elements[35] = (struct element) {36, "Kr", "Krypton", 83.80};
    elements[36] = (struct element) {37, "Rb", "Rubidium", 85.47};
    elements[37] = (struct element) {38, "Sr", "Strontium", 87.62};
    elements[38] = (struct element) {39, "Y", "Yttrium", 88.91};
    elements[39] = (struct element) {40, "Zr", "Zirconium", 91.22};
    elements[40] = (struct element) {41, "Nb", "Niobium", 92.91};
    elements[41] = (struct element) {42, "Mo", "Molybdenum", 95.94};
    elements[42] = (struct element) {43, "Tc", "Technetium", 98.00};
    elements[43] = (struct element) {44, "Ru", "Ruthenium", 101.1};
    elements[44] = (struct element) {45, "Rh", "Rhodium", 102.9};
    elements[45] = (struct element) {46, "Pd", "Palladium", 106.4};
    elements[46] = (struct element) {47, "Ag", "Silver", 107.9};
    elements[47] = (struct element) {48, "Cd", "Cadmium", 112.4};
    elements[48] = (struct element) {49, "In", "Indium", 114.8};
    elements[49] = (struct element) {50, "Sn", "Tin", 118.7};
    elements[50] = (struct element) {51, "Sb", "Antimony", 121.8};
    elements[51] = (struct element) {52, "Te", "Tellurium", 127.6};
    elements[52] = (struct element) {53, "I", "Iodine", 126.9};
    elements[53] = (struct element) {54, "Xe", "Xenon", 131.3};
}

int main() {
    // Create an array of 54 elements (current count of known elements)
    struct element elements[54];

    // Populate the array with element data
    populate_elements(elements);

    // Display a welcome message
    printf("Welcome to the Periodic Table Quiz!\n");

    // Initialize variables to keep track of the user's score and the total number of questions
    int score = 0;
    int total_questions = 0;

    // Ask the user if they want to start the quiz
    printf("Are you ready to start the quiz (yes/no)? ");
    char start_answer[4];
    scanf("%s", start_answer);

    // Start the quiz if the user answered "yes"
    if (strcmp(start_answer, "yes") == 0) {
        // Loop through each element in the array and ask the user a question
        for (int i = 0; i < 54; i++) {
            // Generate a random number between 1 and 3 to choose the type of question to ask
            int question_type = rand() % 3 + 1;

            // Increase the total question count
            total_questions++;

            // Display information about the current element
            printf("\nElement #%d:\n", elements[i].atomic_number);
            printf("Symbol: %s\n", elements[i].symbol);
            printf("Name: %s\n", elements[i].name);
            printf("Atomic mass: %g\n", elements[i].atomic_mass);

            // Ask the user a question based on the question type
            switch(question_type) {
                // Ask the user to input the element's atomic number
                case 1:
                    printf("What is the atomic number of %s? ", elements[i].name);
                    int atomic_number_answer;
                    scanf("%d", &atomic_number_answer);
                    if (atomic_number_answer == elements[i].atomic_number) {
                        printf("Correct!\n");
                        score++;
                    } else {
                        printf("Incorrect. The correct answer is %d.\n", elements[i].atomic_number);
                    }
                    break;

                // Ask the user to input the element's symbol
                case 2:
                    printf("What is the symbol for %s? ", elements[i].name);
                    char symbol_answer[3];
                    scanf("%s", symbol_answer);
                    if (strcmp(symbol_answer, elements[i].symbol) == 0) {
                        printf("Correct!\n");
                        score++;
                    } else {
                        printf("Incorrect. The correct answer is %s.\n", elements[i].symbol);
                    }
                    break;

                // Ask the user to input the element's atomic mass
                case 3:
                    printf("What is the atomic mass of %s? ", elements[i].name);
                    double atomic_mass_answer;
                    scanf("%lf", &atomic_mass_answer);
                    if (atomic_mass_answer == elements[i].atomic_mass) {
                        printf("Correct!\n");
                        score++;
                    } else {
                        printf("Incorrect. The correct answer is %g.\n", elements[i].atomic_mass);
                    }
                    break;
            }
        }

        // Calculate the user's final score
        double percent_correct = (double)score / total_questions * 100;

        // Display the user's score
        printf("\nCongratulations, you completed the quiz!\n");
        printf("Total questions: %d\n", total_questions);
        printf("Correct answers: %d\n", score);
        printf("Percent correct: %g%%\n", percent_correct);
    } else {
        // Display a message if the user did not want to start the quiz
        printf("Okay, maybe next time. Goodbye!\n");
    }

    return 0;
}