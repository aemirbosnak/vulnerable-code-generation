//FormAI DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUESTIONS 20
#define MAX_ANSWER_LENGTH 50

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char correct_answer[MAX_ANSWER_LENGTH];
    int max_points;
    int points_awarded;
} Question;

int num_questions;
Question questions[MAX_QUESTIONS];

void print_question(Question q) {
    printf("%s\n", q.question);
}

bool is_correct_answer(Question q, char* answer) {
    return strcmp(q.correct_answer, answer) == 0;
}

void grade_question(Question q, char* answer) {
    if (is_correct_answer(q, answer)) {
        q.points_awarded = q.max_points;
    } else {
        q.points_awarded = 0;
    }
}

void grade_exam() {
    float total_points_awarded = 0;
    float total_max_points = 0;
    for (int i = 0; i < num_questions; i++) {
        total_points_awarded += questions[i].points_awarded;
        total_max_points += questions[i].max_points;
    }
    float percentage_correct = total_points_awarded / total_max_points * 100.0;
    printf("You scored %.2f%%\n", percentage_correct);
}

int main() {
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions (max %d): ", MAX_QUESTIONS);
    scanf("%d", &num_questions);

    // Create questions
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("Question text: ");
        getchar(); // clear newline from buffer
        fgets(questions[i].question, MAX_ANSWER_LENGTH, stdin);
        strtok(questions[i].question, "\n"); // remove trailing newline
        printf("Correct answer: ");
        fgets(questions[i].correct_answer, MAX_ANSWER_LENGTH, stdin);
        strtok(questions[i].correct_answer, "\n"); // remove trailing newline
        printf("Max points: ");
        scanf("%d", &questions[i].max_points);
    }

    // Take exam
    printf("\n--- Exam start ---\n");
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        print_question(questions[i]);
        char answer[MAX_ANSWER_LENGTH];
        printf("Your answer: ");
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        strtok(answer, "\n"); // remove trailing newline
        grade_question(questions[i], answer);
    }
    printf("--- Exam end ---\n");

    // Grade exam
    grade_exam();

    return 0;
}