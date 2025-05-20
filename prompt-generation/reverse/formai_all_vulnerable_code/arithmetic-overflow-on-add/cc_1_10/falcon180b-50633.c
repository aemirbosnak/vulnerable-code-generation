//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_words, num_of_correct_words, num_of_incorrect_words, total_chars, correct_chars, incorrect_chars, wpm, accuracy;
    float speed;
    char *words[] = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
    char input[100];
    int i, j, k, len;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("This test will measure your typing speed and accuracy.\n");
    printf("You will be given a list of words to type.\n");
    printf("Type each word as accurately and quickly as possible.\n");
    printf("Press enter after each word.\n");

    srand(time(NULL));
    num_of_words = rand() % 10 + 1; // generate a random number of words between 1 and 10

    for (i = 0; i < num_of_words; i++) {
        printf("%s ", words[i]);
    }

    fflush(stdout); // clear the output buffer
    start_time = time(NULL); // start the timer

    while (fgets(input, sizeof(input), stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // remove the newline character
        len = strlen(input);

        if (len == 0) {
            continue;
        }

        for (j = 0; j < num_of_words; j++) {
            k = 0;
            while (words[j][k] == input[k]) {
                k++;
            }

            if (k == len && words[j][k] == '\0') {
                num_of_correct_words++;
                correct_chars += len;
            } else {
                num_of_incorrect_words++;
                incorrect_chars += len;
            }

            total_chars += len;
        }
    }

    end_time = time(NULL); // stop the timer

    wpm = (total_chars / 5) * 60; // calculate words per minute
    accuracy = ((float)correct_chars / total_chars) * 100; // calculate accuracy

    printf("\nTest results:\n");
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}