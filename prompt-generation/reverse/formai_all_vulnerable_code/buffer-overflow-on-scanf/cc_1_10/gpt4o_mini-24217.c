//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_LENGTH 100

typedef struct {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
} QuizQuestion;

void displayWelcomeMessage() {
    printf("===== Welcome to the Periodic Table Quest! =====\n");
    printf("Brave Knight, test thy knowledge of the Elements!\n");
    printf("Answer the questions correctly to earn honor and wisdom.\n");
    printf("=========================================\n");
}

void displayEndMessage(int score) {
    printf("Thou hast finished the quest!\n");
    printf("Thy final score is: %d out of %d\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("Huzzah! Thou art a Master of the Elements!\n");
    } else {
        printf("Keep striving, brave soul! Seek knowledge and return.\n");
    }
}

int askQuestions(QuizQuestion questions[]) {
    int score = 0;
    char userAnswer[MAX_LENGTH];
    
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);
        printf("Thy answer: ");
        scanf("%s", userAnswer);

        if (strcasecmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct! Thou art wise!\n\n");
            score++;
        } else {
            printf("Alas! That is not correct. The right answer was: %s\n\n", questions[i].answer);
        }
    }
    return score;
}

int main() {
    displayWelcomeMessage();

    QuizQuestion questions[MAX_QUESTIONS] = {
        {"What is the alchemical symbol for gold?", "Au"},
        {"What is the alchemical symbol for silver?", "Ag"},
        {"What element has the atomic number 6?", "C"},
        {"What is the alchemical symbol for lead?", "Pb"},
        {"What is the lightest element?", "H"}
    };

    int score = askQuestions(questions);
    displayEndMessage(score);

    return 0;
}