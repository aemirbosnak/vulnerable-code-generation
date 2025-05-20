//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3

struct Element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
};

struct Element elements[MAX_ELEMENTS];

int main() {
    int num_elements = 0;
    FILE *fp = fopen("elements.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %d %d %d", elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].atomic_number, &elements[num_elements].group, &elements[num_elements].period)!= EOF) {
        num_elements++;
    }

    fclose(fp);

    printf("Periodic Table Quiz\n");

    int score = 0;
    int element_index;
    char element_symbol;
    while (1) {
        printf("Enter the symbol of an element or 'q' to quit: ");
        scanf(" %c", &element_symbol);

        if (element_symbol == 'q') {
            break;
        }

        element_index = 0;
        while (element_index < num_elements && strcmp(elements[element_index].symbol, element_symbol)!= 0) {
            element_index++;
        }

        if (element_index == num_elements) {
            printf("Invalid element symbol.\n");
        } else {
            printf("Enter the name of the element: ");
            scanf(" %s", elements[element_index].name);

            if (strcmp(elements[element_index].name, "Helium") == 0) {
                score++;
            }
        }
    }

    printf("Your score is: %d\n", score);

    return 0;
}