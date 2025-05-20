//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_word(char* word, int length) {
    int i;
    for (i = 0; i < length; i++) {
        word[i] = rand() % 26 + 'a';
    }
    word[length] = '\0';
}

int main() {
    int length;
    int max_length = 10;
    int min_length = 5;
    int num_words = 10;
    int i;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = 0;
    int wpm = 0;
    int accuracy = 0;
    char word[max_length];
    time_t start_time, end_time;

    srand(time(NULL));

    printf("Welcome to the Shape Shifting Typing Speed Test!\n");
    printf("In this test, you will be typing words that are constantly changing shape.\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("The words will be between %d and %d characters long.\n", min_length, max_length);
    printf("You will be given %d words to type.\n", num_words);
    printf("Press enter to begin the test.\n");
    scanf("%c", &word[0]);

    time(&start_time);

    for (i = 0; i < num_words; i++) {
        length = rand() % (max_length - min_length + 1) + min_length;
        generate_word(word, length);
        printf("%s\n", word);
        fflush(stdout);
        total_words++;

        while (1) {
            int c = getchar();
            if (c == '\n') {
                break;
            }
            if (c!= word[total_words % length]) {
                incorrect_words++;
            }
            total_words++;
        }
    }

    time(&end_time);

    wpm = (int)((double)total_words / (end_time - start_time) * 60);
    accuracy = (int)((double)correct_words / total_words * 100);

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your accuracy is %d%% and your WPM is %d.\n", accuracy, wpm);

    return 0;
}