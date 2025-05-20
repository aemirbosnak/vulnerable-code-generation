//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEXT "The quick brown fox jumps over the lazy dog."
#define WPM_GOAL 60
#define WPM_THRESHOLD (WPM_GOAL * 0.8)
#define MAX_ATTEMPTS 5

int main() {
    char input[100];
    int attempts = 0;
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int wpm = 0;
    int threshold = WPM_THRESHOLD;
    int passed = 0;
    int failed = 0;
    time_t start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a text to type.\n");
    printf("Your goal is to type %d words per minute.\n", WPM_GOAL);
    printf("You have %d attempts to reach this goal.\n", MAX_ATTEMPTS);
    printf("Press enter to begin.\n");
    scanf("%s", input);

    srand(time(NULL));
    int length = rand() % (sizeof(TEXT) - 1) + 1;
    char* text = TEXT;
    char* truncated_text = malloc(length + 1);
    strncpy(truncated_text, text, length);
    truncated_text[length] = '\0';

    start_time = time(NULL);
    while (attempts < MAX_ATTEMPTS && wpm < threshold) {
        printf("Type the following text:\n%s\n", truncated_text);
        fflush(stdout);
        scanf("%s", input);

        total += strlen(input);
        correct += (strcmp(input, truncated_text) == 0);
        incorrect += (strcmp(input, truncated_text)!= 0);

        if (correct > 0 && incorrect == 0) {
            wpm = (int)round(((double)correct / 5) * 60);
            passed = 1;
        }

        attempts++;
    }

    end_time = time(NULL);
    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct, incorrect);
    printf("Your average words per minute is %d.\n", wpm);

    if (passed) {
        printf("Congratulations! You passed the test!\n");
    } else {
        printf("Sorry, you did not pass the test.\n");
    }

    free(truncated_text);
    return 0;
}