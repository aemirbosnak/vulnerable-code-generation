//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 3
#define MAX_SYMBOL_LEN 3

struct element {
    char name[MAX_NAME_LEN + 1];
    char symbol[MAX_SYMBOL_LEN + 1];
    int atomic_number;
};

void read_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements.txt\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    if (count!= MAX_ELEMENTS) {
        printf("Error: invalid number of elements in elements.txt\n");
        exit(1);
    }

    fclose(file);
}

void print_table(struct element *elements) {
    printf("+----+----------------+----------------+\n");
    printf("| #  | Element Name    | Symbol         |\n");
    printf("+----+----------------+----------------+\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("| %2d | %-14s | %-14s |\n", i + 1, elements[i].name, elements[i].symbol);
    }

    printf("+----+----------------+----------------+\n");
}

int main() {
    struct element elements[MAX_ELEMENTS];

    read_elements(elements);
    print_table(elements);

    return 0;
}