//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double value;
} element_t;

int compare_elements(const void* a, const void* b)
{
    const element_t* elem_a = (const element_t*)a;
    const element_t* elem_b = (const element_t*)b;

    if (elem_a->value > elem_b->value) {
        return 1;
    } else if (elem_a->value < elem_b->value) {
        return -1;
    } else {
        return 0;
    }
}

void print_elements(const element_t* elements, int num_elements)
{
    printf("Elements (sorted by value):\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s: %.2f\n", elements[i].name, elements[i].value);
    }
}

int main()
{
    element_t elements[MAX_ELEMENTS];
    int num_elements = 0;

    printf("Enter elements (name:value):\n");
    while (num_elements < MAX_ELEMENTS && scanf("%s:%lf", elements[num_elements].name, &elements[num_elements].value) == 2) {
        num_elements++;
    }

    qsort(elements, num_elements, sizeof(element_t), compare_elements);

    print_elements(elements, num_elements);

    return 0;
}