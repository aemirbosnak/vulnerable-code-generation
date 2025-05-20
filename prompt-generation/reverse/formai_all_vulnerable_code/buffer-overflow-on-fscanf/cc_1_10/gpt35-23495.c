//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    int score = 0;
    time_t start_time, end_time;

    FILE* fp = fopen("typing_test_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file");
        return 1;
    }

    while (fscanf(fp, "%s", words[word_count]) != EOF && word_count < MAX_WORDS) {
        word_count++;
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the words as fast and accurately as possible.\n");

    printf("Press Enter when you are ready to start...");
    getchar();

    srand((unsigned int) time(NULL));

    start_time = time(NULL);

    for (int i = 0; i < word_count; i++) {
        int random_index = rand() % word_count;
        printf("%s ", words[random_index]);

        char typed_word[MAX_WORD_LENGTH];
        scanf("%s", typed_word);

        if (strcmp(words[random_index], typed_word) == 0) {
            score += strlen(words[random_index]);
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct word was: %s\n", words[random_index]);
        }
    }

    end_time = time(NULL);
    int elapsed_time = (int) (end_time - start_time);

    printf("You typed %d words in %d seconds!\n", word_count, elapsed_time);
    printf("Your typing speed is %d wpm!\n", (int) ((float) score / elapsed_time * 60 / 5));

    return 0;
}