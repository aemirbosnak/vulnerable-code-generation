//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int atomic_weight;
};

void read_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_weight) == 4) {
        count++;
        if (count >= MAX_ELEMENTS) {
            printf("Error: Too many elements in file.\n");
            exit(1);
        }
    }

    fclose(file);
}

void print_table_header() {
    printf("+----+---------------------+---------------------+--------+\n");
    printf("| #  | Name                 | Symbol              | Weight |\n");
    printf("+----+---------------------+---------------------+--------+\n");
}

void print_table_row(struct element element) {
    printf("| %3d | %-10s | %-10s | %5d |\n", element.atomic_number, element.name, element.symbol, element.atomic_weight);
}

void print_table_footer() {
    printf("+----+---------------------+---------------------+--------+\n");
}

void print_table(struct element *elements, int count) {
    print_table_header();

    for (int i = 0; i < count; i++) {
        print_table_row(elements[i]);
    }

    print_table_footer();
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);

    int count = 0;
    while (count < MAX_ELEMENTS && elements[count].atomic_number == 0) {
        count++;
    }

    if (count >= MAX_ELEMENTS) {
        printf("Error: No elements found in file.\n");
        exit(1);
    }

    print_table(elements, count);

    return 0;
}