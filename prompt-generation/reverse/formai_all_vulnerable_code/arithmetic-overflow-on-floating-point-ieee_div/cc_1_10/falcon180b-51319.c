//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    char *words_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int i;
    for (i = 0; i < num_words; i++) {
        int rand_index = rand() % 10;
        strcpy(words[i].word, words_list[rand_index]);
        words[i].length = strlen(words[i].word);
    }
}

int main() {
    int num_words = 5;
    struct word words[MAX_WORDS];
    int i, j;
    char input[MAX_WORD_LENGTH];
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int start_time, end_time;

    // Generate words
    generate_words(words, num_words);

    // Print words
    printf("You will be typing the following words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s (%d characters)\n", words[i].word, words[i].length);
    }

    // Start timer
    start_time = clock();

    // Get user input
    for (i = 0; i < num_words; i++) {
        printf("Type the following word: ");
        scanf("%s", input);

        // Check if input is correct
        for (j = 0; j < strlen(words[i].word); j++) {
            if (input[j]!= words[i].word[j]) {
                break;
            }
        }
        if (j == strlen(words[i].word)) {
            correct++;
        } else {
            incorrect++;
        }
        total++;
    }

    // Stop timer
    end_time = clock();

    // Calculate typing speed
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double words_per_minute = total / time_taken * 60;

    // Print results
    printf("\nResults:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Words per minute: %.2f\n", words_per_minute);

    return 0;
}