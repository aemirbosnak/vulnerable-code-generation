//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME 3
#define MAX_SYMBOL 3

struct element {
    char name[MAX_NAME];
    char symbol[MAX_SYMBOL];
    int atomic_number;
    int group;
    int period;
};

void read_elements(struct element* elements) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period)!= EOF) {
        count++;
    }

    fclose(file);
}

void display_periodic_table(struct element* elements) {
    printf("\n");
    printf("+----+------------------+--------+------------------+\n");
    printf("| %3s | %10s | %8s | %10s |\n", "No", "Element", "Atomic Number", "Group");
    printf("+----+------------------+--------+------------------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].atomic_number == 0) {
            break;
        }

        printf("| %3d | %10s | %8d | %10d |\n", i + 1, elements[i].name, elements[i].atomic_number, elements[i].group);
    }

    printf("+----+------------------+--------+------------------+\n");
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);
    display_periodic_table(elements);

    return 0;
}