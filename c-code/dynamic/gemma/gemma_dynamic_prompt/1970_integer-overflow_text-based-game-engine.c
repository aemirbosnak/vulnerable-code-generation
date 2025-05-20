#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int score = 0;
    int level = 1;

    printf("Welcome to the text-based game engine!\n");
    printf("Current level: %d\n", level);
    printf("Your score: %d\n", score);

    // Calculate the overflow
    int overflow_value = score * level;
    int overflow_result = overflow_value / score;

    // Print the overflow result
    printf("Overflow result: %d\n", overflow_result);

    return 0;
}
