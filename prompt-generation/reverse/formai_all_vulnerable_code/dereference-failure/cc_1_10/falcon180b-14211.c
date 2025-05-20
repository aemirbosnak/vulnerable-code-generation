//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 100

// Define the maximum length of a question
#define MAX_QUESTION_LENGTH 100

// Define the maximum length of an answer
#define MAX_ANSWER_LENGTH 50

// Define the structure of a question
typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Define the structure of an examination
typedef struct {
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Examination;

// Function to read an examination from a file
Examination* read_examination(FILE* file) {
    Examination* exam = malloc(sizeof(Examination));
    if (exam == NULL) {
        printf("Error: Could not allocate memory for examination.\n");
        exit(1);
    }
    exam->num_questions = 0;
    while (fscanf(file, "%s %s\n", exam->questions[exam->num_questions].question, exam->questions[exam->num_questions].answer) == 2) {
        exam->num_questions++;
        if (exam->num_questions >= MAX_QUESTIONS) {
            printf("Error: Too many questions in examination.\n");
            exit(1);
        }
    }
    return exam;
}

// Function to write an examination to a file
void write_examination(FILE* file, Examination* exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        fprintf(file, "%s %s\n", exam->questions[i].question, exam->questions[i].answer);
    }
}

// Function to evaluate an answer
int evaluate_answer(char* answer, char* correct_answer) {
    if (strcmp(answer, correct_answer) == 0) {
        return 1;
    }
    return 0;
}

// Function to run an examination
void run_examination(Examination* exam) {
    printf("Starting examination...\n");
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%d. %s\n", i+1, exam->questions[i].question);
        char answer[MAX_ANSWER_LENGTH];
        scanf("%s", answer);
        if (evaluate_answer(answer, exam->questions[i].answer)) {
            printf("Correct!\n");
        } else {
            printf("Incorrect.\n");
        }
    }
    printf("Examination complete.\n");
}

// Function to run the system
void run_system() {
    FILE* exam_file = fopen("exam.txt", "r");
    if (exam_file == NULL) {
        printf("Error: Could not open exam.txt.\n");
        exit(1);
    }
    Examination* exam = read_examination(exam_file);
    fclose(exam_file);
    run_examination(exam);
    exam_file = fopen("exam.txt", "w");
    if (exam_file == NULL) {
        printf("Error: Could not open exam.txt.\n");
        exit(1);
    }
    write_examination(exam_file, exam);
    fclose(exam_file);
}

int main() {
    run_system();
    return 0;
}