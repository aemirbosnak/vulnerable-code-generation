//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: systematic
/*
 * C Typing Speed Test
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TYPING_SPEED_TEST_TIME 10
#define TYPING_SPEED_TEST_LENGTH 50
#define MAX_WORD_LENGTH 10

void print_typing_speed_test_prompt();
int calculate_typing_speed(char *typed_words);
void print_typing_speed_results(int typing_speed);

int main() {
    char typed_words[TYPING_SPEED_TEST_LENGTH][MAX_WORD_LENGTH];
    int i, j, typing_speed;

    print_typing_speed_test_prompt();

    for (i = 0; i < TYPING_SPEED_TEST_LENGTH; i++) {
        scanf("%s", typed_words[i]);
    }

    typing_speed = calculate_typing_speed(typed_words);

    print_typing_speed_results(typing_speed);

    return 0;
}

void print_typing_speed_test_prompt() {
    printf("Typing Speed Test\n");
    printf("================\n");
    printf("You will be presented with a series of words. Type each word as it is displayed and press enter.\n");
    printf("You will have %d seconds to complete the test.\n\n", TYPING_SPEED_TEST_TIME);
}

int calculate_typing_speed(char *typed_words) {
    int i, j, typing_speed = 0;

    for (i = 0; i < TYPING_SPEED_TEST_LENGTH; i++) {
        for (j = 0; j < strlen(typed_words[i]); j++) {
            typing_speed++;
        }
        typing_speed++; // Add 1 for the space between words
    }

    return typing_speed;
}

void print_typing_speed_results(int typing_speed) {
    printf("Your typing speed is %d words per minute.\n", typing_speed);
}