//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element {
    char name[32];
    char symbol[3];
    int atomic_number;
    float atomic_weight;
} element;

void print_element(element *e) {
    printf("%s (%s): %d, %.2f\n", e->name, e->symbol, e->atomic_number, e->atomic_weight);
}

int main() {
    element elements[] = {
        {"Hydrogen", "H", 1, 1.008},
        {"Helium", "He", 2, 4.0026},
        {"Lithium", "Li", 3, 6.941},
        {"Beryllium", "Be", 4, 9.0122},
        {"Boron", "B", 5, 10.811},
        {"Carbon", "C", 6, 12.011},
        {"Nitrogen", "N", 7, 14.007},
        {"Oxygen", "O", 8, 15.999},
        {"Fluorine", "F", 9, 18.998},
        {"Neon", "Ne", 10, 20.180}
    };

    int num_elements = sizeof(elements) / sizeof(element);

    printf("Periodic Table Quiz\n");
    printf("--------------------\n");

    int score = 0;

    for (int i = 0; i < num_elements; i++) {
        char answer[32];

        printf("What is the name of element %d (%s)? ", i + 1, elements[i].symbol);
        scanf("%s", answer);

        if (strcmp(answer, elements[i].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].name);
        }
    }

    printf("\nYour score: %d/%d\n", score, num_elements);

    return 0;
}