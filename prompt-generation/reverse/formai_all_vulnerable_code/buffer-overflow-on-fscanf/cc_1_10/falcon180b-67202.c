//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_ATTEMPTS 10

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    char category[10];
};

void init_elements(struct element elements[]) {
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        elements[i].symbol[0] = '\0';
        elements[i].name = '\0';
        elements[i].atomic_number = 0;
        elements[i].category[0] = '\0';
    }
}

void load_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, "%s %c %d %s", elements[i].symbol, &elements[i].name, &elements[i].atomic_number, elements[i].category) == 4) {
        i++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    struct element elements[MAX_ELEMENTS];
    init_elements(elements);
    load_elements(elements);

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int index = rand() % MAX_ELEMENTS;
        struct element element = elements[index];

        printf("Enter the symbol for %s:\n", element.name);
        char input[4];
        scanf("%s", input);

        if (strcmp(input, element.symbol) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct symbol is %s.\n", element.symbol);
        }

        attempts++;
    }

    return 0;
}