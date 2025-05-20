//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol[3];
    char name[20];
    int group;
    int period;
} Element;

void print_header() {
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| %-2s | %-18s | %-3s | %-3s |\n", "Symbol", "Name", "Group", "Period");
    printf("--------------------------------------------------------------------------------------------------\n");
}

void print_element(Element e) {
    printf("| %-2s | %-18s | %-3d | %-3d |\n", e.symbol, e.name, e.group, e.period);
}

void read_elements(Element elements[], int limit) {
    FILE *file = fopen("elements.txt", "r");
    int i = 0;

    while (!feof(file) && i < limit) {
        fscanf(file, "%s %s %d %d", elements[i].symbol, elements[i].name, &elements[i].group, &elements[i].period);
        i++;
    }

    fclose(file);
}

int main() {
    int limit = 100;
    Element elements[limit];

    print_header();

    read_elements(elements, limit);

    for (int i = 0; i < limit; i++) {
        print_element(elements[i]);
    }

    printf("--------------------------------------------------------------------------------------------------\n");

    return 0;
}

// File elements.txt content:
// H   Hydrogen       1       1
// He  Helium         18      1
// Li  Lithium        3       1
// Be  Beryllium      4       1
// ...
// Br  Bromine       35       3
// Kr Kronium        86       6
// Rb  Rubidium       37      4
// Fr  Francium      87       6
// I   Iodine        53       5
// Xe Xenon          54       6