//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_NAME_LENGTH 100

typedef struct {
    char question[1000];
    char options[MAX_OPTIONS][1000];
    int answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void start_exam();
int load_questions(Question *questions, int max_questions);
void shuffle_questions(Question *questions, int num_questions);
void display_question(Question question);
int answer_question(Question question);
void show_results(Student student);

int main() {
    start_exam();
    return 0;
}

void start_exam() {
    int num_questions;
    Question questions[MAX_QUESTIONS];
    Student student;
    student.score = 0;
    printf("Welcome to the Online Examination System!\n");
    printf("Please enter your name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    printf("Hello, %s", student.name);
    num_questions = load_questions(questions, MAX_QUESTIONS);
    shuffle_questions(questions, num_questions);
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d\n", i + 1);
        display_question(questions[i]);
        student.score += answer_question(questions[i]);
    }
    show_results(student);
}

int load_questions(Question *questions, int max_questions) {
    FILE *file;
    char filename[100];
    printf("Enter the name of the file containing the questions: ");
    fgets(filename, 100, stdin);
    filename[strlen(filename) - 1] = '\0';
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    int num_questions = 0;
    char line[1000];
    while (fgets(line, 1000, file) != NULL && num_questions < max_questions) {
        // Add question to array
        if (strstr(line, "?") != NULL) {
            strcpy(questions[num_questions].question, line);
            for (int i = 0; i < MAX_OPTIONS; i++) {
                fgets(line, 1000, file);
                strcpy(questions[num_questions].options[i], line);
            }
            fgets(line, 1000, file);
            questions[num_questions].answer = atoi(line);
            num_questions++;
        }
    }
    fclose(file);
    return num_questions;
}

void shuffle_questions(Question *questions, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

void display_question(Question question) {
    printf("%s", question.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d) %s", i + 1, question.options[i]);
    }
}

int answer_question(Question question) {
    int answer;
    printf("Enter your answer (1-%d): ", MAX_OPTIONS);
    scanf("%d", &answer);
    getchar(); // Remove newline character from input buffer
    if (answer == question.answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect!\n");
        return 0;
    }
}

void show_results(Student student) {
    printf("\nResults for %s", student.name);
    printf("Score: %d\n", student.score);
}