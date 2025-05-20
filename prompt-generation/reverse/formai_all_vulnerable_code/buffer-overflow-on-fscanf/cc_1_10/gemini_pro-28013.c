//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: shape shifting
// **C Online Examination System**
// A text-based system for conducting online examinations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure representing a question
typedef struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

// Structure representing an exam
typedef struct Exam {
    Question questions[10];
    int num_questions;
} Exam;

// Function to load questions from a file
void loadQuestions(Exam *exam) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%[^#]#%[^#]#%[^#]#%d\n", exam->questions[i].question, exam->questions[i].options[0], exam->questions[i].options[1], &exam->questions[i].correct_option) != EOF) {
        i++;
    }

    exam->num_questions = i;

    fclose(fp);
}

// Function to take the exam
void takeExam(Exam *exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].options[j]);
        }

        int answer;
        scanf("%d", &answer);

        if (answer == exam->questions[i].correct_option) {
            score++;
        }
    }

    printf("Your score: %d/%d\n", score, exam->num_questions);
}

int main() {
    Exam exam;
    loadQuestions(&exam);
    takeExam(&exam);
    return 0;
}