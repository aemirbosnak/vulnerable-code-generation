//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10

char* words[NUM_WORDS] = {"neon", "cyber", "hacker", "matrix", "punk", "virtual", "reality", "futuristic", "tech", "glitch"};

int main() {
    int i, j;
    char input[WORD_LENGTH];
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int wpm = 0;
    int start_time, end_time;

    srand(time(NULL));
    for (i = 0; i < NUM_WORDS; i++) {
        j = rand() % NUM_WORDS;
        char* temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    printf("Cyberpunk Typing Speed Test\n");
    printf("===========================\n");
    printf("You will be typing %d words.\n", NUM_WORDS);
    printf("Each word is %d characters long.\n", WORD_LENGTH);
    printf("Press enter to begin.\n");
    scanf("%c", &input);

    start_time = clock();
    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i + 1);
        fflush(stdout);
        scanf("%c", input);
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
    }
    end_time = clock();

    wpm = (total - incorrect) / (end_time - start_time) * 60;

    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Words per minute: %d\n", wpm);

    return 0;
}