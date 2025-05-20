//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][128];
    int answer; // index of the correct answer (0-3)
} QuizQuestion;

void displayQuestion(QuizQuestion q, int questionNumber) {
    printf("Question %d: %s\n", questionNumber + 1, q.question);
    for(int i = 0; i < 4; i++) {
        printf("%d: %s\n", i + 1, q.options[i]);
    }
}

int getAnswer() {
    int answer;
    printf("Your Answer (1-4): ");
    scanf("%d", &answer);
    // Adjusting index to match the array index
    return answer - 1;
}

void showResult(int score) {
    printf("\nYou scored %d out of %d.\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("Excellent! You are a chemistry master!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! You have decent chemistry knowledge.\n");
    } else {
        printf("Keep studying! You can improve!\n");
    }
}

int main() {
    QuizQuestion questions[MAX_QUESTIONS] = {
        {
            "What is the chemical symbol for Gold?",
            {"Au", "Ag", "Fe", "Pt"},
            0
        },
        {
            "Which element has the atomic number 1?",
            {"Oxygen", "Hydrogen", "Carbon", "Nitrogen"},
            1
        },
        {
            "What is the main gas found in the air we breathe?",
            {"Oxygen", "Carbon Dioxide", "Nitrogen", "Hydrogen"},
            2
        },
        {
            "Which element is represented by the symbol 'Na'?",
            {"Nickel", "Sodium", "Neon", "Nitrogen"},
            1
        },
        {
            "What is the only liquid metal at room temperature?",
            {"Gallium", "Mercury", "Lead", "Tin"},
            1
        },
    };

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions:\n\n");

    int score = 0;

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i], i);
        int answer = getAnswer();
        
        if (answer == questions[i].answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n\n", questions[i].options[questions[i].answer]);
        }
    }

    showResult(score);
    
    return 0;
}