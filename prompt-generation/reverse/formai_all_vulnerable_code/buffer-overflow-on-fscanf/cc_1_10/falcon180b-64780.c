//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name;
    int atomic_number;
    int group;
    int period;
    int block;
    char category[20];
};

void print_element(struct element element) {
    printf("Symbol: %s\n", element.symbol);
    printf("Name: %c\n", element.name);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Group: %d\n", element.group);
    printf("Period: %d\n", element.period);
    printf("Block: %d\n", element.block);
    printf("Category: %s\n\n", element.category);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    int num_elements = 0;

    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error: could not open elements.txt\n");
        return 1;
    }

    while (fscanf(file, "%s%c%d%d%d%d%s", elements[num_elements].symbol, &elements[num_elements].name, &elements[num_elements].atomic_number, &elements[num_elements].group, &elements[num_elements].period, &elements[num_elements].block, elements[num_elements].category)!= EOF) {
        num_elements++;
    }

    fclose(file);

    srand(time(NULL));

    int score = 0;

    while (score < 10) {
        int index = rand() % num_elements;
        struct element element = elements[index];
        printf("What is the symbol for %s?\n", element.name);
        char input[4];
        scanf("%s", input);

        if (strcmp(input, element.symbol) == 0) {
            score++;
            print_element(element);
        } else {
            printf("Incorrect\n");
        }
    }

    return 0;
}