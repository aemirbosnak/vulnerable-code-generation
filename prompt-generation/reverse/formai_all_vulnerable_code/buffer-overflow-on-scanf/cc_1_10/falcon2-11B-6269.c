//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100

int main()
{
    int words[MAX_WORDS];
    char words_input[MAX_WORDS][MAX_WORD_LENGTH];
    char words_output[MAX_WORDS][MAX_WORD_LENGTH];
    int i, j, k, l, m;
    int word_count = 0;
    int time_start, time_end;
    float time_spent;
    char test_string[100];

    printf("Welcome to the C Typing Speed Test!\n");
    printf("Please enter your name:\n");
    scanf("%s", test_string);
    printf("Hello, %s! Let's start the test.\n", test_string);

    printf("Here are the words you will be typing:\n");
    for (i = 0; i < MAX_WORDS; i++) {
        sprintf(words_input[i], "%d: %s", i+1, "word");
        words[i] = 0;
    }

    for (i = 0; i < MAX_WORDS; i++) {
        printf("%s\n", words_input[i]);
    }

    printf("Please start typing the words.\n");
    printf("When you are done, press Enter.\n");

    fflush(stdin);
    getchar();

    time_start = clock();
    while (1) {
        scanf("%s", words_input[word_count]);
        fflush(stdin);
        getchar();

        time_end = clock();
        time_spent = (float)(time_end - time_start) / CLOCKS_PER_SEC;
        printf("Word %d: %s\n", word_count+1, words_input[word_count]);
        word_count++;

        if (word_count == MAX_WORDS) {
            break;
        }
    }

    printf("Congratulations, you have completed the test!\n");
    printf("Your typing speed is %.2f words per minute.\n", word_count / (time_spent / 60));
    printf("You typed %d words in total.\n", word_count);

    return 0;
}