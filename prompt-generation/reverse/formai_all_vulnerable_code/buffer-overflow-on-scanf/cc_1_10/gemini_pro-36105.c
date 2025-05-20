//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    char question[256];
    char options[4][64];
    int correct_answer;
} question;

typedef struct student {
    char name[64];
    int score;
} student;

// Function to create a new question
question create_question() {
    question q;
    printf("Enter the question: ");
    scanf(" %[^\n]%*c", q.question);
    printf("Enter the options: ");
    for (int i = 0; i < 4; i++) {
        printf("Option %d: ", i + 1);
        scanf(" %[^\n]%*c", q.options[i]);
    }
    printf("Enter the correct answer (0-3): ");
    scanf("%d", &q.correct_answer);
    return q;
}

// Function to create a new student
student create_student() {
    student s;
    printf("Enter the student's name: ");
    scanf(" %[^\n]%*c", s.name);
    s.score = 0;
    return s;
}

// Function to take the exam
void take_exam(student *s, question *q, int num_questions) {
    int answer;
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q[i].options[j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == q[i].correct_answer) {
            s->score++;
        }
    }
}

// Function to print the results
void print_results(student *s, question *q, int num_questions) {
    printf("Exam Results:\n");
    printf("Student Name: %s\n", s->name);
    printf("Score: %d/%d\n", s->score, num_questions);
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", q[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, q[i].options[j]);
        }
        printf("Your answer: %d\n", i + 1);
        printf("Correct answer: %d\n\n", q[i].correct_answer + 1);
    }
}

int main() {
    // Create a new exam
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    question questions[num_questions];
    for (int i = 0; i < num_questions; i++) {
        questions[i] = create_question();
    }

    // Create a new student
    student student = create_student();

    // Take the exam
    take_exam(&student, questions, num_questions);

    // Print the results
    print_results(&student, questions, num_questions);

    return 0;
}