//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[256];
    char answer[256];
    int marks;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business", 5},
    {"Which scientist invented the theory of relativity?", "Albert Einstein", 4},
    {"Which country has the largest population?", "China", 3},
    {"What is the capital of France?", "Paris", 4},
    {"What is the chemical formula for sulfuric acid?", "H2SO4", 3},
    {"Which animal is known for its sharpest eyesight?", "Eagle", 5},
    {"Which planet has the most moons?", "Saturn", 4},
    {"What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business", 5},
    {"What is the sound of one hand clapping?", "Silence", 3},
    {"Who is the current President of the United States?", "Joe Biden", 4}
};

int main() {
    int i, score = 0, correct_answers = 0;
    char answer[256];

    system("clear");

    printf("Welcome to the C Online Examination System!\n");
    printf("----------------------------\n");

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);

        printf("Enter your answer: ");
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answer) == 0) {
            correct_answers++;
            printf("Correct!\n");
            score += questions[i].marks;
        } else {
            printf("Incorrect. The answer is: %s\n", questions[i].answer);
        }
    }

    printf("\nYour total score: %d\n", score);
    printf("Number of correct answers: %d\n", correct_answers);
    printf("Thank you for participating in the C Online Examination System!\n");

    return 0;
}