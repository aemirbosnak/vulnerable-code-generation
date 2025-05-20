//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char question[256];
    char answers[MAX_ANSWERS][256];
    int correctAnswer;
} Question;

Question questions[] = {
    {"Which programming language was invented in 1990?", {"C", "Java", "Python", "Ruby"}, 1},
    {"What is the meaning of the word 'entrepreneur'?", {"Someone who starts a business", "Someone who is good at math", "Someone who is successful", "Someone who is wealthy"}, 2},
    {"Which city is the capital of France?", {"Paris", "Lyon", "Rennes", "Brussels"}, 3},
    {"What is the most common color of the human eye?", {"Blue", "Brown", "Green", "Hazel"}, 4},
    {"Which scientist invented the theory of relativity?", {"Albert Einstein", "Isaac Newton", "Charles Darwin", "Galileo Galilei"}, 5},
    {"Which animal is known for its intelligence?", {"Dog", "Cat", "Elephant", "Horse"}, 6},
    {"What is the sound of one hand clapping?", "Silence", 7},
    {"Which planet is the largest?", {"Jupiter", "Mars", "Earth", "Saturn"}, 8},
    {"What is the meaning of the word 'entrepreneur'?", {"Someone who starts a business", "Someone who is good at math", "Someone who is successful", "Someone who is wealthy"}, 9},
    {"Which country is the largest exporter of oil?", {"Saudi Arabia", "Canada", "The United States", "Russia"}, 10}
};

int main() {
    int i, score = 0, timeLeft = 60;
    time_t start, end;

    start = time(NULL);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        printf("\n");

        char answer[MAX_ANSWERS];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].correctAnswer]) == 0) {
            score++;
        }
    }

    end = time(NULL);

    timeLeft = 60 - (end - start);

    printf("Your score: %d/%d", score, MAX_QUESTIONS);
    printf("\nTime left: %d seconds", timeLeft);

    return 0;
}