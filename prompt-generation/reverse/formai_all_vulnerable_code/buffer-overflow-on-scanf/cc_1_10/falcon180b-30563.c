//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements, num_questions, score = 0;
    char *elements[118];
    char *answers[118];
    char *correct_answers[118];
    int values[118];
    int correct_values[118];
    int i, j, k;

    srand(time(0));
    num_elements = rand() % 118 + 1; // Randomly select number of elements to quiz on
    num_questions = rand() % 10 + 1; // Randomly select number of questions to ask

    // Initialize elements, answers, and values arrays
    for (i = 0; i < num_elements; i++) {
        elements[i] = (char *) malloc(10 * sizeof(char));
        answers[i] = (char *) malloc(10 * sizeof(char));
        values[i] = rand() % 118 + 1; // Randomly assign values to elements
        sprintf(elements[i], "%2d", values[i]);
        correct_answers[i] = elements[i];
    }

    // Shuffle elements array
    for (i = 0; i < num_elements; i++) {
        j = rand() % num_elements;
        k = i;
        while (k!= j) {
            char *temp = elements[k];
            elements[k] = elements[j];
            elements[j] = temp;
            k = (k + 1) % num_elements;
            j = (j + 1) % num_elements;
        }
    }

    // Ask quiz questions
    printf("Periodic Table Quiz\n");
    for (i = 0; i < num_questions; i++) {
        int index = rand() % num_elements;
        printf("What is the atomic number of %s? ", elements[index]);
        scanf("%s", answers[index]);
        if (strcmp(answers[index], correct_answers[index]) == 0) {
            score++;
        }
    }

    // Print score
    printf("\nYou scored %d out of %d questions correct!\n", score, num_questions);

    return 0;
}