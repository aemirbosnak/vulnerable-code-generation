//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define NUM_ELEMENTS 118

struct {
    char name[50];
    char symbol[10];
    int atomic_number;
    float atomic_weight;
} elements[NUM_ELEMENTS];

void init_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d %f", elements[count].name, elements[count].symbol, &elements[count].atomic_number, &elements[count].atomic_weight)!= EOF) {
        count++;
    }

    fclose(file);
}

void generate_question(int question_number) {
    int random_index = rand() % NUM_ELEMENTS;
    printf("Question %d: What is the symbol for element %s?\n", question_number + 1, elements[random_index].name);
}

int main() {
    srand(time(NULL));

    init_elements();

    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        int correct_answer = 0;
        while (correct_answer == 0) {
            generate_question(i);
            char answer[10];
            scanf("%s", answer);

            for (int j = 0; j < NUM_ELEMENTS; j++) {
                if (strcmp(answer, elements[j].symbol) == 0) {
                    correct_answer = 1;
                    score++;
                }
            }

            if (correct_answer == 0) {
                printf("Incorrect, try again.\n");
            }
        }
    }

    printf("Your final score is %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}