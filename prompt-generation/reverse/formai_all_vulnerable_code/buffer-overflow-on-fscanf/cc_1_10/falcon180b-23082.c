//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    MAX_ELEMENTS = 118,
    MAX_NAME_LENGTH = 32,
    MAX_SYMBOL_LENGTH = 3
};

struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
};

void read_elements(struct Element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int num_elements = 0;
    while (fscanf(file, "%s %s %d %d %d", elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].atomic_number, &elements[num_elements].group, &elements[num_elements].period)!= EOF) {
        num_elements++;
    }

    fclose(file);
}

void display_table(struct Element *elements) {
    printf("+----+----------------------+--------+--------+\n");
    printf("| #  | Name                 | Symbol | Group  |\n");
    printf("+----+----------------------+--------+--------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].atomic_number == 0) {
            break;
        }

        printf("| %2d | %-32s | %-3s | %3d |\n", i+1, elements[i].name, elements[i].symbol, elements[i].group);
    }

    printf("+----+----------------------+--------+--------+\n");
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    read_elements(elements);
    display_table(elements);

    return 0;
}