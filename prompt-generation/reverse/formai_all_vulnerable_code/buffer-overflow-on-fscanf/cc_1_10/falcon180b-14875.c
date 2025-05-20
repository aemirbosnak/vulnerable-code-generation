//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int length;
};

void load_words(struct word words[], int count) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        words[i].length = strlen(words[i].word);
        i++;
        if (i >= count) {
            break;
        }
    }
    fclose(file);
}

int main() {
    int max_words = MAX_WORDS;
    int num_words = 0;
    struct word words[MAX_WORDS];
    load_words(words, max_words);
    srand(time(NULL));
    int selected_word = rand() % max_words;
    char input[MAX_WORD_LENGTH];
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be typing the following words:\n");
    for (int i = 0; i < max_words; i++) {
        printf("%s (%d letters)\n", words[i].word, words[i].length);
    }
    printf("\n");
    printf("Type the following word:\n");
    printf("%s\n", words[selected_word].word);
    fgets(input, MAX_WORD_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (strcmp(input, words[selected_word].word) == 0) {
        printf("Congratulations! You typed '%s' correctly.\n", words[selected_word].word);
    } else {
        printf("Sorry, you typed '%s' instead of '%s'.\n", input, words[selected_word].word);
    }
    return 0;
}