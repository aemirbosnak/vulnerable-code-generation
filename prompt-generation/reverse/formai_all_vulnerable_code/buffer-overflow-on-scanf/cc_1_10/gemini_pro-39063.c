//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STRING_LENGTH 50
#define NUM_LINES 10

char *strings[] = {
    "The quick brown fox jumps over the lazy dog.",
    "The rain in Spain falls mainly on the plain.",
    "Now is the time for all good men to come to the aid of their country.",
    "Four score and seven years ago our fathers brought forth on this continent a new nation, conceived in liberty, and dedicated to the proposition that all men are created equal.",
    "We the People of the United States, in order to form a more perfect Union, establish Justice, insure domestic Tranquility, provide for the common defence, promote the general Welfare, and secure the Blessings of Liberty to ourselves and our Posterity, do ordain and establish this Constitution for the United States of America.",
    "I have a dream that one day this nation will rise up and live out the true meaning of its creed: 'We hold these truths to be self-evident, that all men are created equal.'",
    "The greatest glory in living lies not in never falling, but in rising every time we fall.",
    "The future belongs to those who believe in the beauty of their dreams.",
    "You must be the change you wish to see in the world.",
    "In the end, we only regret the chances we didn't take."
};

int main() {
    int i, j, c, errors = 0;
    double start_time, end_time, elapsed_time;
    char input[STRING_LENGTH + 1];

    printf("Typing Speed Test\n");
    printf("==================\n");

    srand(time(NULL));

    for (i = 0; i < NUM_LINES; i++) {
        start_time = clock();

        printf("%s\n", strings[i]);
        scanf("%s", input);

        end_time = clock();
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        for (j = 0; j < STRING_LENGTH; j++) {
            if (input[j] != strings[i][j]) {
                errors++;
            }
        }

        printf("Time: %.2f seconds\n", elapsed_time);
        printf("Errors: %d\n\n", errors);
    }

    return 0;
}