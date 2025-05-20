//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Struct for storing element data
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    char period;
    char group;
} Element;

// Function to read data from a file and store it in an array of Element structs
void read_data(Element elements[], const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[100];
    int i = 0;

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        Element e;
        sscanf(line, "%s %s %d %c %c", e.symbol, e.name, &e.atomic_number, &e.period, &e.group);
        elements[i] = e;
        i++;
    }

    fclose(file);
}

// Function to display the periodic table in a medieval style
void display_table(Element elements[], int num_elements) {
    printf("\n*******************************************************************************\n");
    printf("*                                                                               *\n");
    printf("*          Welcome to the Magnificent and Wondrous Periodic Table!              *\n");
    printf("*                                                                               *\n");
    printf("*******************************************************************************\n");
    printf("*             | Period | Group | Symbol | Name                              | *\n");
    printf("*             |-------|-------|-------|--------------------------------------| *\n");

    for (int i = 0; i < num_elements; i++) {
        printf("* %2d | %2c | %2c | %-5s | %-15s |                                     *\n", i + 1, elements[i].period, elements[i].group, elements[i].symbol, elements[i].name);
    }

    printf("*                                                                               *\n");
    printf("*******************************************************************************\n");
}

int main() {
    const int num_elements = 118;
    Element elements[num_elements];

    // Read data from a file
    read_data(elements, "elements.txt");

    // Display the periodic table
    display_table(elements, num_elements);

    return 0;
}

// Sample data from 'elements.txt' file
// H  Hydrogen  1  1  1
// He Helium   2  0  18
// Li Lithium  3  1  3
// Be Beryllium 4  2  4
// ...