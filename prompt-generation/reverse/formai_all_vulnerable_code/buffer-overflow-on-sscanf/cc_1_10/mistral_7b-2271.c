//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define ELEMENT_SIZE 25

typedef struct {
    char symbol[3];
    char name[ELEMENT_SIZE];
    int group;
    int period;
} Element;

void print_element(Element* elem) {
    printf("| %-2s | %-15s | %d | %d |\n", elem->symbol, elem->name, elem->group, elem->period);
}

void print_table(Element elements[]) {
    printf("+-------+-----------------------------------+---+-----+\n");
    printf("|   SYM |             NAME              | GROUP| PERIOD |\n");
    printf("+-------+-----------------------------------+---+-----+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        print_element(&elements[i]);
    }

    printf("+-------+-----------------------------------+---+-----+\n");
}

void load_elements(Element elements[]) {
    FILE* file = fopen("periodic_table.txt", "r");

    if (file == NULL) {
        printf("Error loading file.\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%s%d%d", elements[index].symbol, elements[index].name, &elements[index].group, &elements[index].period);
        index++;
    }

    fclose(file);
}

int main() {
    Element elements[MAX_ELEMENTS];

    load_elements(elements);
    print_table(elements);

    return EXIT_SUCCESS;
}