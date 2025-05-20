//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 10
#define MAX_DETAILS 10
#define MAX_CHAR 256

const char* conspiracies[MAX_CONSPIRACIES] = {
    "The moon landing was staged",
    "Lizards are controlling the world",
    "Time travel experiments by world leaders",
    "The pyramids were built by aliens",
    "Global warming is a hoax",
    "The government is using mind control via movies",
    "Cats are spies sent by a secret organization",
    "Historical events are altered by time travelers",
    "Vaccines are a plot to microchip the population",
    "Bigfoot is a government experiment gone wrong"
};

const char* details[MAX_DETAILS] = {
    "to hide the truth about extraterrestrials.",
    "to manipulate our thoughts through subliminal messages.",
    "because they are planning to take over the planet.",
    "to harness the energy from black holes.",
    "as a distraction from their real agenda.",
    "to create a new world order.",
    "to eradicate the human race.",
    "to test behavioral responses under extreme pressure.",
    "as part of a secret agreement with ancient civilizations.",
    "to control the weather and its effects on society."
};

void generate_conspiracy(char* buffer) {
    int conspiracy_index = rand() % MAX_CONSPIRACIES;
    int detail_index = rand() % MAX_DETAILS;

    snprintf(buffer, MAX_CHAR, "Conspiracy Theory: %s %s", 
             conspiracies[conspiracy_index], 
             details[detail_index]);
}

void print_conspiracy_theories(int count) {
    char buffer[MAX_CHAR];
    for (int i = 0; i < count; i++) {
        generate_conspiracy(buffer);
        printf("%d. %s\n", i + 1, buffer);
    }
}

int main() {
    int count;

    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the C Random Conspiracy Theory Generator!\n");
    printf("How many conspiracy theories would you like to generate? ");
    scanf("%d", &count);

    if (count > 0 && count <= 100) {
        print_conspiracy_theories(count);
    } else {
        printf("Please enter a number between 1 and 100.\n");
    }

    return 0;
}