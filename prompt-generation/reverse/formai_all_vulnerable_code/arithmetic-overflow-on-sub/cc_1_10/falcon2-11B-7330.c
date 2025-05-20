//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEST_LENGTH 100

int main() {
    int test_length = 0;
    int word_length = 0;
    int test_words[MAX_TEST_LENGTH];
    int test_letters[MAX_TEST_LENGTH];
    int test_time[MAX_TEST_LENGTH];
    int total_words = 0;
    int total_letters = 0;
    int total_time = 0;

    printf("Welcome to the C Typing Speed Test!\n");
    printf("This program will test your typing speed by having you type a random string of letters.\n");
    printf("The program will measure the time it takes you to type the string and calculate your typing speed.\n");
    printf("Please type as fast as you can!\n");

    while (test_length < MAX_TEST_LENGTH) {
        srand(time(NULL));
        test_length = rand() % (MAX_TEST_LENGTH - 1);
        word_length = rand() % (test_length + 1);

        printf("Type the following string of letters as fast as you can: ");
        for (int i = 0; i < test_length; i++) {
            test_words[i] = rand() % 26 + 'a';
            test_letters[i] = test_words[i];
        }

        printf("%s\n", test_words);

        clock_t start_time = clock();

        for (int i = 0; i < word_length; i++) {
            printf(" ");
            scanf("%c", &test_letters[i]);
        }

        clock_t end_time = clock();

        test_time[test_length] = (end_time - start_time) / CLOCKS_PER_SEC * 1000;

        total_words += test_length;
        total_letters += test_length * word_length;
        total_time += test_time[test_length];
    }

    printf("You typed %d words with %d letters in %d seconds on average.\n", total_words, total_letters, total_time / total_words);
}