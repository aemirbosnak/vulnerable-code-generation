//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEMENTS 118 // Total number of elements in the periodic table
#define MAX_NAME_LEN 30 // Maximum length of element name
#define MAX_SYMBOL_LEN 3 // Maximum length of element symbol

struct element {
    char name[MAX_NAME_LEN]; // Element name
    char symbol[MAX_SYMBOL_LEN]; // Element symbol
    int atomic_number; // Atomic number of the element
    char category[MAX_NAME_LEN]; // Element category
};

void load_elements(struct element *elements) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open elements file.\n");
        exit(1);
    }

    // Read element data from file
    int count = 0;
    while (fscanf(fp, "%s %s %d %s\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, elements[count].category)!= EOF) {
        count++;
        if (count >= MAX_ELEMENTS) {
            printf("Error: Too many elements in file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    struct element elements[MAX_ELEMENTS];

    // Load element data from file
    load_elements(elements);

    // Print periodic table
    printf("Periodic Table of Elements\n");
    printf("+--------------------+--------------------+\n");
    printf("| Element Name        | Element Symbol     |\n");
    printf("+--------------------+--------------------+\n");

    // Print table rows
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0] == '\0') {
            break;
        }

        printf("| %-30s | %-3s |\n", elements[i].name, elements[i].symbol);
    }

    return 0;
}