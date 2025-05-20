//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    int atomic_number;
    float atomic_mass;
};

void load_elements(struct element* elements) {
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %f\n", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_mass) == 4) {
        count++;
    }

    fclose(file);
}

void display_elements(struct element* elements) {
    printf("Element\tSymbol\tAtomic Number\tAtomic Mass\n");
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            printf("%-10s%-10s%d\t%.2f\n", elements[i].name, elements[i].symbol, elements[i].atomic_number, elements[i].atomic_mass);
        }
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_elements = 0;
    while (elements[num_elements].name[0]!= '\0') {
        num_elements++;
    }

    char input[MAX_NAME_LENGTH];
    while (1) {
        printf("Enter an element name or symbol (or type 'quit' to exit):\n");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int found = 0;
        for (int i = 0; i < num_elements; i++) {
            if (strcmp(elements[i].name, input) == 0 || strcmp(elements[i].symbol, input) == 0) {
                printf("Element: %s\n", elements[i].name);
                printf("Symbol: %s\n", elements[i].symbol);
                printf("Atomic Number: %d\n", elements[i].atomic_number);
                printf("Atomic Mass: %.2f\n", elements[i].atomic_mass);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Element not found.\n");
        }
    }

    return 0;
}