#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int atomic_number;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
} Element;

int load_periodic_table(Element *elements, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    while (count < MAX_ELEMENTS && fscanf(file, "%d,%[^,],%[^\n]", &elements[count].atomic_number, elements[count].name, elements[count].symbol) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

void print_element(const Element *element) {
    printf("Atomic Number: %d\nName: %s\nSymbol: %s\n", element->atomic_number, element->name, element->symbol);
}

int main() {
    Element elements[MAX_ELEMENTS];
    int num_elements = load_periodic_table(elements, "periodic_table.txt");

    if (num_elements < 0) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_elements; i++) {
        print_element(&elements[i]);
    }

    return EXIT_SUCCESS;
}
