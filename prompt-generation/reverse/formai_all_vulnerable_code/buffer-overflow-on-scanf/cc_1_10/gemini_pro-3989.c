//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: happy
// Cheerful C Online Examination System

#include <stdio.h>
#include <stdlib.h>

// Exam data
typedef struct Question {
    char question[256];
    char options[4][128];
    int answer;
} Question;

Question exam[] = {
    {"What's the capital of France?", {"Paris", "London", "Rome", "Berlin"}, 0},
    {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Michelangelo", "Pablo Picasso", "Vincent van Gogh"}, 0},
    {"Which planet is known as the Red Planet?", {"Mars", "Venus", "Jupiter", "Saturn"}, 0},
    {"What's the chemical symbol for gold?", {"Au", "Ag", "Cu", "Fe"}, 0},
    {"Who wrote the novel 'To Kill a Mockingbird'?", {"Harper Lee", "Ernest Hemingway", "Jane Austen", "William Shakespeare"}, 0}
};

// Exam mechanics
int score = 0;
int currentQuestion = 0;

void askQuestion() {
    printf("\nQuestion %d of %d:\n\n", currentQuestion + 1, (int) (sizeof(exam) / sizeof(Question)));
    printf("%s\n\n", exam[currentQuestion].question);
    for (int i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, exam[currentQuestion].options[i]);
    }
    printf("\nYour answer (A-D): ");
}

void checkAnswer() {
    char answer;
    scanf(" %c", &answer);
    int index = answer - 'A';
    if (index < 0 || index > 3) {
        printf("Invalid answer! Try again.\n");
        checkAnswer();
    } else if (index == exam[currentQuestion].answer) {
        score++;
        printf("Yay! That's correct!\n");
    } else {
        printf("Oops! That's not quite right. The correct answer is %c)\n", 'A' + exam[currentQuestion].answer);
    }
    currentQuestion++;
    if (currentQuestion < sizeof(exam) / sizeof(Question)) {
        askQuestion();
    }
}

void showResults() {
    printf("\nHooray! You've completed the exam!\n");
    printf("Your score is %d out of %d (%.2f%%)\n", score, (int) (sizeof(exam) / sizeof(Question)), 100.0 * score / (sizeof(exam) / sizeof(Question)));
    if (score == (int) (sizeof(exam) / sizeof(Question))) {
        printf("Amazing! You're a genius!\n");
    } else if (score >= (int) (sizeof(exam) / sizeof(Question)) / 2) {
        printf("Well done! You did a great job!\n");
    } else {
        printf("Don't be discouraged! Keep studying and you'll ace it next time.\n");
    }
}

int main() {
    printf("Welcome to the C Online Examination System! :)\n\n");
    askQuestion();
    checkAnswer();
    showResults();
    return 0;
}