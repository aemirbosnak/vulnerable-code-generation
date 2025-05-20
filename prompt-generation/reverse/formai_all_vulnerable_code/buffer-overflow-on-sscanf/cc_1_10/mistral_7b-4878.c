//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol[3];
    int atomic_number;
    char name[30];
    char group;
    int period;
    char type;
} Element;

Element elements[118];

void load_data() {
    FILE *fp;
    char line[100];
    int i = 0;

    fp = fopen("periodic_table.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '%') continue;

        sscanf(line, "%s %d %s %s %s %s",
               elements[i].symbol, &elements[i].atomic_number,
               elements[i].name, &elements[i].group,
               &elements[i].period, &elements[i].type);

        for (int j = 0; j < i; j++) {
            if (strcmp(elements[i].symbol, elements[j].symbol) == 0) {
                printf("Error: Duplicate symbol '%s'\n", elements[i].symbol);
                exit(1);
            }
        }

        i++;
    }

    fclose(fp);
}

void print_table() {
    int width = 0;
    int max_width = 0;

    for (int i = 0; i < 118; i++) {
        int len = strlen(elements[i].symbol);
        if (len > max_width) max_width = len;
    }

    for (int j = 0; j <= max_width; j++) printf("%c", 196);
    printf("\n");

    for (int i = 0; i < 18; i++) {
        printf("%d ", i + 1);

        for (int j = i * 18; j < i * 18 + 18; j++) {
            int len = strlen(elements[j].symbol);
            printf("%*s %-15s %-10s %-10s %-5s\n", len + 2, elements[j].symbol,
                   elements[j].name, &elements[j].group, &elements[j].period,
                   &elements[j].type);
        }

        for (int j = i * 18 + 18; j < 118; j++) {
            if (j % 18 == i * 18) {
                printf("%s\n", "-----------------------------------------------------------------------");
            }
        }
    }
}

int main() {
    load_data();
    print_table();

    return 0;
}