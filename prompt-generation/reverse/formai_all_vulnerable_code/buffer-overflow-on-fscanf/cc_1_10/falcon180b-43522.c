//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define ELEMENT_NAME_LENGTH 3
#define ELEMENT_SYMBOL_LENGTH 2
#define ELEMENT_ATOMIC_NUMBER_LENGTH 3

typedef struct {
    char element_name[ELEMENT_NAME_LENGTH + 1];
    char element_symbol[ELEMENT_SYMBOL_LENGTH + 1];
    char element_atomic_number[ELEMENT_ATOMIC_NUMBER_LENGTH + 1];
    int element_atomic_number_int;
} Element;

Element periodic_table[MAX_ELEMENTS];

void initialize_periodic_table() {
    int i;
    FILE *file;

    file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open periodic_table.txt\n");
        exit(1);
    }

    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (fscanf(file, "%s %s %s %d\n", periodic_table[i].element_name, periodic_table[i].element_symbol, periodic_table[i].element_atomic_number, &periodic_table[i].element_atomic_number_int)!= 4) {
            printf("Error: Invalid data in periodic_table.txt\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    int num_questions, correct_answers;
    int i, j, random_index, user_answer;
    char element_name[ELEMENT_NAME_LENGTH + 1];
    char element_symbol[ELEMENT_SYMBOL_LENGTH + 1];
    char element_atomic_number[ELEMENT_ATOMIC_NUMBER_LENGTH + 1];

    srand(time(NULL));
    num_questions = rand() % 10 + 1; // Generate random number of questions between 1 and 10

    initialize_periodic_table();

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n", num_questions);

    for (i = 0; i < num_questions; i++) {
        random_index = rand() % MAX_ELEMENTS;
        strcpy(element_name, periodic_table[random_index].element_name);
        strcpy(element_symbol, periodic_table[random_index].element_symbol);
        strcpy(element_atomic_number, periodic_table[random_index].element_atomic_number);

        printf("Question %d:\n", i + 1);
        printf("What is the name of the element with symbol '%s'?\n", element_symbol);

        scanf(" %s", element_name);
        if (strcmp(element_name, periodic_table[random_index].element_name) == 0) {
            correct_answers++;
        }

        printf("The correct answer is '%s'.\n\n", periodic_table[random_index].element_name);
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}