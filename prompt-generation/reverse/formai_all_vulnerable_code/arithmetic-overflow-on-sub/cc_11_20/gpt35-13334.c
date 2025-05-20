//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char input;
    int correct = 0;
    int incorrect = 0;
    int time_taken = 0;
    int speed;

    printf("\nType the following text as fast as you can: \n");

    // Randomly generated paragraph for typing test
    printf("\n\"The quick brown fox jumps over the lazy dog. Jackdaws love my big sphinx of quartz. " 
            "The five boxing wizards jump quickly. How vexingly quick daft zebras jump!\" \n");

    time_t start_time = time(NULL);

    for (int i = 0; i < 10; i++) {
        input = getchar();
        if (input == '\n') {
            // Prevents user from spamming enter key
            i--;
            continue;
        }

        if (input == 'T' || input == 't') {
            // Exit program if user types "quit"
            char next_char = getchar();
            if (next_char == 'i' || next_char == 'I') {
                char third_char = getchar();
                if (third_char == 'm' || third_char == 'M') {
                    char fourth_char = getchar();
                    if (fourth_char == 'e' || fourth_char == 'E') {
                        exit(0);
                    }
                }
            }
        }

        if (input == "the quick brown fox jumps over the lazy dog. jackdaws love my big sphinx of quartz. " 
        "the five boxing wizards jump quickly. how vexingly quick daft zebras jump!"[i]) {
            // Correctly typed character
            correct++;
        } else {
            // Incorrectly typed character
            incorrect++;
        }
    }

    time_t end_time = time(NULL);
    time_taken = end_time - start_time;

    if (time_taken != 0) {
        // Calculate typing speed based on time taken and correct characters typed
        speed = correct / time_taken * 60;
    } else {
        speed = 0;
    }

    // Display typing speed, number of correct and incorrect characters
    printf("You typed with a speed of %d WPM (words per minute).\n", speed);
    printf("Number of correct characters: %d\n", correct);
    printf("Number of incorrect characters: %d\n", incorrect);

    return 0;
}