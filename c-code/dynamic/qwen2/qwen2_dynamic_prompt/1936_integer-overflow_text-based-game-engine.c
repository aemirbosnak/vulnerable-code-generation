#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void processGameData(int level, int score) {
    int maxScore = 1000;
    int bonus = 200;

    // Integer overflow vulnerability
    int newScore = score + bonus;

    if (newScore > maxScore) {
        printf("Congratulations! You've reached the maximum score.\n");
    } else {
        printf("Your new score is: %d\n", newScore);
    }
}

int main() {
    int level = 1;
    int score = -200; // Starting with a negative score to demonstrate overflow

    while (score <= 1000) {
        processGameData(level, score);
        score += 300; // Incrementing score by a large number to trigger overflow
        level++;
    }

    return 0;
}
