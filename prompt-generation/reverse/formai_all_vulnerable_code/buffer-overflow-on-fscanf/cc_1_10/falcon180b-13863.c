//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
} element;

void read_elements(element elements[]) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period)!= EOF) {
        count++;
    }

    fclose(file);
}

void print_table(element elements[]) {
    printf("+----+------------------+-------+--------+\n");
    printf("| %6s | %20s | %10s | %10s |\n", "No.", "Name", "Symbol", "Atomic Number");
    printf("+----+------------------+-------+--------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("| %6d | %20s | %10s | %10d |\n", i+1, elements[i].name, elements[i].symbol, elements[i].atomic_number);
        }
    }

    printf("+----+------------------+-------+--------+\n");
}

void main() {
    element elements[MAX_ELEMENTS];
    read_elements(elements);
    print_table(elements);
}