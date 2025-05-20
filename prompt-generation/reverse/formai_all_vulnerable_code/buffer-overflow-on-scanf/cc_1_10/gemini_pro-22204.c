//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int score;
} student;

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create an array of students
    student students[] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Carol", 0},
        {"Dave", 0},
        {"Eve", 0},
    };

    // Get the number of questions
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    // Create an array of questions
    char **questions = malloc(sizeof(char *) * num_questions);
    for (int i = 0; i < num_questions; i++) {
        questions[i] = malloc(sizeof(char) * 100);
        printf("Enter question %d: ", i + 1);
        scanf("%s", questions[i]);
    }

    // Get the answers
    char **answers = malloc(sizeof(char *) * num_questions);
    for (int i = 0; i < num_questions; i++) {
        answers[i] = malloc(sizeof(char) * 100);
        printf("Enter answer %d: ", i + 1);
        scanf("%s", answers[i]);
    }

    // Give the exam
    for (int i = 0; i < 5; i++) {
        printf("Student %s:\n", students[i].name);
        for (int j = 0; j < num_questions; j++) {
            char answer[100];
            printf("Question %d: %s\n", j + 1, questions[j]);
            scanf("%s", answer);
            if (strcmp(answer, answers[j]) == 0) {
                students[i].score++;
            }
        }
    }

    // Print the results
    printf("Results:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }

    // Free the memory
    for (int i = 0; i < num_questions; i++) {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);

    return 0;
}