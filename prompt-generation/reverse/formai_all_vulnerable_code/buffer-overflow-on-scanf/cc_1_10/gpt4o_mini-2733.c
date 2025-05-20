//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][256];
    char answer;
} QuizQuestion;

void printQuestion(QuizQuestion q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("  %c) %s\n", 'A' + i, q.options[i]);
    }
}

int getAnswer() {
    char response;
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &response);
    return response - 'A';
}

int main() {
    QuizQuestion questions[MAX_QUESTIONS] = {
        {
            "What is the chemical symbol for Oxygen?",
            {"O", "Ox", "O2", "O3"},
            'A'
        },
        {
            "Which element has the atomic number 1?",
            {"Oxygen", "Hydrogen", "Helium", "Lithium"},
            'B'
        },
        {
            "What is the chemical symbol for Gold?",
            {"Go", "Au", "Ag", "Pb"},
            'B'
        },
        {
            "Which element is a noble gas?",
            {"Nitrogen", "Oxygen", "Neon", "Chlorine"},
            'C'
        },
        {
            "Which element is known as the basis of life?",
            {"Carbon", "Hydrogen", "Oxygen", "Nitrogen"},
            'A'
        }
    };

    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked 5 questions.\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printQuestion(questions[i]);
        int answerIndex = getAnswer();
        if (answerIndex < 0 || answerIndex >= 4) {
            printf("Invalid answer. Please choose A, B, C or D.\n");
            i--; // repeat the current question
            continue;
        }
        if ('A' + answerIndex == questions[i].answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c) %s.\n\n", questions[i].answer, questions[i].options[questions[i].answer - 'A']);
        }
    }

    printf("You scored %d out of %d.\n", score, MAX_QUESTIONS);
    printf(score >= 3 ? "Well done! You are knowledgeable about elements.\n" : "Keep trying! Study the periodic table for better understanding.\n");

    return 0;
}