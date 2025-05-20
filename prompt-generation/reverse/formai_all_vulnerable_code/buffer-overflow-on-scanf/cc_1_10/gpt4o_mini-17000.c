//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define QUESTION_COUNT 5

typedef struct {
    const char *question;
    const char *options[4];
    int answer;
} Question;

void displayWelcomeMessage() {
    printf("Welcome to the Peaceful Periodic Table Quiz!\n");
    printf("Let’s embark on a serene journey to explore the elements together.\n\n");
}

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int getUserAnswer() {
    int answer;
    printf("Your answer (1-4): ");
    scanf("%d", &answer);
    return answer - 1; // Convert to 0-indexed
}

void evaluateAnswer(int userAnswer, int correctAnswer) {
    if (userAnswer == correctAnswer) {
        printf("Correct! 🌟\n\n");
    } else {
        printf("Oops! The correct answer was: %d. Keep exploring! 🌈\n\n", correctAnswer + 1);
    }
}

void displayConclusion(int score) {
    printf("Your final score: %d out of %d\n", score, QUESTION_COUNT);
    printf("Thank you for participating in our peaceful journey through the periodic table.\n");
    printf("Wishing you continued exploration and learning! ✨\n");
}

int main() {
    displayWelcomeMessage();
    
    Question questions[QUESTION_COUNT] = {
        {
            "1. What is the chemical symbol for Gold?",
            {"Ag", "Au", "Pb", "Fe"},
            1
        },
        {
            "2. Which element has the atomic number 6?",
            {"Carbon", "Oxygen", "Nitrogen", "Hydrogen"},
            0
        },
        {
            "3. What is the chemical symbol for water?",
            {"H2O", "O2", "H2", "HO"},
            0
        },
        {
            "4. Which of the following is a noble gas?",
            {"Oxygen", "Hydrogen", "Neon", "Nitrogen"},
            2
        },
        {
            "5. What is the lightest element in the periodic table?",
            {"Helium", "Hydrogen", "Lithium", "Beryllium"},
            1
        }
    };

    int score = 0;

    for (int i = 0; i < QUESTION_COUNT; i++) {
        displayQuestion(questions[i]);
        int userAnswer = getUserAnswer();
        
        // Check user's answer and update score
        if (userAnswer == questions[i].answer) {
            score++;
        }
        evaluateAnswer(userAnswer, questions[i].answer);
    }

    displayConclusion(score);
    return 0;
}