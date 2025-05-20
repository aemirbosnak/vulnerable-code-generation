//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
    int group;
    int period;
} element;

void load_elements(element *elements) {
    FILE *f = fopen("elements.txt", "r");
    if (f == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(f, "%s %s %d %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group) == 4) {
        count++;
        if (count >= MAX_ELEMENTS) {
            printf("Error: too many elements in file.\n");
            exit(1);
        }
    }

    fclose(f);
}

int main() {
    element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_elements = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            num_elements++;
        }
    }

    char input[MAX_NAME_LENGTH];
    printf("Enter an element name or symbol: ");
    scanf("%s", input);

    tolower(input);
    int found_element = 0;

    for (int i = 0; i < num_elements; i++) {
        if (strcmp(input, elements[i].name) == 0 || strcmp(input, elements[i].symbol) == 0) {
            printf("Element found: %s\n", input);
            printf("Name: %s\n", elements[i].name);
            printf("Symbol: %s\n", elements[i].symbol);
            printf("Atomic number: %d\n", elements[i].atomic_number);
            printf("Group: %d\n", elements[i].group);
            printf("Period: %d\n\n", elements[i].period);
            found_element = 1;
            break;
        }
    }

    if (!found_element) {
        printf("Element not found.\n");
    }

    return 0;
}