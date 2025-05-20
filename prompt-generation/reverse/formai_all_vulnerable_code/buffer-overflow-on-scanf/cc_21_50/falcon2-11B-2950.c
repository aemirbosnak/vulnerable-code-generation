//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 100
#define NUM_ANSWERS 4

typedef struct element_info {
    char element[10];
    int atomic_number;
    int group;
    char symbol[2];
    char name[20];
} ElementInfo;

ElementInfo elements[NUM_ELEMENTS];

int main() {
    int num_correct = 0;
    int num_total = 0;

    int num_questions = 0;
    int num_answers[NUM_ANSWERS];

    int num_groups = 0;
    int num_elements_per_group[NUM_ANSWERS];

    int element_index;
    int answer_index;
    int question_index;
    int correct_index;

    while (1) {
        printf("Enter element number (or -1 to exit): ");
        scanf("%d", &element_index);
        if (element_index == -1)
            break;

        num_questions++;

        for (answer_index = 0; answer_index < NUM_ANSWERS; answer_index++)
            num_answers[answer_index] = 0;

        for (element_index = 0; element_index < NUM_ELEMENTS; element_index++) {
            if (elements[element_index].atomic_number == element_index) {
                num_elements_per_group[answer_index]++;
                num_answers[answer_index]++;
            }
        }

        for (answer_index = 0; answer_index < NUM_ANSWERS; answer_index++) {
            if (num_elements_per_group[answer_index] > 1)
                num_groups++;
        }

        for (answer_index = 0; answer_index < NUM_ANSWERS; answer_index++) {
            if (num_answers[answer_index] > 0) {
                correct_index = -1;
                for (element_index = 0; element_index < NUM_ELEMENTS; element_index++) {
                    if (elements[element_index].atomic_number == element_index) {
                        if (answer_index == 0) {
                            if (strcmp(elements[element_index].symbol, "Xe") == 0) {
                                correct_index = element_index;
                                break;
                            }
                        } else if (answer_index == 1) {
                            if (strcmp(elements[element_index].symbol, "Br") == 0) {
                                correct_index = element_index;
                                break;
                            }
                        } else if (answer_index == 2) {
                            if (strcmp(elements[element_index].symbol, "Na") == 0) {
                                correct_index = element_index;
                                break;
                            }
                        } else if (answer_index == 3) {
                            if (strcmp(elements[element_index].symbol, "P") == 0) {
                                correct_index = element_index;
                                break;
                            }
                        }
                    }
                }

                if (correct_index!= -1) {
                    printf("%d) %s (%d) is in group %d.\n", question_index, elements[correct_index].element, elements[correct_index].atomic_number, elements[correct_index].group);
                    printf("The correct answer is group %d.\n", answer_index);
                    num_correct++;
                }
            }
        }

        printf("Number of questions: %d\n", num_questions);
        printf("Number of correct answers: %d\n", num_correct);
        printf("Number of total answers: %d\n", num_total);
        printf("Number of groups: %d\n", num_groups);
        printf("Number of elements per group:\n");
        for (answer_index = 0; answer_index < NUM_ANSWERS; answer_index++)
            printf("  %d\n", num_elements_per_group[answer_index]);
        printf("---------------------------------------------------------\n");

        num_total++;
    }

    return 0;
}