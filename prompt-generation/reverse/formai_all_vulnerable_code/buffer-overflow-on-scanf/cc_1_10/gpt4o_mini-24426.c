//GPT-4o-mini DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

typedef struct {
    char question[256];
    char options[4][100];
    char answer;
} Question;

void displayIntro() {
    printf("====================================\n");
    printf("    Retro Online Examination System   \n");
    printf("====================================\n");
    printf("Welcome to the Quiz! You will be presented with ");
    printf("5 questions. Answer them by typing A, B, C, or D.\n");
    printf("Good luck!\n\n");
}

void displayQuestion(Question q, int q_num) {
    printf("Question %d: %s\n", q_num + 1, q.question);
    printf("A. %s\n", q.options[0]);
    printf("B. %s\n", q.options[1]);
    printf("C. %s\n", q.options[2]);
    printf("D. %s\n", q.options[3]);
}

void displayScore(int score) {
    printf("\nYour total score: %d out of %d\n", score, MAX_QUESTIONS);
    if (score >= 4) {
        printf("Excellent work!\n");
    } else if (score >= 2) {
        printf("Not bad, but you can do better!\n");
    } else {
        printf("You might want to study some more.\n");
    }
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"London", "Berlin", "Paris", "Madrid"}, 'C'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 'B'},
        {"Who wrote 'Romeo and Juliet'?", {"Mark Twain", "Jane Austen", "Charles Dickens", "William Shakespeare"}, 'D'},
        {"What is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"}, 'D'},
        {"What year did the Titanic sink?", {"1912", "1914", "1920", "1910"}, 'A'}
    };

    char userAnswers[MAX_QUESTIONS];
    displayIntro();

    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i], i);
        printf("Enter your answer (A/B/C/D): ");
        char answer;
        scanf(" %c", &answer);
        userAnswers[i] = answer;
        if (answer == questions[i].answer) {
            score++;
        }
        printf("\n");
    }
    
    displayScore(score);
    printf("\nThank you for participating!\n");
    printf("====================================\n");

    return 0;
}