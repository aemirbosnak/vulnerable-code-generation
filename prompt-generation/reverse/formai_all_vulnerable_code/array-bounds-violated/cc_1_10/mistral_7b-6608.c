//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THEORIES 10
#define WORDS_COUNT 10

typedef struct {
    char *word;
    int count;
} TheoryWord;

TheoryWord conspiracy_theories[MAX_THEORIES][WORDS_COUNT];

void init_theories() {
    conspiracy_theories[0][0].word = "Reptilian";
    conspiracy_theories[0][1].word = "Illuminati";
    conspiracy_theories[0][2].word = "Moon landing";
    conspiracy_theories[0][3].word = "JFK assassination";
    conspiracy_theories[0][4].word = "9/11 attack";
    conspiracy_theories[0][5].word = "Area 51";
    conspiracy_theories[0][6].word = "Masonic symbols";
    conspiracy_theories[0][7].word = "Global Warming";
    conspiracy_theories[0][8].word = "Flat Earth";
    conspiracy_theories[0][9].word = "Chemtrails";

    conspiracy_theories[1][0].word = "Grey aliens";
    conspiracy_theories[1][1].word = "Area 51 reversed";
    conspiracy_theories[1][2].word = "Paul is dead";
    conspiracy_theories[1][3].word = "Lizard people";
    conspiracy_theories[1][4].word = "Black helicopters";
    conspiracy_theories[1][5].word = "New World Order";
    conspiracy_theories[1][6].word = "Bermuda Triangle";
    conspiracy_theories[1][7].word = "Bigfoot";
    conspiracy_theories[1][8].word = "Pizzagate";
    conspiracy_theories[1][9].word = "Moon landing hoax";

    srand(time(NULL));
}

int main() {
    int i, j;
    init_theories();

    for (i = 0; i < MAX_THEORIES; i++) {
        printf("Conspiracy Theory #%d:\n", i + 1);
        for (j = 0; j < WORDS_COUNT; j++) {
            int random_index = rand() % (WORDS_COUNT * 2);
            while (conspiracy_theories[i][random_index].count > 0) {
                random_index = rand() % (WORDS_COUNT * 2);
            }
            printf("%s ", conspiracy_theories[i][random_index].word);
            conspiracy_theories[i][random_index].count++;
        }
        printf("\n");
    }

    return 0;
}