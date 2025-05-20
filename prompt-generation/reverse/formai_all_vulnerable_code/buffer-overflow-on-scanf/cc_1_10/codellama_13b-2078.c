//Code Llama-13B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct {
    char name[10];
    char symbol[3];
    int atomic_number;
    float atomic_mass;
    char period[2];
    char group[2];
    char block[10];
} Element;

Element elements[MAX_ELEMENTS] = {
    {"Hydrogen", "H", 1, 1.0079, "1", "1", "s-block"},
    {"Helium", "He", 2, 4.0026, "1", "18", "noble-gas"},
    {"Lithium", "Li", 3, 6.941, "2", "1", "alkali-metal"},
    {"Beryllium", "Be", 4, 9.0122, "2", "2", "alkaline-earth-metal"},
    {"Boron", "B", 5, 10.811, "2", "13", "p-block"},
    {"Carbon", "C", 6, 12.0107, "2", "14", "p-block"},
    {"Nitrogen", "N", 7, 14.0067, "2", "15", "p-block"},
    {"Oxygen", "O", 8, 15.9994, "2", "16", "p-block"},
    {"Fluorine", "F", 9, 18.9984, "2", "17", "p-block"},
    {"Neon", "Ne", 10, 20.1797, "2", "18", "noble-gas"},
    // ...
};

int main() {
    int i, j, k;
    int correct_answers = 0;
    int total_questions = 0;

    srand(time(NULL));

    for (i = 0; i < MAX_QUESTIONS; i++) {
        int element_index = rand() % MAX_ELEMENTS;
        Element *element = &elements[element_index];
        printf("What is the atomic number of %s?\n", element->name);
        printf("A) %d\nB) %d\nC) %d\nD) %d\n", element->atomic_number, element->atomic_number + 1, element->atomic_number + 2, element->atomic_number + 3);
        char answer;
        scanf("%c", &answer);
        if (answer == element->atomic_number + '0') {
            correct_answers++;
        }
        total_questions++;
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, total_questions);

    return 0;
}