//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 5
#define MAX_LENGTH 255

typedef struct {
    char question[MAX_LENGTH];
    char options[MAX_OPTIONS][MAX_LENGTH];
    char answer;
} Question;

Question questions[MAX_QUESTIONS];
int currentQuestion = 0;
int score = 0;

void generateQuestion() {
    char temp[MAX_LENGTH];
    int i;

    printf("\nQuestion %d:\n", currentQuestion + 1);
    fgets(questions[currentQuestion].question, MAX_LENGTH, stdin);
    strtok(questions[currentQuestion].question, "\n");

    printf("Enter options (comma-separated): ");
    fgets(temp, MAX_LENGTH, stdin);
    strtok(temp, ",");
    i = 0;
    while (strtok(NULL, ", ") != NULL) {
        strcpy(questions[currentQuestion].options[i], strtok(NULL, ", "));
        i++;
    }

    printf("Enter answer (A-E): ");
    scanf("%c", &questions[currentQuestion].answer);
}

void displayQuestion() {
    int i;

    printf("\n%s\n", questions[currentQuestion].question);
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", i + 'A', questions[currentQuestion].options[i]);
    }
}

void checkAnswer() {
    char userAnswer;

    scanf(" %c", &userAnswer);
    if (userAnswer == questions[currentQuestion].answer) {
        score++;
    }
}

void nextQuestion() {
    currentQuestion++;
    if (currentQuestion >= MAX_QUESTIONS) {
        printf("\nExamination finished!\nYour score is %d.\n", score);
        exit(0);
    }
}

int main() {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_QUESTIONS; i++) {
        generateQuestion();
    }

    for (i = 0; i < MAX_QUESTIONS; i++) {
        system("clear"); // Unix/Linux
        // system("cls"); // Windows
        displayQuestion();
        checkAnswer();
        nextQuestion();
    }

    return 0;
}