//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_THEORIES 10
#define NUM_AGENTS 8
#define NUM_PLACES 6
#define NUM_NUMBERS 4

const char *theories[NUM_THEORIES] = {
    "the moon landing was staged",
    "aliens built the pyramids",
    "the government is hiding a cure for cancer",
    "birds are actually surveillance drones",
    "the earth is flat and covered by a dome",
    "the Bermuda Triangle is a portal to another dimension",
    "global warming is a hoax",
    "time travel is being researched by the elite",
    "COVID-19 was created in a lab for population control",
    "Bigfoot is an interdimensional being"
};

const char *agents[NUM_AGENTS] = {
    "the Illuminati",
    "NASA",
    "the Freemasons",
    "the CIA",
    "big pharmaceutical companies",
    "the New World Order",
    "the Rothschild family",
    "aliens"
};

const char *places[NUM_PLACES] = {
    "Area 51",
    "the Vatican",
    "Stonehenge",
    "the North Pole",
    "the Bermuda Triangle",
    "the Moon"
};

const char *numbers[NUM_NUMBERS] = {
    "7",
    "3",
    "42",
    "13"
};

void generate_conspiracy_theory() {
    int theory_index = rand() % NUM_THEORIES;
    int agent_index = rand() % NUM_AGENTS;
    int place_index = rand() % NUM_PLACES;
    int number_index = rand() % NUM_NUMBERS;

    printf("Conspiracy Theory:\n");
    printf("The %s claims that %s %s, and this can be proven by the number %s, which is linked to %s.\n",
           agents[agent_index],
           theories[theory_index],
           places[place_index],
           numbers[number_index],
           agents[agent_index]);
}

int main() {
    srand(time(NULL));
    int number_of_theories;

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Enter the number of conspiracy theories to generate (up to 10): ");
    scanf("%d", &number_of_theories);

    if (number_of_theories < 1 || number_of_theories > 10) {
        printf("Please enter a valid number between 1 and 10.\n");
        return 1;
    }

    printf("\nGenerating %d Conspiracy Theories...\n", number_of_theories);
    for (int i = 0; i < number_of_theories; i++) {
        generate_conspiracy_theory();
    }

    return 0;
}