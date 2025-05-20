//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* words[] = {"the", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dog"};
    int num_words = sizeof(words) / sizeof(words[0]);
    int word_index = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = 0;
    int start_time, end_time;
    int elapsed_time;
    int wpm;

    srand(time(NULL));
    word_index = rand() % num_words;

    printf("Welcome to the Cryptic C Typing Speed Test!\n\n");
    printf("You will be typing the following passage:\n\n");
    printf("%s\n\n", words[word_index]);

    start_time = clock();

    while (1) {
        char input[100];
        fgets(input, 100, stdin);
        total_words += strlen(input);

        if (strcmp(input, words[word_index]) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }

        if (total_words >= num_words) {
            break;
        }

        word_index = (word_index + 1) % num_words;
        printf("\n%s\n", words[word_index]);
    }

    end_time = clock();
    elapsed_time = (end_time - start_time) / (double)CLOCKS_PER_SEC;
    wpm = (int)(60 * num_words / (elapsed_time * 5));

    printf("\n\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your typing speed is %d words per minute.\n", wpm);

    return 0;
}