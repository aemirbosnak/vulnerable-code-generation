#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define LINE_LENGTH 100

typedef struct {
    char name[30];
    int atomic_number;
    char symbol[4];
    int group;
    int period;
    int weight;
} Element;

Element elements[MAX_ELEMENTS];
int num_elements = 0;

void load_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    char line[LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, LINE_LENGTH, file)) {
        line_num++;
        sscanf(line, "%s %d %s %d %d %d", elements[num_elements].name, &elements[num_elements].atomic_number,
               elements[num_elements].symbol, &elements[num_elements].group, &elements[num_elements].period,
               &elements[num_elements].weight);
        num_elements++;
    }
    fclose(file);
}

void print_element(Element e) {
    printf("%d. %s (%s) - Group %d, Period %d, Weight %d\n", e.atomic_number, e.name, e.symbol, e.group, e.period, e.weight);
}

void print_elements() {
    for (int i = 0; i < num_elements; i++) {
        print_element(elements[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: periodic_table data.txt\n");
        return 1;
    }

    load_data(argv[1]);
    print_elements();

    return 0;
}
