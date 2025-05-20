//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
};

void load_words(struct word* words, int* num_words) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    *num_words = 0;
    while (fscanf(file, "%s", words[*num_words].word)!= EOF) {
        (*num_words)++;
    }
    fclose(file);
}

bool is_word(char* text, int start, int end) {
    while (start < end) {
        char c = tolower(text[start]);
        if (!isalpha(c)) {
            return false;
        }
        start++;
    }
    return true;
}

void check_spelling(struct word* words, int num_words, char* text) {
    int i, j;
    int word_start = 0;
    int word_end = 0;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word_end = i;
        } else {
            if (word_end - word_start > 0) {
                for (j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, text + word_start) == 0) {
                        words[j].is_correct = true;
                        break;
                    }
                }
            }
            word_start = i + 1;
        }
    }

    for (j = 0; j < num_words; j++) {
        if (!words[j].is_correct) {
            printf("%s is not in the dictionary\n", words[j].word);
        }
    }
}

int main() {
    struct word words[MAX_WORDS];
    int num_words;

    load_words(words, &num_words);

    char text[1000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    check_spelling(words, num_words, text);

    return 0;
}