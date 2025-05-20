//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <time.h>
#include <string.h>

#define LENGTH 100
#define DELAY 0.1

int main() {
    int i, score = 0;
    char words[LENGTH][LENGTH];
    char input[LENGTH][LENGTH];
    char correct[LENGTH][LENGTH];

    for (i = 0; i < LENGTH; i++) {
        words[i][LENGTH] = '\0';
        input[i][LENGTH] = '\0';
        correct[i][LENGTH] = '\0';
    }

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Here are the words you need to type:\n");

    for (i = 0; i < LENGTH; i++) {
        words[i][LENGTH] = (char) (i + 'a');
        printf("%c", words[i][LENGTH]);
    }
    printf("\n\n");

    for (i = 0; i < LENGTH; i++) {
        input[i][LENGTH] = (char) (i + 'a');
        correct[i][LENGTH] = (char) (i + 'a');
    }

    clock_t start, end;
    double elapsed;

    for (i = 0; i < LENGTH; i++) {
        start = clock();
        printf("Type %s now.\n", words[i]);
        fflush(stdout);
        gets(input[i]);
        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        score += elapsed * 100;
        if (strcmp(input[i], correct[i]) == 0) {
            score += 1000;
        }
        printf("Your typing speed is %lf words per minute.\n", score / LENGTH);
        printf("Correct answer: %c\n\n", correct[i][LENGTH]);
        fflush(stdout);
    }

    return 0;
}