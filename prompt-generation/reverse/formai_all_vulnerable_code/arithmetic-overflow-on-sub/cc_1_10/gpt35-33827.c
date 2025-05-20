//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_TESTS 3
#define TEST_TIME_LIMIT 5

int main(void) {
    int i;
    char input[100];
    int elapsed_time, num_correct_chars, total_chars_typed;
    double typing_speed;
    clock_t start_time, end_time;

    char* test_phrases[NUM_TESTS] = {"The quick brown fox jumps over the lazy dog", 
                                 "Sphinx of black quartz, judge my vow", 
                                 "Pack my box with five dozen liquor jugs"};

    srand(time(NULL));

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will have %d seconds to type each phrase.\n", TEST_TIME_LIMIT);

    for (i = 0; i < NUM_TESTS; ++i) {
        printf("\nTest phrase %d: %s\n", i+1, test_phrases[i]);
        printf("Press enter to start.\n");
        fgets(input, sizeof(input), stdin);
        printf("Starting in 3...\n");
        sleep(1);
        printf("2...\n");
        sleep(1);
        printf("1...\n");
        sleep(1);
        printf("GO!\n");

        num_correct_chars = 0;
        total_chars_typed = 0;
        start_time = clock();
        while (((elapsed_time = (clock() - start_time) / CLOCKS_PER_SEC) < TEST_TIME_LIMIT) && (total_chars_typed < strlen(test_phrases[i]))) {
            fgets(input, sizeof(input), stdin);
            if (input[0] == test_phrases[i][total_chars_typed]) {
                ++num_correct_chars;
            }
            ++total_chars_typed;
        }
        end_time = clock();
        typing_speed = (double) total_chars_typed / (double) (end_time - start_time) * CLOCKS_PER_SEC * 60;
        printf("Time elapsed: %d seconds\n", elapsed_time);
        printf("Total characters typed: %d\n", total_chars_typed);
        printf("Number of correct characters: %d\n", num_correct_chars);
        printf("Typing speed: %.2f characters per minute\n", typing_speed);
    }

    printf("\nThank you for taking the Typing Speed Test!\n");

    return 0;
}