//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
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
    int group;
    int period;
    char category[MAX_NAME_LENGTH];
};

void read_elements(struct element elements[]);
void print_elements(struct element elements[]);
int compare_elements(const void *a, const void *b);

int main() {
    struct element elements[MAX_ELEMENTS];

    read_elements(elements);
    qsort(elements, MAX_ELEMENTS, sizeof(struct element), compare_elements);
    print_elements(elements);

    return 0;
}

void read_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error reading elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void print_elements(struct element elements[]) {
    printf("Name\tSymbol\tAtomic Number\tGroup\tPeriod\tCategory\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-10s %-5s %5d %5d %5d %s\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].group, elements[i].period, elements[i].category);
        }
    }
}

int compare_elements(const void *a, const void *b) {
    struct element *e1 = (struct element *)a;
    struct element *e2 = (struct element *)b;

    if (e1->atomic_number < e2->atomic_number) {
        return -1;
    } else if (e1->atomic_number > e2->atomic_number) {
        return 1;
    } else {
        return 0;
    }
}