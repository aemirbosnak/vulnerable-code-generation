//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 32
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 4

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
} Element;

Element elements[NUM_ELEMENTS];

void init_elements() {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error opening elements file.\n");
        exit(1);
    }

    int count = 0;

    while (fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number)!= EOF) {
        count++;
    }

    fclose(file);
}

void print_element(Element element) {
    printf("%-32s %-3s %s\n", element.name, element.symbol, "");
}

void print_periodic_table() {
    printf("+------------------------+\n");
    printf("|   Periodic Table Quiz   |\n");
    printf("+------------------------+\n");

    printf("| Name                     | Symbol | Atomic Number |\n");
    printf("+------------------------+\n");

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        print_element(elements[i]);
    }

    printf("+------------------------+\n");
}

void quiz() {
    int score = 0;
    int num_questions = 10;

    srand(time(NULL));

    for (int i = 0; i < num_questions; i++) {
        int random_index = rand() % NUM_ELEMENTS;
        Element random_element = elements[random_index];

        char name[MAX_NAME_LENGTH];
        char symbol[MAX_SYMBOL_LENGTH];
        int atomic_number;

        printf("Question %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", name);
        printf("Symbol: ");
        scanf("%s", symbol);
        printf("Atomic Number: ");
        scanf("%d", &atomic_number);

        if (strcmp(name, random_element.name) == 0 &&
            strcmp(symbol, random_element.symbol) == 0 &&
            atomic_number == random_element.atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
        }
    }

    printf("Final score: %d/%d\n", score, num_questions);
}

int main() {
    init_elements();
    print_periodic_table();
    quiz();

    return 0;
}