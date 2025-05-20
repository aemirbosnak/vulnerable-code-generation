//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
};

void read_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error opening elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s%s%d%d%d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period)!= EOF) {
        count++;
    }

    fclose(file);
}

void print_element(struct element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic number: %d\n", element.atomic_number);
    printf("Group: %d\n", element.group);
    printf("Period: %d\n\n", element.period);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);

    printf("Periodic Table:\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            print_element(elements[i]);
        }
    }

    return 0;
}