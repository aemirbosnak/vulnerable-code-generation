//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

void generate_words(Word words[], int num_words) {
    const char *words_list[] = {
        "apple", "banana", "cherry", "date", "elderberry", "fig", "grape",
        "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "peach",
        "plum", "quince", "raspberry", "strawberry", "tangerine", "watermelon",
        "xylophone", "yellow", "zebra"
    };

    for (int i = 0; i < num_words; i++) {
        int rand_index = rand() % (sizeof(words_list) / sizeof(words_list[0]));
        strcpy(words[i].word, words_list[rand_index]);
        words[i].length = strlen(words[i].word);
    }
}

int main() {
    Word words[MAX_NUM_WORDS];
    int num_words;

    printf("Enter the number of words you want to type: ");
    scanf("%d", &num_words);

    if (num_words > MAX_NUM_WORDS) {
        printf("Error: Too many words.\n");
        return 1;
    }

    generate_words(words, num_words);

    printf("Enter the words as they appear:\n");

    for (int i = 0; i < num_words; i++) {
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, words[i].word)!= 0) {
            printf("Incorrect word.\n");
            return 1;
        }
    }

    printf("Congratulations! You have completed the typing test.\n");

    return 0;
}