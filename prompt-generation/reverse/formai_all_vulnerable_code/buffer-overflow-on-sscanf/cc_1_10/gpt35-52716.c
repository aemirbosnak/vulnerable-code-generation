//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

struct element {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[30];
    int atomic_number;
    double atomic_mass;
    char state[20];
};

void print_element(struct element e) {
    printf("%s (%s)\n", e.symbol, e.name);
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Atomic Mass: %.4f\n", e.atomic_mass);
    printf("State at room temperature: %s\n", e.state);
}

int main() {
    struct element elements[NUM_ELEMENTS];

    FILE *fp = fopen("periodic_table.txt", "r");

    int index = 0;
    char line[100];

    // Read data and populate elements array
    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s %s %d %lf %s", elements[index].symbol, elements[index].name, &elements[index].atomic_number, &elements[index].atomic_mass, elements[index].state);
        index++;
    }

    fclose(fp);

    printf("=== Welcome to the Periodic Table Quiz ===\n\n");

    int correct_answers = 0;

    char answer[MAX_SYMBOL_LENGTH];

    for (int i = 0; i < 10; i++) {
        // Generate random element index
        int random_index = rand() % NUM_ELEMENTS;

        print_element(elements[random_index]);

        printf("Enter the symbol of this element: ");
        scanf("%s", answer);

        if (strcmp(answer, elements[random_index].symbol) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", elements[random_index].symbol);
        }
    }

    printf("You answered %d out of 10 questions correctly.\n", correct_answers);

    return 0;
}