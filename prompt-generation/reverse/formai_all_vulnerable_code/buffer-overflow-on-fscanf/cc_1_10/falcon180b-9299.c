//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int atomic_mass;
};

void load_elements(struct element *table) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d %d", table[count].symbol, table[count].name, &table[count].atomic_number, &table[count].atomic_mass) == 4) {
        count++;
        if (count >= MAX_ELEMENTS) {
            printf("Error: too many elements in file.\n");
            exit(1);
        }
    }

    if (ferror(fp)) {
        printf("Error: could not read elements file.\n");
        exit(1);
    }

    fclose(fp);
}

void print_table(struct element *table) {
    printf("+----+----------------+-------+--------+\n");
    printf("| #  |   Symbol       |  Name  | Atomic  |\n");
    printf("+----+----------------+-------+--------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (table[i].symbol[0] == '\0') {
            break;
        }

        printf("| %2d | %-3s | %-16s | %6d |\n", i + 1, table[i].symbol, table[i].name, table[i].atomic_number);
    }

    printf("+----+----------------+-------+--------+\n");
}

int main() {
    struct element table[MAX_ELEMENTS];

    load_elements(table);
    print_table(table);

    return 0;
}