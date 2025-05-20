//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages businesses", "b. A person who is always selling things", "c. A person who is always making money", "d. A person who is always getting ahead"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which animal is known for its sharp eyesight?", {"a. Tiger", "b. Lion", "c. Owl", "d. Snake"}, 0},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 3},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 4},
    {"What is the sound of one hand clapping?", {"a. Silence", "b. Silence", "c. Silence", "d. Silence"}, 1},
    {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and manages businesses", "b. A person who is always selling things", "c. A person who is always making money", "d. A person who is always getting ahead"}, 1},
    {"Which scientist invented the theory of relativity?", {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"}, 2},
    {"Which animal is known for its sharp eyesight?", {"a. Tiger", "b. Lion", "c. Owl", "d. Snake"}, 0},
    {"What is the capital of France?", {"a. Paris", "b. Lyon", "c. Marseille", "d. Lille"}, 3},
    {"Which planet is the largest?", {"a. Mars", "b. Earth", "c. Jupiter", "d. Saturn"}, 4}
};

void takeExam() {
    int i, score = 0;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s", questions[i].question);
        printf("\n");
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s", questions[i].answers[j]);
            printf("\n");
        }
        printf("Enter your answer: ");
        char answer[MAX_ANSWERS];
        scanf("%s", answer);
        if (answer[0] == questions[i].correctAnswer) {
            score++;
        }
    }
    printf("Your score: %d", score);
    printf("\n");
}

int main() {
    takeExam();
    return 0;
}