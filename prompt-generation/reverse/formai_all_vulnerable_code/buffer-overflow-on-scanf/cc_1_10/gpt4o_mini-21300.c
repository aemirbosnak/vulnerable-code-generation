//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define NUM_QUESTIONS 5

typedef struct {
    char element[3];
    char question[100];
    char options[4][30];
    int answerIndex;
} QuizQuestion;

void displayQuestion(QuizQuestion q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {
    QuizQuestion questions[NUM_QUESTIONS] = {
        {"H", "What is the chemical symbol for Hydrogen?", {"H", "O", "He", "N"}, 0},
        {"He", "What is the chemical symbol for Helium?", {"He", "H", "N", "Ar"}, 0},
        {"Li", "What is the chemical symbol for Lithium?", {"Li", "Na", "K", "Rb"}, 0},
        {"Be", "What is the chemical symbol for Beryllium?", {"Be", "B", "C", "N"}, 0},
        {"B", "What is the chemical symbol for Boron?", {"B", "Be", "C", "O"}, 0}
    };

    int score = 0;
    int answer;

    printf("Welcome to the Periodic Table Quiz!\n\n");

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        displayQuestion(questions[i]);
        
        printf("Your answer (1-4): ");
        scanf("%d", &answer);

        if (answer - 1 == questions[i].answerIndex) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %s.\n\n", questions[i].options[questions[i].answerIndex]);
        }
    }

    printf("You scored %d out of %d.\n", score, NUM_QUESTIONS);
    return 0;
}