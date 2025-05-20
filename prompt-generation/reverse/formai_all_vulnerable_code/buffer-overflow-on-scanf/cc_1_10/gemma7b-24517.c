//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at sales", "c. A person who is creative", "d. A person who is wealthy"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Lyon", "d. Brussels"}, 3},
    {"Which planet is the largest?", {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. A hum", "c. A click", "d. A buzz"}, 5},
    {"Which animal is known for its intelligence?", {"a. Dog", "b. Cat", "c. Horse", "d. Elephant"}, 6},
    {"What is the most common color of hair in the world?", {"a. Black", "b. Brown", "c. Red", "d. Blonde"}, 7},
    {"Which scientist developed the theory of quantum mechanics?", {"a. Albert Einstein", "b. Isaac Newton", "c. Max Planck", "d. Galileo Galilei"}, 8},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at sales", "c. A person who is creative", "d. A person who is wealthy"}, 9},
    {"Which animal is known for its intelligence?", {"a. Dog", "b. Cat", "c. Horse", "d. Elephant"}, 10}
};

int main() {
    int score = 0;
    int currentQuestion = 0;

    system("clear");

    printf("Welcome to the Future Exam System!\n");

    while (currentQuestion < MAX_QUESTIONS) {
        printf("Question %d: %s\n", currentQuestion + 1, questions[currentQuestion].question);

        for (int i = 0; i < MAX_ANSWERS; i++) {
            printf("Answer %d: %s\n", i + 1, questions[currentQuestion].answers[i]);
        }

        int answerChoice = -1;
        printf("Please select your answer choice: ");
        scanf("%d", &answerChoice);

        if (answerChoice > 0 && answerChoice <= MAX_ANSWERS) {
            if (questions[currentQuestion].correctAnswer == answerChoice) {
                score++;
            }

            currentQuestion++;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);

    return 0;
}