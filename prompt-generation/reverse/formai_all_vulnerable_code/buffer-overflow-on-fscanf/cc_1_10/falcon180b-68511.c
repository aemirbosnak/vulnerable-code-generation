//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_ATOMIC_NUMBER_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_ATOMIC_NUMBER_LENGTH];
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period) == 5) {
        count++;
    }

    fclose(file);
}

void print_table() {
    printf("+----+----------------+-----+--------+\n");
    printf("| #  | Name            | Sym | Group  |\n");
    printf("+====+================+=====+=========\n");

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("| %2d | %-15s | %-3s | %2d |\n", i + 1, elements[i].name, elements[i].symbol, elements[i].group);
        }
    }

    printf("+----+----------------+-----+--------+\n");
}

int main() {
    load_elements();
    print_table();

    return 0;
}