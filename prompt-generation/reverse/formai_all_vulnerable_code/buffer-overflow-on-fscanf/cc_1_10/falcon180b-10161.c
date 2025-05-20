//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118 // Maximum number of elements in the periodic table
#define MAX_NAME_LENGTH 30 // Maximum length of an element name
#define MAX_SYMBOL_LENGTH 3 // Maximum length of an element symbol

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS]; // Array to store all elements in the periodic table

void load_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r"); // Open the file containing the periodic table data
    if (file == NULL) {
        printf("Error: Could not open periodic_table.txt\n");
        exit(1);
    }

    int count = 0; // Keep track of the number of elements loaded
    while (count < MAX_ELEMENTS && fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

void print_periodic_table() {
    printf("Periodic Table:\n");
    printf("+----+----------------+-----+\n");
    printf("| #  | Element Name     | #   |\n");
    printf("+====+================+=====\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("| %2d | %-30s | %3d |\n", i + 1, elements[i].name, elements[i].atomic_number);
        }
    }

    printf("+----+----------------+-----+\n");
}

int main() {
    load_periodic_table();
    print_periodic_table();

    return 0;
}