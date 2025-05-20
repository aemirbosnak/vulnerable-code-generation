//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_ANSWERS 5

// Question structure
typedef struct {
    char question[100];
    int num_options;
    char options[MAX_OPTIONS][100];
    int correct_answer;
} Question;

// Exam structure
typedef struct {
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Function to initialize an exam with random questions
void init_exam(Exam* exam) {
    srand(time(NULL));
    for (int i = 0; i < exam->num_questions; i++) {
        exam->questions[i].num_options = rand() % MAX_OPTIONS + 2;
        for (int j = 0; j < exam->questions[i].num_options; j++) {
            sprintf(exam->questions[i].options[j], "Option %d", j + 1);
        }
        exam->questions[i].correct_answer = rand() % exam->questions[i].num_options;
    }
}

// Function to display a question and its options
void display_question(Question* question) {
    printf("%s\n", question->question);
    for (int i = 0; i < question->num_options; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

// Function to check if an answer is correct
int check_answer(Question* question, int answer) {
    return answer == question->correct_answer;
}

// Function to grade an exam
int grade_exam(Exam* exam, int* answers) {
    int correct_answers = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        if (check_answer(&exam->questions[i], answers[i])) {
            correct_answers++;
        }
    }
    return correct_answers;
}

int main() {
    // Initialize an exam with 10 random questions
    Exam exam = { 10, { 0 } };
    init_exam(&exam);

    // Take the exam
    int answers[MAX_QUESTIONS];
    int num_correct_answers = 0;
    for (int i = 0; i < exam.num_questions; i++) {
        display_question(&exam.questions[i]);
        scanf("%d", &answers[i]);
        num_correct_answers += check_answer(&exam.questions[i], answers[i]);
    }

    // Grade the exam
    int grade = grade_exam(&exam, answers);
    printf("You got %d out of %d questions correct.\n", grade, exam.num_questions);

    return 0;
}