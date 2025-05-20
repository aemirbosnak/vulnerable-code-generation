//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 100
#define MAX_FORMULA_LENGTH 100

struct Element {
    char name[MAX_NAME_LENGTH];
    char formula[MAX_FORMULA_LENGTH];
    int atomic_number;
    double atomic_weight;
};

void load_elements(struct Element elements[]) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %lf", elements[count].name, elements[count].formula, &elements[count].atomic_number, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(file);
}

void shuffle_elements(struct Element elements[]) {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    srand(time(NULL));

    struct Element elements[MAX_ELEMENTS];
    load_elements(elements);
    shuffle_elements(elements);

    int score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i + 1, elements[index].name);

        char guess[MAX_NAME_LENGTH];
        scanf("%s", guess);

        if (strcmp(guess, elements[index].formula) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].formula);
        }
    }

    printf("Your final score is %d out of %d.\n", score, total_questions);

    return 0;
}