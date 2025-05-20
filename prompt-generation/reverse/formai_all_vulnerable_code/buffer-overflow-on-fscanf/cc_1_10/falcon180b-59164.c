//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 30
#define MAX_SYMBOL_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
    char category[MAX_NAME_LENGTH];
};

void read_elements(struct element *elements) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %d %d %s", elements[count].name, elements[count].symbol, &(elements[count].atomic_number), &(elements[count].group), &(elements[count].period), elements[count].category)!= EOF) {
        count++;
    }

    fclose(fp);
}

void print_elements(struct element *elements) {
    printf("Element\tSymbol\tAtomic Number\tGroup\tPeriod\tCategory\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-30s %-3s %8d %8d %8d %s\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].group, elements[i].period, elements[i].category);
        }
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];

    read_elements(elements);
    print_elements(elements);

    return 0;
}