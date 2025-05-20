//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_CONSPIRACY_PARTS 5

// Array of conspiracy parts
const char *conspiracy_parts[MAX_CONSPIRACY_PARTS] = {
    "reptilian overlords",
    "moon landing hoax",
    "chemtrails",
    "Illuminati",
    "alien autopsy",
    "fluoride in water",
    "flat earth",
    "JFK assassination conspiracy",
    "9/11 inside job",
    "lizard people"
};

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to recursively generate a conspiracy theory
void generate_conspiracy(int depth, int num_parts) {
    int i, j;

    // Base case: no more parts to add
    if (num_parts == 0) {
        printf("Conspiracy theory of depth %d: %s\n", depth, "The truth is hidden.");
        return;
    }

    // Recursive case: add a random conspiracy part
    printf("Conspiracy theory of depth %d: ", depth);
    i = random_number(0, MAX_CONSPIRACIES - 1);
    printf("%s ", conspiracy_parts[i]);

    generate_conspiracy(depth + 1, num_parts - 1);
}

int main() {
    srand(time(NULL));
    int depth, num_parts;

    // Generate a random number of conspiracy parts
    num_parts = random_number(1, MAX_CONSPIRACIES);

    // Generate the conspiracy theory
    depth = 0;
    printf("Generating conspiracy theory with %d parts:\n", num_parts);
    generate_conspiracy(depth, num_parts);

    return 0;
}