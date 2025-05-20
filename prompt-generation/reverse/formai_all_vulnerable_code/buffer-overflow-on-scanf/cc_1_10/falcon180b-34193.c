//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void generate_words(struct word words[], int num_words) {
    const char *word_list[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "watermelon", "xylophone", "yellow", "zebra"};
    int i;

    for (i = 0; i < num_words; i++) {
        int rand_index = rand() % sizeof(word_list) / sizeof(word_list[0]);
        strcpy(words[i].word, word_list[rand_index]);
        words[i].length = strlen(words[i].word);
    }
}

int main() {
    struct word words[MAX_WORDS];
    int num_words, i, correct_words = 0, incorrect_words = 0;
    double speed;

    srand(time(NULL));
    num_words = rand() % MAX_WORDS + 1;

    generate_words(words, num_words);

    printf("You will be typing the following %d words:\n", num_words);
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i].word);
    }

    printf("\nPress enter to begin the test...\n");
    getchar();

    clock_t start_time = clock();
    while (1) {
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strlen(input) == words[correct_words].length) {
            if (strcmp(input, words[correct_words].word) == 0) {
                correct_words++;
            } else {
                incorrect_words++;
            }
        } else {
            incorrect_words++;
        }

        if (correct_words == num_words) {
            break;
        }
    }

    speed = (double)num_words / (clock() - start_time) * 60;

    printf("\nTest complete!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your typing speed is %.2f words per minute.\n", speed);

    return 0;
}