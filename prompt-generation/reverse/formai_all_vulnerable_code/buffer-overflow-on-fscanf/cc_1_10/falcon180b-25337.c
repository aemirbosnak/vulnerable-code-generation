//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[3];
    char name[20];
    int atomic_number;
    int group;
    float atomic_weight;
};

void load_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Failed to load elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %f", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(file);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_questions = 10;
    int correct_answers = 0;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        struct element question = elements[index];

        printf("Question %d:\n", i + 1);
        printf("Symbol: %s\n", question.symbol);
        printf("Name: %s\n", question.name);
        printf("Atomic number: %d\n", question.atomic_number);
        printf("Group: %d\n", question.group);
        printf("Atomic weight: %.2f\n", question.atomic_weight);

        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, question.symbol) == 0) {
            correct_answers++;
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}