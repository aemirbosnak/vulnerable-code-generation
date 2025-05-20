//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char c, input;
    int correct = 0, incorrect = 0, i = 0, time_taken, typing_speed, avg_typing_speed;
    int start = rand() % 26;
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char test_word[7];

    printf("--------------Welcome to the Typing Speed Test--------------\n");
    printf("------------------------------------------------------------\n");
    printf("To start the test, please type the given word as fast as you can\n");

    while (i < 6) {
        test_word[i] = alphabet[start];
        printf("%c", test_word[i]);
        start = (start + 1) % 26;
        i++;
    }
    printf("\n");

    time_t start_time = time(NULL);

    while (1) {

        input = getchar();

        if (input == '\n') {
            break;
        }

        if (input == test_word[i-6]) {
            printf("%c", input);
            correct++;
        } else {
            printf("\033[1;31m%c\033[0m", input);
            incorrect++;
        }

        i++;

        if (i == 7) {
            break;
        }
    }

    time_taken = (int)(time(NULL) - start_time);

    if (time_taken > 0 && correct > 0) {
        typing_speed = (correct / time_taken) * 60;
        printf("\n\nCongratulations! You typed the word correctly!\n");
        printf("Number of correct characters: %d\n", correct);
        printf("Number of incorrect characters: %d\n", incorrect);
        printf("Time taken: %d seconds\n", time_taken);
        printf("Typing speed: %d characters per minute\n", typing_speed);
    } else {
        printf("\n\nOops! Looks like you did not type the word correctly. Better luck next time!\n");
    }

    printf("------------------------------------------------------------\n");
    printf("Thank you for taking the Typing Speed Test. Please come back soon!\n");
    printf("------------------------------------------------------------\n");

    return 0;
}