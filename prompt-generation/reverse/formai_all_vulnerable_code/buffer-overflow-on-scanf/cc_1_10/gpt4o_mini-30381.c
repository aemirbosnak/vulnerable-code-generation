//GPT-4o-mini DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 5
#define MAX_OPTION_LENGTH 50

typedef struct {
    char question[256];
    char options[4][MAX_OPTION_LENGTH];
    char answer;
} QuizQuestion;

void displayQuestion(QuizQuestion q) {
    printf("\n%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q.options[i]);
    }
}

char getAnswer() {
    char answer;
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    return answer;
}

void evaluateAnswer(char answer, char correctAnswer) {
    if (answer == correctAnswer) {
        printf("Correct!\n");
    } else {
        printf("Wrong! The correct answer was %c.\n", correctAnswer);
    }
}

void printScore(int score) {
    printf("\nYou scored: %d out of %d\n", score, MAX_QUESTIONS);
}

int main() {
    QuizQuestion questions[MAX_QUESTIONS] = {
        {"What is the chemical symbol for Gold?", {"A) Au", "B) Ag", "C) Pb", "D) Fe"}, 'A'},
        {"Which element has the atomic number 6?", {"A) Oxygen", "B) Carbon", "C) Nitrogen", "D) Hydrogen"}, 'B'},
        {"What is the most abundant gas in the Earth's atmosphere?", {"A) Oxygen", "B) Carbon Dioxide", "C) Nitrogen", "D) Argon"}, 'C'},
        {"Which element is known for its critical role in DNA?", {"A) Nitrogen", "B) Phosphorus", "C) Carbon", "D) Hydrogen"}, 'B'},
        {"What is the lightest element on the periodic table?", {"A) Helium", "B) Lithium", "C) Hydrogen", "D) Beryllium"}, 'C'},
    };

    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Answer the following questions by entering A, B, C, or D.\n");

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(questions[i]);
        char userAnswer = getAnswer();
        evaluateAnswer(userAnswer, questions[i].answer);
        if (userAnswer == questions[i].answer) {
            score++;
        }
    }

    printScore(score);
    return 0;
}