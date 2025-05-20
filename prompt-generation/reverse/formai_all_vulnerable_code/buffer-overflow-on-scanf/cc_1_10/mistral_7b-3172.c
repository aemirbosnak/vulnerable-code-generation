//MISTRAL-7B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANSWERS_COUNT 8

typedef struct {
    const char* answer;
    int probability;
} Answer;

Answer answers[ANSWERS_COUNT] = {
    {"It is certain.", 75},
    {"It is decidedly so.", 70},
    {"Without a doubt.", 65},
    {"Yes, definitely.", 60},
    {"You may rely on it.", 55},
    {"As I see it, yes.", 50},
    {"Most likely.", 45},
    {"Outlook good.", 40}
};

void shuffleAnswers(Answer* answers, int count) {
    int i, j, tempProb;
    for (i = 0; i < count; ++i) {
        for (j = i + 1; j < count; ++j) {
            if (rand() % 100 < (answers[i].probability - answers[j].probability)) {
                tempProb = answers[i].probability;
                answers[i].probability = answers[j].probability;
                answers[j].probability = tempProb;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    Answer questions[1];
    Answer* answersToPrint = answers;
    int i;

    printf("Ask me a yes or no question and press Enter...\n");

    while (1) {
        scanf("%s", questions[0].answer);

        if (strcmp(questions[0].answer, "quit") == 0) {
            printf("See you later! :)\n");
            break;
        }

        shuffleAnswers(answers, ANSWERS_COUNT);

        for (i = 0; i < ANSWERS_COUNT; ++i) {
            if (answers[i].probability > 50) {
                answersToPrint = &answers[i];
                break;
            }
        }

        printf("%s\n", answersToPrint->answer);
    }

    return 0;
}