//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

struct Element {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
};

void load_elements(struct Element elements[]) {
    FILE *file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error loading elements.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %c %d %d\n", elements[count].symbol, &elements[count].name, &elements[count].atomic_number, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(file);
}

void shuffle_array(struct Element elements[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    load_elements(elements);

    srand(time(NULL));
    shuffle_array(elements, MAX_ELEMENTS);

    int score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: ", i + 1);

        int correct_answer = -1;
        int user_answer = -1;

        for (int j = 0; j < MAX_ELEMENTS; j++) {
            if (strcmp(elements[j].symbol, "?") == 0) {
                correct_answer = j;
                break;
            }
        }

        while (1) {
            printf("Enter your answer (1-%d): ", MAX_ELEMENTS - 1);
            scanf("%d", &user_answer);

            if (user_answer >= 1 && user_answer <= MAX_ELEMENTS - 1) {
                break;
            }

            printf("Invalid input. Please try again.\n");
        }

        if (user_answer == correct_answer) {
            score++;
        }
    }

    printf("You scored %d out of %d questions.\n", score, total_questions);

    return 0;
}