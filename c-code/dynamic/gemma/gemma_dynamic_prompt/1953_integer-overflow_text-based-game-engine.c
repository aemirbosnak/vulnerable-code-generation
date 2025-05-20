#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    int max_score = 1000000000;

    // Increment score beyond max_score to trigger overflow
    score = score + max_score + 1;

    // Print score
    printf("Your score: %d", score);

    return 0;
}
