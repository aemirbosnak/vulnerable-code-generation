//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define QUESTION_LENGTH 80
#define ANSWER_LENGTH 100

struct question {
    char text[QUESTION_LENGTH];
    int answer;
};

struct question database[MAX_QUESTIONS];

void setupDatabase() {
    int i;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        sprintf(database[i].text, "What is the answer to the question: %d * %d = ?", rand() % 10 + 1, rand() % 10 + 1);
        database[i].answer = rand() % 100 + 1;
    }
}

int askQuestion(char *questionText) {
    int i, guess, answer;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        if (strcmp(questionText, database[i].text) == 0) {
            answer = database[i].answer;
            break;
        }
    }
    scanf("%d", &guess);
    return guess == answer;
}

int main() {
    int i, success = 0;
    char question[QUESTION_LENGTH];
    srand(time(NULL));

    setupDatabase();

    for (i = 0; i < 5; i++) {
        printf("Question %d:\n", i + 1);
        fgets(question, sizeof(question), stdin);
        question[strcspn(question, "\n")] = '\0';
        success |= askQuestion(question);
        printf(success ? "Correct!\n" : "Incorrect. The answer is %d.\n", database[i % MAX_QUESTIONS].answer);
    }

    return 0;
}