//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 118

typedef struct {
    char name[3];
    char symbol[3];
    int atomic_number;
    int group;
    int period;
} element;

element periodic_table[MAX_ELEMENTS];

int main() {
    int i;
    FILE *file;
    char line[100];

    // Open the file
    file = fopen("periodic_table.txt", "r");

    // Read in the elements
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (fgets(line, 100, file) == NULL) {
            break;
        }
        strcpy(periodic_table[i].name, line);
        strcpy(periodic_table[i].symbol, line + strlen(line) - 1);
        periodic_table[i].atomic_number = i + 1;
        periodic_table[i].group = i / 8;
        periodic_table[i].period = i % 8;
    }

    fclose(file);

    // Print the periodic table
    printf("Periodic Table:\n");
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (periodic_table[i].name[0] == '\0') {
            break;
        }
        printf("%s %s %d\n", periodic_table[i].name, periodic_table[i].symbol, periodic_table[i].atomic_number);
    }

    return 0;
}