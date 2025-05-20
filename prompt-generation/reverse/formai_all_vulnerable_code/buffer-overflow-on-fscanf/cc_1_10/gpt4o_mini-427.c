//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTION_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_QUEST_LENGTH 256

typedef struct {
    char question[MAX_QUEST_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    int correctAnswer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

void displayQuestion(Question q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

void takeExam(Question questions[], int numQuestions, Student *student) {
    for (int i = 0; i < numQuestions; i++) {
        displayQuestion(questions[i], i);
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer - 1 == questions[i].correctAnswer) {
            student->score++;
        }
    }
}

void displayResults(Student student) {
    printf("Exam completed!\n");
    printf("Name: %s\n", student.name);
    printf("Score: %d/%d\n", student.score, MAX_QUESTIONS);
}

void loadQuestions(Question questions[], int *numQuestions) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        printf("Error opening questions file.\n");
        exit(1);
    }

    *numQuestions = 0;
    while (fscanf(file, " %[^\n]\n", questions[*numQuestions].question) != EOF && 
           *numQuestions < MAX_QUESTIONS) {
        for (int i = 0; i < 4; i++) {
            fscanf(file, " %[^\n]\n", questions[*numQuestions].options[i]);
        }
        fscanf(file, "%d\n", &questions[*numQuestions].correctAnswer);
        (*numQuestions)++;
    }

    fclose(file);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions = 0;
    Student student;

    printf("Welcome to the Online Examination System!\n");
    printf("Enter your name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';  // remove trailing newline
    student.score = 0;

    loadQuestions(questions, &numQuestions);
    takeExam(questions, numQuestions, &student);
    displayResults(student);

    return 0;
}