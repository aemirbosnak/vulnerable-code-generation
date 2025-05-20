//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4

typedef struct {
    char question[256];
    char options[MAX_OPTIONS][256];
    int correctAnswer; // index of the correct answer
} Question;

void displayQuestion(Question q, int questionNumber) {
    printf("\nQuestion %d: %s\n", questionNumber + 1, q.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int getUserAnswer() {
    int answer;
    while (1) {
        printf("Your answer (1-%d): ", MAX_OPTIONS);
        scanf("%d", &answer);
        if (answer >= 1 && answer <= MAX_OPTIONS) {
            return answer - 1; // return index
        } else {
            printf("Invalid answer, please try again.\n");
        }
    }
}

void showResults(int score) {
    printf("\nYou've completed the exam!\n");
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS) {
        printf("Excellent! You're a genius!\n");
    } else if (score >= MAX_QUESTIONS / 2) {
        printf("Good job! You've passed.\n");
    } else {
        printf("Don't worry, keep practicing!\n");
    }
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 2},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 1},
        {"What is the largest mammal in the world?", {"Elephant", "Blue Whale", "White Shark", "Giraffe"}, 1},
        {"In which year did Apollo 11 land on the Moon?", {"1965", "1969", "1972", "1975"}, 1},
        {"What is the chemical symbol for Gold?", {"Au", "Ag", "Pb", "Fe"}, 0}
    };

    int score = 0;

    printf("Welcome to the Online Examination System!\n");
    printf("You will be asked %d questions. Choose the correct option from 1 to %d.\n", MAX_QUESTIONS, MAX_OPTIONS);

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i], i);
        int userAnswer = getUserAnswer();
        if (userAnswer == questions[i].correctAnswer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was: %s\n", questions[i].options[questions[i].correctAnswer]);
        }
    }

    showResults(score);
    
    printf("Thank you for participating in the online examination!\n");

    return 0;
}