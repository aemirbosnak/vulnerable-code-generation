//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int atomic_weight;
};

void read_elements(struct element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].atomic_weight) == 4) {
        count++;
    }

    fclose(file);
}

int main() {
    struct element elements[MAX_ELEMENTS];

    read_elements(elements);

    int num_elements = count_elements(elements);
    printf("Found %d elements in the periodic table.\n", num_elements);

    for (int i = 0; i < num_elements; i++) {
        printf("%s - %s\n", elements[i].symbol, elements[i].name);
    }

    return 0;
}

int count_elements(struct element elements[]) {
    int count = 0;

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].symbol[0] == '\0') {
            break;
        }

        count++;
    }

    return count;
}