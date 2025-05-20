//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char *options[4];
    int correctAnswer;
} Question;

typedef struct {
    char *name;
    int score;
} Student;

Question questions[] = {
    {
        "What is the capital of France?",
        {"Paris", "London", "Rome", "Madrid"},
        0
    },
    {
        "What is the largest ocean in the world?",
        {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"},
        0
    },
    {
        "What is the name of the tallest mountain in the world?",
        {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"},
        0
    },
    {
        "What is the chemical symbol for gold?",
        {"Au", "Ag", "Cu", "Fe"},
        0
    },
    {
        "What is the name of the first computer virus?",
        {"Creeper", "Elk Cloner", "Jerusalem", "Morris"},
        0
    }
};

Student students[] = {
    {
        "Alice",
        0
    },
    {
        "Bob",
        0
    },
    {
        "Carol",
        0
    },
    {
        "Dave",
        0
    },
    {
        "Eve",
        0
    }
};

int numQuestions = sizeof(questions) / sizeof(questions[0]);
int numStudents = sizeof(students) / sizeof(students[0]);

void printQuestion(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

int getAnswer(Question question) {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1;
}

void gradeQuestion(Question question, int answer, Student *student) {
    if (answer == question.correctAnswer) {
        student->score++;
    }
}

void printResults() {
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i].name, students[i].score);
    }
}

int main() {
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numQuestions; j++) {
            printQuestion(questions[j]);
            int answer = getAnswer(questions[j]);
            gradeQuestion(questions[j], answer, &students[i]);
        }
    }

    printResults();

    return 0;
}