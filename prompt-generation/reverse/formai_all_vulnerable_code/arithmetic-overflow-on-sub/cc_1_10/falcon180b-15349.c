//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define NUM_WORDS 10
#define NUM_TRIALS 3

// Function to generate a random word of a given length
void generate_word(char* word, int length) {
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
}

// Function to print a random word and measure the user's typing speed
double measure_typing_speed(char* word) {
    clock_t start = clock();
    printf("Type the following word: %s\n", word);
    fflush(stdout); // Ensure the prompt is printed immediately
    char input[MAX_WORD_LENGTH];
    scanf("%s", input);
    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    char words[NUM_WORDS][MAX_WORD_LENGTH];
    for (int i = 0; i < NUM_WORDS; i++) {
        generate_word(words[i], rand() % (MAX_WORD_LENGTH - 1) + 1);
    }

    double total_typing_speed = 0;
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        int index = rand() % NUM_WORDS;
        printf("Trial %d:\n", trial + 1);
        for (int i = 0; i < NUM_WORDS; i++) {
            if (i == index) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");

        double typing_speed = measure_typing_speed(words[index]);
        printf("Your typing speed for '%s' is %.2f words per second.\n", words[index], typing_speed);
        total_typing_speed += typing_speed;
    }

    printf("Your average typing speed across all trials is %.2f words per second.\n", total_typing_speed / NUM_TRIALS);

    return 0;
}