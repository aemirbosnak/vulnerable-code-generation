//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions, correct_answers;
    char answer[50];
    int i;
    struct {
        char element[50];
        char symbol[50];
        int atomic_number;
    } periodic_table[] = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Boron", "B", 5},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10},
        {"Sodium", "Na", 11},
        {"Magnesium", "Mg", 12},
        {"Aluminum", "Al", 13},
        {"Silicon", "Si", 14},
        {"Phosphorus", "P", 15},
        {"Sulfur", "S", 16},
        {"Chlorine", "Cl", 17},
        {"Argon", "Ar", 18},
        {"Potassium", "K", 19},
        {"Calcium", "Ca", 20},
        {"Iron", "Fe", 26},
        {"Copper", "Cu", 29},
        {"Gold", "Au", 79},
        {"Silver", "Ag", 47},
        {"Platinum", "Pt", 78},
        {"Mercury", "Hg", 80}
    };
    srand(time(NULL));
    num_questions = rand() % 20 + 5; // Generate a random number of questions between 5 and 20
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", num_questions);
    for (i = 0; i < num_questions; i++) {
        int index = rand() % 20; // Generate a random index for the periodic_table array
        printf("Question %d: What is the symbol for %s?\n", i+1, periodic_table[index].element);
        scanf("%s", answer);
        if (strcmp(answer, periodic_table[index].symbol) == 0) {
            correct_answers++;
        }
    }
    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);
    return 0;
}