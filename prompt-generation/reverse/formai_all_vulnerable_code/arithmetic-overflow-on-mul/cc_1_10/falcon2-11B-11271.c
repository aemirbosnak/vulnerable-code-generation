//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_questions, num_choices, num_students;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("Enter the number of choices: ");
    scanf("%d", &num_choices);
    printf("Enter the number of students: ");
    scanf("%d", &num_students);

    int* answers = (int*)malloc(num_students * sizeof(int));
    int* marks = (int*)malloc(num_questions * num_choices * sizeof(int));

    // Get answers from students
    for (int i = 0; i < num_students; i++) {
        printf("Student %d, enter your answers:\n", i + 1);
        for (int j = 0; j < num_questions; j++) {
            printf("Question %d, choice %d (1-based): ", j + 1, j + 1);
            scanf("%d", &answers[i]);
        }
    }

    // Mark the answers
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_choices; j++) {
            for (int k = 0; k < num_students; k++) {
                marks[i * num_choices + j] += (answers[k] == j + 1)? 1 : 0;
            }
        }
    }

    // Calculate scores
    int total_marks = 0;
    for (int i = 0; i < num_questions; i++) {
        int correct_answers = 0;
        for (int j = 0; j < num_choices; j++) {
            if (marks[i * num_choices + j] > 0)
                correct_answers++;
        }
        printf("Question %d has %d correct answers.\n", i + 1, correct_answers);
        total_marks += correct_answers;
    }

    printf("Total marks: %d\n", total_marks);

    // Free memory
    free(answers);
    free(marks);

    return 0;
}