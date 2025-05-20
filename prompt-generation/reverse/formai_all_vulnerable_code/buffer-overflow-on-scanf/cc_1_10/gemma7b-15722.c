//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define MAX_ANSWERS 3

typedef struct Question {
    char *question;
    char **answers;
    int correctAnswer;
} Question;

Question questions[NUM_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?", {"a) A dreamer", "b) A businessman", "c) A salesman"}, 1},
    {"Which scientist invented the theory of relativity?", {"a) Albert Einstein", "b) Isaac Newton", "c) Charles Darwin"}, 2},
    {"What is the capital of France?", {"a) Paris", "b) Rome", "c) Lyon"}, 3},
    {"Which planet is the largest?", {"a) Earth", "b) Mars", "c) Jupiter"}, 4},
    {"What is the sound of one hand clapping?", {"a) Silence", "b) A drum", "c) A squeak"}, 5},
    {"Which animal is known for its sharp claws?", {"a) Tiger", "b) Lion", "c) Bear"}, 6},
    {"Which composer wrote the Symphony No. 9?", {"a) Beethoven", "b) Mozart", "c) Bach"}, 7},
    {"What is the meaning of the word 'entrepreneur' in French?", {"a) Un rêves", "b) Un homme d'affaires", "c) Un vendeur"}, 8},
    {"Which scientist invented the telephone?", {"a) Alexander Graham Bell", "b) Isaac Newton", "c) Charles Darwin"}, 9},
    {"What is the meaning of the word 'entrepreneur' in Spanish?", {"a) Un sueño", "b) Un hombre de negocios", "c) Un vendedor"}, 10}
};

int main() {
    time_t start, end;
    int score = 0, i, chosenAnswer;
    char name[20];

    printf("Welcome to the C Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    start = time(NULL);

    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("%d. %s\n", i + 1, questions[i].question);

        printf("Your choices: ");
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%c) %s\n", j + 1, questions[i].answers[j]);
        }

        printf("Please select your answer: ");
        scanf("%d", &chosenAnswer);

        if (chosenAnswer == questions[i].correctAnswer) {
            score++;
        }
    }

    end = time(NULL);

    printf("Congratulations, %s! You have scored %d out of %d.", name, score, NUM_QUESTIONS);

    printf("Your total time: %d seconds", end - start);

    return 0;
}