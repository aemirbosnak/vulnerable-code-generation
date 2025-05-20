//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[3];
    char symbol;
    int atomic_number;
    int atomic_weight;
    char category;
} Element;

Element periodic_table[MAX_ELEMENTS];

void load_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error loading periodic table\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s%c%d%d%c", periodic_table[count].name, &periodic_table[count].symbol, &periodic_table[count].atomic_number, &periodic_table[count].atomic_weight, &periodic_table[count].category)!= EOF) {
        count++;
    }

    fclose(file);
}

void print_periodic_table() {
    printf("PERIODIC TABLE\n");
    printf("=============\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (periodic_table[i].name[0] == '\0') {
            break;
        }

        printf("%-20s %-2c %4d %10d %c\n", periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_number, periodic_table[i].atomic_weight, periodic_table[i].category);
    }
}

int main() {
    load_periodic_table();
    print_periodic_table();

    return 0;
}