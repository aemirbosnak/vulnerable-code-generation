//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWER_LENGTH 100

// structure to hold question data
typedef struct {
    char question[MAX_QUESTIONS];
    char correct_answer[MAX_ANSWER_LENGTH];
} Question;

// function to load questions from file
void load_questions(Question* questions, int num_questions, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    int question_num = 0;
    while (question_num < num_questions && fscanf(file, "%s %s", questions[question_num].question, questions[question_num].correct_answer) == 2) {
        question_num++;
    }

    if (question_num < num_questions) {
        printf("Error: not enough questions in file %s\n", filename);
        exit(1);
    }

    fclose(file);
}

// function to display a question
void display_question(Question question, int num_choices) {
    printf("%s\n", question.question);
    for (int i = 0; i < num_choices; i++) {
        printf("%d. %s\n", i + 1, question.correct_answer);
    }
}

// function to check answer
int check_answer(char* answer, char* correct_answer) {
    return strcmp(answer, correct_answer) == 0;
}

// main function
int main() {
    // load questions from file
    Question questions[MAX_QUESTIONS];
    int num_questions = 0;
    load_questions(questions, MAX_QUESTIONS, "questions.txt");
    num_questions = 0;

    // run exam
    int num_correct = 0;
    int num_incorrect = 0;
    int num_skipped = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("Question %d of %d:\n", i + 1, num_questions);
        display_question(questions[i], 4);
        char answer[MAX_ANSWER_LENGTH];
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if (check_answer(answer, questions[i].correct_answer)) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i].correct_answer);
            num_incorrect++;
        }
    }

    printf("Exam complete. You got %d out of %d questions correct.\n", num_correct, num_questions);

    return 0;
}