//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTS_COUNT 118
#define ELEMENT_NAME_MAX_LENGTH 40
#define ELEMENT_SYMBOL_MAX_LENGTH 3

typedef struct {
    char name[ELEMENT_NAME_MAX_LENGTH];
    char symbol[ELEMENT_SYMBOL_MAX_LENGTH];
    int atomic_number;
} Element;

Element elements[ELEMENTS_COUNT];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

int main() {
    load_elements();

    int score = 0;
    int questions_answered = 0;

    while (questions_answered < ELEMENTS_COUNT) {
        int random_index = rand() % ELEMENTS_COUNT;
        Element element = elements[random_index];

        printf("Question %d: What is the name of the element with the symbol '%s'?\n", questions_answered + 1, element.symbol);

        char answer[ELEMENT_NAME_MAX_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, element.name) == 0) {
            score++;
        }

        questions_answered++;
    }

    printf("You got %d out of %d questions correct.\n", score, ELEMENTS_COUNT);

    return 0;
}