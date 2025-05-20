//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
};

void load_elements(struct element *table) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d", table[count].name, table[count].symbol, &table[count].atomic_number)!= EOF) {
        count++;
    }

    fclose(fp);
}

void print_table(struct element *table) {
    printf("+----+-----------------+-------+\n");
    printf("| #  | Element          | Symbol |\n");
    printf("+----+-----------------+-------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (table[i].name[0] == '\0') {
            break;
        }

        printf("| %2d | %-20s | %-3s |\n", i+1, table[i].name, table[i].symbol);
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);
    print_table(elements);

    return 0;
}