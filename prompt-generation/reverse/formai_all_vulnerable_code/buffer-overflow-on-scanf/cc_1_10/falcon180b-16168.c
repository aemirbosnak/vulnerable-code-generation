//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define MAX_SCORE 20
#define MIN_SCORE 0

char* questions[NUM_QUESTIONS] = {
    "What is the capital of France? ",
    "What is the tallest mountain in the world? ",
    "What is the largest ocean by area? ",
    "What is the smallest country in the world? ",
    "What is the largest desert in the world? ",
    "What is the smallest continent by area? ",
    "What is the longest river in the world? ",
    "What is the highest waterfall in the world? ",
    "What is the largest island in the world? ",
    "What is the deepest ocean trench in the world?"
};

char* answers[NUM_QUESTIONS] = {
    "Paris",
    "Mount Everest",
    "Pacific Ocean",
    "Vatican City",
    "Antarctic Desert",
    "Australia",
    "Nile River",
    "Angel Falls",
    "Greenland",
    "Mariana Trench"
};

int main() {
    srand(time(NULL));
    int score = 0;
    int index;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        index = rand() % NUM_QUESTIONS;
        printf("%s ", questions[index]);
        char answer[100];
        scanf("%s", answer);
        if (strcmp(answer, answers[index]) == 0) {
            score++;
        }
    }

    printf("\nYour final score is: %d out of %d\n", score, MAX_SCORE);

    return 0;
}