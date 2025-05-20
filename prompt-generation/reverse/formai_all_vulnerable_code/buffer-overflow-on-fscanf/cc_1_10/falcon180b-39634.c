//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

struct element {
    char symbol[2];
    char name[20];
    int atomic_number;
    int group;
    int period;
};

void load_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d", elements[count].symbol, elements[count].name, &elements[count].atomic_number, &elements[count].group, &elements[count].period) == 5) {
        count++;
    }

    fclose(file);
}

void shuffle_elements(struct element *elements) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        struct element temp = elements[i];
        int j = rand() % MAX_ELEMENTS;
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);
    shuffle_elements(elements);

    int score = 0;
    int num_questions = rand() % 10 + 1;

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %d?\n", i+1, elements[index].atomic_number);

        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            score++;
        }
    }

    printf("You scored %d out of %d questions.\n", score, num_questions);

    return 0;
}