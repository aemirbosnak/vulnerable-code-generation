//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
    char category[MAX_NAME_LENGTH];
    float atomic_weight;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open periodic_table.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %d %d %s %f\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(fp);
}

void print_elements() {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%s (%s)\n", elements[i].name, elements[i].symbol);
        }
    }
}

int main() {
    load_elements();
    print_elements();

    return 0;
}