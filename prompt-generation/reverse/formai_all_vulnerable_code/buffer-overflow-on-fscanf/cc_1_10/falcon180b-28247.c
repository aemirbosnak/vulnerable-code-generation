//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int atomic_mass;
    char category[MAX_NAME_LENGTH];
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error: Could not load elements file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(file, "%s %s %d %d %s\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_mass, elements[count].category) == 5) {
        count++;
    }

    fclose(file);
}

void print_elements() {
    printf("Name\tSymbol\tAtomic Number\tAtomic Mass\tCategory\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-50s %-3s %10d %10d %-50s\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_mass, elements[i].category);
        }
    }
}

int main() {
    load_elements();
    print_elements();

    return 0;
}