//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_THEORIES 10
#define MAX_WORD_LEN 20
#define WORDS_COUNT 100

typedef struct {
    char name[MAX_WORD_LEN];
    int probability;
} Theory;

Theory theories[NUM_THEORIES] = {
    {"New World Order", 85},
    {"Lizard People", 6},
    {"Black Helicopters", 3},
    {"Moon Landing Hoax", 12},
    {"Reptilian Agenda", 5},
    {"Alien Autopsy", 2},
    {"Flat Earth", 1},
    {"Deep State", 75},
    {"Illuminati", 50},
    {"5G Conspiracy", 15}
};

void seed_rng() {
    time_t rawtime;
    struct tm * timeinfo;
    int seed;

    char *tzptr = NULL;
    char time_string[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", timeinfo);

    sscanf(time_string, "%d%d%d%d%d%d", &seed, &seed, &seed, &seed, &seed, &seed);

    srand(seed);
}

int main() {
    int i, random_index;
    double random_number;
    seed_rng();

    printf("Theorizing...\n");

    for (i = 0; i < 5; i++) {
        random_number = (double)rand() / RAND_MAX;
        random_index = rand() % NUM_THEORIES;

        while (random_number >= theories[random_index].probability / 100.0) {
            random_index = rand() % NUM_THEORIES;
        }

        printf("%s\n", theories[random_index].name);
    }

    return 0;
}