//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LEN 30
#define MAX_SYMBOL_LEN 3

struct element {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int atomic_number;
    int group;
    int period;
    char category[MAX_NAME_LEN];
};

void load_elements(struct element *elements) {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements file\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %d %d %s", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].group, &elements[count].period, elements[count].category) == 6) {
        count++;
    }

    fclose(file);
}

void print_elements(struct element *elements, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d. %s (%s) - %s\n", i, elements[i].name, elements[i].symbol, elements[i].category);
    }
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_elements = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        if (elements[i].name[0]!= '\0') {
            num_elements++;
        } else {
            break;
        }
    }

    int questions = 10;
    int elements_per_question = num_elements / questions;

    int correct_answers = 0;

    for (int i = 0; i < questions; i++) {
        int start = i * elements_per_question;
        int end = (i + 1) * elements_per_question - 1;
        if (end >= num_elements) {
            end = num_elements - 1;
        }

        printf("Question %d:\n", i + 1);
        print_elements(elements, start, end);

        char answer[MAX_NAME_LEN];
        printf("Enter your answer: ");
        scanf("%s", answer);

        for (int j = start; j <= end; j++) {
            if (strcmp(answer, elements[j].name) == 0) {
                correct_answers++;
                break;
            }
        }
    }

    printf("You got %d out of %d correct.\n", correct_answers, num_elements);

    return 0;
}