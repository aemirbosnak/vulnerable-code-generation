//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|;':\",./<>?"
#define CHARACTERS_LENGTH 95

#define WPM_THRESHOLD 30
#define ACCURACY_THRESHOLD 90

struct {
    char text[1000];
    int length;
    int correct;
    int incorrect;
    int wpm;
    int accuracy;
} test;

void initialize_test() {
    test.correct = 0;
    test.incorrect = 0;
    test.length = 0;
    test.wpm = 0;
    test.accuracy = 0;
}

void generate_test() {
    srand(time(NULL));
    int i;
    for (i = 0; i < 1000; i++) {
        test.text[i] = CHARACTERS[rand() % CHARACTERS_LENGTH];
        test.length++;
    }
    test.text[test.length] = '\0';
}

void display_test() {
    printf("Test:\n%s\n", test.text);
}

int main() {
    initialize_test();
    generate_test();
    display_test();

    int start_time = clock();
    int i;
    for (i = 0; i < test.length; i++) {
        char c = getchar();
        if (c == test.text[i]) {
            test.correct++;
        } else {
            test.incorrect++;
        }
    }
    int end_time = clock();

    test.wpm = (double)(test.correct + test.incorrect) / ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 60;
    test.accuracy = (double)test.correct / test.length * 100;

    printf("\nResults:\n");
    printf("Correct: %d\n", test.correct);
    printf("Incorrect: %d\n", test.incorrect);
    printf("Words per minute: %.2f\n", test.wpm);
    printf("Accuracy: %.2f%%\n", test.accuracy);

    if (test.wpm >= WPM_THRESHOLD && test.accuracy >= ACCURACY_THRESHOLD) {
        printf("Congratulations! You passed the typing speed test.\n");
    } else {
        printf("Sorry, you did not pass the typing speed test.\n");
    }

    return 0;
}