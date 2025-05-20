//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 5
#define MAX_WORDS 50
#define MAX_LINE 255

typedef struct Question {
    char question[MAX_LINE];
    char options[MAX_OPTIONS][MAX_LINE];
    char answer;
} Question;

void loadQuestions(Question questions[], int numQuestions);
int checkAnswer(char userAnswer, Question question);
void displayQuestion(Question question);

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions = 0;
    char userAnswer;

    loadQuestions(questions, MAX_QUESTIONS);

    for (int i = 0; i < numQuestions; i++) {
        system("clear");
        displayQuestion(questions[i]);
        scanf("%c", &userAnswer);
        getchar();
        if (checkAnswer(userAnswer, questions[i])) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer was: %c\n", questions[i].answer);
        }
        printf("Press enter to continue...");
        getchar();
        system("clear");
    }

    printf("Exam finished. Total score: %d\n", numQuestions);

    return 0;
}

void loadQuestions(Question questions[], int numQuestions) {
    FILE *file = fopen("questions.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[MAX_LINE];
    int questionNum = 0;

    while (fgets(line, MAX_LINE, file) != NULL) {
        sscanf(line, "%[^:]: %[^:]: %[^:]: %s", questions[questionNum].question, questions[questionNum].options[0], questions[questionNum].options[1], questions[questionNum].options[2]);
        sscanf(questions[questionNum].options[3], "%c", &questions[questionNum].answer);
        questionNum++;
        if (questionNum >= numQuestions) {
            break;
        }
        gets(line); // Consume newline character
    }

    fclose(file);
    numQuestions = questionNum;
}

void displayQuestion(Question question) {
    printf("\n%s\n", question.question);

    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

int checkAnswer(char userAnswer, Question question) {
    userAnswer = toupper(userAnswer);
    return userAnswer == question.answer;
}