//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORDS 50
#define WORD_LEN 10

void print_instructions() {
    printf("Welcome to Retro Typing Speed Test!\n");
    printf("Type the words shown on screen as fast as you can!\n");
    printf("Press ENTER to start the test...\n");
    getchar();
    system("clear");
}

int main() {
    srand(time(NULL));
    char words[MAX_WORDS][WORD_LEN] = {"cat", "dog", "tree", "house", "car", "book", "love", "joy", "light", "peace",
									   "ruby", "python", "cocoa", "laptop", "phone", "happy", "focus", "abrupt", "quack", "rudiment"};
    char input[WORD_LEN];
    int test_time = 10, word_count = 0, correct_count = 0;
    clock_t start_time, end_time;
    double elapsed_time;

    print_instructions();
    start_time = clock();
    while ((elapsed_time = ((double) (clock() - start_time)) / CLOCKS_PER_SEC) < test_time) {
        int word_idx = rand() % MAX_WORDS;
        printf("%s\n", words[word_idx]);
        scanf("%s", input);
        if (strcmp(input, words[word_idx]) == 0) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Wrong...\n");
        }
        word_count++;
    }
    end_time = clock();
    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    system("clear");
    printf("RESULTS - Retro Typing Speed Test\n");
    printf("Total words typed: %d\n", word_count);
    printf("Total correct words: %d\n", correct_count);
    printf("Total incorrect words: %d\n", word_count - correct_count);
    printf("Total time elapsed: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %d WPM\n", (int) (((double) correct_count / elapsed_time) * 60 / 5));

    return 0;
}