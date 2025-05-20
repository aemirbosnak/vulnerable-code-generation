//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define MAX_SCORE 10

struct question {
    char *text;
    int answer;
};

void shuffle_questions(struct question questions[NUM_QUESTIONS]) {
    int i, j;
    for (i = 0; i < NUM_QUESTIONS; i++) {
        j = rand() % NUM_QUESTIONS;
        struct question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    struct question questions[NUM_QUESTIONS] = {
        {"What is the capital of France? ", 1},
        {"What is the largest planet in our solar system? ", 3},
        {"What is the smallest country in the world? ", 2},
        {"What is the tallest animal on Earth? ", 2},
        {"What is the largest ocean on Earth? ", 1},
        {"What is the hottest planet in our solar system? ", 3},
        {"What is the smallest continent in the world? ", 2},
        {"What is the largest bird in the world? ", 2},
        {"What is the smallest country in Europe? ", 1},
        {"What is the largest desert in the world? ", 2}
    };

    int score = 0;
    int i;

    srand(time(NULL));
    shuffle_questions(questions);

    for (i = 0; i < NUM_QUESTIONS; i++) {
        printf("%s ", questions[i].text);
        int answer;
        scanf("%d", &answer);

        if (answer == questions[i].answer) {
            score++;
        }
    }

    printf("\nYour final score is: %d out of %d\n", score, MAX_SCORE);

    return 0;
}