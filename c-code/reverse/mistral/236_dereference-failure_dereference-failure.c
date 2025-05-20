#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    char name[30];
    int atomic_number;
    char symbol[4];
    double atomic_weight;
} Element;

int main() {
    FILE *file = fopen("periodic_table.txt", "r");
    Element elements[MAX_ELEMENTS];
    int num_elements = 0;

    while (num_elements < MAX_ELEMENTS && fscanf(file, "%s,%d,%s,%lf", elements[num_elements].name, &elements[num_elements].atomic_number, elements[num_elements].symbol, &elements[num_elements].atomic_weight) == 4) {
        num_elements++;
    }

    int question;
    printf("Guess the atomic number of the following element: \n");
    scanf("%d", &question);

    for (int i = 0; i < num_elements; i++) {
        if (question == elements[i].atomic_number) {
            printf("Correct! The element is %s (%s).\n", elements[i].name, elements[i].symbol);
            return 0;
        }
    }

    printf("Incorrect. The element does not exist in the provided data.\n");
    return 0;
}
