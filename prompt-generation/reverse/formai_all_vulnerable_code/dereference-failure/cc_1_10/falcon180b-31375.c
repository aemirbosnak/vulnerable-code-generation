//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
    double atomic_weight;
    char description[MAX_NAME_LENGTH];
};

void print_element(struct element *e);

int main() {
    struct element elements[MAX_ELEMENTS];
    int num_elements = 0;

    // Read in elements from file
    FILE *f = fopen("elements.txt", "r");
    if (f == NULL) {
        printf("Error opening elements file\n");
        return 1;
    }

    char line[MAX_NAME_LENGTH];
    while (fgets(line, MAX_NAME_LENGTH, f)!= NULL) {
        if (num_elements >= MAX_ELEMENTS) {
            printf("Maximum number of elements reached\n");
            break;
        }

        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));
        int group = atoi(strtok(NULL, ","));
        int period = atoi(strtok(NULL, ","));
        double atomic_weight = atof(strtok(NULL, ","));
        strncpy(elements[num_elements].description, strtok(NULL, ","), MAX_NAME_LENGTH);

        elements[num_elements].atomic_number = atomic_number;
        elements[num_elements].group = group;
        elements[num_elements].period = period;
        elements[num_elements].atomic_weight = atomic_weight;
        strncpy(elements[num_elements].name, name, MAX_NAME_LENGTH);
        strncpy(elements[num_elements].symbol, symbol, MAX_SYMBOL_LENGTH);

        num_elements++;
    }

    fclose(f);

    // Print out table of elements
    printf("Name\tSymbol\tAtomic Number\tGroup\tPeriod\tAtomic Weight\n");
    for (int i = 0; i < num_elements; i++) {
        print_element(&elements[i]);
    }

    return 0;
}

void print_element(struct element *e) {
    printf("%-20s", e->name);
    printf("%-3s", e->symbol);
    printf("%-10d", e->atomic_number);
    printf("%-10d", e->group);
    printf("%-10d", e->period);
    printf("%-10.2f", e->atomic_weight);
    printf("\n");
}