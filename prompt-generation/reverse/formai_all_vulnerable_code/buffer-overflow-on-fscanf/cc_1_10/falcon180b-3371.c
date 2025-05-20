//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    char category[20];
};

void read_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %s", elements[count].symbol, elements[count].name, &elements[count].atomic_number, elements[count].category) == 4) {
        count++;
    }

    fclose(file);
}

int compare_names(const void *a, const void *b) {
    struct element *elem_a = (struct element *)a;
    struct element *elem_b = (struct element *)b;

    return strcmp(elem_a->name, elem_b->name);
}

int compare_symbols(const void *a, const void *b) {
    struct element *elem_a = (struct element *)a;
    struct element *elem_b = (struct element *)b;

    return strcmp(elem_a->symbol, elem_b->symbol);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    read_elements(elements);

    int num_elements = count_elements(elements);

    qsort(elements, num_elements, sizeof(struct element), compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s - %s\n", elements[i].symbol, elements[i].name);
    }

    qsort(elements, num_elements, sizeof(struct element), compare_symbols);

    printf("\nSorted by symbol:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s - %s\n", elements[i].symbol, elements[i].name);
    }

    return 0;
}

int count_elements(struct element elements[]) {
    int count = 0;
    while (elements[count].symbol[0]!= '\0') {
        count++;
    }
    return count;
}