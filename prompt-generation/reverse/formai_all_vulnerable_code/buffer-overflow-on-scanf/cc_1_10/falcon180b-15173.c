//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH + 1];
    int length;
};

void generate_words(struct word words[], int num_words) {
    const char *const word_list[] = {
        "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew",
        "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry",
        "strawberry", "tangerine", "watermelon", "xylophone", "yogurt", "zebra"
    };

    srand(time(NULL));
    for (int i = 0; i < num_words; i++) {
        int rand_index = rand() % (sizeof(word_list) / sizeof(word_list[0]));
        strncpy(words[i].word, word_list[rand_index], MAX_WORD_LENGTH);
        words[i].length = strlen(words[i].word);
    }
}

int main(void) {
    struct word words[MAX_WORDS];
    int num_words;

    printf("Enter the number of words to type (1-%d): ", MAX_WORDS);
    scanf("%d", &num_words);

    generate_words(words, num_words);

    int correct = 0;
    int incorrect = 0;
    int total = 0;

    for (int i = 0; i < num_words; i++) {
        printf("\nWord %d: ", i + 1);
        char input[MAX_WORD_LENGTH + 1];
        fgets(input, MAX_WORD_LENGTH + 1, stdin);

        input[strcspn(input, "\n")] = '\0';
        total++;

        if (strcmp(input, words[i].word) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    printf("\nYou typed %d words correctly and %d words incorrectly.\n", correct, incorrect);

    return 0;
}