//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    int atomic_number;
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];

void load_data() {
    FILE *fp;
    int i = 0;

    fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file periodic_table.txt\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(fp) && i < MAX_ELEMENTS) {
        fscanf(fp, "%s%d%d%d", elements[i].name, &elements[i].atomic_number,
               &elements[i].group, &elements[i].period);
        i++;
    }

    fclose(fp);
}

void print_header() {
    int i;

    printf(" %-3s", "");
    for (i = 1; i <= 18; i++)
        printf(" %-10s", "Period", i);
    printf("\n");

    printf("--------------------------------------------------------");
    for (i = 1; i <= 18; i++)
        printf("----------------------------------------------------");
    printf("\n");
}

void print_elements() {
    int i, j;

    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].period > 0) {
            printf(" %-3s", elements[i].name);
            for (j = 1; j <= elements[i].period; j++)
                printf(" %-10s", "");
            printf(" %-5d", elements[i].group);
            printf("\n");
        }
    }
}

int main() {
    load_data();
    print_header();
    print_elements();

    return EXIT_SUCCESS;
}

/* Periodic table data file format:
 * Each line starts with the name of an element, followed by its atomic number,
 * group number, and period number. All numbers are separated by spaces.
 */