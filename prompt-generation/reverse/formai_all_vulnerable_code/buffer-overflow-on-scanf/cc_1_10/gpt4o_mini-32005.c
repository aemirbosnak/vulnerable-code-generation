//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char optionA[64];
    char optionB[64];
    char optionC[64];
    char optionD[64];
    char correctOption;
} QuizQuestion;

void displayScore(int score);
void displayHeader();
void displayQuestion(QuizQuestion q);

int main() {
    QuizQuestion questions[MAX_QUESTIONS] = {
        {
            "What is the chemical symbol for Gold?",
            "A) Au",
            "B) Ag",
            "C) Pb",
            "D) Fe",
            'A'
        },
        {
            "Which element has the atomic number 6?",
            "A) Helium",
            "B) Carbon",
            "C) Oxygen",
            "D) Nitrogen",
            'B'
        },
        {
            "What is the chemical symbol for Iron?",
            "A) Fe",
            "B) Ir",
            "C) I",
            "D) In",
            'A'
        },
        {
            "Which of the following is a noble gas?",
            "A) Nitrogen",
            "B) Oxygen",
            "C) Argon",
            "D) Carbon Dioxide",
            'C'
        },
        {
            "What element is represented by the symbol 'Na'?",
            "A) Magnesium",
            "B) Sodium",
            "C) Potassium",
            "D) Calcium",
            'B'
        }
    };

    int score = 0;
    char userAnswer;

    displayHeader();

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i]);
        printf("Your answer: ");
        scanf(" %c", &userAnswer);
        
        userAnswer = toupper(userAnswer); // Convert answer to uppercase
        
        if (userAnswer == questions[i].correctOption) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n\n", questions[i].correctOption);
        }
    }

    displayScore(score);
    return 0;
}

void displayHeader() {
    printf("================================\n");
    printf("       Periodic Table Quiz      \n");
    printf("================================\n");
    printf("Test your knowledge of elements!\n");
    printf("================================\n");
}

void displayQuestion(QuizQuestion q) {
    printf("%s\n", q.question);
    printf("%s\n", q.optionA);
    printf("%s\n", q.optionB);
    printf("%s\n", q.optionC);
    printf("%s\n", q.optionD);
}

void displayScore(int score) {
    printf("================================\n");
    printf("             Your Score         \n");
    printf("================================\n");
    printf("You answered %d out of %d questions correctly.\n", score, MAX_QUESTIONS);

    if (score == MAX_QUESTIONS) {
        printf("Amazing! You're a master of the elements!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! You have a solid understanding of the periodic table.\n");
    } else {
        printf("Keep studying! The elements can be tricky sometimes.\n");
    }
    printf("================================\n");
}